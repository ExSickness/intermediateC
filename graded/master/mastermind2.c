#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 6

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
		printf("%d",target[i]);
	}
	printf("\n");

/*
	target[0] = 7;
	target[1] = 3;
	target[2] = 4;
	target[3] = 3;

	printf("%d",target[0]);
	printf("%d",target[1]);
	printf("%d",target[2]);
	printf("%d\n",target[3]);
*/

	while(red != 4)
	{
		red=0;
		white=0;
		int skip[4] = {0};
		int whiteSkip[4] = {0};
		userInput(guess);

		// Red Loop, sets indexes to skip
		for(int i = 0; i < 4;i++)
		{
			if(target[i] == guess[i])
			{
				red +=1;
				skip[i] = 1;
				whiteSkip[i] = 1;
			}
		}
		printf("%d",skip[0]);
		printf("%d",skip[1]);
		printf("%d",skip[2]);
		printf("%d\n",skip[3]);
		for(int p = 0; p <4; p++) // 3,2,1,0
		{
			//printf("\nBLAHBLAH P IS: %d\n",p);
			if(skip[p])
				{
					//printf("Continuing. p is: %d\n",p);
					whiteSkip[p] = 1;
					continue;
				}

			for(int x = 0;x<4; x++)
			{
				//printf("XXXXXX: %d\n",x);
				if((whiteSkip[x]) || (skip[p]))
				{
					//printf("Skipping loop index %d\n",x);
					continue;
				}
				else if(guess[p] == target[x])
				{
					white +=1;
					//printf("Found white. %d and %d\n",guess[p],target[x]);
					whiteSkip[x] = 1;
					break;
				}
			}
		}
		count +=1;

		printf("%d red, %d white\n",red,white);
		printf("=======================================\n");
		
	}
	printf("You've won in %d guesses.\n",count);

	return(0);
}



void userInput(char* user)
{
	printf("Guess a number: ");
	fgets(user,MAX,stdin);

	for(int i = 0; i < 4; i++)
	{
		user[i] = user[i] - 48;
	}
}