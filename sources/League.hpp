#ifndef CPP_EX6_LEAGUE_HPP
#define CPP_EX6_LEAGUE_HPP

#include <unordered_set>
#include <vector>
#include <string>
#include <memory>
#include "Team.hpp"
#include "Schedule.hpp"

namespace my_league {

    class League {

    private:

        std::unordered_set<std::string> _team_names;
        std::vector<std::shared_ptr<Team>> _teams;
        Schedule _schedule;

        void checkValidName(const std::string &name) const;

        void fillMissingTeams();

        void play();

        void sortTeams();

        static std::string generateRandomName();

        static double generateRandomRating();

    public:

        League();

        League(const std::initializer_list<std::shared_ptr<Team>> &teams);

        void playAll();

        void displayStandings(int n_first = 5);

        void displayLongestWinningStreak();

        void displayLongestLosingStreak();

        void displayNumTeamsScoredMore();

        void displayAvgPtsPerGame();

        void displayTopScoring(int n_first=5);

        friend std::ostream &operator<<(std::ostream &out, const League &league);

    };

}

#endif //CPP_EX6_LEAGUE_HPP
