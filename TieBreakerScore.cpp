#include "TieBreakerScore.hpp"

#include <complex>
#include <iostream>
#include <iomanip>

TieBreakerScore::TieBreakerScore(Player *player1, Player *player2)
    : Score(player1, player2)
{
}

// If player1 or player2 has a score above 7, and their score is above the losing opponent by 2, return true.
bool TieBreakerScore::haveAWinner() const {
    return (p1Score >= 7 || p2Score >= 7) && std::abs(p1Score - p2Score) >= 2;
}

// Print the TieBreakerScore player1Score and player2Score while using the TieBreakerScore's print()
void TieBreakerScore::print() const {
    std::cout << std::setw(16) << "(tie breaker  " << p1Score << '-' << p2Score << ')';
}