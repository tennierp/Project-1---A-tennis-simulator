#include "SetScore.hpp"

#include <iostream>
#include <stdexcept>
#include <iomanip>

SetScore::SetScore(Player *player1, Player *player2)
    : Score(player1, player2), tieScore(nullptr)
{
}

SetScore::~SetScore()
{
    delete tieScore;
}

// When a player has 6 or more points leading the opponent by 2, they will win
// Otherwise they will play a TieBreaker to reach 7 and one player will one with 7 points
bool SetScore::haveAWinner() const
{
    if ((p1Score >= 6 || p2Score >= 6) && std::abs(p1Score - p2Score) >= 2) {
        return true;
    }

    return p1Score >= 7 || p2Score >= 7;
}

// If both players have a score of 6, a tiebreak has to be played
bool SetScore::shouldPlayATieBreaker() const
{
    return p1Score == 6 && p2Score == 6;
}

void SetScore::addTieScore(Score *score)
{
    if (score == nullptr) {
        throw std::invalid_argument("The tie-break score must not be null.");
    }
    if (tieScore != nullptr) {
        throw std::logic_error("This set already has a tie-break score.");
    }

    // Ownership transfers only after all validation succeeds.
    addScore(score->getWinner());
    tieScore = score;
}

void SetScore::print() const
{
    std::cout << std::setw(10) << player1Score() << std::setw(18) << player2Score();

    if (tieScore != nullptr) {
        tieScore->print();
    }

    std::cout << "\n";
}