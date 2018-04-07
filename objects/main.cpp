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
            break;
        case SDLK_p:
            Aq->input ='p';
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
            Aq->snail.setTujuan(temp);
            break;
        }
    }
    

    if(Aq->input == 'g' && Aq->coin -Guppy::GUPPY_PRICE >=0){
        srand(time(NULL));
        Aq->num_fish++;
        Aq->num_guppy++;
        Point temp;
        string nama = "adit";
        Aq->coin -=Guppy::GUPPY_PRICE;
        Aq->guppy.add(new Guppy(temp,'l'));
        Aq->ikan[Aq->num_fish] = thread(&Guppy::dewaGuppy,Aq->guppy[Aq->num_guppy]);
        Aq->input = '0';
    }else if(Aq->input =='p'&& Aq->coin-Piranha::PIRANHA_PRICE >=0){
        srand(time(NULL));
        Aq->num_piran++;
        Aq->num_fish++;
        Point temp;
        string nama = "adit";
        Aq->coin -=Piranha::PIRANHA_PRICE;
        Aq->piranha.add(new Piranha(temp,'l'));
        Aq->ikan[Aq->num_fish] = thread(&Piranha::dewaPiranha,Aq->piranha[Aq->num_piran]);
        Aq->input = '0';
    }else if(Aq->input =='c'){
        Aq->num_food++;
        Aq->num_object++;
        int x,y;
        SDL_GetMouseState(&x,&y);
        Aq->foods.add(new Food(x));
        Aq->object[Aq->num_object] = thread(&Food::executeFood,Aq->foods[Aq->num_food]); 
        Point temp;
        temp.setX(x);
        temp.setY(y);
        Aq->input = '0';
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
            //cout<<pmin.getX()<<" "<<pmin.getY()<<endl;
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
                    Point t;
                    t.setX(-100);
                    t.setY(-100);
                    //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                    Aq->guppy[gup]->setIsHungry(false);
                    Aq->guppy[gup]->setPosition(t);
                    Aq->guppy[gup]->setName("die");
                    Aq->piranha[pir]->Eat();
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
                    Point t;
                    t.setX(-100);
                    t.setY(-100);
                    Aq->guppy[gup]->Eat();
                    //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                    Aq->foods[i]->setPosition(t);
                    Aq->foods[i]->setName("die");
                    Aq->foods.del(i);
                    Aq->num_food = Aq->num_food - 1;
                }
            }
        }
    }   
    //interaksi ikan ngeluarin uang

    //interaksi siput ngambil uang
    Aq->unlockAquarium();
}

void AddFishFromFish(Aquarium& Aq, const Fish& _fish);
void AddCoinFromCoins(Aquarium& Aq, const Coin &coin);
void AddFoodfromFoods(Aquarium& Aq, const Food &food);

void DeleteFishFromFish(Aquarium& Aq, const Fish &_fish);
void DeleteCoinFromCoins(Aquarium& Aq, const Coin &coin);
void DeleteFoodfromFoods(Aquarium& Aq, const Food &food);


int main(){
    Aquarium Aq = Aquarium();
    Aq.runAquarium();
    return 0;
}