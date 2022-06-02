#ifndef CPP_EX6_TEAM_HPP
#define CPP_EX6_TEAM_HPP

#include <string>

class Team {

private:

    std::string _name;
    double _rating;

public:

    Team(const std::string &name, double rating);

    const std::string &getName();

    void setName(const std::string &name);

    double getRating();

//    void setRating(double rating);

};

#endif //CPP_EX6_TEAM_HPP
