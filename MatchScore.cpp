#include "MatchScore.hpp"

#include <iostream>
#include <iomanip>
#include <set>

MatchScore::MatchScore(Player *player1, Player *player2)
    : Score(player1, player2), scores{}, setNumber(0)
{
}

MatchScore::~MatchScore()
{
    for (int i = 0; i < setNumber; ++i) {
        delete scores[i];
    }
}

// A match ends when either player has won three sets.
bool MatchScore::haveAWinner() const
{
    return p1Score == 3 || p2Score == 3;
}

// Validate score and capacity, record its winner, store score, and
// transfer ownership to this MatchScore only after validation succeeds.
void MatchScore::addSetScore(Score *score)
{
    if (score == nullptr) {
        throw std::invalid_argument("The match score must not be null.");
    }

    if (scores[4] != nullptr) {
        throw std::invalid_argument("The score array already has 5 matchs");
    }

    addScore(score->getWinner());
    scores[setNumber] = score;
    setNumber++;
}

void MatchScore::print() const
{
    std::cout << "   Set No.    Player A          Player B\n";
    for (int i = 0; i < setNumber; i++) {
        std::cout << std::setw(7) << i + 1;
        scores[i]->print();
    }

    std::cout << '\n';
    if (p1Score > p2Score) {
        std::cout << "Player A wins the match " << p1Score << " sets to " << p2Score << std::endl;
        // Player B wins the match 3 sets to 1
    } else if (p1Score < p2Score) {
        std::cout << "Player B wins the match " << p2Score << " sets to " << p1Score << std::endl;
    }
}
