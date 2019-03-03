#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "Node.h"
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;

//this thing leaks memory like one ones business ;D

template <typename T>
class LinkedList
{
    /* No other member variables should be added */
    private:
        Node<T>* head;
        Node<T>* tail;

        size_t type;
        size_t size;

        bool is_circularly;

    public:

        /* Default Constructor - I gave you this for Free */
        LinkedList() : head(NULL), tail(NULL), type(0), size(0), is_circularly(false){}

        /* ... but not this one */
        LinkedList(Node<T>* head, Node<T>* tail, size_t type, bool is_circularly)
        {
          this -> head = head;
          this -> tail = tail;
          this -> type = type;
          this -> size = 0;
          this -> is_circularly = is_circularly;
        }

        /* getter for size */
        size_t get_size()
        {
          return this -> size;
        }

        /* add to the end of the list */
        void append(T data)
        {

          //construct new node to be appended
          Node<T>* toAppend = new Node<T>(data);

          //case for when the list is empty
          if(!size)
          {
            head = toAppend;
            tail = toAppend;
          }

          //otherwise
          else
          {
              //sets the next pointer to NULL
              toAppend->set_next(NULL);

              //sets the current tail's next to the new node
              tail -> set_next(toAppend);

              //cases for when the list is doubly, circularly, and doubly circularly
              if(type)
              {
                //sets appended prev pointer to what is the current tail
                toAppend -> set_prev(tail);
              }

              if(is_circularly)
              {
                //sets the appended next pointer to the head if we have a circularly
                toAppend -> set_next(head);
              }

              if(is_circularly && type)
              {
                //does the same as is_circularly but also sets the head prev pointer to the appnded element
                toAppend -> set_next(head);
                head -> set_prev(toAppend);
              }

              //makes the appended thing the new tail
              tail = toAppend;
          }

          size++;
          return;

        }

        /* add to the front of the list */
        void prepend(T data)
        {

          //creates new node
          Node<T>* toPrepend = new Node<T>(data);

          //for when the list is empty
          if(!size)
          {
            head = toPrepend;
            tail = toPrepend;
          }

          else
          {
            //new node points to where the head is pointing
            toPrepend -> set_next(head);

            if(type)
            {
              tail -> set_next(NULL);
              toPrepend -> set_prev(NULL);
            }

            if(is_circularly)
            {
              //points tail to new node at the beginning of list
              toPrepend -> set_prev(tail);
            }

            if(is_circularly && type)
            {
              //points tail to new node and points new node prev to tail
              tail -> set_next(toPrepend);
              toPrepend -> set_prev(tail);
            }

            head = toPrepend;
          }

          size++;
          return;

        }

        /* add so the new node is the ith node */
        void add_at_i(T data, size_t i)
        {
          //create a counter to loop from the beginning of the list to the end
          //if the user enters 0, we call the prepend function
          //if the user enters a number equal to the size of the list, call append
          Node<T>* appendI = new Node<T>(data);
          Node<T>* current = new Node<T>(data);
          Node<T>* previousN = new Node<T>(data);

          int temp = 0;

          //empty list
          if(!size)
          {
            append(data);
            head = appendI;
            tail = appendI;
          }

          //if user enters 0
          if(!i)
          {
            prepend(data);
            head = appendI;
          }

          //if user enters size
          if(i == size)
          {
            append(data);
            tail = appendI;
          }

          else
          {

            //iterates through the list, updating node pointers until we reach the position where we want to add
            current = head;
            while(temp < i)
            {
              previousN = current;
              current = (current -> get_next());
              temp++;
            }

            previousN -> set_next(appendI);
            appendI -> set_next(current);

            if(type)
            {
              appendI -> set_prev(previousN);
            }

            if(is_circularly && type && (i == 0))
            {
              appendI -> set_prev(tail);
              appendI -> set_next(head);
              head = appendI;
            }

            if(is_circularly && type && (i == size))
            {
              appendI -> set_prev(previousN);
              appendI -> set_next(head);
              tail = appendI;
            }

          }

          size++;
          return;

        }

        /* remove the ith node from the list */
        void remove_at_i(size_t i)
        {

          //temp nodes for iterating through the list
          Node<T>* temp = new Node<T>(0);
          Node<T>* nextIterate = new Node<T>(0);
          int counter = 0;


          if(!size)
          {
            cout << "The list is already empty." << endl;
            return;
          }

          if(i < 0 || i > size)
          {
            cout << "Out of bounds." << endl;
            return;
          }

          //when deleteing the first thing in the list
          if(i == 0)
          {

            //holds the first node
            temp = head;

            //head points to second thing in list
            head = (head -> get_next());

            //sets the previous to NULL when in a doubly linked list
            if(type)
            {
              head -> set_prev(NULL);
            }

            //if its a circle, second thing now needs to also point to the tail
            if(is_circularly)
            {
              head -> set_prev(tail);
            }

          }

          //deleting the last thing in the list
          if(i == size)
          {

            //cout << "inside i = size" << endl;
            if(is_circularly)
            {

              temp = head;
              nextIterate = head;

              while(counter < (i-1))
              {
                temp = nextIterate;
                nextIterate = (nextIterate -> get_next());
                counter++;
              }
              tail = temp;
              tail -> set_next(head);
              nextIterate -> set_next(NULL);

            }

            if(type)
            {

              temp = head;
              nextIterate = head;

              while(counter < (i-2))
              {
                temp = nextIterate;
                nextIterate = (nextIterate -> get_next());
                counter++;
              }
              tail = nextIterate;
              tail -> set_prev(temp);
              nextIterate -> set_next(NULL);

            }

            else
            {

              temp = head;
              nextIterate = head;

              while(counter < (i-1))
              {
                temp = nextIterate;
                nextIterate = (nextIterate -> get_next());
                counter++;
              }
              tail = temp;
              tail -> set_next(NULL);

            }

          }

          else
          {

            if(type)
            {

              while(counter < (i-1))
              {
                temp = nextIterate;
                nextIterate = (nextIterate -> get_next());
                counter++;
              }
              nextIterate = (nextIterate -> get_next());
              temp -> set_next(nextIterate);
              nextIterate -> set_prev(temp);

            }

            else
            {
              //additional node to so we can null the pointer of thing to remove
              //and not lose the thing after it
              Node<T>* third = new Node<T>(0);

              temp = head;
              nextIterate = head;

              while(counter < i)
              {
                temp = nextIterate;
                nextIterate = (nextIterate -> get_next());
                counter++;
              }
              third = (nextIterate -> get_next());
              temp -> set_next(third);
              nextIterate -> set_next(NULL);

            }

          }

          size--;
          return;

        }

        /* update the type of the array along with all the links
           and members of the list */
        void change_type(size_t type)
        {
          //should iterate through the list, and depending on the current type
          //should add or remove prev pointers to all of the nodes

          //if we make the list circularly, give the head node a prev pointer to the tail
          //and the tail node a next pointer to the head
          Node<T>* previousPointer = new Node<T>(0);
          Node<T>* currentPointer = new Node<T>(0);
          Node<T>* nextPointer = new Node<T>(0);

          previousPointer = head;
          currentPointer = head;
          nextPointer = head;

          //making sure the pointers are all at head
          //cout << previousPointer << " " << currentPointer << " " << nextPointer << endl;

          if(type)
          {

            this -> type = 1;
            //cout << "inside type" << endl;
            currentPointer -> set_prev(NULL);
            //cout << "first pointer set" << endl;
            //first iteration does not move the previous pointer
            currentPointer = (nextPointer -> get_next());
            nextPointer = (nextPointer -> get_next());
            //cout << "moves current and next" << endl;

            currentPointer -> set_prev(previousPointer);
            //cout << "current points to prev" << endl;

            while(nextPointer != NULL)
            {
              //inside while loop
              previousPointer = currentPointer;
              //cout << "previous = current" << endl;
              currentPointer = nextPointer;
              //cout << "current = next" << endl;
              currentPointer -> set_prev(previousPointer);
              //cout << currentPointer -> get_prev() << "    this is current get prev" << endl;
              nextPointer = (nextPointer -> get_next());
              //cout << "next is get next" << endl;
            }
            //cout << "Left while loop" << endl;
            currentPointer -> set_prev(previousPointer);
            //cout << "current points to prev" << endl;
            previousPointer = currentPointer;
            //cout << "previous is now current" << endl;
            currentPointer = tail;
            //cout << "current equals tail" << endl;
            currentPointer -> set_prev(previousPointer);

          }

          if(type && is_circularly)
          {

            this -> type = 1;
            //cout << "type and circle" << endl;
            currentPointer -> set_prev(NULL);

            //first iteration does not move the previous pointer
            currentPointer = (nextPointer -> get_next());
            nextPointer = (nextPointer -> get_next());

            currentPointer -> set_prev(previousPointer);

            while(nextPointer != head)
            {
              previousPointer = currentPointer;
              currentPointer = nextPointer;
              nextPointer = (nextPointer -> get_next());
              currentPointer -> set_prev(previousPointer);
            }

            currentPointer -> set_prev(previousPointer);
            nextPointer -> set_prev(currentPointer);
            nextPointer -> set_next(head);

          }

          if(!type)
          {

            this -> type = 0;
            //cout << "not type" << endl;
            //first iteration does not move the previous pointer
            currentPointer = (nextPointer -> get_next());
            nextPointer = (nextPointer -> get_next());

            while(nextPointer != NULL)
            {
              previousPointer = currentPointer;
              currentPointer = nextPointer;
              nextPointer = (nextPointer -> get_next());
              previousPointer -> set_prev(NULL);
              currentPointer -> set_prev(NULL);
            }

            nextPointer -> set_prev(NULL);
            currentPointer -> set_prev(NULL);

          }

          if(!type && !is_circularly)
          {

            this -> type = 0;
            //cout << "not type and not circle" << endl;
            currentPointer -> set_prev(NULL);

            //first iteration does not move the previous pointer
            currentPointer = (nextPointer -> get_next());
            nextPointer = (nextPointer -> get_next());

            currentPointer -> set_prev(NULL);

            while(nextPointer != NULL)
            {
              previousPointer = currentPointer;
              currentPointer = nextPointer;
              nextPointer = (nextPointer -> get_next());
              currentPointer -> set_prev(NULL);
            }

            nextPointer -> set_prev(NULL);

          }
        }

        /* remove all the elements in the list */
        void delete_list()
        {
          //iterate through the list, using the delete function on each node
          //pointer that exists so far
          Node<T>* deleteAll = new Node<T>(0);

          deleteAll = head;
          while(deleteAll != NULL)
          {
            head -> set_next(deleteAll->get_next());
            deleteAll -> set_next(NULL);
            delete deleteAll;
            deleteAll = (head -> get_next());
          }

          head = NULL;
          tail = NULL;

        }

        /* rotate the nodes in the list r spots.
           if r < 0 rotate left
           if r > 0 rotate right
        */
        void rotate(int r);

        /* reverse the order of the list */
        void reverse();

        /* put the list in a random order */
        void random_shuffle()
        {

          //temp nodes so i dont lose pointers
          Node<T>* startingNode = new Node<T>(NULL);
          Node<T>* temp = new Node<T>(NULL);

          int counter = 0;
          int randomNode = 0;

          startingNode = head;
          //j_temp = head;

          randomNode = (rand() % (this -> size));

          while(counter < randomNode)
          {
            startingNode = (startingNode -> get_next());
            counter++;
          }
          
          //cout << (startingNode -> get_data()) << endl;

        }

        /* display the node iformation of the ith node */
        void display_i(size_t i)
        {

          cout << "[" << i << "]" << " Node Info: " << endl;
          Node<T>* displayThis = new Node<T>(NULL);
          int counter = 0;
          if(i == 0)
          {
            //cout << "Times round: " << counter << endl;
            cout << "Data: " << (head -> get_data()) << endl;
            head -> display_links();
            return;
            //counter++;
          }
          if(i == (this -> size))
          {
            //cout << "Times round: " << counter << endl;
            cout << "Data: " << (tail -> get_data()) << endl;
            tail -> display_links();
            return;
            //counter++;
          }
          else
          {
            displayThis = head;
            for(int q = 0; q < i; q++)
            {
              displayThis = (displayThis -> get_next());
            }
            //cout << "Times round: " << counter << endl;
            cout << "Data: " << (displayThis -> get_data()) << endl;
            displayThis -> display_links();
            return;
            //counter++;
          }

        }

        /* Print the data from all the nodes - again a freebie */
        void display_all()
        {
            std::cout << "List: ";

            if (this->head == NULL)
            {
                std::cout << "EMPTY LIST\n";
                return;
            }

            Node<T>* c = this->head;
            if(!is_circularly)
            {
              while (c != NULL)
              {
                std::cout << c->get_data() << " ";
                c = c->get_next();
              }
              std::cout << std::endl;
            }
            int sizeCount = 0;
            if(is_circularly)
            {
              while (sizeCount < size)
              {
                std::cout << c->get_data() << " ";
                c = c->get_next();
                sizeCount++;
              }
              std::cout << std::endl;
            }
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
                std::cout << "Error: i cannot be larger than j\n";
                return;
            }

            std::cout << "List: ";

            while(i <= j)
            {

              if (this->head == NULL)
              {
                  std::cout << "EMPTY LIST\n";
                  return;
              }

              Node<T>* c = this->head;
              while (c != NULL && i <= j)
              {
                  std::cout << c->get_data() << " ";
                  c = c->get_next();
                  i++;
              }
              std::cout << std::endl;

            }

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
