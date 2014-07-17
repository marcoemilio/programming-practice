/*!
*	@author Marco Emílio
*
*	@brief Header general stack.
*
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct StackElement{     
    void* data;     
    struct StackElement* next;     
}StackElement;

typedef struct Stack{
	StackElement* top;
}Stack;

StackElement* create_element_stack(void* data, StackElement* next);

void push(Stack* __stack, void* data);

void* pop(Stack* __stack);

Stack* create_stack(void* data);
	
void clear_stack(Stack* __stack);

int check_stack(Stack* __stack);