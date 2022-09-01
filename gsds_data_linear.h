#ifndef GSDS_DATA_LINEAR
#define GSDS_DATA_LINEAR

#include <stdexcept>
#include "gsds_data_structure.h"

using namespace std;

//using namespace std;

class gsds_data_linear: public gsds_data_structure 
{

    public:
        int *data_ptr;

        // class constructor
        gsds_data_linear(int len) : gsds_data_structure(len)
        {
            length = len;
            data_ptr = new int[length];
            fill(data_ptr, data_ptr+length, 0);
        }


        ~gsds_data_linear() 
        {
            delete [] data_ptr;
        }


        void push(int val) 
        {
            throw out_of_range("Not implemented yet.");
        }


        int pop() 
        {
             throw out_of_range("Not implemented yet.");
        }


        void print() 
        {
            string print_arr = "";
            for(int i = 0; i < length; i++) 
            {
                print_arr += to_string(data_ptr[i]);    // std::to_string()
                print_arr += ", ";
            }
            cout << print_arr << endl;
        }
};


#endif

