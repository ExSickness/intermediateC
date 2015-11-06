#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int ret = system("ls");

	printf("systemic reg = %d\n",ret);
}