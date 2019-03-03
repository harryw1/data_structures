#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{

  srand(time(0));
  LinkedList<int> * list = new LinkedList<int>(NULL, NULL, 0, 0);
  list -> append(0);
  list -> display_i(0);
  list -> append(1);
  list -> display_i(1);
  list -> prepend(42);
  list -> display_i(0);
  list -> add_at_i(84, 1);
  list -> display_i(1);
  list -> remove_at_i(1);
  list -> display_all();
  list -> display_range(0,0);
  list -> change_type(1);
  list -> append(100);
  list - remove_at_i((list->get_size()));
  list -> info();
  //list -> random_shuffle();

  cout << endl;

  for(int i = 0; i < (list -> get_size()); i++)
  {
    list -> display_i(i);
    cout << endl;
  }

}
