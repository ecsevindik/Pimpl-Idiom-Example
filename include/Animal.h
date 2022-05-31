#ifndef ANIMAL_H_
#define ANIMAL_H_

#include <string>

template<typename Derived>
class Animal {

public:

    void eat() { asDerived()->eat();}

    void sleep() {asDerived()->sleep();}

protected:

    Animal() = default;
    ~Animal() = default;
    Animal(const Animal&) = delete; // Copy-constructor delete
    Animal(Animal&&) = delete; // Move-constructor delete
    Animal& operator=(const Animal&) = delete; // Copy-assignment delete
    Animal& operator=(Animal&&) = delete; // Move-assignment delete

private:

    Derived* asDerived() {return static_cast<Derived*>(this);}
    const Derived* asDerived() const {static_cast <const Derived*>(this);}

};

#endif // ANIMAL_H_