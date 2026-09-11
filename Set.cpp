#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "TieBreaker.hpp"

Set::Set(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

// Games keep track of points, sets keep track of games
// Repeatedly use Game, alternating the servers until there is a winner. If score reaches 6-6, use TieBreaker.
Score *Set::play(Player *firstServer)
{
    Player *server = firstServer;
    SetScore *setScore = new SetScore(player1(), player2());

    while (!setScore->haveAWinner()) {

        if (setScore->shouldPlayATieBreaker()) {
            TieBreaker tieBreaker = TieBreaker(player1(), player2());
            Score *score = tieBreaker.play(server);
            setScore->addTieScore(score);
        } else {
            Game game = Game(player1(), player2());
            Score *score = game.play(server);
            setScore->addScore(score->getWinner());
            delete score;

            server = otherPlayer(server);
        }
    }

    return setScore;
}
