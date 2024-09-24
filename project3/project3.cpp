/*
    Instructions

    Write a program that simulates a lottery. The program should have an array of 10 integers named lottery and should generate a random number in the range of 0 through 9 for each element in the array. The user should enter ten digits, which should be stored in an integer array named user. The program is to compare the corresponding elements in the two arrays and keep a count of the digits that match. For example, the following shows the lottery array and the user array with sample numbers stored in each. There are two matching digits (elements 2 and 4).

    lottery array:
        7 4 9 1 3 5 6 7 9 9

    user array:
        4 2 9 7 3 7 8 9 6 6

    The program should display the random numbers stored in the lottery array and the number of matching digits.

    If all of the digits match, display a message proclaiming the user as a grand prize winner.

    Also output the values that are the same as well as the elements.
    Also output how many numbers were the same.
    You are required to use a function for the user array and the lottery array.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

void generateLottery(int lottery[], int size); // generate random nums into lottery array
void userNums(int user[], int size); // get user input for 10 nums to compare to lottery
int compareArrays(int lottery[], int user[], int size); // compare user nums to lottery nums and obtain matches

int main() {
    const int SIZE = 10;
    int lottery[SIZE], user[SIZE];
    srand(time(0)); // improved RNG?? kept getting the same "random" number in generateLottery, but read that this might help which it does!
    
    userNums(user, SIZE);
    
    generateLottery(lottery, SIZE);
    
    cout << "Lottery numbers: ";
    for (int i = 0; i < SIZE; i++) {
        cout << lottery[i] << " ";
    }
    cout << endl;

    int matchCount = compareArrays(lottery, user, SIZE);

    cout << "Number of matching digits: " << matchCount << endl; // output the number of matching digits

    // check if user is the grand prize winner
    if (matchCount == SIZE) {
        cout << "Congratulations! You are the grand prize winner!" << endl;
    }

    return 0;
}

void generateLottery(int lottery[], int size){
    for (int i = 0; i < size; i++){
        lottery[i] = rand() % 10; // RNG for int 0 to 9
    }
};

void userNums(int user[], int size){
    cout << "Enter 10 digits (0 - 9, with spaces to separate digits) for your lottery numbers: ";
    for (int i = 0; i < size; i++){
        cin >> user[i];
        // check that the user only inputs single digit ints; if not, try again
        while (user[i] < 0 || user[i] > 9){
            cout << "One or more of your inputs were invalide, enter only digits between 0 and 9: ";
            cin >> user[i];
        }
    }
};

int compareArrays(int lottery[], int user[], int size){
    int matchCount = 0;
    cout << "Matching elements: ";
    for (int i = 0; i < size; i++) {
        if (lottery[i] == user[i]) {
            if (matchCount > 0) {
                cout << ", ";
            }
            cout << "index " << i << " (value: " << lottery[i] << ")";
            matchCount++;
        }
    }
    if (matchCount == 0) {
        cout << "No matches, womp womp";
    }
    cout << endl;
    return matchCount;
};