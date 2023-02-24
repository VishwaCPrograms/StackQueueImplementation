/* Name: Vishwa Venkateshwaran */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab4.h"

void changeArrSize(void* pointer, int size) {
	int i = 0;
	int *p = malloc(size*sizeof(int));
	Stack2 *stack2 = (Stack2*) pointer;
	for(i = 0; i < stack2->length; i++) {
		*(p+i) = *((stack2->entries + i));
	}
	free(stack2->entries);
	stack2->entries = p;
}

Stack* newStack2() {
	Stack *Stack = malloc(sizeof(Stack));
	Stack2 *stack2 = malloc(sizeof(Stack2));
	if (Stack) {
		Stack->Stack = stack2;
		Stack->length = lengthS2;
		Stack->push = pushS2;
		Stack->pop = popS2;
		stack2->arrSize = MIN_SIZE;
		stack2->length = 0;
		stack2->entries = malloc(stack2->arrSize*sizeof(int));
	}
	return Stack;
}

void pushS2(void* pointer, int data) {
	Stack2 *stack2 = (Stack2*) pointer;
	*(stack2->entries + stack2->length) = data;
	stack2->length++;
	if (stack2->length == stack2->arrSize) {
		stack2->arrSize = 2*stack2->arrSize;
		changeArrSize(stack2, stack2->arrSize);
	}
}

int popS2(void* pointer) {
	Stack2 *stack2 = (Stack2*) pointer;
	int data = *(stack2->entries + stack2->length - 1);
	stack2->length--;
	if (stack2->length > MIN_SIZE) {
		if (stack2->length == 1/4*(stack2->arrSize)) {	
			stack2->arrSize = 1/2*stack2->arrSize;
			changeArrSize(stack2, stack2->arrSize);
		}
	}
	return data;
}

int lengthS2(void* pointer) {
	Stack2 *stack2 = (Stack2*) pointer;
	return stack2->length;	
}
