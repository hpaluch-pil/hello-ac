/*
 * fooac.c - librafy fooac (foo autoconf) source file
 */

#include <stdio.h>
#include <stdlib.h>

void fooac_func1(int p1){
	printf("Hello from %s:%u\n", __FILE__, __LINE__);
	printf("Parameter p1=%d\n",p1);
	printf("New function fix (full compatible)\n");
}

