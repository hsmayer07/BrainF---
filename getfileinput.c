#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

program* getfileinput(FILE *inFile) {
	if(inFile == NULL) {
		return NULL;
	}
	
	//start with 2^0
	instruction *inputSource = malloc(1 * sizeof(instruction));
	int memAmt = 1;
	int ptr = 0;
	char temp;
	while((temp = fgetc(inFile)) != EOF) {
		//valid characters
		if(temp == '+' || temp == '-' || temp == '>' || temp == '<' || temp == '.' || temp == ',' || temp == '[' || temp == ']') {
			if(ptr == memAmt) {
				memAmt *= 2;
				inputSource = realloc(inputSource, memAmt * sizeof(instruction));
			}
			if(temp == '+') {
				inputSource[ptr] = INC;
			} else if(temp == '-') {
				inputSource[ptr] = DEC;
			} else if (temp == '>') {
				inputSource[ptr] = SR;
			} else if(temp == '<') {
				inputSource[ptr] = SL;
			} else if(temp == '.') {
				inputSource[ptr] = IN;
			} else if (temp == ',') {
				inputSource[ptr] = OUT;
			} else if(temp == '[') {
				inputSource[ptr] = BB; 
			} else if (temp == ']') {
				inputSource[ptr] = BR;
			}
			ptr++;
		}
	}

	program *result = malloc(sizeof(program));
	result -> instructions = inputSource;
	result -> size = ptr;
	return result;
}
