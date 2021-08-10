/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 * Compilation : gcc min_stc.c
 * Execution : ./a.out
 *
 * @Vasu ( 1910990395 )  , 09/8/2021
 * Assignment_4 - Stacks and Queues.
 *
 */

// typedef struct having two value data_store and get_min
typedef struct {
    int data_store;      
    int get_mini;
} MinStack;

// counter for stack
int size;
// creating minStackCreate i.e create own stack
MinStack* minStackCreate() {
    // using malloc function for dynamic allocation
    MinStack *my_stack = (MinStack *)malloc(1000000 * sizeof(MinStack)); 
    size = 0;
    // my_stack created
    return my_stack;
}

void minStackPush(MinStack* obj, int val) {
    obj[size].data_store = val;
    // if size is 0 i.e stack is empty so element that we push is minimum
    if(size==0)
    {
        obj[size].get_mini = val;
    }
    else
    {
        // compare element for updating minimum element
        obj[size].get_mini = val < minStackGetMin(obj) ? val : minStackGetMin(obj);
    }
    // increment size of stack
    size++;
}

void minStackPop(MinStack* obj) {
    // decrease size of stack
    size--;
}

int minStackTop(MinStack* obj) {
    // return top of stack
    return obj[size - 1].data_store;
}

int minStackGetMin(MinStack* obj) {
    // return minimum of stack
    return obj[size - 1].get_mini;
}

void minStackFree(MinStack* obj) {
    // free stack
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/
