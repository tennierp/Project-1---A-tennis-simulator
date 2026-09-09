#include "TieBreakerScore.hpp"

#include <complex>
#include <iostream>

TieBreakerScore::TieBreakerScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}

// TODO: Define the two overrides declared in TieBreakerScore.hpp.

bool TieBreakerScore::haveAWinner() const {
    return (p1Score >= 7 || p2Score >= 7) && std::abs(p1Score - p2Score) >= 2;
}

void TieBreakerScore::print() const {
    std::cout << "TieBreakerScore::print begins\n"
              << "Player A score = " << player1Score() << '\n'
              << "Player B score = " << player2Score() << '\n'
              << "TieBreakerScore::print ends\n";
}