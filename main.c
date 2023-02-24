/* Vishwa Venkateshwaran */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lab4.h"

void push(Stack *this, int x){
	this->push(this->Stack, x);
}

int pop(Stack *this){
	return this->pop(this->Stack);
}

int stackLength(Stack *this){
	return this->length(this->Stack);
}

void StackTest1(int type) {
	Stack* newStack = type == 1 ? newStack1() : newStack2();
	int i, removed, errors;
	clock_t start, end;
	double cpu_time_used;

	printf("\nStack test 1 type %d\n", type);
	start = clock();
	errors = 0;

	for(i = 0; i < NUM_ENTRIES; i++){
		push(newStack, i);
	}
	
	printf("Expected length after adding all the elements: %i, length recieved: %i\n", NUM_ENTRIES, stackLength(newStack));
	
	
	for(i = 0; i < NUM_ENTRIES; i++){
		removed = pop(newStack);
		if(removed != NUM_ENTRIES - i - 1){
			printf("Expected %i, removed %i\n", NUM_ENTRIES - i - 1, removed);
			errors++;
		}
	}

	printf("Expected length after removing all the elements: 0, length recieved: %i\n", stackLength(newStack));
	
	printf("Ended with %i errors\n", errors);

	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Took %f seconds\n", cpu_time_used);
	
}

void StackTest2(int type) {
	Stack* newStack = type == 1 ? newStack1() : newStack2();
	int i, removed, errors, j=1;
	clock_t start, end;
	double cpu_time_used;

	printf("\nStack test 2 type %d\n", type);
	start = clock();
	errors = 0;

	for(i = NUM_ENTRIES; i > 0; i--){
		push(newStack, i);
	}

	printf("Expected length after adding all the elements: %i, length recieved: %i\n", NUM_ENTRIES, stackLength(newStack));
	
	for(i = NUM_ENTRIES; i > 0; i--){
		removed = pop(newStack);
		if(removed != j){
			printf("Expected %i, removed %i\n", j, removed);
			errors++;
		}
		j++;
	}

	printf("Expected length after removing all the elements: 0, length recieved: %i\n", stackLength(newStack));
	
	printf("Ended with %i errors\n", errors);

	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;
	printf("Took %f seconds\n", cpu_time_used);
}

int main(int argc, char *argv[]) {

	StackTest1(1);
	StackTest1(2);

	StackTest2(1);
	StackTest2(2);
	
	return 0;
}
