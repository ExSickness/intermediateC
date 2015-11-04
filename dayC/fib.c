#include <stdio.h>
#include <stdlib.h>

int fib(int num)
{
	if(num < 2)
	{
		return num;
	}

	return fib(num -1) + fib(num -2);
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Usage: %s <number>\n", argv[0]);
		return(3);
	}

	char *err;
	long value = strtol(argv[1],&err,10);

	if(*err)
	{
		fprintf(stderr,"Arg '%s' not an integer\n",argv[1]);
		return(4);
	}

	printf("%d\n", fib(value));
}




/*
	char *err;
	int temp;
	// var        strtoconvert     error-check                      basetoconverto
	temp = strtol(argv[1],             &err                            ,10)
*/