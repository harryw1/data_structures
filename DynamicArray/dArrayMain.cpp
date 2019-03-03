#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "DynamicArray.cpp"

int main()
{
    srand(time(0));
    DynamicArray<int> myArray;
    unsigned int menuSelection;

    while(true)
    {
        std::cout << "~~~~~~~~~~~~~" << std::endl;
        std::cout << "DYNAMIC ARRAY" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << std::setw(8) << "1. " << std::setw(2) << "Append" << std::endl;
        std::cout << std::setw(8) << "2. " << std::setw(2) << "Prepend" << std::endl;
        std::cout << std::setw(8) << "3. " << std::setw(2) << "Insert" << std::endl;
        std::cout << std::setw(8) << "4. " << std::setw(2) << "Remove" << std::endl;
        std::cout << std::setw(8) << "5. " << std::setw(2) << "Remove all" << std::endl;
        std::cout << std::setw(8) << "6. " << std::setw(2) << "Rotate" << std::endl;
        std::cout << std::setw(8) << "7. " << std::setw(2) << "Reverse" << std::endl;
        std::cout << std::setw(8) << "8. " << std::setw(2) << "Random Shuffle" << std::endl;
        std::cout << std::setw(8) << "9. " << std::setw(2) << "Print Array" << std::endl;
        std::cout << std::setw(8) << "10. " << std::setw(2) << "Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Please make a selection: ";
        std::cin >> menuSelection;
        if(menuSelection < 1 || menuSelection > 10)
        {
            std::cout << std::endl;
            std::cout << "Please make a valid selection." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            if(menuSelection == 1)
            {
                int userInput;
                std::cout << "Please enter the item to be appended: ";
                std::cin >> userInput;
                myArray.append(userInput);
            }
            if(menuSelection == 2)
            {
                int userInput;
                std::cout << "Please enter the item to be prepended: ";
                std::cin >> userInput;
                myArray.prepend(userInput);
            }
            if(menuSelection == 3)
            {
                int userInput;
                int indexInsert;
                std::cout << "Please enter the item to be inserted: ";
                std::cin >> userInput;
                std::cout << std::endl;
                std::cout << "Please enter the index to insert at (ie. 0 to insert at head): ";
                std::cin >> indexInsert;
                myArray.insert(userInput, indexInsert);
            }
            if(menuSelection == 4)
            {
                int userInput;
                std::cout << "Please enter the item to be removed (ie. 0 to remove the head): ";
                std::cin >> userInput;
                myArray.remove(userInput);
            }
            if(menuSelection == 5)
            {
                std::cout << "Removing all..." << std::endl;
                myArray.remove_all();
                std::cout << "All items removed from array." << std::endl;
            }
            if(menuSelection == 6)
            {
                int userInput;
                std::cout << "Please enter the number of roations to be made: ";
                std::cin >> userInput;
                myArray.rotate(userInput);
            }
            if(menuSelection == 7)
            {
                std::cout << "Reversing..." << std::endl;
                myArray.reverse();
                std::cout << "Array reversed." << std::endl;
            }
            if(menuSelection == 8)
            {
                std::cout << "Shuffling..." << std::endl;
                myArray.random_shuffle();
                std::cout << "Array shuffled." << std::endl;
            }
            if(menuSelection == 9)
            {   
                std::cout << "Current array:" << std::endl;
                std::cout << std::endl;
                myArray.print_array();
            }
            if(menuSelection == 10)
            {
                std::cout << "Exiting" << std::endl;
                break;
            }
        }
        
    }

    /*std::cout << std::endl;
    std::string x;
    std::cout << "Press enter to continue...";
    std::getline(std::cin, x);
    std::cout << std::endl;*/
    return 0;
}