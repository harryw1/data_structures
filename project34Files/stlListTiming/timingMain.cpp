#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
#include <string>
#include <list>
#include <vector>

int main()
{
    srand(time(0));
    //instantiates list (doubly-linked)
    std::list<int> myList;
    //iterator from list called it
    std::list<int>::iterator it;

    //TIMING FUNCTION STUFF
    std::clock_t start;

    while(true)
    {
        int menuSelection;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "STL List (Doubly-Linked)" << std::endl;
        std::cout << "------------------------" << std::endl;
        //push_back
        std::cout << std::setw(8) << "1. " << std::setw(2) << "Append" << std::endl;
        //push_front
        std::cout << std::setw(8) << "2. " << std::setw(2) << "Prepend" << std::endl;
        //insert
        std::cout << std::setw(8) << "3. " << std::setw(2) << "Insert" << std::endl;
        //erase
        std::cout << std::setw(8) << "4. " << std::setw(2) << "Remove Element" << std::endl;
        //clear
        std::cout << std::setw(8) << "5. " << std::setw(2) << "Remove All" << std::endl;
        //????
        std::cout << std::setw(8) << "6. " << std::setw(2) << "Rotate" << std::endl;
        //reverse
        std::cout << std::setw(8) << "7. " << std::setw(2) << "Reverse" << std::endl;
        //???
        std::cout << std::setw(8) << "8. " << std::setw(2) << "Shuffle" << std::endl;
        //begin: iterator is called it... it++ moves the iterator to the next element
        std::cout << std::setw(8) << "9. " << std::setw(2) << "Display" << std::endl;
        //exit
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
                //TIMING
                start = std::clock();
                for(int i = 0; i < 1000; i++)
                {
                    myList.push_back(userInput);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
            }
            if(menuSelection == 2)
            {
                int userInput;
                std::cout << "Please enter the item to be prepended: ";
                std::cin >> userInput;
                start = std::clock();
                for(int i = 0; i < 1000000; i++)
                {    
                    myList.push_front(userInput);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
            }
            if(menuSelection == 3)
            {
                int userInput;
                int indexInsert;
                it = myList.begin();
                std::cout << "Please enter the item to be inserted: ";
                std::cin >> userInput;
                std::cout << std::endl;
                std::cout << "Please enter the index to insert at (ie. 0 to insert at head): ";
                std::cin >> indexInsert;
                for(int i = 0; i < indexInsert; i++)
                {
                    ++it;
                }
                start = std::clock();
                for(int i = 0; i < 1000000; i++)
                {    
                    myList.insert(it, userInput);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
            }
            if(menuSelection == 4)
            {
                int userInput;
                it = myList.begin();
                std::cout << "Please enter the item to be removed (ie. 0 to remove the head): ";
                std::cin >> userInput;
                if(userInput >  myList.size())
                {
                    std::cout << std::endl;
                    std::cout << "Out of bounds exception in std::list::remove(i)..." << std::endl;
                    std::cout << std::endl;
                    break;
                }
                for(int i = 0; i < userInput; i++)
                {
                    ++it;
                }
                start = std::clock();
                for(int i = 0; i < 99; i++)
                {    
                    myList.erase(it);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
            }
            if(menuSelection == 5)
            {
                std::cout << "Removing all..." << std::endl;
                for(int i = 0; i < 100; i++)
                {
                    myList.clear();
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
                std::cout << "All items removed from list." << std::endl;
            }
            if(menuSelection == 6)
            {
                int userInput;
                std::cout << "Please enter the number of roations to be made: ";
                std::cin >> userInput;
                // creates a vector with name ...
                std::vector<int> vectorCopy;
                // reserves necessary space for the vector based on list size
                vectorCopy.reserve(myList.size());
                // copies elements from list to vector
                std::copy(myList.begin(), myList.end(), std::back_inserter(vectorCopy));
                // rotates the vector based on i
                std::rotate(vectorCopy.begin(), vectorCopy.begin() + userInput, vectorCopy.end());
                // clears list
                myList.clear();
                // assigns new values
                it = myList.begin();
                start = std::clock();
                for(int i = 0; i < vectorCopy.size(); i++)
                {
                    myList.push_back(vectorCopy[i]);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
                std::cout << "List rotated." << std::endl;
            }
            if(menuSelection == 7)
            {
                std::cout << "Reversing..." << std::endl;
                start = std::clock();
                myList.reverse();
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
                std::cout << "List reversed." << std::endl;
            }
            if(menuSelection == 8)
            {
                std::cout << "Shuffling..." << std::endl;
                // creates a vector with name ...
                std::vector<int> vectorCopy;
                // reserves neceessary space for the vector based on list size
                vectorCopy.reserve(myList.size());
                // copies elemets from list to vector
                std::copy(myList.begin(), myList.end(), std::back_inserter(vectorCopy));
                // shuffles the vector
                std::random_shuffle(vectorCopy.begin(), vectorCopy.end());
                // clears list
                myList.clear();
                // assigns new values
                it = myList.begin();
                start = std::clock();
                for(int i = 0; i < vectorCopy.size(); i++)
                {
                    myList.push_back(vectorCopy[i]);
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
                std::cout << "List shuffled." << std::endl;
            }
            if(menuSelection == 9)
            {   
                int i;
                it = myList.begin();
                std::cout << "Current list:" << std::endl;
                start = std::clock();
                for(it, i = 0; it!= myList.end(); it++, i++)
                {
                    std::cout << "Index [" << i << "]" << ": " << *it << std::endl;
                }
                std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
                std::cout << std::endl;
            }
            if(menuSelection == 10)
            {
                std::cout << "Exiting" << std::endl;
                break;
            }
        }
    
    }

    return 0;
}