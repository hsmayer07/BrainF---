#include <stdio.h>
#include <stdlib.h>
#include "brain.h"

#define LENGTH 30000

unsigned char tape[LENGTH];
int ptr = 0;
int pc = 0;
int max = 1003;
int mag = 0;


void interpreter(program *executable) {
	int size = executable -> size;

	for(int i = 0; i < LENGTH; i++) {
		tape[i] = 0;
	}

	Opcode_t currentInstruction;
	char wentBack = (char) 0;
	while(pc < size){
		currentInstruction = executable -> instructions[pc].opcode;
		//printf("PC = %d. Instruction = %d. ptr =  %d \n", pc, currentInstruction, ptr);
		switch(currentInstruction) {
			case INC: 
				tape[ptr] ++;
				break;
			case DEC:
				tape[ptr] --;
				break;
			case SR:
				ptr++;
				//ptr = ptr % 30000;
				break;
			case SL:
				ptr--;
				//ptr = ptr % 30000;
				break;
			case OUT:
				fputc(tape[ptr], stdout);
				break;
			case IN:
				tape[ptr] = (char) fgetc(stdin);
				break;
			case BB:
				if(tape[ptr] == 0) {
					pc = executable -> instructions[pc].operand;
				}
				break;
			case BR:
				if(tape[ptr] != 0) {
					pc = executable -> instructions[pc].operand;
					wentBack = (char) 1;
				}
				break;
			default:
				fprintf(stderr, "Illegal Instruction Exception: Illegal instructio found at %d. Terminating. \n", pc);
				break;
		}
		if(!wentBack) {
			pc++;
		} else {
			wentBack = (char) 0;
		}
		mag++;
	}
	printf("Finished. Executed %d instructions in total \n", mag);

}
