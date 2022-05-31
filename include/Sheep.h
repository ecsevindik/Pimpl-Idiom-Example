#ifndef SHEEP_H_
#define SHEEP_H_

#include "Animal.h"

class Sheep : private Animal<Sheep> {

public:
    Sheep(const std::string& name);
    ~Sheep() = default;

    void eat();
    void sleep();

private:
    std::string m_name;
};


#endif // SHEEP_H_