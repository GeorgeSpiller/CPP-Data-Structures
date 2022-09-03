#ifndef GSDS_STACK
#define GSDS_STACK

#include "BaseClasses/gsds_data_linear.h"

using namespace std;

class gsds_stack: public gsds_data_linear
{
    
    private:
        int top = 0;

        
        bool isEmpty() 
        {
            return top <= 0;
        }


        bool isFull() 
        {
            return top == length;
        }
    

    public:

        gsds_stack(int len) : gsds_data_linear(len)
        {
            // setting length and setting array is handled in the base and derrived class constructors
        }


        void push(int arg) 
        {
            if (isFull()) 
            {
                throw overflow_error("Cannot push! Stack is full.");
            }

            data_ptr[top] = arg;
            top += 1;
            
        }


        int pop() 
        {
            if (isEmpty()) 
            {
                throw underflow_error("Cannot pop! Stack is already empty.");
            }

            top -= 1;
            int retVal = data_ptr[top];
            data_ptr[top] = 0;
            return retVal;

        }

};




#endif