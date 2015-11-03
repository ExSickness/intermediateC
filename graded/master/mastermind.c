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
		printf("%d",target[i]);
	}
	printf("\n");

	while(red != 4)
	{
		red=0;
		white=0;
		userInput(guess);

		
		// Loop
		for(int i = 0; i < 4;i++)       // 0,1,2,3
		{
			if(target[i] == guess[i])
			{
				printf("Red found!\n");
				red +=1;
				printf("Skippping. i : %d ",i);
				continue;
			}
			for(int p = 3; p >= 0; p--) // 3,2,1,0
			{
				//printf("i: %d    p: %d\n",i,p);
				if(guess[i] == target[p])
				{
					white +=1;
					printf("White found!\n");
					break;
				}
			}
		}

		printf("%d red, %d white, guess count: %d\n",red,white,count);
		count +=1;
	}
	printf("You've won in %d guesses.",count);


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