#ifndef CPP_EX6_LEAGUE_HPP
#define CPP_EX6_LEAGUE_HPP

#include <set>
#include <vector>
#include <string>
#include <memory>
#include "Team.hpp"

class League {

private:

    std::set<std::string> _team_names;
    std::vector<std::shared_ptr<Team>> _teams;
//    const int MAX_PLAYERS{20};


};

#endif //CPP_EX6_LEAGUE_HPP
