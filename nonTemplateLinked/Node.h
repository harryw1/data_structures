#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstdlib>

using namespace std;

//template <typename T>
class Node
{
    /* no other member variables should be used */
    private:
        int data;
        Node next;
        Node prev;

    public:
        /* Constructor needs a body */
        Node(int data, Node::Node next = NULL, Node::Node prev = NULL)
        {
          this -> data = data;
          this -> next = next;
          this -> prev = prev;
        }

        /* getters/setters for this->data */
        int get_data()
        {
          return this -> data;
        }
        int set_data(int data)
        {
          this -> data = data;
        }

        /* getters/setters for this->next */
        int get_next()
        {
          return this -> next;
        }
        int set_next(int &next)
        {
          this -> next = next;
        }

        /* getters/setters for this->prev */
        int get_prev()
        {
          return this -> prev;
        }
        int set_prev(int &prev)
        {
          this -> prev = prev;
        }

        /* display the pointer addresses */
        void display_links()
        {
          cout << "Previous: " << prev << endl;
          cout << "Next: " << next << endl;
        }

        /* display all node information */
        void print_node()
        {
          cout << "Data: " << data << endl;
        }
};

#endif
