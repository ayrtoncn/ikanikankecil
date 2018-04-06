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
using namespace std;    

char input;

Piranha *piran=new Piranha[100];
Guppy *fishy=new Guppy[100];
Food *food = new Food[100];

int num_fish;
int num_guppy;
int num_piran;
int num_food;
int num_object;
thread ikan[100];
thread object[100];
std::mutex lock1;

int main(){
    init();
    num_fish = -1;
    num_guppy = -1;
    num_piran =-1;
    num_food = -1;
    num_object = -1;
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
            case SDL_BUTTON_LEFT:
                // cout<<num_food<<endl;
                input = 'c';
                break;
            }
        }
        
        if(input == 'g'){
            srand(time(NULL));
            num_fish++;
            num_guppy++;
            Point temp;
            string nama = "adit";
            fishy[num_guppy] = Guppy(temp,'l');
            ikan[num_fish] = thread(&Guppy::dewaGuppy,&fishy[num_guppy]);
            input = '0';
        }else if(input =='p'){
            srand(time(NULL));
            num_piran++;
            num_fish++;
            Point temp;
            string nama = "adit";
            piran[num_piran] = Piranha(temp,'l');
            ikan[num_fish] = thread(&Piranha::dewaPiranha,&piran[num_piran]);
            input = '0';
        }else if(input =='c'){
            num_food++;
            num_object++;
            int x,y;
            SDL_GetMouseState(&x,&y);
            food[num_food] = Food(x);
            object[num_object] = thread(&Food::executeFood,&food[num_food]); 
            Point temp;
            temp.setX(x);
            temp.setY(y);
            fishy[0].setTujuan(temp);
            input = '0';
        }
        clear_screen();
        draw_image("bg1.jpg", SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        for(int i = 0; i <= num_guppy ; i++){
            if(fishy[i].getName()!="die"){
                if(fishy[i].getOrientation() =='l'){
                    draw_image("ikankiri.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
                }else{
                    draw_image("ikankanan.png", fishy[i].getPosition().getX(), fishy[i].getPosition().getY());
                }
            }
        }
        for(int i = 0; i <= num_piran ; i++){
            if(piran[i].getOrientation() =='l'){
                draw_image("piranhakiri.png", piran[i].getPosition().getX(), piran[i].getPosition().getY());
            }else{
                draw_image("piranhakanan.png", piran[i].getPosition().getX(), piran[i].getPosition().getY());
            }
        }     
        for(int i=0;i<=num_food;i++){
            draw_image("pelet.png",food[i].getPosition().getX(),food[i].getPosition().getY());
        }  
        lock1.lock();
        for(int pir = 0; pir < num_piran; pir++){
            for(int gup = 0; gup < num_guppy; gup++){
                if(fishy[gup].getPosition().getX() <= piran[pir].getPosition().getX()+50 && fishy[gup].getPosition().getX() >= piran[pir].getPosition().getX()-60 && fishy[gup].getPosition().getY() <= piran[pir].getPosition().getY()+50 && fishy[gup].getPosition().getY() >= piran[pir].getPosition().getY()-50){
                    Point t;
                    t.setX(-100);
                    t.setY(-100);
                    //cout<<"MATIIIIIIIIIIIIIIIIIIIIII"<<endl;
                    fishy[gup].setPosition(t);
                    fishy[gup].setName("die");
                }
            }
        }           
        lock1.unlock();
        if(input=='x'){
            running=false;
            input = '0';
        }
        update_screen();
    }
    
    
    return 0;
}