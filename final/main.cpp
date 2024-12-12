/*
    Emery Mangona
    CIS 242 Final

    The name of the game is TicTacToe
        1. Give it a unique name
        2. Must include the following:
            • Classes (must go in your header file)
            • Constructor
            • Inheritance
            • Virtual Function
            • Pointers
            • Either arrays, vectors, or lists
            • Try/Catch
            • Functions
            • If/Else
            • Loops
            • Save and store scores to a file
        3. This must be a single or 2-player game

    EXTRA CREDIT: Time the game
*/

#include <iostream>
#include "Game.h"
#include "ToeTacTic.h"

int main() {
    ToeTacTic game;
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nWelcome to Toe Tac Tic!\n";
        std::cout << "1. Play Game\n";
        std::cout << "2. View Scores\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                game.resetGame();
                game.playGame();
                break;
            case 2:
                game.loadScores();
                break;
            case 3:
                std::cout << "Thanks for playing!\n";
                running = false;
                break;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }

    return 0;
}

ToeTacTic::ToeTacTic() : board(3, std::vector<char>(3, ' ')), currentPlayer('X'), compOpponent(false) {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
}

void ToeTacTic::resetGame() {
    board = std::vector<std::vector<char>>(3, std::vector<char>(3, ' '));
    currentPlayer = 'X';

    // check that the user input is valid
    bool validInput = false;
    while (!validInput) {
        std::cout << "Play against the computer? (Enter 1 for yes, 0 for no): ";
        std::cin >> compOpponent;
        
        // check if input is either 1 or 0
        if (std::cin.fail() || (compOpponent != 0 && compOpponent != 1)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter 1 for yes, or 0 for no.\n";
        } else {
            validInput = true; // exit the loop when valid input is given
        }
    }

}

// commenting the original below for reference with the for loop
// void drawBoard(const std::vector<char>& spaces) {
//     std::cout << '\n';
//     std::cout << "     |     |     " << '\n';
//     std::cout << "  " << spaces[0] << "  |  " << spaces[1] << "  |  " << spaces[2] << "  " << '\n';
//     std::cout << "_____|_____|_____" << '\n';
//     std::cout << "     |     |     " << '\n';
//     std::cout << "  " << spaces[3] << "  |  " << spaces[4] << "  |  " << spaces[5] << "  " << '\n';
//     std::cout << "_____|_____|_____" << '\n';
//     std::cout << "     |     |     " << '\n';
//     std::cout << "  " << spaces[6] << "  |  " << spaces[7] << "  |  " << spaces[8] << "  " << '\n';
//     std::cout << "     |     |     " << '\n';
//     std::cout << '\n';
// }

void ToeTacTic::drawBoard() {
    std::cout << "\nCurrent Board:\n";
    for (size_t i = 0; i < 3; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            std::cout << " " << board[i][j] << " ";
            if (j < 2) {
                std::cout << "|";
            }
        }
        std::cout << "\n";
        if (i < 2) {
            std::cout << "---|---|---\n";
        }
    }
    std::cout << "\n";
}

bool ToeTacTic::checkWinner() {
    for (size_t i = 0; i < 3; ++i) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool ToeTacTic::checkTie() {
    for (const auto& row : board)
        for (char cell : row)
            if (cell == ' ') {
                return false;
            }
    return !checkWinner();
}

void ToeTacTic::playCompMove() {
    int row, col;
    do {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');

    board[row][col] = currentPlayer;
    std::cout << "Computer chose: row " << row + 1 << ", column " << col + 1 << "\n";
}

std::string ToeTacTic::getCurrentPlayerName() const {
    if (currentPlayer == 'X') {
        return playerXName;
    } else {
        return playerOName;
    }
}

void ToeTacTic::playGame() {
    std::cin.ignore();
    std::cout << "Enter name for Player X: ";
    std::getline(std::cin, playerXName);

    if (compOpponent) {
        playerOName = "Computer";
    } else {
        std::cout << "Enter name for Player O: ";
        std::getline(std::cin, playerOName);
    }

    int row, col;
    while (true) {
        drawBoard();
        if (currentPlayer == 'O' && compOpponent) {
            playCompMove();
        } else {
            std::cout << getCurrentPlayerName() << "'s turn (" << currentPlayer << "). Enter row (1 - 3) and column (1 - 3), separated by a space: ";
            std::cin >> row >> col;

            // adjusting row and col input so gameplay flows better
            row -= 1;
            col -= 1;

            try {
                if (row < 0 || row >= 3 || col < 0 || col >= 3){
                    throw std::out_of_range("Invalid input. Try again.");
                }
                if (board[row][col] != ' '){
                    throw std::logic_error("Cell already occupied. Try again.");
                }
                board[row][col] = currentPlayer;
            } catch (const std::exception& e) {
                std::cout << e.what() << "\n";
                continue;
            }
        }

        if (checkWinner()) {
            drawBoard();
            std::string winnerName = (currentPlayer == 'X') ? playerXName : playerOName;
            std::cout << winnerName << " wins!\n";
            saveScores(winnerName);
            break;
        } else if (checkTie()) {
            drawBoard();
            std::cout << "It's a tie between " << playerXName << " and " << playerOName << "!\n";
            saveScores("Tie");
            break;
        }

        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }
}

void ToeTacTic::saveScores(const std::string& winner) {
    std::ofstream file("scores.txt", std::ios::app);
    if (file.is_open()) {
        if (winner == "Tie") {
            file << "Tie between " << playerXName << " and " << playerOName << "\n";
        } else {
            file << "Winner: " << winner << "\n";
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to save scores.\n";
    }
}

void ToeTacTic::loadScores() {
    std::ifstream file("scores.txt");
    if (file.is_open()) {
        std::cout << "\nPrevious Scores:\n";
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << "\n";
        }
        file.close();
    } else {
        std::cout << "No previous scores available.\n";
    }
}