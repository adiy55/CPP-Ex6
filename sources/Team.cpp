#include "Team.hpp"

namespace my_league {

    Team::Team(const std::string &name, double rating)
            : _name{name}, _rating{rating} {}

    const std::string &Team::getName() { return _name; }

    void Team::setName(const std::string &name) { _name = name; }

    double Team::getRating() { return _rating; }

    std::ostream &operator<<(std::ostream &out, const Team &team) {
        out << "{Name: " << team._name << ", Rating: " << team._rating << "}\n";
        return out;
    }

}
