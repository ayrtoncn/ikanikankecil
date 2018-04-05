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
using namespace std;    

char input;

Piranha *piran=new Piranha[100];
Guppy *fishy=new Guppy[100];

int num_fish;
int num_guppy;
int num_piran;
thread ikan[100];
std::mutex lock1;

int main(){
    init();
    num_fish = -1;
    num_guppy = -1;
    num_piran =-1;
    bool running=true;
    while(running){
        handle_input();
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            // x untuk keluar
            case SDLK_g:
                input = 'g';
                break;
            case SDLK_x:
                input ='x';
                break;
            case SDLK_p:
                input ='p';
                break;
            }
        }
        if(input == 'g'){
            num_fish++;
            num_guppy++;
            Point temp;
            string nama = "adit";
            fishy[num_guppy] = Guppy(temp,'l');
            ikan[num_fish] = thread(&Guppy::dewaGuppy,&fishy[num_guppy]);
            input = '0';
        }else if(input =='p'){
            num_piran++;
            num_fish++;
            Point temp;
            string nama = "adit";
            piran[num_piran] = Piranha(temp,'l');
            ikan[num_fish] = thread(&Piranha::dewaPiranha,&piran[num_piran]);
            input = '0';
        }   
        clear_screen();
        draw_image("bg1.jpg", SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        for(int i = 0; i <= num_guppy ; i++){
            if(fishy[i].getOrientation() ==1){
                draw_image("ikankiri.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
            }else{
                draw_image("ikankanan.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
            }
        }
        for(int i = 0; i <= num_piran ; i++){
            if(piran[i].getOrientation() ==1){
                draw_image("piranhakiri.png", piran[i].getPosition().getX(), piran[i].getPosition().getY());
            }else{
                draw_image("piranhakanan.png", piran[i].getPosition().getX(), piran[i].getPosition().getY());
            }
        }
        if(input=='x'){
            running=false;
            input = '0';
        }
        update_screen();
    }
    
    return 0;
}