#include "TieBreaker.hpp"

#include "Player.hpp"
#include "PointScore.hpp"
#include "TieBreakerScore.hpp"

TieBreaker::TieBreaker(Player *player1, Player *player2)
    : Competition(player1, player2)
{
}

Score *TieBreaker::play(Player *firstServer)
{
    // TODO: Play points in the required service order until TieBreakerScore
    // reports a winner. Return an owning pointer to that score.
    // (void)firstServer;
    // return nullptr;

    TieBreakerScore *tieBreakerScore = new TieBreakerScore(player1(), player2());
    Player *server = firstServer;
    Player *opponent = otherPlayer(firstServer);
    int currentServersTurns = 1;

    while (!tieBreakerScore->haveAWinner()) {
        PointScore pointScore(player1(), player2());
        pointScore.addScore(server->serveAPoint(opponent));
        tieBreakerScore->addScore(pointScore.getWinner());
        currentServersTurns++;

        if (currentServersTurns == 2) {
            Player *temp = server;
            server = opponent;
            opponent = temp;
            currentServersTurns = 0;
        }
    }

    return tieBreakerScore;
}
