#ifndef TIE_BREAKER_SCORE_HPP
#define TIE_BREAKER_SCORE_HPP

#include "Score.hpp"

/** A tie-break requires at least seven points and a lead of two points. */
class TieBreakerScore : public Score {
public:
    TieBreakerScore(Player *player1, Player *player2);

    // Override Scores two pure virtual functions to make TieBreakerScore have its own
    bool haveAWinner() const override;
    void print() const override;
};

#endif