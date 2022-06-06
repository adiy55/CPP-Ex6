#include "League.hpp"

namespace my_league {

    League::League(const std::initializer_list<std::shared_ptr<Team>> &teams)
            : _schedule{} {
        // todo: throw exception if given more than 20 teams?
        for (const std::shared_ptr<Team> &team: teams) {
            _teams.emplace_back(team);
            this->checkValidName(team->getName());
            _team_names.emplace(team->getName());
        }
        _schedule.initTeams(static_cast<int>(teams.size()));
    }

    void League::checkValidName(const std::string &name) const {
        if (_team_names.contains(name)) { throw std::runtime_error{"Team name already exits!"}; }
    }

    std::ostream &operator<<(std::ostream &out, const League &league) {
        for (const std::shared_ptr<Team> &team: league._teams) { out << (*team); }
        return out;
    }

    void League::play() {
        auto[home, away] = _schedule.nextMatchUp();
        std::cout << "Playing:\n"
                  << "Home Team: no." << home << " " << *_teams[static_cast<std::size_t>(home)]
                  << "Away Team: no." << away << " " << *_teams[static_cast<std::size_t>(away)];
    }

}
