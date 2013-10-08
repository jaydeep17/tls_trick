#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libstack.c"

void func(const char *arr) {
	char buffer[4];
	strcpy(buffer,arr);
	printf("you entered %s\n", arr);
}

int main(int argc, char const *argv[])
{
	// int x = 0;
	// func(argv[1]);
	// x = 1;
	// if(x == 0)
	// 	printf("Congrats you exploited it. x = %d\n", x);
	push(1);
	push(2);
	push(3);
	popStack();
	push(4);
	display();
	return 0;
}