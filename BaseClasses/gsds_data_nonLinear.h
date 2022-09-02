#ifndef GSDS_DATA_NONLINEAR
#define GSDS_DATA_NONLINEAR

#include "gsds_data_structure.h"

using namespace std;

//using namespace std;

class gsds_data_nonlinear: public gsds_data_structure 
{

    public:
        int *data_ptr;

        // class constructor
        gsds_data_nonlinear(int len) : gsds_data_structure(len)
        {
            length = len;
            data_ptr = new int[length];
            fill(data_ptr, data_ptr+length, 0);
        }


        ~gsds_data_nonlinear() 
        {
            delete [] data_ptr;
        }


        void push(int val) 
        {
            throw not_implemented();
        }


        int pop() 
        {
            throw not_implemented();
        }


        void print() 
        {

        }
};


#endif

