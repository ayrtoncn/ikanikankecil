#include "Piranha.cpp"

piranha_count = 0;

// CTOR CCTOR DTOR
Piranha::Piranha(Point position, char orientation): Fish("Piranha" + (string) (piranha_count + 1), PIRANHA_FULL_PERIOD, PIRANHA_HUNGER_PERIOD, PIRANHA_COIN_PERIOD, PIRANHA_MOVEMENT_SPEED, position, orientation) {
    piranha_count++;
}

Piranha::Piranha(const Piranha &piranha) {
    Fish::Fish(piranha);
    piranha_count++;
    name = "Piranha" + (string) piranha_count;
}

Piranha::~Piranha() {
    piranha_count--;
}

Piranha Piranha::&operator=(const Piranha &piranha) {
    if (this != &piranha) {
        Fish::Fish(piranha);
        piranha_count++;
        name = "Piranha" + (string) piranha_count;
    }
}

// GETTER SETTER
static int Piranha::getPiranhaCount() {
    return piranha_count;
}

static void Piranha::setPiranhaCount(int _piranha_count) {
    piranha_count = _piranha_count;
}

// METHODS
void Piranha::DropCoin() {

}

void Piranha::Eat() {
    
}