#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
using namespace std;

const double speed = 50; // pixels per second
struct fish{
    int id;
    int cx;
    int cy;
    int orientation;
    int jenis;
};

fish fishy[100];
fish piranha[100];

int num_pin;
int num_fish;
int num_ikan;

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
    if(jenis == 1){
        cy = fishy[ay].cy;
        cx = fishy[ay].cx;
    }else{
        cy = piranha[ay].cy;
        cx = piranha[ay].cx;
    }

    bool running = true;

    double prevtime = time_since_start();
    time_t start;
    time(&start);
    srand(time(NULL));
    double delay= rand()%4+1;
    int arah = rand()%8+1;
    int orientation;
    while (running) {
        if(jenis == 1 && fishy[ay].id==-99){
            break;
        }else if(jenis == 2 && piranha[ay].id == -99){
            break;
        }
        lock1.lock();
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
        if(jenis == 1){
            fishy[ay].cx = cx;
            fishy[ay].cy = cy;
            fishy[ay].orientation=orientation;
        }else{
            piranha[ay].cx = cx;
            piranha[ay].cy = cy;
            piranha[ay].orientation=orientation;
        }
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
        for(int i = 0; i < num_pin; i++){
            for(int j = 0; j < num_fish; j++){
                if(fishy[j].cx <= piranha[i].cx+100 && fishy[j].cx >= piranha[i].cx-100 && fishy[j].cy <= piranha[i].cy+100 && fishy[j].cy >= piranha[i].cy-100){
                    fishy[j].id = -99;
                    fishy[j].cx = -100;
                    fishy[j].cy = -100;
                }
            }
        }
        lock1.unlock();
    }
    cout << "Mati" << endl;
}


int main( int argc, char* args[] )
{
    num_ikan = -1;
    num_fish = -1;
    num_pin = -1;
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
            lock1.lock();
            num_fish++;
            num_ikan++;
            fishy[num_fish].cx = (100*num_fish)%1000;
            fishy[num_fish].cy = (100*num_fish)%580;
            fishy[num_fish].id = num_fish;
            fishy[num_fish].orientation = 1;
            fishy[num_fish].jenis = 1;
            ikan[num_ikan] = thread(gerak,num_fish,1);
            input = '0';
            lock1.unlock();
        }else if(input == 'p'){
            lock1.lock();
            num_pin++;
            num_ikan++;
            piranha[num_pin].cx = (100*num_pin)%1000;
            piranha[num_pin].cy = (100*num_pin)%580;
            piranha[num_pin].id = num_pin;
            piranha[num_pin].orientation = 1;
            piranha[num_pin].jenis = 2;
            ikan[num_ikan] = thread(gerak,num_pin,2);
            input = '0';
            lock1.unlock();
        }
        clear_screen();
        for(int i = 0; i <= num_fish ; i++){
            if(fishy[i].jenis==1 && fishy[i].id != -99){
                if(fishy[i].orientation ==1){
                    draw_image("ikankiri.png", fishy[i].cx, fishy[i].cy);
                }else{
                    draw_image("ikankanan.png", fishy[i].cx, fishy[i].cy);
                }
            }
        }
        for(int i = 0; i <= num_pin; i++){
            if(piranha[i].id != 99){
                if(piranha[i].orientation ==1){
                    draw_image("piranhakiri.png", piranha[i].cx, piranha[i].cy);
                }else{
                    draw_image("piranhakanan.png", piranha[i].cx, piranha[i].cy);
                }
            }
        }
        if(input=='x'){
            running=false;
            input = '0';
        }
        update_screen();
    }
    for(int i = 0; i <= num_fish; i++){
        fishy[i].id=-99;
        ikan[i].join();
    }
    close();
    return 0;
}
