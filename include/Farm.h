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
    std::unique_ptr<Impl> pimpl; // Unique pointer to Impl

    struct ImplAdvanced;
    struct ImplAdvancedDeleter {
        void operator()(ImplAdvanced*);
    };
    std::unique_ptr<ImplAdvanced, ImplAdvancedDeleter> pimplAdv; // Unique pointer to Impl with custom deleter

    std::string m_name;
};

#endif // FARM_H_