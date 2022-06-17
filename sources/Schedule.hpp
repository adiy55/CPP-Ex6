#ifndef CPP_EX6_SCHEDULE_HPP
#define CPP_EX6_SCHEDULE_HPP

#include <queue>

namespace my_league {

    class Schedule {

    private:
        int _n_teams;
        bool _is_even;
        int _start{0};
        int _end{0};
        int _mid{0};
        std::queue<std::pair<int, int>> _matches;

        void initMatchups();

        void initMatchupsBasic();

    public:

        Schedule();

        void initTeams(int n_teams);

        std::pair<int, int> nextMatchUp();

    };
}

#endif //CPP_EX6_SCHEDULE_HPP
