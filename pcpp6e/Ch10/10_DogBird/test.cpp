#include "Bird/Bird.h"
#include "Dog/Dog.h"

#include <print>
using namespace std;

class DogBird : public Dog, public Bird
{
    public:
        void makeNoise();
};

void DogBird::makeNoise() {
    println("make some noise");
    bark();
    chirp();
    println("Done make some noise");
}

int main(){
    DogBird mDB;
    mDB.bark();
    mDB.chirp();
    mDB.makeNoise();
}
