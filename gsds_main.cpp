#include <iostream>
#include <assert.h>

#include "Linear_DataStructures\gsds_stack.h"
#include "Linear_DataStructures\gsds_queue.h"
#include "NonLinear_DataStructures\gsds_LinkedList.h"

using namespace std;


void test_stack() 
{
    cout << "Testing Stack...." << endl;
    gsds_stack stack_default = gsds_stack(10);
    gsds_stack stack_overflow = gsds_stack(2);
    gsds_stack stack_underflow = gsds_stack(2);
    int poped_value;

    // test push and pop
    stack_default.push(8);
    stack_default.push(600);
    stack_default.push(420);

    assert(stack_default.pop() == 420);
    assert(stack_default.pop() == 600);
    assert(stack_default.pop() == 8);

    // test overflow
    assert(stack_overflow.length == 2);
    stack_overflow.push(1);
    stack_overflow.push(1);
    try 
    {
        stack_overflow.push(1);
        assert(false);
    } catch (overflow_error) 
    {
        assert(true);
    }

    // test underflow
    try 
    {
        stack_underflow.pop();
        assert(false);
    } catch (underflow_error) 
    {
        assert(true);
    }

    cout << "Tests Complete!" << endl;
}


void test_queue() 
{
    cout << "Testing Queue..." << endl;
    gsds_queue queue_default = gsds_queue(10);
    gsds_queue queue_overflow = gsds_queue(2);
    gsds_queue queue_underflow = gsds_queue(2);
    int poped_value;

    // test push and pop
    queue_default.push(8);
    queue_default.push(600);
    queue_default.push(420);
    
    assert(queue_default.pop() == 8);
    assert(queue_default.pop() == 600);
    assert(queue_default.pop() == 420);

    // test overflow
    assert(queue_overflow.length == 2);
    queue_overflow.push(1);
    queue_overflow.push(1);
    try 
    {
        queue_overflow.push(1);
        assert(false);
    } catch (overflow_error) 
    {
        assert(true);
    }

    // test underflow
    try 
    {
        queue_underflow.pop();
        assert(false);
    } catch (underflow_error) 
    {
        assert(true);
    }
    cout << "Tests Complete!" << endl;
}


// Main entry point to the program.
int main() {

    // test_stack();
    // test_queue();
    gsds_linkedList llist = gsds_linkedList();
    llist.append(420);
    llist.print();
    llist.append(421);
    llist.print();
    llist.append(422);
    llist.print();

}