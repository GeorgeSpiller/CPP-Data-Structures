#ifndef GSDS_DATA_NONLINEAR
#define GSDS_DATA_NONLINEAR

#include "gsds_data_structure.h"

using namespace std;

class gsds_data_nonlinear: public gsds_data_structure 
{

    public:

        int *data_ptr;


        // used for dynamic data structures
        gsds_data_nonlinear() : gsds_data_structure(0)
        {
            length = 0;
            data_ptr = nullptr; // not used
        }


        // used for static data structures
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
            throw not_implemented();
        }

        void print() 
        {
            if (data_ptr != nullptr) 
            {
                string print_arr = "";
                for(int i = 0; i < length; i++) 
                {
                    print_arr += to_string(data_ptr[i]);    // std::to_string()
                    print_arr += ", ";
                }
                cout << print_arr << endl;
            }
        }


    private:
    
        bool isFull() 
        {
            throw not_implemented();
        } 


        bool isEmpty() 
        {
            throw not_implemented();
        } 
};



#endif

