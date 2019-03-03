#ifndef NODE_H_
#define NODE_H_

#include <iostream>
#include <cstdlib>

using namespace std;

template <typename T>
class Node
{
    /* no other member variables should be used */
    private:
        T data;
        Node<T>* next;
        Node<T>* prev;

    public:
        /* Constructor needs a body */
        Node(T data, Node::Node<T>* next = NULL, Node::Node<T>* prev = NULL)
        {
          this -> data = data;
          this -> next = next;
          this -> prev = prev;
        }

        /* getters/setters for this->data */
        T get_data()
        {
          return this -> data;
        }
        void set_data(T data)
        {
          this -> data = data;
        }

        /* getters/setters for this->next */
        Node<T>* get_next()
        {
          return this -> next;
        }
        void set_next(Node<T>* next)
        {
          this -> next = next;
        }

        /* getters/setters for this->prev */
        Node<T>* get_prev()
        {
          return this -> prev;
        }
        void set_prev(Node<T>* prev)
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
