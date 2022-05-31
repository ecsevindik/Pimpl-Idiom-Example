#include "Farm.h"

int main() {

    std::string farmName = "Ali Babanin Ciftligi";
    auto farm = std::make_unique<Farm>(farmName);

    farm->feedAnimals();
    farm->putAnimalsInSleep();

    return 0;
}