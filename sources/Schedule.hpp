#ifndef CPP_EX6_SCHEDULE_HPP
#define CPP_EX6_SCHEDULE_HPP

#include <queue>

namespace my_league {

    class Schedule {

    private:
        int _n_teams;
        bool _swap_teams;
        bool _is_even;
        int _start;
        int _end;
        int _mid;
        std::queue<std::pair<int, int>> _matches;

        void nextRound();

    public:

        Schedule();

        void initTeams(int n_teams);

        std::pair<int, int> nextMatchUp();

    };
}

#endif //CPP_EX6_SCHEDULE_HPP
