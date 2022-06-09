#include "Team.hpp"

namespace my_league {

    Team::Team(const std::string &name, double rating)
            : _name{name}, _rating{rating} {}

    const std::string &Team::getName() { return _name; }

    void Team::setName(const std::string &name) { _name = name; }

    double Team::getRating() { return _rating; }

    void Team::addPoints(int scored, int opponent_scored) {
        _pts_scored += scored;
        _pts_opponent_scored += opponent_scored;
    }

    void Team::addWin() {
        ++_total_wins;
        ++_win_counter;
        _loss_counter = 0;
        if (_win_streak < _win_counter) { _win_streak = _win_counter; }
    }

    void Team::addLoss() {
        ++_total_losses;
        ++_loss_counter;
        _win_counter = 0;
        if (_loss_streak < _loss_counter) { _loss_streak = _loss_counter; }
    }

    int Team::getTotalWins() const { return _total_wins; }

    int Team::getTotalLosses() const { return _total_losses; }

    std::ostream &operator<<(std::ostream &out, const Team &team) {
        out << "{Name: " << team._name << ", Rating: " << team._rating << "}";
        return out;
    }

    int Team::getPtsScored() const { return _pts_scored; }

    int Team::getPtsOpponentScored() const { return _pts_opponent_scored; }

}
