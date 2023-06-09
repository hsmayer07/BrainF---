#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

int main(int argc, char *argv[]) {
	if(argc != 2) {
		fprintf(stderr, "Incorrect number of arguments supplied. Try again! \n");
		return 1;
	}

	FILE *source = fopen(argv[1], "r");
	if(source == NULL) {
		fprintf(stderr, "Bad file name supplied. Try again!\n");
		return 1;
	}

	program *executable = getfileinput(source); 
	printf("Size = %d \n", executable -> size);
	interpreter(executable);
} 
