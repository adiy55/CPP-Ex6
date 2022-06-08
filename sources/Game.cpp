#include "Game.hpp"

namespace my_league {

    Game::Game() : _pts_home{0}, _pts_away{0} {}

    void Game::simulateGame(Team &home, Team &away) {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> home_d{77.5, 4.5};
        std::normal_distribution<> away_d{75, 5};
//        int best_h = 0, best_a = 0, tmp;
//        for (int i = 0; i < 100000; ++i) {
//            tmp = static_cast<int>(std::round(home_d(gen)));
//            best_h = tmp > best_h ? tmp : best_h;
//            tmp = static_cast<int>(std::round(away_d(gen)));
//            best_a = tmp > best_a ? tmp : best_a;
//        }
//        std::cout << "home: " << best_h << "\naway: " << best_a << '\n';
        _pts_home = static_cast<int>(std::round(home_d(gen)));
        _pts_away = static_cast<int>(std::round(away_d(gen)));
        if (home.getRating() >= away.getRating()) { _pts_home += 10; }
        else { _pts_away += 10; }
        std::cout << "home: " << _pts_home << ", away: " << _pts_away << '\n';
    }

//    int Game::shotAttempt() {
//        std::random_device rd{};
//        std::mt19937 gen{rd()};
//        std::normal_distribution<> d{2, 0.5}; // numbers between 0 and 4, mean 2 with std .5
//        int num = static_cast<int>(std::round(d(gen)));
//        if (num <= 0) { num *= (-1); } // in case of negative 0
//        return num;
//    }

}