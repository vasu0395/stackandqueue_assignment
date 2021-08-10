/**
 * Program that converts an arithmetic expression from infix notation to postfix notation.
 * Compilation : gcc Ip.c
 * Execution : ./a.out
 *
 * @vasu ( 1910990395 )  , 09/8/2021
 * Assignment_4 - Stacks and Queues.
 * Resource used :- GFG (for Precedence handling)
 */
 
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// Program for infixToPostfix conversion
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
    new_stack=(char*)malloc(capacity * sizeof(char));
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
    //printf("Element %d push into stack\n",x);
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
int precedence(char ch) {
    // since precedence of '+' & '-' is same
    if(ch == '+' || ch == '-')
	return 1;
    // since precedence of '*' & '/' is same
    else if(ch == '*' || ch == '/')
	return 2;
    else
	return -1;
}
void infixToPostfix(char *s) {
    int size_input=0;
    // calculate input string size
    while(*(s + size_input)!='\0')
    size_input++;
    // temporary string
    char result[100];
    // for index control in result
    int low=0;
    
    for(int i = 0; i < size_input; i++) {
	char c = s[i];
		
	// if character is not an operator directly add it into result
	if((c >= '0' && c <= '9'))
		result[low++]=c;

	// ‘(‘, push it to the stack.
	else if(c == '(')
		push('(');

	// if ')' pop untill '('
	else if(c == ')') {
	// pop untill '('
	    while(peek() != '(')
		{
	            // adding directly to result
		    result[low++]=peek();
		    pop();
		}
	    pop();
	}

	//If an operator then placed according to precedence
	else {
	     while(!is_empty() && precedence(s[i]) <= precedence(peek())) {
	         // adding to result
		 result[low++]=peek();
		 pop();
		}
	    push(c);
	}

	}

	// Pop all the remaining elements from the stack and adding to result
	while(!is_empty()) {
	    result[low++]=peek();
	    pop();
	}

      // string ending character
      result[low]='\0';
      // output result string
      printf("%s",result);
}

int main() {
    printf("Enter string : ");
    char exp[100];
    scanf("%s",exp);
    infixToPostfix(exp);
    printf("\n");
    return 0;
}



