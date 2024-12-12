#pragma once

#ifndef TOETACTIC_H
#define TOETACTIC_H

#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <cstdlib> // for rand and srand
#include <ctime> // for seeding rand
#include "Game.h"

// defining TicTacToe class derived from the Game class
class ToeTacTic : public Game {
    private:
        std::vector<std::vector<char>> board; // 2D vector for the game board
        char currentPlayer; // 'X' or 'O'
        bool compOpponent; // flag for computer opponent
        std::string playerXName;
        std::string playerOName;
        std::string getCurrentPlayerName() const;
    
    public:
        ToeTacTic(); // constructor
        void resetGame () override; // resets the game board; override virtual func in Game
        void playGame(); // core gameplay logic
        void drawBoard(); // draw the current game board
        bool checkWinner(); // check if a winner exists
        bool checkTie(); // check if the game is a tie
        void saveScores(const std::string& winner); // save scores to a file
        void loadScores(); // load previous scores from a file
        void playCompMove(); // computer's turn logic
};

#endif