#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

//const char * const words[] = { "tomato", "waldo", "friday", "porcupine", "ocean", "baseball" };
char* target = "waldo";

int child_handler(FILE *fp);

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr,"Usage: %s <file>\n", argv[0]);
	}

	pid_t child = fork();

	if(child < 0)
	{
		perror("Could not fork\n");
		return(4);
	}
	else if(child) // Parent block. Child was created and returned a PID
	{
		// Wait until they can send us data
		// Open the file tow rite to
		// Write the data
	}
	else // Child block. Return from fork() was a zero.
	{
	// Open the file to read
	FILE* src = fopen(argv[1], "r");
	if(!src)
	{
		perror("Could not read file.");
		return(6);
	}
	child_handler(src);
		
		// Read the data
		
/*
		char buf[256];
		while(!feof(src))
		{
			fgets(buf, sizeof(buf), src);
			for(size_t n = 0; buf[n]; n++)
			{
				if( 0 == strncmp(target,&buf[n], strlen(target) ))
				{
					printf("Child found %s\n", target);
				}
			}
		}
*/

		
	}
}

int child_handler(FILE *fp)
{
	char buf[256];
	while(!feof(src))
	{
		char *idx = buf;
		while(*idx)
		{
			if( 0 == strncmp(target,idx, strlen(target) ))
			{
				printf("Child found %s\n", target);
			}
			idx++;
		}
	}
	// Scan for interesting words
	
	// Send it to parent

	fclose(src);
}