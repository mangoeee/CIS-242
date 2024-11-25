/*
    Emery Mangona
    CIS 242 Lab 4

    Write a function to check if two sublists are identical.
        If the two sublists list1 and list2 are identical, return "Identical". Otherwise, return "Not identical".
        For example, if list1[] = {1, 2, 3} and list2[] = {1, 2, 3}, the expected output is "Identical".
        HINT: Two subsets are said to be identical if they have the same elements in the same order. For example, {2, 5} and {2, 5} are identical lists.

    Additional requirements:
        The amount of numbers that need to be entered are 10. 
        You will need to ask the user to enter values into each list.
        Please have a random generator to enter a set of numbers that goes into a list.
        You will have 3 lists in total and each should be in its own function.
        2 sets of numbers are made by the user and the random generator has its own set.
        For the list, you can use any of the following containers: deque, list, std::vector.
*/

#include <iostream>
#include "header.h"

int main() {
    const int SIZE = 10;
    std::vector<int> list1, list2, randomList;

    // populate the lists
    std::cout << "Populate List 1:" << std::endl;
    populateUserList(list1, SIZE);

    std::cout << "\nPopulate List 2:" << std::endl;
    populateUserList(list2, SIZE);

    std::cout << "\nPopulating Random List:" << std::endl;
    populateRandomList(randomList, SIZE);

    // display the lists
    std::cout << "\nList 1: ";
    for (int num : list1) { // (range-based for loop) for each elem num in list1, print elem 
        std::cout << num << " ";
    } 

    std::cout << "\nList 2: ";
    for (int num : list2) { // (range-based for loop) for each elem num in list2, print elem
        std::cout << num << " ";
    }

    std::cout << "\nRandom List: ";
    for (int num : randomList) { // (range-based for loop) for each elem num in randomList, print elem
        std::cout << num << " ";
    }

    // check for identical lists
    std::cout << "\n\nChecking List 1 and List 2: " << checkIdentical(list1, list2) << std::endl;
    std::cout << "Checking List 1 and Random List: " << checkIdentical(list1, randomList) << std::endl;
    std::cout << "Checking List 2 and Random List: " << checkIdentical(list2, randomList) << std::endl;

    // find matches and min/max values
    findMatches(list1, list2, randomList);
    findMinMax(list1, list2, randomList);

    // check grand prize winner
    if (checkGrandPrize(list1, list2, randomList)) {
        std::cout << "\n\nGrand Prize Winner! All three lists are identical!";
    }

    return 0;
}