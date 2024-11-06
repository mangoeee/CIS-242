/*
    Emery Mangona
    CIS 242 Project 5

    Inventory Bin Stack
        Design an inventory class that stores the following members:

        serialNum:      An integer that holds a part's serial number.
        manufactDate:   A member that holds the date the part was manufactured.
        lotNum:         An integer that holds the part's lot number.

        The class should have appropriate member functions for storing data into, and retrieving data from, these members.

        Next, design a stack class that can hold objects of the class described above. If you wish, you may use the template you designed in Programming Challenge 1 or 2. 

        Last, design a program that uses the stack class described above. The program should have a loop that asks the user if he or she wishes to add a part to inventory, or take a part from inventory. The loop should repeat until the user is finished. 

        If the user wishes to add a part to inventory, the program should ask for the serial number, date of manufacture, and lot number. The data should be stored in an inventory object, and pushed onto the stack. 

        If the user wishes to take a part from inventory, the program should pop the top-most part from the stack and display the contents of its member variables. 

        When the user finishes the program, it should display the contents of the member values of all the objects that remain on the stack.
*/

#include <iostream>
#include "template.h" // staticStack template
#include "inventory.h" // inventory class

void displayMenu();

int main() {
    StaticStack<Inventory> inventoryStack(10); // create inventory stack of capacity 10
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch(choice) {
            case 1: { // add a part to inventory
                int sn, ln;
                std::string date;
                std::cout << "Enter part's serial number: ";
                std::cin >> sn;
                std::cout << "Enter part's manufacturing date (MM/DD/YYYY): ";
                std::cin >> date;
                std::cout << "Enter part's lot number: ";
                std::cin >> ln;

                Inventory item(sn, date, ln);
                try {
                    inventoryStack.push(item);
                    std::cout << "Part added to inventory.\n";
                } catch (const StaticStack<Inventory>::Overflow &) {
        std::cout << "Error: Inventory is full.\n";
                }
                break;
            }
            case 2: { // remove part from inventory
                Inventory item;
                try {
                    inventoryStack.pop(item);
                    std::cout << "Removed part details:\n";
                    std::cout << "Serial Number: " << item.getSerialNum() << "\n";
                    std::cout << "Manufacture Date: " << item.getManufactDate() << "\n";
                    std::cout << "Lot Number: " << item.getLotNum() << "\n";
                } catch (const StaticStack<Inventory>::Underflow &) {
                    std::cout << "Error: Inventory is empty.\n";
                }
                break;
            }
            case 3: { // display all remaining parts
                    if (inventoryStack.isEmpty()) {
                        std::cout << "The inventory is empty.\n";
                    } else {
                        std::cout << "Remaining items in inventory:\n";

                        // temporarily store items in another stack to maintain the original order
                        StaticStack<Inventory> tempStack(inventoryStack.getCapacity()); // create a temporary stack to hold items in reverse

                        // pop items from the original stack and push them into tempStack for display
                        while (!inventoryStack.isEmpty()) {
                            Inventory item;
                            inventoryStack.pop(item);
                            std::cout << "-------------------------\n";
                            std::cout << "Serial Number: " << item.getSerialNum() << "\n";
                            std::cout << "Manufacture Date: " << item.getManufactDate() << "\n";
                            std::cout << "Lot Number: " << item.getLotNum() << "\n";
                            std::cout << "-------------------------\n";
                            tempStack.push(item); // store in temporary stack
                        }

                        // restore original stack by pushing items back from tempStack
                        while (!tempStack.isEmpty()) {
                            Inventory item;
                            tempStack.pop(item);
                            inventoryStack.push(item);
                        }
                    }
                    break;
            }
            case 4: // exit program
                std::cout << "Exiting program.\n";
                break;
            default: // invalid choice
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 4);

    return 0;
}

void displayMenu() {
    std::cout << "\nInventory Management Menu:\n";
    std::cout << "1. Add a part to inventory\n";
    std::cout << "2. Remove latest part from inventory\n";
    std::cout << "3. Display all remaining parts\n";
    std::cout << "4. Quit\n";
    std::cout << "Enter your choice: ";
}