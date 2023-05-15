#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

program* getfileinput(FILE *inFile) {
	if(inFile == NULL) {
		return NULL;
	}
	
	//start with 2^0
	instruction *inputSource = malloc(1 * sizeof(instruction));
	int *forwardPtrs = malloc(sizeof(int));
	int memAmt = 1;
	int ptr = 0;
	char temp;
	Stackptr bbStack; 
	Stackptr brStack;
	bbStack.head = NULL;
	brStack.head = NULL;
	bbStack.size = 0;
	brStack.size = 0;

	while((temp = fgetc(inFile)) != EOF) {
		//valid characters
		if(temp == '+' || temp == '-' || temp == '>' || temp == '<' || temp == '.' || temp == ',' || temp == '[' || temp == ']') {
			if(ptr == memAmt) {
				memAmt *= 2;
				inputSource = realloc(inputSource, memAmt * sizeof(instruction));
			}
			if(temp == '+') {
				inputSource[ptr].opcode = INC;
			} else if(temp == '-') {
				inputSource[ptr].opcode = DEC;
			} else if (temp == '>') {
				inputSource[ptr].opcode = SR;
			} else if(temp == '<') {
				inputSource[ptr].opcode = SL;
			} else if(temp == '.') {
				inputSource[ptr].opcode = OUT;
			} else if (temp == ',') {
				inputSource[ptr].opcode = IN;
			} else if(temp == '[') {
				inputSource[ptr].opcode = BB; 
				push(ptr, &bbStack);
			} else if (temp == ']') {
				inputSource[ptr].opcode = BR;
				inputSource[ptr].operand = pop(&bbStack);
				inputSource[inputSource[ptr].operand].operand = ptr;
			}
			ptr++;
		}
	}

	if(brStack.size != 0) {
		fprintf(stderr, "Fatal Compile Error: Unbalanced brackets detected. \n");
		return NULL;
	}

	program *result = malloc(sizeof(program));
	result -> instructions = inputSource;
	result -> size = ptr;
	return result;
}
