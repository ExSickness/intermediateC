#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 5

void userInput(char* input);
int game();

int main(void)
{
	game();

	return(0);
}


int game()
{
	int target[MAX];
	char guess[MAX];
	int count = 0,red=0,white=0;

	printf("Target is: ");
	srand(time(NULL));
	for (int i = 0; i < 4; i++)
	{
		
		target[i] = rand() % 10;
		//printf("%d",target[i]);
	}
	printf("\n");

	target[0] = 5;
	target[1] = 8;
	target[2] = 8;
	target[3] = 8;

	

	while(red != 4)
	{
		red=0;
		white=0;
		int skip[4] = {0};
		userInput(guess);

		// Red Loop, sets indexes to skip
		for(int i = 0; i < 4;i++)
		{
			if(target[i] == guess[i])
			{
				red +=1;
				skip[i] = 1;
			}
		}
		printf("%d",skip[0]);
		printf("%d",skip[1]);
		printf("%d",skip[2]);
		printf("%d\n",skip[3]);
		for(int p = 0; p <4; p++) // 3,2,1,0
		{
			if(skip[p])
				{
					continue;
				}

			for(int x = 0;x<4; x++)
			{
				if(skip[x])
				{
					continue;
				}
				if(guess[p] == target[x])
				{
					white +=1;
					printf("Found white.\n");
					skip[x] = 1;
					break;
				}
			}
		}
		count +=1;

		printf("%d - %d red, %d white\n",count,red,white);
		
	}
	printf("You've won in %d guesses.\n",count);


	return(0);
}



void userInput(char* user)
{
	printf("Guess a number: ");
	char buffer[MAX];
	fgets(user,MAX,stdin);

	for(int i = 0; i < 4; i++)
	{
		user[i] = user[i] - 48;
	}
	fgets(buffer,MAX,stdin);
}