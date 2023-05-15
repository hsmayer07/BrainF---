#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

Stack_t *head = NULL;
int size = 0;

void push(int value) {
	//printf("Called to PUSH!!\n");
	if(head == NULL) {
		head = malloc(sizeof(Stack_t));
		head -> prev = NULL;
		head -> value = value;
		head -> next = NULL;
	} else {
		head -> next = malloc(sizeof(Stack_t));
		head -> next -> prev = head; 
		head -> next -> next = NULL;
		head -> next -> value = value;
		head = head -> next;
	}
	size++;
}

int pop() {
	//printf("Called to POP!!\n");
	if(head == NULL) {
		return -1;
	}
	int temp = head -> value;
	if(head -> prev != NULL) {
		Stack_t *tempS = head -> prev;
		free(head);
		head = tempS;
		head -> next = NULL;
	} else {
		free(head);
		head = NULL;
	}
	size--;
	return temp;
}

int peek() {
	if(head != NULL) {
		return head -> value;
	}
	return -1;
}

int getSize() {
	return size;
}

