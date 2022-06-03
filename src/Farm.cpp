#include "Farm.h"
#include "Dog.h"
#include "Sheep.h"

// Define Impl here
struct Farm::Impl {
    Impl(const std::string& dogName) 
    : m_dog(dogName) {}

    Dog m_dog;
};

// Define ImplAdvanced here
struct Farm::ImplAdvanced {
    ImplAdvanced(const std::string sheepName) 
    : m_sheep(sheepName) {}

    Sheep m_sheep;
};

Farm::Farm(const std::string& farmName)
: pimpl(std::make_unique<Impl>("Karabas"))
, pimplAdv(new ImplAdvanced("Dolly"))
, m_name(farmName) {}

Farm::~Farm() = default; // This has to be defined here because of unique_ptr of Impl. Destructor must be in the same place where Impl is defined

void Farm::ImplAdvancedDeleter::operator()(Farm::ImplAdvanced* ptr){
    delete ptr;
}

void Farm::putAnimalsInSleep() {
    pimpl->m_dog.sleep();
    pimplAdv->m_sheep.sleep();
}

void Farm::feedAnimals() {
    pimpl->m_dog.eat();
    pimplAdv->m_sheep.eat();
}