#include <iostream>
#include "Schedule.hpp"

namespace my_league {

    // (n_teams-1) rounds of matchups x 2
    Schedule::Schedule()
            : _n_teams{0}, _swap_teams{false}, _is_even{true}, _start{0}, _end{0}, _mid{0} {}

    void Schedule::initTeams(int n_teams) {
        _n_teams = n_teams;
        if (_n_teams % 2 != 0) { // if num of teams is odd add a dummy value (teams rest when playing against index 0)
            ++_n_teams;
            _is_even = false;
        }
        _start = 1;
        _end = _n_teams - 1;
        _mid = static_cast<int>(_n_teams / 2);
        this->initMatchups();
    }

    std::pair<int, int> Schedule::nextMatchUp() {
        if (_matches.empty()) throw std::runtime_error{"Season is over!"};
        std::pair<int, int> curr_match = _matches.front();
        _matches.pop();
        return curr_match;
    }

    /*
     * after each iteration, the end index moves to the start and shifts the rest of the indices forwards.
     * At first the numbers are ordered from lowest to highest, so the end index decreases.
     */
    void Schedule::initMatchups() {
        std::queue<std::pair<int, int>> swapped_matches{};
        for (; _end > 0; --_end) {
            int curr_start = _start, curr_end = _end;
            if (_is_even) {
                _matches.emplace(0, curr_end);
                swapped_matches.emplace(curr_end, 0);
                --curr_end;
            }
            for (int i = 1; i < _mid; ++i) { // until mid -> matches two teams each iteration
                if (curr_start % _n_teams == 0) curr_start = 1; // index 0 is fixed
                if (curr_end == 0) curr_end = _n_teams - 1; // reset to last end
                _matches.emplace(curr_start, curr_end);
                swapped_matches.emplace(curr_end, curr_start);
                ++curr_start;
                --curr_end;
            }
            _start = _end; // end index moves to the start
        }
        while (!swapped_matches.empty()) {
            _matches.emplace(swapped_matches.front());
            swapped_matches.pop();
        }
    }

//    void Schedule::initMatchups() {
//        std::vector<int> row1;
//        std::vector<int> row2;
//        std::queue<std::pair<int, int>> swapped_matches{};
//        for (int i = 0; i <= _end; ++i) { // init indices
//            if (i < _mid) { row1.push_back(i); }
//            else { row2.push_back(i); }
//        }
//        std::reverse(row2.begin(), row2.end());
//        for (int i = 0; i < _end; ++i) {
//            for (unsigned int j = 0; j < _mid; ++j) {
//                if ((j == 0 && _is_even) || j > 0) {
//                    _matches.emplace(row1[j], row2[j]);
//                    swapped_matches.emplace(row2[j], row1[j]);
//                }
//                int shift_up = row2[0];
//                int shift_down = row1[static_cast<unsigned int>(_mid - 1)];
//                for (unsigned int k = static_cast<unsigned int>(_mid) - 1; k > 0; --k) { // move from right to left
//                    row1[k] = row1[k - 1];
//                }
//                for (unsigned int k = 1; k < static_cast<unsigned int>(_mid); ++k) {
//                    row2[k - 1] = row2[k];
//                }
//                row1[1] = shift_up;
//                row2[static_cast<unsigned int>(_mid - 1)] = shift_down;
//            }
//        }
//        while (!swapped_matches.empty()) {
//            _matches.emplace(swapped_matches.front());
//            swapped_matches.pop();
//        }
//    }

}