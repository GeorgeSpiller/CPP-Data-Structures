#ifndef GSDS_LINKEDLIST
#define GSDS_LINKEDLIST

#include "../BaseClasses/gsds_data_nonLinear.h"

using namespace std;

class gsds_linkedList: public gsds_data_nonlinear
{
    
    private:
        int* start;
        int* end;
        struct {
            int value;      // value of the node
            int* nextNode;  // location of the next node in the Linked List. end node is NullPtr
        } node;

    public:

        gsds_linkedList() : gsds_data_nonlinear()
        {
            
        }

        void insert(int val, int index) 
        {
            throw not_implemented();
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
                start = *new node;
                end = *new node;
                start.value =  val;
                start.nextNode = *end;
                end.value = nullptr;
                end.nextNode = nullptr;

                length = 2;
            } else 
            {
                if (end.value == nullptr) 
                {
                    end.value = val;
                } else 
                {
                    // call insert on length - 1;
                }
            }
        }

        void print() 
        {
            throw not_implemented();
        }

};




#endif