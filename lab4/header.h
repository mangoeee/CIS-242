#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include <algorithm>

// func to populate a list with user input
void populateUserList(std::vector<int>& list, int size) {
    std::cout << "Enter " << size << " values for the list:" << std::endl;
    for (int i = 0; i < size; ++i) {
        int value;
        std::cin >> value; // store user input in value
        list.push_back(value); // add value to end of vector
    }
}

// func to populate a list with random numbers
void populateRandomList(std::vector<int>& list, int size, int min = 1, int max = 10) {
    srand(static_cast<unsigned>(time(0)));
    for (int i = 0; i < size; ++i) {
        list.push_back(rand() % (max - min + 1) + min); // add rand value to end of vector
    }
}

// func to find matches between lists
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
    int maxVal = INT_MIN, minVal = INT_MAX;
    std::string maxSource, minSource;
    int maxIndex = -1, minIndex = -1;

    // check list1 and store values to display later
    for (size_t i = 0; i < list1.size(); ++i) {
        if (list1[i] > maxVal) {
            maxVal = list1[i];
            maxSource = "list 1";
            maxIndex = i;
        }
        if (list1[i] < minVal) {
            minVal = list1[i];
            minSource = "list 1";
            minIndex = i;
        }
    }

    // Check list2 and store values to display later
    for (size_t i = 0; i < list2.size(); ++i) {
        if (list2[i] > maxVal) {
            maxVal = list2[i];
            maxSource = "list 2";
            maxIndex = i;
        }
        if (list2[i] < minVal) {
            minVal = list2[i];
            minSource = "list 2";
            minIndex = i;
        }
    }

    // Check randomList and store values to display later
    for (size_t i = 0; i < list3.size(); ++i) {
        if (list3[i] > maxVal) {
            maxVal = list3[i];
            maxSource = "list 3";
            maxIndex = i;
        }
        if (list3[i] < minVal) {
            minVal = list3[i];
            minSource = "list 3";
            minIndex = i;
        }
    }

    std::cout << "\nHighest number across all lists: " << maxVal
              << " (from " << maxSource << ", element " << maxIndex + 1 << ")";
    std::cout << "\nLowest number across all lists: " << minVal
              << " (from " << minSource << ", element " << minIndex + 1 << ")\n";
}

// func to check if two lists are identical
std::string checkIdentical(const std::vector<int>& list1, const std::vector<int>& list2) {
    if (list1 == list2) {
        return "Identical";
    } else {
        return "Not identical";
    }
}

// func to check if all three lists are identical for grand prize
bool checkGrandPrize(const std::vector<int>& list1, const std::vector<int>& list2, const std::vector<int>& list3) {
    return list1 == list2 && list2 == list3;
}