#ifndef CPP_EX6_GAME_HPP
#define CPP_EX6_GAME_HPP

#include <random>
#include <memory>
#include "Team.hpp"

namespace my_league {

    class Game {

    private:
        std::shared_ptr<Team> _home;
        std::shared_ptr<Team> _away;
        int _pts_home;
        int _pts_away;

        void updateResults();

    public:

        Game(std::shared_ptr<Team> &home, std::shared_ptr<Team> &away);

        void simulateGame();

    };

}

#endif //CPP_EX6_GAME_HPP
