#include "Game.hpp"
#include "Constants.cpp"

using namespace constants;

namespace my_league {

    Game::Game(std::shared_ptr<Team> &home, std::shared_ptr<Team> &away)
            : _home{home}, _away{away} {}

    void Game::simulateGame() {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> home_d{HOME_MEAN, HOME_STD}; // generate home team score
        std::normal_distribution<> away_d{AWAY_MEAN, AWAY_STD}; // generate away team score
        _pts_home = static_cast<int>(std::round(home_d(gen)));
        _pts_away = static_cast<int>(std::round(away_d(gen)));
        if (_home->getRating() >= _away->getRating()) { _pts_home += BONUS; } // add 10 pts to team with higher rating
        else { _pts_away += BONUS; }
        this->updateResults(); // update team stats
    }

    void Game::updateResults() {
        _home->addPoints(_pts_home, _pts_away);
        _away->addPoints(_pts_away, _pts_home);
        if (_pts_home >= _pts_away) { // tie-breaker: home team wins
            _home->addWin();
            _away->addLoss();
        } else {
            _home->addLoss();
            _away->addWin();
        }
    }

}