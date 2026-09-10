#include "TieBreakerScore.hpp"

#include <complex>
#include <iostream>

TieBreakerScore::TieBreakerScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}

// TODO: Define the two overrides declared in TieBreakerScore.hpp.

// If player1 or player2 has a score above 7, and their score is above the losing opponent by 2, return true.
bool TieBreakerScore::haveAWinner() const {
    return (p1Score >= 7 || p2Score >= 7) && std::abs(p1Score - p2Score) >= 2;
}

// Print the TieBreakerScore player1Score and player2Score while using the TieBreakerScore's print()
void TieBreakerScore::print() const {
    std::cout << "TieBreakerScore::print begins\n"
              << "Player A score = " << player1Score() << '\n'
              << "Player B score = " << player2Score() << '\n'
              << "TieBreakerScore::print ends\n";
}