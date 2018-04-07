#include "Aquarium.hpp"
#include "../oop.hpp"
#include <iostream>
#include <math.h>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <thread>
#include <mutex>
#include "../Fish/Fish.hpp"
#include "../Guppy/Guppy.hpp"
#include "../Piranha/Piranha.hpp"
#include "../Food/Food.hpp"

mutex lock1;

Aquarium::Aquarium(){
    piranha = LinkedList<Piranha*>();
    guppy = LinkedList<Guppy*>();
    coins = LinkedList<Coin*>();
    foods = LinkedList<Food*>();
    snail = Snail();
    height = 720;
    width = 1280;
}

Aquarium::~Aquarium(){
	
}

Aquarium::Aquarium(int _width, int _height){
    piranha = LinkedList<Piranha*>();
    guppy = LinkedList<Guppy*>();
    coins = LinkedList<Coin*>();
    foods = LinkedList<Food*>();
    snail = Snail();
    height = 720;
    width = 1280;
}

Aquarium& Aquarium::operator=(const Aquarium& aq){
	piranha = LinkedList<Piranha*>();
    guppy = LinkedList<Guppy*>();
    coins = LinkedList<Coin*>();
    foods = LinkedList<Food*>();
    snail = Snail();
    height = 720;
    width = 1280;	
}

void Aquarium::unlockAquarium(){
    lock1.unlock();
}

void Aquarium::lockAquarium(){
    lock1.lock();
}

void Aquarium::runAquarium(){
	init();
	num_fish = -1;
    num_guppy = -1;
    num_piran =-1;
    num_food = -1;
    //object index 0 di buat untuk snail
    num_object = 0;
    //insialisasi snail
    object[num_object] = thread(&Snail::executeSnail,&snail);
	bool running = true;
	while(running){
		InteractionChecker(this);
        clear_screen();
        draw_image("bg1.jpg", SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
        for(int i = 0; i <= num_guppy ; i++){
            if(guppy[i]->getName()!="die"){
                if(guppy[i]->getOrientation() =='l'){
                    draw_image("ikankiri.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                }else{
                    draw_image("ikankanan.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                }
            }
        }
        for(int i = 0; i <= num_piran ; i++){
            if(piranha[i]->getOrientation() =='l'){
                draw_image("piranhakiri.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
            }else{
                draw_image("piranhakanan.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
            }
        }     
        for(int i=0;i<=num_food;i++){
            if(foods[i]->getName()!="die"){
                draw_image("pelet.png",foods[i]->getPosition().getX(),foods[i]->getPosition().getY());
            }
        }
        if(snail.getOrientation() =='l'){
            draw_image("snailkiri.png", snail.getPosition().getX(), snail.getPosition().getY());
        }else{
            draw_image("snailkanan.png", snail.getPosition().getX(), snail.getPosition().getY());
        }
          
        if(input=='x'){
            running=false;
            input = '0';
        }
        update_screen();
	}
}