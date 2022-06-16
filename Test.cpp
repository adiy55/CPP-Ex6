// more than 20 teams
// duplicate names, empty string, bad characters
// test schedule order

#include "doctest.h"
#include "sources/League.hpp"
#include "sources/Team.hpp"

using namespace my_league;

TEST_CASE ("More than 20 teams") {
    std::shared_ptr<Team> gsw = std::make_shared<Team>("Golden State Warriors", 0.99);
    std::shared_ptr<Team> atl = std::make_shared<Team>("Atlanta Hawks", 0.79);
    std::shared_ptr<Team> bos = std::make_shared<Team>("Boston Celtics", 0.91);
    std::shared_ptr<Team> bkn = std::make_shared<Team>("Brooklyn Nets", 0.7);
    std::shared_ptr<Team> cha = std::make_shared<Team>("Charlotte Hornets", 0.75);
    std::shared_ptr<Team> chi = std::make_shared<Team>("Chicago Bulls", 0.69);
    std::shared_ptr<Team> dal = std::make_shared<Team>("Dallas Mavericks", 0.89);
    std::shared_ptr<Team> den = std::make_shared<Team>("Denver Nuggets", 0.82);
    std::shared_ptr<Team> lac = std::make_shared<Team>("Los Angeles Clippers", 0.8);
    std::shared_ptr<Team> lal = std::make_shared<Team>("Los Angeles Lakers", 0.76);
    std::shared_ptr<Team> mem = std::make_shared<Team>("Memphis Grizzlies", 0.86);
    std::shared_ptr<Team> mia = std::make_shared<Team>("Miami Heat", 0.85);
    std::shared_ptr<Team> mil = std::make_shared<Team>("Milwaukee Bucks", 0.91);
    std::shared_ptr<Team> min = std::make_shared<Team>("Minnesota Timberwolves", 0.22);
    std::shared_ptr<Team> nop = std::make_shared<Team>("New Orleans Pelicans", 0.52);
    std::shared_ptr<Team> phi = std::make_shared<Team>("Philadelphia 76ers", 0.74);
    std::shared_ptr<Team> phx = std::make_shared<Team>("Phoenix Suns", 0.84);
    std::shared_ptr<Team> tor = std::make_shared<Team>("Toronto Raptors", 0.68);
    std::shared_ptr<Team> uta = std::make_shared<Team>("Utah Jazz", 0.8);
    std::shared_ptr<Team> was = std::make_shared<Team>("Washington Wizards", 0.66);

}