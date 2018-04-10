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
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankiri1.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        } else {
                            draw_image("ikankiri1laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }else if(guppy[i]->getGrowthLevel()<=6){
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankiri2.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }else{
                            draw_image("ikankiri2laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }else{
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankiri3.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }else{
                            draw_image("ikankiri3laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }
                    
                }else{
                    if(guppy[i]->getGrowthLevel()<=3){
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankanan1.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }else{
                            draw_image("ikankanan1laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }else if(guppy[i]->getGrowthLevel()<=6){
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankanan2.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }else{
                            draw_image("ikankanan2laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }else{
                        if(!guppy[i]->getIsHungry()){
                            draw_image("ikankanan3.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }else{
                            draw_image("ikankanan3laper.png", guppy[i]->getPosition().getX(), guppy[i]->getPosition().getY());
                        }
                    }
                    
                }
            }
        }
        for(int i = 0; i <= num_piran ; i++){
            if(piranha[i]->getName()!="die"){
                if(piranha[i]->getOrientation() =='l'){
                    if(!piranha[i]->getIsHungry()){
                        draw_image("piranhakiri.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                    }else{
                        draw_image("piranhakirilaper.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                    }
                }else{
                    if(!piranha[i]->getIsHungry()){
                        draw_image("piranhakanan.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                    }else{
                        draw_image("piranhakananlaper.png", piranha[i]->getPosition().getX(), piranha[i]->getPosition().getY());
                    }
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
          
        if((input=='x') || (num_eggs == 3) || ((coin-Guppy::GUPPY_PRICE<0) && (num_coin<=-1) && (num_guppy+num_piran <= 0))){
            running=false;
            input = '0';
        }
        ostringstream strs;
        strs<<coin;
        draw_text("Jumlah telur: ", 18, 10, 50, 0, 0, 0);
        draw_text(std::to_string(num_eggs),18, 140, 50, 0, 0, 0);
        draw_text("G untuk membeli guppy, P untuk membeli piranha, E untuk membeli telur, x untuk keluar", 18, 10, 10, 0, 0, 0);
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

void Aquarium::save() {
    int n_guppy = guppy.getAmount();
    int n_piran = piranha.getAmount();
    int n_coins = coins.getAmount();
    int n_foods = foods.getAmount();

    Guppy arr_guppy[n_guppy];
    Piranha arr_piran[n_piran];
    Coin arr_coins[n_coins];
    Food arr_foods[n_foods];

    for (int i = 0; i < n_guppy; i++) {
        arr_guppy[i] = *guppy[i];
    }
    for (int i = 0; i < n_piran; i++) {
        arr_piran[i] = *piranha[i];
    }
    for (int i = 0; i < n_coins; i++) {
        arr_coins[i] = *coins[i];
    }
    for (int i = 0; i < n_foods; i++) {
        arr_foods[i] = *foods[i];
    }

    ofstream save_file;
    save_file.open("savegame", ios::out | ios::trunc);

    // marker for amount of everything
    save_file.write((char *)&n_guppy, sizeof(n_guppy));
    save_file.write((char *)&n_piran, sizeof(n_piran));
    save_file.write((char *)&n_coins, sizeof(n_coins));
    save_file.write((char *)&n_foods, sizeof(n_foods));
    
    // attributes
    save_file.write((char *)&num_fish, sizeof(num_fish));
    save_file.write((char *)&num_guppy, sizeof(num_guppy));
    save_file.write((char *)&num_piran, sizeof(num_piran));
    save_file.write((char *)&num_food, sizeof(num_food));
    save_file.write((char *)&num_eggs, sizeof(num_eggs));
    save_file.write((char *)&num_coin, sizeof(num_coin));
    save_file.write((char *)&num_object, sizeof(num_object));
    save_file.write((char *)&coin, sizeof(coin));

    for (int i = 0; i < n_guppy; i++) {
        save_file.write((char *)&arr_guppy[i], sizeof(arr_guppy[i]));
    }

    for (int i = 0; i < n_piran; i++) {
        save_file.write((char *)&arr_piran[i], sizeof(arr_piran[i]));
    }

    for (int i = 0; i < n_coins; i++) {
        save_file.write((char *)&arr_coins[i], sizeof(arr_coins[i]));
    }

    for (int i = 0; i < n_foods; i++) {
        save_file.write((char *)&arr_foods[i], sizeof(arr_foods[i]));
    }

    save_file.write((char *)&snail, sizeof(snail));

    save_file.close();
}

void Aquarium::load() {
    ifstream load_file;
    load_file.open("savegame", fstream::in);

    // loading markers
    int n_guppy;
    int n_piran;
    int n_coins;
    int n_foods;

    load_file.read((char *)&n_guppy, sizeof(n_guppy));
    load_file.read((char *)&n_piran, sizeof(n_piran));
    load_file.read((char *)&n_coins, sizeof(n_coins));
    load_file.read((char *)&n_foods, sizeof(n_foods));

    // attributes
    load_file.read((char *)&num_fish, sizeof(num_fish));
    load_file.read((char *)&num_guppy, sizeof(num_guppy));
    load_file.read((char *)&num_piran, sizeof(num_piran));
    load_file.read((char *)&num_food, sizeof(num_food));
    load_file.read((char *)&num_eggs, sizeof(num_eggs));
    load_file.read((char *)&num_coin, sizeof(num_coin));
    load_file.read((char *)&num_object, sizeof(num_object));
    load_file.read((char *)&coin, sizeof(coin));

    for (int i = 0; i < n_guppy; i++) {
        Guppy new_guppy;
        load_file.read((char *)&new_guppy, sizeof(new_guppy));
        guppy.add(new Guppy(new_guppy));
    }

    for (int i = 0; i < n_piran; i++) {
        Piranha new_piran;
        load_file.read((char *)&new_piran, sizeof(new_piran));
        piranha.add(new Piranha(new_piran));
    }

    for (int i = 0; i < n_coins; i++) {
        Coin new_coin;
        load_file.read((char *)&new_coin, sizeof(new_coin));
        coins.add(new Coin(new_coin));
    }

    for (int i = 0; i < n_foods; i++) {
        Food new_food;
        load_file.read((char *)&new_food, sizeof(new_food));
        foods.add(new Food(new_food));
    }

    load_file.read((char *)&snail, sizeof(snail));

    load_file.close();
}