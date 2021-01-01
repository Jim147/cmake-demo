#include "stdio.h"

extern void prnstr(char * s);

int main()
{
	prnstr("Hello world!\n");
	printf("Hello world 2!\n");
	return 0;
}

