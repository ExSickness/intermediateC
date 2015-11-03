#include <stdio.h>
#include <errno.h>

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		fprintf(stderr,"Usage: %s <filename>\n>",argv[0]);
		return(2);
	}

	FILE *data; 
	data = fopen(argv[1], "r");

	if(!data)
	{
		//printf("%d\n" errno);

		perror("Could not open file");
		return(3);
	}

	char buf[24];
	while( fgets(buf, sizeof(buf), data) )
	{
		printf("%s",buf);
	}

	//TODO: Add check for file error
	while(ftell(data) != 1)
	{
		fseek(data, -2, SEEK_CUR);
		fgets(buf,2,data);
		printf("%s",buf);
	}
	fclose(data);

}