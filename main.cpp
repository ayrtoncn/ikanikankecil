#include "oop.hpp"
#include "objects/Aquarium/Aquarium.hpp"
#include "objects/Coin/Coin.hpp"
#include "objects/Fish/Fish.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <pthread.h>
#include <unistd.h>
#include <mutex>
using namespace std;
const double speed = 60; // pixels per second

Aquarium Aq;
thread threads[1000];
int thread_num;
mutex lock1;


void FishController(void* threadarg){
    
}

int main(){
    Aq = new Aquarium();
    thread_num = 0;
    int rc;
    init();
    bool running = true;
    while(running){
        handle_input();
        for (auto key : get_tapped_keys()) {
            switch (key) {
                case SDLK_b:
                    lock1.lock();
                    threads[0] = thread(FishController,Aq.getFish(Aq.getFishList()->getAmmount()));
                    if(rc){
                        cout<<"gagal";
                        exit(-1);
                    }
                    lock1.unlock();
                    break;
                // x untuk keluar
                case SDLK_x:
                    running = false;
                    break;
            }
        }
        draw_image("bg1.jpg", SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        for(int i = 0; i < Aq.getFishList()->getAmmount(); i++){
            if(!strcmp(Aq.getFish(i)->getName().c_str(),"Guppy")){
                if(Aq.getFish(i)->getOrientation() == 1){
                    draw_image("ikankiri.png",Aq.getFish(i)->getPosition().getX(),Aq.getFish(i)->getPosition().getY());
                }else{
                    draw_image("ikankanan.png",Aq.getFish(i)->getPosition().getX(),Aq.getFish(i)->getPosition().getY());
                }
            }else{
                if(Aq.getFish(i)->getOrientation() == 1){
                    draw_image("piranhakiri.png",Aq.getFish(i)->getPosition().getX(),Aq.getFish(i)->getPosition().getY());
                }else{
                    draw_image("piranhakanan.png",Aq.getFish(i)->getPosition().getX(),Aq.getFish(i)->getPosition().getY());
                }
            }
        }
        update_screen();
    }
}