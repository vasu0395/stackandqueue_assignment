 * Program to implement Stack using Queues on Leetcode.
 * Compilation : gcc suq.c
 * Execution : ./a.out
 *
 * @Vasu ( 1910990395 )  , 15/8/2021
 * Ques 3. Assignment_4 - Stacks and Queues.
 *
 */

typedef struct {
int data;
} MyStack;

int size;
int front;
int end;
int size1;
int front1;
int end1;
/** Initialize your data structure here. */

MyStack* myStackCreate()
{
    // creating queue using dynamic memory allocation
     MyStack *queue = (MyStack *)malloc(1000 * sizeof(MyStack));
     size = 0;
     front = 0;
     end = 0;
     return queue;
}
// creating newqueue
MyStack* mynewStackCreate()
{
    // creating queue using dynamic memory allocation
     MyStack *queue = (MyStack *)malloc(1000 * sizeof(MyStack));
     size1 = 0;
     front1 = 0;
     end1 = 0;
     return queue;
}

/** Push element x onto stack. */
void myStackPush(MyStack* queue, int x)
{

     int sz=size;

     // first copy element of queue into new created queue
     MyStack* que=mynewStackCreate();
     int temp=0;
     for(int i=front;i<=end-1;i++)
     {
         que[temp++].data=queue[i].data;
     }

    myStackCreate();
    //putting the element 'x' as first element of original queue */
    queue[end++].data = x;
    for(int i=0;i<temp;i++)
    {
        queue[end++].data=que[i].data;
    }
    //increase size by 1
    size=sz+1;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* queue)
{
    // store top element
    int ele = queue[front].data;
    front++;
    // remove from queue and decrease size by 1
    size--;
    return ele;
}

/** Get the top element. */
int myStackTop(MyStack* queue)
{
    // return top
    return queue[front].data;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* queue)
{
    if(size==0)
        return true;
    return false;
}

void myStackFree(MyStack* queue)
{
    // using free function to free memory allocated
    free(queue);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/
~
