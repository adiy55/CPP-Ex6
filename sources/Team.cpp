#include "Team.hpp"
#include <regex>

namespace my_league {

    Team::Team(const std::string &name, double rating)
            : _name{name}, _rating{rating} { this->checkInput(); }

    const std::string &Team::getName() { return _name; }

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

    int Team::getWinStreak() const { return _win_streak; }

    int Team::getLossStreak() const { return _loss_streak; }

    int Team::getPtsScored() const { return _pts_scored; }

    int Team::getPtsOpponentScored() const { return _pts_opponent_scored; }

    void Team::checkInput() const {
        if (_rating < 0.0 || _rating > 1.0) { throw std::invalid_argument{"Rating should be between 0 and 1!"}; }
        this->validateName();
    }

    void Team::validateName() const {
        std::regex valid_format{R"([\w][\w\s_]*)"}; // \w = shorthand for alpha or digits
        // regex_match checks for a full match
        if (!std::regex_match(_name, valid_format)) { throw std::invalid_argument{"Invalid name!"}; }
    }

}
