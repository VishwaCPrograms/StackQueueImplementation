/* Name: Vishwa Venkateshwaran */

#include <stdio.h>
#include <stdlib.h>
#include "lab4.h"

Stack* newStack1() {
	Stack *Stack = malloc(sizeof(Stack));
	Stack1 *stack1 = malloc(sizeof(Stack1));
	if (Stack) {
		Stack->Stack = stack1;
		Stack->length = lengthS1;
		Stack->push = pushS1;
		Stack->pop = popS1;
		stack1->length = 0;
	}
	return Stack;
}

void pushS1(void* pointer, int data) {
	Stack1 *stack1 = (Stack1*) pointer;
	LLNode *newNode = malloc(sizeof(LLNode));
	if(stack1->firstNode) {
		newNode->next = stack1->firstNode;
	} else {
		stack1->lastNode = newNode;
	}
	stack1->firstNode = newNode;
	stack1->length++;
	newNode->data = data;
}

int popS1(void* pointer) {
	Stack1 *stack1 = (Stack1*) pointer;
	LLNode *returningNode = stack1->firstNode;
	int data = stack1->firstNode->data;
	free(returningNode);
	stack1->firstNode = stack1->firstNode->next;
	stack1->length--;
	return data;
}

int lengthS1(void* pointer) {
	Stack1 *stack1 = (Stack1*) pointer;
	return stack1->length;
}
