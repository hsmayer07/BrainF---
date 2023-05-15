#include <stdio.h>
#include <stdlib.h>
#include "brain.h"


void push(int value, Stackptr *h) {
	Stack_t *head = h -> head;
	if(head == NULL) {
		head = malloc(sizeof(Stack_t));
		head -> prev = NULL;
		head -> value = value;
		head -> next = NULL;
		h -> head = head;
	} else {
		head -> next = malloc(sizeof(Stack_t));
		head -> next -> prev = head; 
		head -> next -> next = NULL;
		head -> next -> value = value;
		h -> head = head -> next;
	}
	h -> size ++;
}

int pop(Stackptr *h) {
	Stack_t *head = h -> head;
	if(head == NULL) {
		return -1;
	}
	int temp = head -> value;
	if(head -> prev != NULL) {
		Stack_t *tempS = head -> prev;
		free(head);
		h -> head = tempS;
		head -> next = NULL;
	} else {
		free(head);
		h -> head = NULL;
	}
	h -> size --;
	return temp;
}

int peek(Stack_t *head) {
	if(head != NULL) {
		return head -> value;
	}
	return -1;
}


