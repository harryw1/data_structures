#include <iostream>
#include <ctime>
#include "LinkedList.h"

using namespace std;

int main()
{
  srand(time(0));
  LinkedList<int> * list = new LinkedList<int>(NULL, NULL, 0, 0);

  std::clock_t start;

  start = std::clock()
  list -> append(0);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_i(0);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> append(1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_i(1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> prepend(42);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_i(0);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> add_at_i(84, 1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_i(1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> remove_at_i(1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_all();
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> display_range(0,0);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> change_type(1);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> append(100);
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list - remove_at_i((list->get_size()));
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  
  start = std::clock()
  list -> info();
  std::cout << "Stopwatch: " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms." << std::endl;
  //list -> random_shuffle();

  cout << endl;

  for(int i = 0; i < (list -> get_size()); i++)
  {
    list -> display_i(i);
    cout << endl;
  }

}
