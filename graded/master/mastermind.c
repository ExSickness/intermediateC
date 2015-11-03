#include <stdio.h>
#include <stdlib.h>

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

	printf("Target is: ");
	for (int i = 0; i < 4; i++)
	{
		target[i] = rand() % 10;
		printf("%d",target[i]);
	}
	printf("\n");

	userInput(guess);

	int red=0,white=0;
	// Red loop
	for(int i = 0; i < 4; i++)
	{
		
		if(target[i] == guess[i])
		{
			printf("Red found!\n");
			red +=1;
		}
		
	}
	// White loop
	for(int i = 0; i < 4;i++)       // 0,1,2,3
	{
		if(target[i] == guess[i])
		{
			continue;
		}
		for(int p = 3; p >= 0; p--) // 3,2,1,0
		{
			if(guess[i] == target[p])
			{
				white +=1;
				printf("White found!\n");
			}
		}
	}

	printf("%d red, %d white\n",red,white);




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