#include <iostream>
#include "Schedule.hpp"

namespace my_league {

    // (n_teams-1) rounds of matchups x 2
    Schedule::Schedule()
            : _n_teams{0}, _swap_teams{false}, _is_even{true}, _start{0}, _end{0}, _mid{0} {}

    void Schedule::initTeams(int n_teams) {
        _n_teams = n_teams;
        if (_n_teams % 2 != 0) {
            ++_n_teams;
            _is_even = false;
        }
        _start = 1;
        _end = (_n_teams) - 1;
        _mid = static_cast<int>(_n_teams / 2);
    }

    std::pair<int, int> Schedule::nextMatchUp() {
        if (_end <= 0) {
            if (!_swap_teams) { _swap_teams = true; }
        }
        this->nextRound();
        std::pair<int, int> curr_match = _matches.front();
        _matches.pop();
        return curr_match;
    }

    void Schedule::nextRound() {
        int curr_start = _start, curr_end = _end;
        if (_is_even) {
            if (_swap_teams) { _matches.emplace(curr_end--, 0); }
            else { _matches.emplace(0, curr_end--); }
        }
        for (int i = 1; i < _mid; ++i) {
            if (curr_start % _n_teams == 0) curr_start = 1;
            if (curr_end == 0) curr_end = _n_teams - 1;
            if (_swap_teams) _matches.emplace(curr_end--, curr_start++);
            else _matches.emplace(curr_start++, curr_end--);
        }
        _start = _end;
        --_end;
    }

}