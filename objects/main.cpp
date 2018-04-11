#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
#include "Fish/Fish.hpp"
#include "Guppy/Guppy.hpp"
#include "Piranha/Piranha.hpp"
#include "Food/Food.hpp"
#include "Aquarium/Aquarium.hpp"
using namespace std;    

void InteractionChecker(Aquarium* Aq){
    Aq->lockAquarium();
    //interaksi dengan pengguna
    handle_input();
    for (auto key : get_tapped_keys()) {
        switch (key) {
        // r untuk reset
        // x untuk keluar
        case SDLK_g:
            Aq->input = 'g';
            break;
        case SDLK_x:
            Aq->input ='x';
            Aq->unlockAquarium();
            break;
        case SDLK_p:
            Aq->input ='p';
            break;
        case SDLK_e:
            Aq->input = 'e';
            break;
        case SDLK_s:
            Aq->input = 's';
            break;
        case SDL_BUTTON_LEFT:
            // cout<<num_food<<endl;
            Aq->input = 'c';
            //percobaan gerakin siput ke arah mouse click
            int x,y;
            SDL_GetMouseState(&x,&y);
            Point temp;
            temp.setX(x);
            temp.setY(y);
            break;
        }
    }
    
    int eggPrice = 30;
    if(Aq->input == 'g' && Aq->coin -Guppy::GUPPY_PRICE >=0) {
        srand(time(NULL));
        Aq->num_fish++;
        Aq->num_guppy++;
        Point temp;
        string nama = "adit";
        Aq->coin -=Guppy::GUPPY_PRICE;
        Aq->guppy.add(new Guppy(temp,'l'));
        Aq->ikan[Aq->num_fish] = thread(&Guppy::dewaGuppy,Aq->guppy[Aq->num_guppy]);
        Aq->input = '0';
    }
    else if(Aq->input =='p'&& Aq->coin-Piranha::PIRANHA_PRICE >=0) {
        srand(time(NULL));
        Aq->num_piran++;
        Aq->num_fish++;
        Point temp;
        string nama = "adit";
        Aq->coin -=Piranha::PIRANHA_PRICE;
        Aq->piranha.add(new Piranha(temp,'l'));
        Aq->ikan[Aq->num_fish] = thread(&Piranha::dewaPiranha,Aq->piranha[Aq->num_piran]);
        Aq->input = '0';
        //harga makanan belum dijadikan static
    }
    else if(Aq->input =='c') {
        int x,y;
        SDL_GetMouseState(&x,&y);
        bool coin_take=false;
        //interaksi mouse dengan coin
        for (int i = 0; i <= Aq->num_coin; i++) {
            if (Aq->coins[i]->getPosition().getX() <= x + 20 
            && Aq->coins[i]->getPosition().getX() >= x- 20 
            && Aq->coins[i]->getPosition().getY() >= y - 20
            && Aq->coins[i]->getPosition().getY() <= y + 20)
            {
                coin_take = true;
                Aq->coin += Aq->coins[i]->getValue();
                Aq->coins[i]->stop();
                Aq->coins.del(i);
                Aq->num_coin--;
                break;
            }
        }

        if(!coin_take && Aq->coin -5 >=0) {
            // /cout<<"AAA"<<endl;
            Aq->coin -=5;
            Aq->num_food++;
            Aq->num_object++;
            Aq->foods.add(new Food(x));
            Aq->object[Aq->num_object] = thread(&Food::executeFood,Aq->foods[Aq->num_food]); 
            Point temp;
            temp.setX(x);
            temp.setY(y);
            Aq->input = '0';
        }
        else {
            Aq->input = '0';
        }      
    }
    else if(Aq->input =='e' && Aq->coin - eggPrice >=0){
        Aq->coin -= eggPrice;
        Aq->num_eggs++;
        Aq->input = '0';
    }
    else if (Aq->input == 's') {
        Aq->save();
    }

    
    //interaksi piranha mencari guppy
    for (int pir = 0;pir<=Aq->num_piran;pir++){
        if(Aq->piranha[pir]->getIsHungry()){
            double min=999999;
            Point pmin;
            for(int gup =0;gup<=Aq->num_guppy;gup++){
                if(Aq->guppy[gup]->getName()!="die"){
                    double temp = sqrt(pow(Aq->piranha[pir]->getPosition().getX()-Aq->guppy[gup]->getPosition().getX(),2)+pow(Aq->piranha[pir]->getPosition().getY()-Aq->guppy[gup]->getPosition().getY(),2));
                    if(min>temp){
                        min = temp;
                        pmin.setX(Aq->guppy[gup]->getPosition().getX());
                        pmin.setY(Aq->guppy[gup]->getPosition().getY());
                    }
                }
            }
            //cout<<pmin.getX()<<" "<<pmin.getY()<<endl;
            Aq->piranha[pir]->setTujuan(pmin);
        }
    }

    //Interaksi ikan mencari makanan
    for (int gup = 0;gup<=Aq->num_guppy;gup++){
        if(Aq->guppy[gup]->getIsHungry()){
            double min=999999;
            Point pmin;
            for(int i =0;i<=Aq->num_food;i++){
                if(Aq->foods[i]->getName()!="die"){
                    double temp = sqrt(pow(Aq->guppy[gup]->getPosition().getX()-Aq->foods[i]->getPosition().getX(),2)+pow(Aq->guppy[gup]->getPosition().getY()-Aq->foods[i]->getPosition().getY(),2));
                    if(min>temp){
                        min = temp;
                        pmin.setX(Aq->foods[i]->getPosition().getX());
                        pmin.setY(Aq->foods[i]->getPosition().getY());

                    }
                }
            }
            Aq->guppy[gup]->setTujuan(pmin);
        }
    }

    //Interaksi ikan piranha makan guppy
    for(int pir = 0; pir <= Aq->num_piran; pir++){
        if(Aq->piranha[pir]->getIsHungry()){
            for(int gup = 0; gup <= Aq->num_guppy; gup++){
                if(Aq->guppy[gup]->getPosition().getX() <= Aq->piranha[pir]->getPosition().getX()+50 
                && Aq->guppy[gup]->getPosition().getX() >= Aq->piranha[pir]->getPosition().getX()-60 
                && Aq->guppy[gup]->getPosition().getY() <= Aq->piranha[pir]->getPosition().getY()+50 
                && Aq->guppy[gup]->getPosition().getY() >= Aq->piranha[pir]->getPosition().getY()-50){
                    //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                    Aq->guppy[gup]->setIsHungry(false);
                    Aq->guppy[gup]->setName("die");
                    Aq->piranha[pir]->Eat();

                    Aq->num_coin++;
                    Aq->num_object++;
                    int level;
                    if(Aq->guppy[gup]->getGrowthLevel()<=3){
                        level = 2;
                    }else if(Aq->guppy[gup]->getGrowthLevel()<=6){
                        level = 3;
                    }else{
                        level = 4;
                    }
                    Aq->coins.add(new Coin(Aq->guppy[gup]->getPrice() * level, 20, Aq->piranha[pir]->getPosition()));
                    Aq->object[Aq->num_object] = thread(&Coin::executeCoin, Aq->coins[Aq->num_coin]);

                    Aq->guppy.del(gup);
                    Aq->num_guppy = Aq->num_guppy - 1;
                }
            }
        }
    }           

    //interaksi ikan makan makanan
    for(int gup = 0; gup <= Aq->num_guppy; gup++){
        if(Aq->guppy[gup]->getIsHungry()){
            for(int i = 0; i <= Aq->num_food; i++){
                if(Aq->foods[i]->getPosition().getX() <= Aq->guppy[gup]->getPosition().getX()+50 
                && Aq->foods[i]->getPosition().getX() >= Aq->guppy[gup]->getPosition().getX()-60 
                && Aq->foods[i]->getPosition().getY() <= Aq->guppy[gup]->getPosition().getY()+50 
                && Aq->foods[i]->getPosition().getY() >= Aq->guppy[gup]->getPosition().getY()-50){
                    Aq->guppy[gup]->Eat();
                    Aq->foods[i]->stop();
                    Aq->foods.del(i);
                    Aq->num_food = Aq->num_food - 1;
                }
            }
        }
    }

    //Interaksi makanan sampai dasar
        for(int i = 0; i <= Aq->num_food; i++){
            if(Aq->foods[i]->getPosition().getY() >= SCREEN_HEIGHT-30){
                //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                Aq->foods[i]->stop();
                Aq->foods.del(i);
                Aq->num_food = Aq->num_food - 1;
            }
        }

    //interaksi ikan ngeluarin uang
    //Guppy
    for(int gup = 0; gup <= Aq->num_guppy; gup++){
        if(Aq->guppy[gup]->getDropCoin()){
            Aq->guppy[gup]->setDropCoin(false);
            Aq->guppy[gup]->DropCoin();
            if(Aq->guppy[gup]->getGrowthLevel()<=3){
                Aq->num_coin++;
                Aq->num_object++;
                Aq->coins.add(new Coin(10, 20, Aq->guppy[gup]->getPosition()));
                Aq->object[Aq->num_object] = thread(&Coin::executeCoin, Aq->coins[Aq->num_coin]);
            } else if(Aq->guppy[gup]->getGrowthLevel()<=6){
                Aq->num_coin++;
                Aq->num_object++;
                Aq->coins.add(new Coin(20, 20, Aq->guppy[gup]->getPosition()));
                Aq->object[Aq->num_object] = thread(&Coin::executeCoin, Aq->coins[Aq->num_coin]);
            } else if(Aq->guppy[gup]->getGrowthLevel()>6){
                Aq->num_coin++;
                Aq->num_object++;
                Aq->coins.add(new Coin(30, 20, Aq->guppy[gup]->getPosition()));
                Aq->object[Aq->num_object] = thread(&Coin::executeCoin, Aq->coins[Aq->num_coin]);
            }
        }
    }

    //interaksi siput mencari uang
    if (Aq->num_coin >= 0)
    {
        double min = 999999;
        double minL= 999999;
        Point pmin;
        Point pminL;
        for (int i = 0; i <= Aq->num_coin; i++)
        {
            double temp = sqrt(pow(Aq->snail.getPosition().getX() - Aq->coins[i]->getPosition().getX(), 2));
            double temp2 = sqrt(pow(SCREEN_HEIGHT-Aq->coins[i]->getPosition().getY(), 2));
            if(Aq->coins[i]->getPosition().getY()>=SCREEN_HEIGHT-40)
            {
                if (minL > temp)
                {
                    minL = temp;
                    pminL.setX(Aq->coins[i]->getPosition().getX());
                    pminL.setY(Aq->coins[i]->getPosition().getY());
                }
            }else{
                if (min > temp2)
                {
                    min = temp2;
                    pmin.setX(Aq->coins[i]->getPosition().getX());
                    pmin.setY(Aq->coins[i]->getPosition().getY());
                }
            }
            if(minL == 999999){
                Aq->snail.setTujuan(pmin);
            }else if(minL!=999999){
                Aq->snail.setTujuan(pminL);
            }
        }        
    }else{
        Aq->snail.setTujuan(Point());
    }

    //interaksi siput ngambil uang
    for (int i = 0; i <= Aq->num_coin; i++)
    {
        if (Aq->coins[i]->getPosition().getX() <= Aq->snail.getPosition().getX() + 20 
        && Aq->coins[i]->getPosition().getX() >= Aq->snail.getPosition().getX() - 20 
        && Aq->coins[i]->getPosition().getY() >= Aq->snail.getPosition().getY() - 20)
        {
            Aq->coin += Aq->coins[i]->getValue();
            Aq->coins[i]->~Coin();
            Aq->coins.del(i);
            Aq->num_coin--;
        }
    }
    

    Aq->unlockAquarium();
}

void AddFishFromFish(Aquarium& Aq, const Fish& _fish);
void AddCoinFromCoins(Aquarium& Aq, const Coin &coin);
void AddFoodfromFoods(Aquarium& Aq, const Food &food);

void DeleteFishFromFish(Aquarium& Aq, const Fish &_fish);
void DeleteCoinFromCoins(Aquarium& Aq, const Coin &coin);
void DeleteFoodfromFoods(Aquarium& Aq, const Food &food);


int main(){
    Aquarium *Aq = new Aquarium();
    Aq->runAquarium();
    delete Aq;
    return 0;
}