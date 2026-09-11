#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"
#include "SetScore.hpp"

Match::Match(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

// Creates a matchScore and plays the sets, alternating servers, until their is a winner
Score *Match::play(Player *firstServer)
{
    MatchScore *matchScore = new MatchScore(player1(), player2());

    while (!matchScore->haveAWinner()) {
        Set set = Set(player1(), player2());
        Score* score = set.play(firstServer);
        matchScore->addSetScore(score);
        firstServer = otherPlayer(firstServer);
    }

    return matchScore;
}
