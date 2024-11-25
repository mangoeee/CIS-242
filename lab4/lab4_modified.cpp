
/*
    Emery Mangona
    CIS 242 Lab 4

    Extended functionality to compare lists:
    1. Output which numbers are the same and their count across lists.
    2. Identify and output the highest and lowest numbers from all lists.
    3. Check if all three lists are identical, output "Grand Prize Winner!" if true.
*/

#include <iostream>
#include <set>
#include <algorithm>
#include "lab4.h"

void findMatches(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    std::set<int> allMatches;
    int count = 0;

    // Find numbers that appear in all three lists
    for (int num : list1) {
        if (std::find(list2.begin(), list2.end(), num) != list2.end() &&
            std::find(list3.begin(), list3.end(), num) != list3.end()) {
            allMatches.insert(num);
            ++count;
        }
    }

    std::cout << "\nMatching numbers in all three lists: ";
    if (allMatches.empty()) {
        std::cout << "None";
    } else {
        for (int match : allMatches) {
            std::cout << match << " ";
        }
        std::cout << "\nTotal matches: " << count;
    }
}

void findMinMax(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    int highest = std::max({*std::max_element(list1.begin(), list1.end()),
                            *std::max_element(list2.begin(), list2.end()),
                            *std::max_element(list3.begin(), list3.end())});

    int lowest = std::min({*std::min_element(list1.begin(), list1.end()),
                           *std::min_element(list2.begin(), list2.end()),
                           *std::min_element(list3.begin(), list3.end())});

    std::cout << "\nHighest number across all lists: " << highest;
    std::cout << "\nLowest number across all lists: " << lowest;
}

bool checkGrandPrize(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    return list1 == list2 && list2 == list3;
}

int main() {
    const int SIZE = 10;
    std::vector<int> list1, list2, randomList;

    // Populate the lists
    std::cout << "Populate List 1:" << std::endl;
    populateUserList(list1, SIZE);

    std::cout << "\nPopulate List 2:" << std::endl;
    populateUserList(list2, SIZE);

    std::cout << "\nPopulating Random List:" << std::endl;
    populateRandomList(randomList, SIZE);

    // Display the lists
    std::cout << "\nList 1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }

    std::cout << "\nList 2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }

    std::cout << "\nRandom List: ";
    for (int num : randomList) {
        std::cout << num << " ";
    }

    // Check for identical lists
    std::cout << "\n\nChecking List 1 and List 2: " << checkIdentical(list1, list2) << std::endl;
    std::cout << "Checking List 1 and Random List: " << checkIdentical(list1, randomList) << std::endl;
    std::cout << "Checking List 2 and Random List: " << checkIdentical(list2, randomList) << std::endl;

    // Find matches and min/max values
    findMatches(list1, list2, randomList);
    findMinMax(list1, list2, randomList);

    // Grand Prize Winner check
    if (checkGrandPrize(list1, list2, randomList)) {
        std::cout << "\n\nGrand Prize Winner! All three lists are identical!";
    }

    return 0;
}
