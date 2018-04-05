// CTOR CCTOR DTOR
Guppy::Guppy(Point position, char orientation): Fish("Guppy" + (string) (guppy_count + 1), GUPPY_FULL_PERIOD, GUPPY_HUNGER_PERIOD, GUPPY_COIN_PERIOD, GUPPY_MOVEMENT_SPEED, position, orientation) {
    guppy_count++;
}

Guppy::Guppy(const Guppy &guppy) {
    Fish::Fish(guppy);
    guppy_count++;
    name = "Guppy" + (string) guppy_count;
}

Guppy::~Guppy() {
    guppy_count--;
}

Guppy Guppy::&operator=(const Guppy &guppy) {
    if (this != &guppy) {
        Fish::Fish(guppy);
        guppy_count++;
        name = "Guppy" + (string) guppy_count;
    }
}

// GETTER SETTER
static int Guppy::getGuppyCount() {
    return guppy_count;
}

int Guppy::getGrowthLevel() const {
    return growth_level;
}

static void Guppy::setGuppyCount(int _guppy_count) {
    guppy_count = _guppy_count;
}

void Guppy::setGrowthLevel(int _growth_level) {
    growth_level = _growth_level;
}

// METHODS
void Guppy::DropCoin() {

}

void Guppy::Eat() {

}