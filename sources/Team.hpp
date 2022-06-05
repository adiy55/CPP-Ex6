#ifndef CPP_EX6_TEAM_HPP
#define CPP_EX6_TEAM_HPP

#include <string>
#include <iostream>

namespace my_league {

    class Team {

    private:

        std::string _name;
        double _rating;

    public:

        Team(const std::string &name, double rating);

        const std::string &getName();

        void setName(const std::string &name);

        double getRating();

        friend std::ostream &operator<<(std::ostream &out, const Team &team);

//    void setRating(double rating);

    };
}

#endif //CPP_EX6_TEAM_HPP
