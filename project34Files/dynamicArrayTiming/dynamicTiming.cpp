#include "DynamicArray.cpp"
#include <iostream>
#include <ctime>

int main()
{

    DynamicArray<int> arrayTest;
    std::clock_t start;
    for(int i = 0; i < 1000000; i++)
    {
        arrayTest.append(10);
    }
    //arrayTest.append(10);
    ////////////////////
    start = std::clock();
    for(int i = 0; i < 1; i++)
    {
        arrayTest.print_array();
    }
    std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
    ////////////////////
}