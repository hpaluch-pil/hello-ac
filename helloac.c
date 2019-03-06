/*
 * helloac.c - hello autoconf - main executable
 */

#include <stdlib.h>
#include <stdio.h>

#include "fooac.h"
int main(int argc, char **argv){

	printf("Hello from %s:%u\n", __FILE__, __LINE__);
	printf("Program '%s' version: '%s'\n\n", PACKAGE, VERSION);

	fooac_func1(123);
	puts("");
	fooac_func2(456789);

	return EXIT_SUCCESS;
}
