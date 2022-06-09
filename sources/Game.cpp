#include "Game.hpp"

namespace my_league {

    Game::Game(std::shared_ptr<Team> &home, std::shared_ptr<Team> &away)
            : _home{home}, _away{away}, _pts_home{0}, _pts_away{0} {}

    void Game::simulateGame() {
        std::random_device rd{};
        std::mt19937 gen{rd()};
        std::normal_distribution<> home_d{77.5, 4.5};
        std::normal_distribution<> away_d{75, 5};
        _pts_home = static_cast<int>(std::round(home_d(gen)));
        _pts_away = static_cast<int>(std::round(away_d(gen)));
        if (_home->getRating() >= _away->getRating()) { _pts_home += 10; }
        else { _pts_away += 10; }
        this->updateResults();
//        std::cout << "home: " << _pts_home << ", away: " << _pts_away << '\n';
    }

    void Game::updateResults() {
        if (_pts_home >= _pts_away) { // tie-breaker: home team wins
            _home->addWin();
            _home->addPoints(_pts_home, _pts_away);
            _away->addLoss();
            _away->addPoints(_pts_away, _pts_home);
        } else {
            _home->addLoss();
            _home->addPoints(_pts_home, _pts_away);
            _away->addWin();
            _away->addPoints(_pts_away, _pts_home);
        }

    }

    // todo: win/loss counter + pts
}