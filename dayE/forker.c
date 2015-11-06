#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	pid_t child = fork();

	int x = 1;
	if(child < 0)
	{
		perror("Could not fork.\n");
		return(2);
	}
	else if(child)
	{
		while(x < 1000)
		{
			x *= 2;
		}
	}
	else
	{
		while(x < 1000)
		{
			x *=3;
		}
	}

	printf("x = %d\n",x);
}