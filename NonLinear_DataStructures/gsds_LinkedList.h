#ifndef GSDS_LINKEDLIST
#define GSDS_LINKEDLIST

#include "BaseClasses/gsds_data_nonLinear.h"
#include <sstream>  // used in print_verbose to print pointers.
#include <list>

using namespace std;

class gsds_linkedList: public gsds_data_nonlinear
{
    
    private:
        struct node{
            int value;              // value of the node
            node *nextNode;         // location of the next node in the Linked List. end node is NullPtr
        };

        node *start_ptr = new node; //the starting node.
        node *end_ptr = new node;   // the final node.
        list<node*> node_ptrs;      // list of pointers to all other nodes (not including start and end).

    public:

        gsds_linkedList() : gsds_data_nonlinear()
        {
            end_ptr->nextNode = nullptr;
        }

        ~gsds_linkedList()
        {
            delete start_ptr;
            delete end_ptr;
            for(list<node*>::iterator n=node_ptrs.begin(); n!=node_ptrs.end(); ++n)
            {
                delete (*n);       
            }   
        }

        void insert(int val, int index) 
        {
            //  Note: for future index checking: check if index is <= length + 1 

            node *newNode_ptr = new node;
            node_ptrs.push_back(newNode_ptr);
            newNode_ptr->value = val;
            newNode_ptr->nextNode = nullptr;


            // loop through all nodes from the begining, until index is found
            node *currNode_ptr = start_ptr;
            int currIndex = 0;
            while (currNode_ptr->nextNode != nullptr) 
            {
                // -1 as we want to replace the previous node's 'next node' with the new node
                if (currIndex == index - 1) 
                {
                    newNode_ptr->nextNode = currNode_ptr->nextNode;
                    currNode_ptr->nextNode = newNode_ptr;
                    length ++;
                    break;
                } else if (index == 0) 
                {
                    newNode_ptr->value = start_ptr->value;
                    newNode_ptr->nextNode = start_ptr->nextNode;
                    start_ptr->value = val;
                    start_ptr->nextNode = newNode_ptr;
                    length ++;
                    break;
                }
                currIndex ++;
                currNode_ptr = currNode_ptr->nextNode;
            }
        }

        int index(int index) 
        {
            throw not_implemented();
        }


        void delAtIndex(int index) 
        {
            throw not_implemented();
        }


        void delItem(int val) 
        {
            throw not_implemented();
        }


        void append(int val)
        {
            if (length == 0) 
            {
                start_ptr->value =  val;
                start_ptr->nextNode = end_ptr;
                length = 1;
            } else 
            {    
                insert(val, length);
            }
        }

        void print_verbose() 
        {
            node *currPtr = start_ptr;
            string print_arr = "";

            while (currPtr->nextNode != nullptr)  
            {
                print_arr += "[";    // std::to_string()
                stringstream ss;
                ss << currPtr; 
                print_arr += ss.str();
                print_arr += "]";
                print_arr += to_string(currPtr->value);
                print_arr += ", ";
                currPtr = currPtr->nextNode;
            }
            print_arr += "[";    // std::to_string()
            stringstream ss;
            ss << currPtr; 
            print_arr += ss.str();
            print_arr += "]";
            print_arr += to_string(currPtr->value);

            cout << print_arr << endl;
        }

        void print() 
        {
            node *currPtr = start_ptr;
            string print_arr = "";

            while (currPtr->nextNode != nullptr)  
            {
                print_arr += to_string(currPtr->value);
                print_arr += ", ";
                currPtr = currPtr->nextNode;
            }
            cout << print_arr << endl;
        }
};




#endif