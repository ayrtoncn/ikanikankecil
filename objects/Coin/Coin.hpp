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
    ha