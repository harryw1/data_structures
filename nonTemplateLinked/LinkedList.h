#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

using namespace std;

//template <typename T>
class LinkedList
{
    /* No other member variables should be added */
    private:
        Node head;
        Node tail;

        size_t type;
        size_t size;

        bool is_circularly;

    public:

        /* Default Constructor - I gave you this for Free */
        LinkedList() : head(NULL), tail(NULL), type(0), size(0), is_circularly(false){}

        /* ... but not this one */
        LinkedList(Node head, Node tail, size_t type, bool is_circularly)
        {
          this -> head = head;
          this -> tail = tail;
          this -> type = type;
          this -> is_circularly = is_circularly;
        }

        /* getter for size */
        size_t get_size()
        {
          return this -> size;
        }

        /* add to the end of the list */
        void append(int data)
        {
          Node node(data);
          Node tmp;
          while(tmp -> next != NULL)
          {
            tmp = tmp -> next;
          }
          node -> next = tmp;
          tmp -> next = NULL;
          if(is_circularly)
          {
            tmp -> prev = tail;
          }
          tail = tmp;
          /*Node<int> node = new Node(data);
          Node tmp = head;
          while(tmp -> next != nullptr){
            tmp = tmp -> next;
          }
          tmp = node;
          tmp -> next = nullptr;
          if(is_circularly)
          {
            tmp -> prev = tail;
          }
          tail = tmp;*/
        }

        /* add to the front of the list */
        void prepend(int data);

        /* add so the new node is the ith node */
        void add_at_i(int data, size_t i);

        /* remove the ith node from the list */
        void remove_at_i(size_t i);

        /* update the type of the array along with all the links
           and members of the list */
        void change_type(size_t type);

        /* remove all the elements in the list */
        void delete_list();

        /* rotate the nodes in the list r spots.
           if r < 0 rotate left
           if r > 0 rotate right
        */
        void rotate(int r);

        /* reverse the order of the list */
        void reverse();

        /* put the list in a random order */
        void random_shuffle();

        /* display the node iformation of the ith node */
        void display_i(size_t i);

        /* Print the data from all the nodes - again a freebie */
        void display_all()
        {
            std::cout << "List: ";

            if (this->head == NULL)
            {
                std::cout << "EMPTY LIST\n";
                return;
            }

            Node<int>* c = this->head;
            while (c != NULL)
            {
                std::cout << c->get_data() << " ";
                c = c->get_next();
            }
            std::cout << std::endl;
        }

        /* print node information for all nodes in the given range
           if one of the range values are not given use the following
           if no start: start at node 0

                I started this one for you
        */
        void display_range(size_t i = 0, size_t j = 0)
        {
            if (i > j)
            {
                std::cout << "Error: j cannot be larger than i\n";
                return;
            }

            std::cout << "List: ";

        }

        /* display the head/tail addresses - Free */
        void display_links()
        {
            std::cout << "Links:"
                    << "\n\thead = " << this->head
                    << "\n\ttail = " << this->tail
                    << std::endl;
        }

        /* display all list information - another! Im so nice. */
        void info()
        {
            std::string t = (this->type) ? "Doubly" : "Singly";
            t += (is_circularly) ? "-circularly " : " ";
            std::cout << "Type: " << t << "linked-list\n";

            std::cout << "Size: " << this->size << std::endl;
            this->display_links();
        }
};

#endif
