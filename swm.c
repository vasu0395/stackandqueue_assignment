/**
 * Program for Sliding Window Maximum.
 * Compilation : swm.c
 * Execution : ./a.out
 *
 * @Vasu ( 1910990395 )  , 09/8/2021
 * Assignment_4 - Stacks and Queues.
 *
 */

int top=-1; // initalize marker of stack
bool initalize=false; // for checking stack initalize or not
int capacity=3; // by default making capacity 3
int *stack; // creating dynamic stack
// function to initalize stack with intial capacity
void initalize_stack() 
{
    // using malloc function for Dynamic Memory Allocation
    stack=(int*)malloc(capacity * sizeof(int)); // create stack of size capacity
}
// function to resize stack
void resize_stack()
{
    // first double the capacity
    capacity = capacity * 2;
    // create new stack of double size as of previous 
    int *new_stack;
    // using malloc function for Dynamic Memory Allocation
    new_stack=(int*)malloc(capacity * sizeof(int));
    // first simply push all element of stack into new_stack
    for(int i=0;i<capacity/2;i++)
    new_stack[i]=stack[i];
    // assign stack to new stack
    stack=new_stack;
}
// function to perform push operation
void push(int x)
{
    // if initalize not done before
    if(!initalize)
    {
        initalize_stack();
        initalize=true;
    }
    // first increase top count
    top++;
    // if we reached at end then increase size of stack by calling resize_stack().
    if(top==capacity-1)
    {
        resize_stack();
    }
    // push element at index top
    //printf("Element %d push into stack\n",x);
    stack[top]=x;
}
// function to return top element of stack
int peek()
{
    // return top element of stack
    return stack[top];
}
// function to return pop element and remove it from stack
int pop()
{
    // since stack is empty then no pop operation perform
    if(top==-1)
    {
        printf("under_flow_condition");
        return -1;
    }
    // store pop element
    int x=stack[top];
    // remove it from stack
    top--;
    // return it's value
    return x;
}
// function to check weather stack is empty or not
bool is_empty()
{
    // if we have empty stack then top always point to -1.
    if(top==-1)
    return true;
    
    return false;
}
// function to clear stack
void clear()
{
    capacity=2;
    top=-1;
    initalize_stack();
}
// function for maxSlidingWindow
int* maxSlidingWindow(int* nums, int n, int k, int* returnSize){
    // dynamic allocation of memory
    int *arr=(int *)malloc(sizeof(int) * n);
    // low to keep track of new size
    int low=0;
    
    for(int i=0;i<=n-k;i++)
    {  
        // visiting every window of size K and finding max using stack
        for(int j=i;j<=i+k-1;j++)
        {
            if(is_empty())
            {
                push(nums[j]);
            }
            else if(peek()<=nums[j])
                push(nums[j]);
        }
        // put result into newly created array
        arr[low]=peek();
        //clear stack
        clear();
        low++;
    }
    
    clear();
    // assign returnSize to low
    *returnSize=low;
    // return newly array
    return arr;
}
