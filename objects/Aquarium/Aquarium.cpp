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
    coin = 100;
    height = SCREEN_HEIGHT;
    width = SCREEN_WIDTH;
}

Aquarium::~Aquarium(){
	
}

Aquarium::Aquarium(int _width, int _height){
    piranha = LinkedList<Piranha*>();
    guppy = LinkedList<Guppy*>();
    coins = LinkedList<Coin*>();
    foods = LinkedList<Food*>();
    snail = Snail();
    coin = 100;
    height = SCREEN_HEIGHT;
    width = SCREEN_WIDTH;
}

Aquarium& Aquarium::operator=(const Aquarium& aq){
	piranha = LinkedList<Piranha*>();
    guppy = LinkedList<Guppy*>();
    coins = LinkedList<Coin*>();
    foods = LinkedList<Food*>();
    snail = Snail();
    height = SCREEN_HEIGHT;
    width = SCREEN_WIDTH;
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
    num_coin = -1;
    num_piran =-1;
    num_eggs = 0;
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
                    if(guppy[i]->getGrowthLevel()<=3){
                        draw_image("ikankiri1.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }else if(guppy[i]->getGrowthLevel()<=6){
                        draw_image("ikankiri2.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }else{
                        draw_image("ikankiri3.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }
                    
                }else{
                    if(guppy[i]->getGrowthLevel()<=3){
                        draw_image("ikankanan1.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }else if(guppy[i]->getGrowthLevel()<=6){
                        draw_image("ikankanan2.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }else{
                        draw_image("ikankanan3.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                    }
                    
                }
            }
        }
        for(int i = 0; i <= num_piran ; i++){
            if(piranha[i]->getName()!="die"){
                if(piranha[i]->getOrientation() =='l'){
                    draw_image("piranhakiri.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                }else{
                    draw_image("piranhakanan.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                }
            }
        }     
        for(int i=0;i<=num_food;i++){
            if(foods[i]->getName()!="die"){
                draw_image("pelet.png",foods[i]->getPosition().getX(),foods[i]->getPosition().getY());
            }
        }
        for (int i = 0; i <= num_coin; i++)
        {
            if (coins[i]->getValue() != 0)
            {
                draw_image("coin.png", coins[i]->getPosition().getX(), coins[i]->getPosition().getY());
            }
        }
        if(snail.getOrientation() =='l'){
            draw_image("snailkiri.png", snail.getPosition().getX(), snail.getPosition().getY());
        }else{
            draw_image("snailkanan.png", snail.getPosition().getX(), snail.getPosition().getY());
        }
          
        if((input=='x') || (num_eggs == 3) || ((coin-Guppy::GUPPY_PRICE<0) && (num_guppy+num_piran <= 0))){
            running=false;
            input = '0';
        }
        ostringstream strs;
        strs<<coin;
        draw_text("Jumlah telur: ", 18, 10, 50, 0, 0, 0);
        draw_text(std::to_string(num_eggs),18, 140, 50, 0, 0, 0);
        draw_text("G untuk membeli guppy, P untuk membeli piranha, x untuk keluar", 18, 10, 10, 0, 0, 0);
        draw_text(strs.str(), 18, 10, 30, 0, 0, 0);
        update_screen();
        
	}
    if (num_eggs == 3){
        bool running = true;
        while(running){
            InteractionChecker(this);
            clear_screen();
            draw_image("bg1.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
            draw_text("You win!", 30, 10, 10, 0, 0, 0);
            update_screen();
            if (input=='x'){
                running=false;
                input='0';
            }
        }
    } else {
        bool running = true;
        while (running){
            InteractionChecker(this);
            clear_screen();
            draw_image("bg1.jpg", SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
            draw_text("You noob.", 30, 10, 10, 0, 0, 0);
            update_screen();
            if (input == 'x'){
                running = false;
                input = '0';
            }
        }
    }
}