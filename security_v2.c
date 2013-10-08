#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "libstack.c"

void func(const char *arr) {
	char buffer[4];
	int *p = (int*)&buffer[0];
	p += 7;
	push(*p);

	printf("%p\n", p);
	strcpy(buffer,arr);
//	printf("you entered %s\n", arr);

//	printf("your top of stack is %d\n", top->Data);
	int a = top->Data;
	int b = p;
	if(a != b) {
		printf("You just experienced a buffer overflow ATTACK !!! :D\n");
		exit(0);
	}
}

int main(int argc, char const *argv[])
{
	int x = 0;
	func(argv[1]);
	x = 1;
	if(x == 0)
		printf("Congrats you exploited it. x = %d\n", x);
	return 0;
}