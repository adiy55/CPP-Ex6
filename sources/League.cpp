#include "League.hpp"

League::League(const std::initializer_list<std::shared_ptr<Team>> &teams) {
    for (const std::shared_ptr<Team> &team: teams) {
        _teams.emplace_back(team);
        this->checkValidName(team->getName());
        _team_names.emplace(team->getName());
    }
}

void League::checkValidName(const std::string &name) const {
    if (_team_names.contains(name)) { throw std::runtime_error{"Team name already exits!"}; }
}
