typedef enum {
	INC, DEC, SR, SL, OUT, IN, BB, BR
} instruction;

typedef struct Program_t {
	instruction *instructions;
	int size;
	int *openPtrs;
	int *closePtrs;
} program;

typedef struct Stack {
	int value;
	struct Stack *prev;
	struct Stack *next;
} Stack_t;


program* getfileinput(FILE *);
void interpreter(program *);
void push(int);
int pop();
int peek();
int getSize();
