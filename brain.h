typedef enum {
	INC, DEC, SR, SL, OUT, IN, BB, BR
} Opcode_t;

typedef struct Instruction {
	Opcode_t opcode;
	int operand;
} instruction;

typedef struct Program_t {
	instruction *instructions;
	int size;
} program;

typedef struct Stack {
	int value;
	struct Stack *prev;
	struct Stack *next;
} Stack_t;

typedef struct StackP {
	Stack_t *head;
	int size; 
} Stackptr; 

program* getfileinput(FILE *);
void interpreter(program *);
void push(int, Stackptr *);
int pop(Stackptr *);
int peek(Stack_t *);
