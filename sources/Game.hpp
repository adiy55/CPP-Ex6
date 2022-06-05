#ifndef CPP_EX6_GAME_HPP
#define CPP_EX6_GAME_HPP

#include "Team.hpp"

namespace my_league {

    class Game {

    private:
        int pts_home;
        int pts_away;

    public:

        void simulateGame(Team &home, Team &away);

    };

}

#endif //CPP_EX6_GAME_HPP
