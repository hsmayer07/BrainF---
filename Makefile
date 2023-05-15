brain: compiler.o main.o llstack.o interpreter.o brain.h
	gcc compiler.o main.o llstack.o interpreter.o -o brain

main.o: main.c brain.h
	gcc -c main.c

compiler.o: compiler.c brain.h
	gcc -c compiler.c

llstack.o: llstack.c brain.h
	gcc -c llstack.c

interpreter.o: interpreter.c brain.h
	gcc -c interpreter.c
