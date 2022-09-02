#ifndef GSDS_QUEUE
#define GSDS_QUEUE

#include "gsds_data_linear.h"

using namespace std;

class gsds_queue: public gsds_data_linear
{
    
    private:
        int head = 0;
        int tail = 0;

    public:

        gsds_queue(int len) : gsds_data_linear(len)
        {
            // setting length and setting array is handled in the base and derrived class constructors
        }

        void push(int arg) 
        {
            if (isQueueFull()) 
            {
                throw overflow_error("Cannot push! Queue is full.");
            }

            data_ptr[head] = arg;

            // wrap around
            head = incrementWrapArround(head);
        }

        int pop() 
        {
            if (isQueueEmpty()) 
            {
                throw underflow_error("Cannot pop! Queue is empty.");
            }

            int retVal = data_ptr[tail];
            data_ptr[tail] = 0;

            // wrap arround
            tail = incrementWrapArround(tail);

            return retVal;
        }
    
    private:

        bool isQueueFull() 
        {
            int headNextVal = incrementWrapArround(head);
            return headNextVal == tail;
        }

        bool isQueueEmpty()
        {
            return head == tail;
        }

        int incrementWrapArround(int val) 
        {
            val += 1;
            if (val == length + 1) 
            {
                val = 0;
            }
            return val;
        }
};  




#endif