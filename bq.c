/**
 * Program for check Balanced Parenthesis or not .
 * Compilation : gcc bp.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 09/8/2021
 * Assignment_4 - Stacks and Queues.
 *
 */
 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Program for balanced parenthesis
// using previous created stack
int top=-1; // initalize marker of stack
bool initalize=false; // for checking stack initalize or not
int capacity=3; // by default making capacity 3
char *stack; // creating dynamic stack
// function to initalize stack with intial capacity
void initalize_stack() 
{
    // using malloc function for Dynamic Memory Allocation
    stack=(char*)malloc(capacity * sizeof(char)); // create stack of size capacity
}
// function to resize stack
void resize_stack()
{
    // first double the capacity
    capacity = capacity * 2;
    // create new stack of double size as of previous 
    char *new_stack;
    // using malloc function for Dynamic Memory Allocation
    new_stack=(char*)malloc(capacity * sizeof(int));
    // first simply push all element of stack into new_stack
    for(int i=0;i<capacity/2;i++)
    new_stack[i]=stack[i];
    // assign stack to new stack
    stack=new_stack;
}
// function to perform push operation
void push(char x)
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
    //printf("Element %c push into stack\n",x);
    stack[top]=x;
}
// function to return top element of stack
char peek()
{
    // return top element of stack
    return stack[top];
}
// function to return pop element and remove it from stack
char pop()
{
    // since stack is empty then no pop operation perform
    if(top==-1)
    {
        printf("under_flow_condition");
        return -1;
    }
    // store pop element
    char x=stack[top];
    //printf("%c pop out \n",x);
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
// input string as parameter
void solve(char *ch)
{
    // calculate size of string
    int size=0;
    while(*(ch + size)!='\0')
    size++;
    
    for(int i=0;i<size;i++)
    {
        // if stack is empty then push character into it.
        if(is_empty())
        {
            push(*(ch + i));
        }
        // if there is an opening parenthesis push into stack.
        else if(*(ch + i)=='{' || *(ch + i)=='(' || *(ch + i)=='[' )
        {
            push(*(ch + i));
        }
        else
        {
            // if there is a closing parenthesis
            if(*(ch + i)=='}')
            {
                // if peek element is opposite parenthesis
                if(peek()=='{')
                pop();
                else
                {
                    // peek element is not opposite parenthesis 
                    printf("False");
                    return;
                }
            }
            // if there is a closing parenthesis
            if(*(ch + i)==']')
            {
                // if peek element is opposite parenthesis
                if(peek()=='[')
                pop();
                else
                {
                    // peek element is not opposite parenthesis
                    printf("False");
                    return;
                }
            }
            // if there is a closing parenthesis
            if(*(ch + i)==')')
            {
                // if peek element is opposite parenthesis
                if(peek()=='(')
                pop();
                else
                {
                    // peek element is not opposite parenthesis
                    printf("False");
                    return;
                }
            }
        }
    }
    // if stack become empty then balanced parenthesis
    if(is_empty())
        printf("True");
    else
        printf("False");
  
// special cases :- '['

}
int main() {
    printf("Enter Input string : ");
    char str[100];
    // input string
    scanf("%s",str);
    // calling function solve with parameter string
    solve(str);
    printf("\n");
    return 0;
}


