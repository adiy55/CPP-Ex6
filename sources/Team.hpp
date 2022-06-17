#ifndef CPP_EX6_TEAM_HPP
#define CPP_EX6_TEAM_HPP

#include <string>
#include <iostream>

namespace my_league {

    class Team {

    private:

        std::string _name;
        double _rating;
        int _pts_scored{0};
        int _pts_opponent_scored{0};
        int _win_streak{0};
        int _loss_streak{0};
        int _win_counter{0};
        int _loss_counter{0};
        int _total_wins{0};
        int _total_losses{0};

    public:

        Team(const std::string &name, double rating);

        const std::string &getName();

        double getRating();

        void addPoints(int scored, int opponent_scored);

        void addWin();

        void addLoss();

        int getTotalWins() const;

        int getTotalLosses() const;

        int getPtsScored() const;

        int getPtsOpponentScored() const;

        friend std::ostream &operator<<(std::ostream &out, const Team &team);

        int getWinStreak() const;

        int getLossStreak() const;

    };
}

#endif //CPP_EX6_TEAM_HPP
