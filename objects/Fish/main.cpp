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

const double speed = 50; // pixels per second
struct fish{
    int id;
    int cx;
    int cy;
    int orientation;
    int jenis;
};

// Fish fishy[100];
// Fish piranha[100];

int num_pin;
int num_fish;
int num_ikan;

// thread ikan[100];
// mutex lock1;
char input;


int main( int argc, char* args[] )
{
    num_ikan = 1;
    num_fish = 1;
    num_pin = -1;
    Point temp;
    string nama = "adit";
    Fish F(nama,50,50,50,50,50,temp,'l');
    init();

    bool running = true;
    while(running){
        handle_input();
        double prevtime = time_since_start();
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        F.Move(prevtime,now,sec_since_last);
        clear_screen();
        //for(int i = 0; i < 1 ; i++){
        if(F.getOrientation() =='l'){
            draw_image("ikankiri.png", F.getPosition().getX(), F.getPosition().getY());
        }else{
            draw_image("ikankanan.png", F.getPosition().getX(), F.getPosition().getY());
        }
            
        //}
        // for(int i = 0; i <= num_pin; i++){
        //     if(piranha[i].getOrientation() =='l'){
        //         draw_image("piranhakiri.png", piranha[i].getPosition().getX(), piranha[i].getPosition().getY());
        //     }else{
        //         draw_image("piranhakanan.png", piranha[i].getPosition().getX(), piranha[i].getPosition().getY());
        //     }
        // }
        if(input=='x'){
            running=false;
            input = '0';
        }
        update_screen();
    }
    close();
    return 0;
}
