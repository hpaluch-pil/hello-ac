/*
 * fooac.c - librafy fooac (foo autoconf) source file
 */

/* should be first included file */
#include "helloac-config.h"

#include <stdio.h>
#include <stdlib.h>

void fooac_func1(int p1){
	printf("Hello from %s:%u function: %s()\n", __FILE__, __LINE__,__FUNCTION__);
	printf("Parameter p1=%d\n",p1);
	printf("New function fix (full compatible)\n");
}

void fooac_func2(int p1, int p2){
	printf("Hello from %s:%u function: %s()\n", __FILE__, __LINE__,__FUNCTION__);
	printf("Parameter p1=%d, p2=%d\n",p1,p2);
	printf("Incompatible API change in function\n");
}
