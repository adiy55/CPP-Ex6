#include "doctest.h"
#include "sources/League.hpp"
#include "sources/Team.hpp"
#include "sources/Game.hpp"

using namespace my_league;

TEST_CASE ("Creating a League Cases") {
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

            SUBCASE("More than 20 teams") {
        std::shared_ptr<Team> extra_team = std::make_shared<Team>("extra", 0.66);
                CHECK_THROWS((League{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem,
                                     mia, mil, min, nop, phi, phx, tor, uta, was, extra_team}));
    }

            SUBCASE("Less than 20 teams") { // should generate random teams
                CHECK_NOTHROW((League{})); // no teams
                CHECK_NOTHROW((League{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem,
                                      mia, mil, min, nop, phi, phx, tor, uta})); // 19 teams

    }

            SUBCASE("Duplicate Team Name") {
        std::shared_ptr<Team> new_team1 = std::make_shared<Team>("Golden State Warriors", 0.99); // same name and rating
        std::shared_ptr<Team> new_team2 = std::make_shared<Team>("Boston Celtics", 0.9); // same name
                CHECK_THROWS((League{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem,
                                     mia, mil, min, nop, phi, phx, tor, uta, new_team1}));
                CHECK_THROWS((League{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem,
                                     mia, mil, min, nop, phi, phx, tor, uta, new_team2}));
                CHECK_THROWS((League{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem,
                                     mia, mil, min, nop, phi, phx, tor, uta, new_team1, new_team2}));
    }

            SUBCASE("Check number of games team played in season") {
        League nba{gsw, atl, bos, bkn, cha, chi, dal, den, lac, lal, mem, mia, mil, min, nop, phi, phx, tor, uta, was};
        nba.playAll();
                CHECK_EQ(gsw->getTotalWins() + gsw->getTotalLosses(), 38); // plays against 19 teams twice
    }
}


TEST_CASE ("Team Cases") {

            SUBCASE("Invalid Name") {
                CHECK_THROWS((Team{"", 0.25}));
                CHECK_THROWS((Team{"   ", 0.56}));
                CHECK_THROWS((Team{"$$$$", 0.32}));
    }

            SUBCASE("Invalid Rating") {
                CHECK_THROWS((Team{"Golden State Warriors", 999999}));
                CHECK_THROWS((Team{"Dallas Mavericks", 987.654}));
                CHECK_THROWS((Team{"Los Angeles Lakers", -87.12}));
    }

            SUBCASE("Not printable") {
                CHECK_THROWS((Team{"✡", 0.66}));
                CHECK_THROWS((Team{"☞", 0.45}));
                CHECK_THROWS((Team{"☜", 0.78}));
                CHECK_THROWS((Team{"⍺", 0.89}));
                CHECK_THROWS((Team{"♕", 0.23}));
    }
}

TEST_CASE ("Game Cases") {

    std::shared_ptr<Team> gsw = std::make_shared<Team>("Golden State Warriors", 0.99);
    std::shared_ptr<Team> bos = std::make_shared<Team>("Boston Celtics", 0.91);

    Game game{gsw, bos};
    game.simulateGame();

            SUBCASE("Check win/loss counter increment") {
                CHECK(bool ((gsw->getTotalWins() == 1 || gsw->getTotalLosses() == 1)));
                CHECK(bool ((bos->getTotalWins() == 1 || bos->getTotalLosses() == 1)));
    }

            SUBCASE("Check points scored in valid range") {
                CHECK(bool ((gsw->getPtsScored() >= 55) || (gsw->getPtsScored() <= 110)));
                CHECK(bool ((bos->getPtsScored() >= 55) || (bos->getPtsScored() <= 110)));
    }

            SUBCASE("Check points scored matches") {
                CHECK(gsw->getPtsScored() == bos->getPtsOpponentScored());
                CHECK(bos->getPtsScored() == gsw->getPtsOpponentScored());
    }

}