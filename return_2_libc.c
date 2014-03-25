#include <stdio.h>
#include <string.h>

void func(const char *str) {
	char buf[4];
	strcpy(buf,str);
	printf("you entered [%s]\n",buf);
}

int main(int argc, char *argv[]) {
	if(argc != 2) {
		printf("Need an argument\n");
		return 0;
	}
	func(argv[1]);
	return 0;
}
