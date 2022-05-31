#include "Farm.h"
#include "Dog.h"
#include "Sheep.h"

struct Farm::Impl {
    Impl(const std::string& dogName, const std::string sheepName) 
    : m_dog(dogName)
    , m_sheep(sheepName) {}

    Dog m_dog;
    Sheep m_sheep;
};

Farm::Farm(const std::string& farmName)
: pimpl(std::make_unique<Impl>("Karabas", "Dolly"))
, m_name(farmName) {

}

Farm::~Farm() = default; // This has to be defined here because of unique_ptr of Impl. Destructor must be in the same place where Impl is defined

void Farm::putAnimalsInSleep() {
    pimpl->m_dog.sleep();
    pimpl->m_sheep.sleep();
}

void Farm::feedAnimals() {
    pimpl->m_dog.eat();
    pimpl->m_sheep.eat();
}