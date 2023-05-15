brain: getfileinput.o main.o llstack.o interpreter.o brain.h
	gcc getfileinput.o main.o llstack.o interpreter.o -o brain

main.o: main.c brain.h
	gcc -c main.c

getfileinput.o: getfileinput.c brain.h
	gcc -c getfileinput.c

llstack.o: llstack.c brain.h
	gcc -c llstack.c

interpreter.o: interpreter.c brain.h
	gcc -c interpreter.c
