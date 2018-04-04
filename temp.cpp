#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();
    time_t start;
    time(&start);
    srand(time(NULL));
    double delay= rand()%4+1;
    int arah = rand()%8+1;
    int orientation;
    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.

        // for (auto key : get_pressed_keys()) {
        //     switch (key) {
        //     case SDLK_UP:
        //         cy -= speed * sec_since_last;
        //         break;
        //     case SDLK_DOWN:
        //         cy += speed * sec_since_last;
        //         break;
        //     case SDLK_LEFT:
        //         cx -= speed * sec_since_last;
        //         break;
        //     case SDLK_RIGHT:
        //         cx += speed * sec_since_last;
        //         break;
        //     }
        // }

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
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            // strs<< arah;
            // strs<< " ";
            // strs <<cx;
            // strs<<" ";
            // strs<<cy;
            // strs<<" ";
            // strs<<time(0);
            // strs<<"start";
            // strs<<start;
            // strs<<"delay";
            // strs<<delay;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        if(orientation ==1){
            draw_image("ikankiri.png", cx, cy);
        }else{
            draw_image("ikankanan.png", cx, cy);
        }
        
        update_screen();
    }

    close();

    return 0;
}

#include "oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>

const double speed = 50; // pixels per second

int main( int argc, char* args[] )
{
    init();

    // Menghitung FPS
    int frames_passed = 0;
    double fpc_start = time_since_start();
    std::string fps_text = "FPS: 0";

    // Posisi ikan
    double cy = SCREEN_HEIGHT / 2;
    double cx = SCREEN_WIDTH / 2;

    bool running = true;

    double prevtime = time_since_start();
    time_t start;
    time(&start);
    srand(time(NULL));
    double delay= rand()%4+1;
    int arah = rand()%8+1;
    int orientation;
    while (running) {
        double now = time_since_start();
        double sec_since_last = now - prevtime;
        prevtime = now;

        handle_input();
        if (quit_pressed()) {
            running = false;
        }

        // Gerakkan ikan selama tombol panah ditekan
        // Kecepatan dikalikan dengan perbedaan waktu supaya kecepatan ikan
        // konstan pada komputer yang berbeda.

        // for (auto key : get_pressed_keys()) {
        //     switch (key) {
        //     case SDLK_UP:
        //         cy -= speed * sec_since_last;
        //         break;
        //     case SDLK_DOWN:
        //         cy += speed * sec_since_last;
        //         break;
        //     case SDLK_LEFT:
        //         cx -= speed * sec_since_last;
        //         break;
        //     case SDLK_RIGHT:
        //         cx += speed * sec_since_last;
        //         break;
        //     }
        // }

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
        // Proses masukan yang bersifat "tombol"
        for (auto key : get_tapped_keys()) {
            switch (key) {
            // r untuk reset
            case SDLK_r:
                cy = SCREEN_HEIGHT / 2;
                cx = SCREEN_WIDTH / 2;
                break;
            // x untuk keluar
            case SDLK_x:
                running = false;
                break;
            }
        }

        // Update FPS setiap detik
        frames_passed++;
        if (now - fpc_start > 1) {
            std::ostringstream strs;
            strs << "FPS: " ;
            // strs<< arah;
            // strs<< " ";
            // strs <<cx;
            // strs<<" ";
            // strs<<cy;
            // strs<<" ";
            // strs<<time(0);
            // strs<<"start";
            // strs<<start;
            // strs<<"delay";
            // strs<<delay;
            strs << frames_passed/(now - fpc_start);
            fps_text = strs.str();;
            fpc_start = now;
            frames_passed = 0;
        }

        // Gambar ikan di posisi yang tepat.
        clear_screen();
        // draw_text("Panah untuk bergerak, r untuk reset, x untuk keluar", 18, 10, 10, 0, 0, 0);
        // draw_text(fps_text, 18, 10, 30, 0, 0, 0);
        if(orientation ==1){
            draw_image("ikankiri.png", cx, cy);
        }else{
            draw_image("ikankanan.png", cx, cy);
        }
        
        update_screen();
    }

    close();

    return 0;
}

