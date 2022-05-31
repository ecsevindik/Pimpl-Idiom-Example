#ifndef FARM_H_
#define FARM_H_

#include <string>
#include <memory>

class Farm {
public:
    Farm(const std::string& farmName);
    ~Farm();

    void putAnimalsInSleep();
    void feedAnimals();

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl;
    std::string m_name;
};

#endif // FARM_H_