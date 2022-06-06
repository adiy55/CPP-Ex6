#ifndef CPP_EX6_LEAGUE_HPP
#define CPP_EX6_LEAGUE_HPP

#include <set>
#include <vector>
#include <string>
#include <memory>
#include "Team.hpp"
#include "Schedule.hpp"

namespace my_league {

    class League {

    private:

        std::set<std::string> _team_names;
        std::vector<std::shared_ptr<Team>> _teams;
        Schedule _schedule;

//    const int MAX_PLAYERS{20};

        void checkValidName(const std::string &name) const;

        void fillMissingTeams();

    public:

        League();

        League(const std::initializer_list<std::shared_ptr<Team>> &teams);

        void play();

        friend std::ostream &operator<<(std::ostream &out, const League &league);

    };

}

#endif //CPP_EX6_LEAGUE_HPP
