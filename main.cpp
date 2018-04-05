#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
using namespace std;

const double speed = 60; // pixels per second
struct fish{
    int id;
    int cx;
    int cy;
    int orientation;
    int jenis;
};

fish fishy[100];

int num_fish;

thread ikan[100];
std::mutex lock1;
char input;
void gerak(int ay,int jenis){
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;
    cy = fishy[ay].cy;
    cx = fishy[ay].cx;

    bool running = true;

    double prevtime = time_since_start();
    time_t start;
    time(&start);
    srand(time(NULL));
    double delay= rand()%4+1;
    int arah = rand()%8+1;
    int orientation;
    while (running) {
        std::lock_guard<mutex> locker(lock1);
        //cout << std::this_thread::get_id() << endl;
        if(fishy[ay].id==-99){
            break;
        }
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }
        if(cx<=10){
            arah = 4;
            time(&start);
        }else if(cx>=SCREEN_WIDTH-10){
            arah = 3;
            time(&start);
        }else if(cy<=10){
            arah = 2;
            time(&start);
        }else if(cy>=SCREEN_HEIGHT-10){
            arah = 1;
            time(&start);
        }

        if(difftime(time(0),start)<=delay){
            switch(arah){
                case 1:
                    cy -= speed * sec_since_last;
                    break;
                case 2:
                    cy += speed * sec_since_last;
                    break;
                case 3:
                    cx -= speed * sec_since_last;
                    orientation = 1;
                    break;
                case 4:
                    cx += speed * sec_since_last;
                    orientation = 2;
                    break;
                case 5:
                    cx += speed * sec_since_last;
                    cy += speed * sec_since_last;
                    orientation = 2;
                    break;
                case 6:
                    cx += speed * sec_since_last;
                    cy -= speed * sec_since_last;
                    orientation = 2;
                    break;
                case 7:
                    cx -= speed * sec_since_last;
                    cy += speed * sec_since_last;
                    orientation = 1;
                    break;
                case 8:
                    cx -= speed * sec_since_last;
                    cy -= speed * sec_since_last;
                    orientation = 1;
                    break;
            }
        }else{
            time(&start);
            delay= rand()%4+1;
            arah = rand()%8+1;
        }
        fishy[ay].cx = cx;
        fishy[ay].cy = cy;
        fishy[ay].orientation=orientation;
        // Proses masukan yang bersifat "tombol"
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

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }
        
        if(jenis == 1){
            for(int i = 0; i < num_fish; i++){
                if(fishy[i].jenis == 0){
                    if(fishy[i].cx <= fishy[ay].cx+30 && fishy[i].cx >= fishy[ay].cx-30 && fishy[i].cy <= fishy[ay].cy+30 && fishy[i].cy >= fishy[ay].cy-30){
                        fishy[i].id = -99;
                        fishy[i].cx = -100;
                        fishy[i].cy = -100;
                    }
                }
            }            
        }
    }
    cout << "Mati" << endl;
}


int main( int argc, char* args[] )
{
    num_fish = -1;
    init();
    // Menghitung FPS
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
            fishy[num_fish].cx = (100*num_fish)%1000;
            fishy[num_fish].cy = (100*num_fish)%580;
            fishy[num_fish].id = num_fish;
            fishy[num_fish].orientation = 1;
            fishy[num_fish].jenis = 0;
            ikan[num_fish] = thread(gerak,num_fish,0);
            input = '0';
        }else if(input == 'p'){
            num_fish++;
            fishy[num_fish].cx = (100*num_fish)%1000;
            fishy[num_fish].cy = (100*num_fish)%580;
            fishy[num_fish].id = num_fish;
            fishy[num_fish].orientation = 1;
            fishy[num_fish].jenis = 1;
            ikan[num_fish] = thread(gerak,num_fish,1);
            input = '0';
        }
        clear_screen();
        for(int i = 0; i <= num_fish ; i++){
            if(fishy[i].jenis==0 && fishy[i].id != -99){
                if(fishy[i].orientation ==1){
                    draw_image("ikankiri.png", fishy[i].cx, fishy[i].cy);
                }else{
                    draw_image("ikankanan.png", fishy[i].cx, fishy[i].cy);
                }
            }
            if(fishy[i].jenis==1 && fishy[i].id != -99){
                if(fishy[i].orientation ==1){
                    draw_image("piranhakiri.png", fishy[i].cx, fishy[i].cy);
                }else{
                    draw_image("piranhakanan.png", fishy[i].cx, fishy[i].cy);
                }
            }
        }
        if(input=='x'){
            running=false;
            input = '0';
        }
        for(int ay = 0; ay < num_fish; ay++){
            if(fishy[ay].jenis == 1){
                for(int i = 0; i < num_fish; i++){
                    if(fishy[i].jenis == 0){
                        if(fishy[i].cx <= fishy[ay].cx+30 && fishy[i].cx >= fishy[ay].cx-30 && fishy[i].cy <= fishy[ay].cy+30 && fishy[i].cy >= fishy[ay].cy-30){
                            fishy[i].id = -99;
                            fishy[i].cx = -100;
                            fishy[i].cy = -100;
                        }
                    }
                }
            }
        }  
        update_screen();
    }
    for(int i = 0; i <= num_fish; i++){
        fishy[i].id=-99;
        ikan[i].join();
    }
    return 0;
}
