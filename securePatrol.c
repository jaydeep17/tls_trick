#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackLib.c"

__thread struct Stack *ptr;

void func(const char *msg) {
	char buffer[10];
	
	/*
	 * Stack Patrol prologue
	 */
	int *securePointer = &buffer;
	securePointer = (char*)securePointer + 10 /* size of buffer */ + 20 /* by doing this securePointer points to RET */;
	Stack_Push(ptr,*securePointer);

	/*
	 * Function code
	 */
	printf("sp = %p\n", securePointer);
	strcpy(buffer,msg);
	printf("garbage\n");


	/*
	 * Stack Patrol epilogue
	 */
	int ret = Stack_Pop(ptr);
	int secValue = (*securePointer);
	if(ret != secValue) {
		printf("You are a victim of buffer overflow\n");
		exit(0);
	}
}

int main(int argc, char const *argv[]) {
	/*
	 * Code to run when program starts
	 */
	if(ptr == 0) {
        ptr = malloc(sizeof *ptr);
    }
	Stack_Init(ptr);


	/*
	 * program code
	 */
	if(argc < 2) {
		printf("an argument is required to run it\n");
		return 0;
	}
	func(argv[1]);
	return 0;
}