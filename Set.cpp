#include "Set.hpp"
#include "SetScore.hpp"
#include "Game.hpp"
#include "TieBreaker.hpp"

Set::Set(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

// games keep track of points, sets keep track of games
Score *Set::play(Player *firstServer)
{
    // TODO: Repeatedly use Game, alternating the server after every game.
    // If the score reaches 6-6, use TieBreaker and transfer ownership of its
    // returned score to SetScore. Return an owning SetScore pointer.
    
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
