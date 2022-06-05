#include <iostream>
#include "League.hpp"
#include "Team.hpp"

using namespace my_league;

int main() {

    std::shared_ptr<Team> gsw = std::make_shared<Team>("Golden State Warriors", 0.99);
    std::cout << *gsw;

    return 0;
}