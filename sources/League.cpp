#include "League.hpp"
#include "Constants.cpp"
#include "Game.hpp"

using constants::MAX_PLAYERS;

namespace my_league {

    League::League(const std::initializer_list<std::shared_ptr<Team>> &teams)
            : _schedule{} {
        int counter = 0;
        for (const std::shared_ptr<Team> &team: teams) {
            if (counter >= MAX_PLAYERS) { throw std::runtime_error{"Exceeded max number of teams!"}; }
            _teams.emplace_back(team);
            this->checkValidName(team->getName());
            _team_names.emplace(team->getName());
            ++counter;
        }
        _schedule.initTeams(static_cast<int>(teams.size()));
    }

    void League::checkValidName(const std::string &name) const {
        if (_team_names.contains(name)) { throw std::runtime_error{"Team name already exits!"}; }
    }

    std::ostream &operator<<(std::ostream &out, const League &league) {
        for (const std::shared_ptr<Team> &team: league._teams) { out << (*team) << '\n'; }
        return out;
    }

    void League::play() {
        auto[home, away] = _schedule.nextMatchUp();
//        std::cout << "\nPlaying: "
//                  << "Home: no." << home << " " << *_teams[static_cast<std::size_t>(home)] << ", Away: no." << away
//                  << " " << *_teams[static_cast<std::size_t>(away)];
        Game game{_teams[static_cast<std::size_t>(home)], _teams[static_cast<std::size_t>(away)]};
        game.simulateGame();
    }

    void League::playAll() {
        // _teams.size()-1 = num of rounds, _teams.size()/2 = games per round
        int n_teams = static_cast<int>(_teams.size());
        int games_per_season = (n_teams - 1) * (n_teams / 2) * 2;
        for (int i = 0; i < games_per_season; ++i) {
            this->play();
        }
        this->sortTeams();
    }

    void League::sortTeams() {
        std::sort(_teams.begin(), _teams.end(), [](std::shared_ptr<Team> &a, std::shared_ptr<Team> &b) {
            int a_diff = a->getTotalWins() - a->getTotalLosses();
            int b_diff = b->getTotalWins() - b->getTotalLosses();
            if (a_diff > b_diff) { return true; }
            else if (b_diff > a_diff) { return false; }
            return a->getPtsScored() - a->getPtsOpponentScored() >= b->getPtsScored() - b->getPtsOpponentScored();
        });
    }

    void League::displayStandings(int n_first) {
        std::cout << "\nTop " << n_first << " teams in the league:\n";
        for (int i = 0; i < n_first; ++i) {
            std::cout << (i + 1) << "." << *_teams[static_cast<std::size_t>(i)] << '\n';
        }
    }

    void League::displayLongestWinningStreak() {
        int longest = 0, curr_longest = 0;
        std::for_each(_teams.cbegin(), _teams.cend(), [&longest, &curr_longest](const std::shared_ptr<Team> &team) {
            if (team->getWinStreak() > curr_longest) { longest = curr_longest = team->getWinStreak(); }
        });
        std::cout << "The longest winning streak is: " << longest << '\n';
    }

    void League::displayLongestLosingStreak() {
        int longest = 0, curr_longest = 0;
        std::for_each(_teams.cbegin(), _teams.cend(), [&longest, &curr_longest](const std::shared_ptr<Team> &team) {
            if (team->getLossStreak() > curr_longest) { longest = curr_longest = team->getLossStreak(); }
        });
        std::cout << "The longest losing streak is: " << longest << '\n';
    }

    void League::displayNumTeamsScoredMore() {
        int counter = 0;
        std::for_each(_teams.cbegin(), _teams.cend(), [&counter](const std::shared_ptr<Team> &team) {
            if (team->getPtsScored() > team->getPtsOpponentScored()) { ++counter; }
        });
        std::cout << "Number of Teams that scored more than their opponent: " << counter << '\n';
    }


}

/*
 * organize teams by conditions
 * stats:
 * - top n teams (given n)
 * - longest winning streak
 * - longest losing streak
 * - teams that scored more than opponent scored
 *
 * - avg pts per game (need to save num games played)
 * - teams that scored less than opponent scored
 */