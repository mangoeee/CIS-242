#pragma once

#ifndef GAME_H
#define GAME_H

// defining Game class
class Game {
    public:
        virtual void resetGame() = 0; // virtual func
        virtual ~Game() {}; // destructor
};

#endif