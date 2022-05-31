#ifndef DOG_H_
#define DOG_H_

#include "Animal.h"

class Dog : public Animal<Dog> {
public:

    Dog(const std::string& name);
    ~Dog() = default;

    void eat();
    void sleep();

private:
    std::string m_name;
};


#endif // DOG_H_