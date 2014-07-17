/*!
*	@author Marco Emílio
*
*	@brief Implementation of a general stack.
*
*/

#include "stack.h"

StackElement* create_element_stack(void* data, StackElement* next)
{
	StackElement* element = (StackElement*)calloc(1, sizeof(StackElement));
	
	if(element)
	{
		element->data = data;
		element->next = next;
	}
	return (element);
}

void push(Stack* __stack, void* data)
{
	if(__stack)
	{
		__stack->top = create_element_stack(data, __stack->top);
	}
}

void* pop(Stack* __stack)
{
	if(!__stack)
		return NULL;
	if(!__stack->top)
		return NULL;
		
	StackElement* aux = __stack->top;
	__stack->top = aux->next;

	return(aux->data);
}

Stack* create_stack(void* data)
{
	Stack* __stack = (Stack*)malloc(sizeof(Stack));
	if(__stack)
	{
		if(data)
		{
			push(__stack, data);
		}
		else
		{
			__stack->top = NULL;
		}
	}
	
	return(__stack);
}
	
void clear_stack(Stack* __stack)
{
	for(;__stack->top;)
		free(pop(__stack));
		
	__stack->top = NULL;
}

int check_stack(Stack* __stack)
{
	return __stack->top != NULL;
}
