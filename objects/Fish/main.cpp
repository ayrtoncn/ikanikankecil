#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
#include "Fish.hpp"
using namespace std;


char input;

Fish *fishy=new Fish[100];

int num_fish;
int num_ikan;

thread ikan[100];
std::mutex lock1;

int main( int argc, char* args[] )
{
    init();
    num_ikan = -1;
    num_fish = -1;
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
            Point temp;
            string nama = "adit";
            Fish F(nama,50,50,50,50,50,temp,'l');
            fishy[num_fish] = F;
            ikan[num_fish] = thread(&Fish::dewaIkan,&fishy[num_fish]);
            input = '0';
        }   
        clear_screen();
        for(int i = 0; i <= num_fish ; i++){
            if(fishy[i].getOrientation() ==1){
                draw_image("ikankiri.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
            }else{
                draw_image("ikankanan.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
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
