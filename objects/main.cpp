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
            break;
        }
    }
    if(Aq->input == 'g'){
        srand(time(NULL));
        Aq->num_fish++;
        Aq->num_guppy++;
        Point temp;
        string nama = "adit";
        Aq->guppy.add(new Guppy(temp,'l'));
        Aq->ikan[Aq->num_fish] = thread(&Guppy::dewaGuppy,Aq->guppy[Aq->num_guppy]);
        Aq->input = '0';
    }else if(Aq->input =='p'){
        srand(time(NULL));
        Aq->num_piran++;
        Aq->num_fish++;
        Point temp;
        string nama = "adit";
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
    //Interaksi ikan piranha makan guppy
    for(int pir = 0; pir < Aq->num_piran; pir++){
        for(int gup = 0; gup < Aq->num_guppy; gup++){
            if(Aq->guppy[gup]->getPosition().getX() <= Aq->piranha[pir]->getPosition().getX()+50 
            && Aq->guppy[gup]->getPosition().getX() >= Aq->piranha[pir]->getPosition().getX()-60 
            && Aq->guppy[gup]->getPosition().getY() <= Aq->piranha[pir]->getPosition().getY()+50 
            && Aq->guppy[gup]->getPosition().getY() >= Aq->piranha[pir]->getPosition().getY()-50){
                Point t;
                t.setX(-100);
                t.setY(-100);
                //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                Aq->guppy[gup]->setPosition(t);
                Aq->guppy[gup]->setName("die");
            }
        }
    }           

    //interaksi ikan makan makanan

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