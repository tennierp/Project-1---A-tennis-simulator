#include "Match.hpp"
#include "MatchScore.hpp"
#include "Set.hpp"
#include "SetScore.hpp"

Match::Match(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *Match::play(Player *firstServer)
{
    // TODO: Repeatedly use Set until MatchScore reports a winner. Alternate
    // the first server between sets and return an owning MatchScore pointer.

    MatchScore *matchScore = new MatchScore(player1(), player2());

    while (!matchScore->haveAWinner()) {
        Set set = Set(player1(), player2());
        Score* score = set.play(firstServer);
        matchScore->addSetScore(score);
        firstServer = otherPlayer(firstServer);

        //
        // if (matchScore->haveAWinner()) {
        //     TieBreaker tieBreaker = TieBreaker(player1(), player2());
        //     Score *score = tieBreaker.play(server);
        //     setScore->addTieScore(score);
        // } else {
        //     Game game = Game(player1(), player2());
        //     Score *score = game.play(server);
        //     setScore->addScore(score->getWinner());
        //     delete score;
        //
        //     server = otherPlayer(server);
        // }
    }

    return matchScore;
}
