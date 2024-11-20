#include "human.h"
#include <ios>
#include <iostream>

int main(int, char**) {
    std::cout << "##################### START TEST HUMAN ###################\n";
    Human* man = HumanMaker().setHeight(45).setWeight(2.8).born({1995, 4, 18}, Gender::Male);

    if (!man) {
        return -1;
    }

    std::cout << "human alive: " << std::boolalpha << man->alive() << std::endl
              << "human age: " << man->age() << std::endl
              << "human height: " << man->height() << std::endl
              << "human weight: " << man->weight() << std::endl;

    if (man->gender() == Gender::Male) {
        std::cout << "The baby is a boy" << std::endl;
    }
    else {
        std::cout << "The baby is a girl" << std::endl;
    }

    delete man;
    return 0;
}
