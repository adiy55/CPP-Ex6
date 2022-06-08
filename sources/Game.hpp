#ifndef CPP_EX6_GAME_HPP
#define CPP_EX6_GAME_HPP

#include <random>
#include "Team.hpp"

namespace my_league {

    class Game {

    private:
        int _pts_home;
        int _pts_away;

        void updateResults(Team &home, Team &away) const;

    public:

        Game();

        void simulateGame(Team &home, Team &away);

    };

}

#endif //CPP_EX6_GAME_HPP
