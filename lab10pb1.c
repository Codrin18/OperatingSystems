#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char input_str[30];

	printf("Enter your input: ");
	fgets(input_str,30,stdin);

	int fd1[2]; //  1-2 diagram 
	pipe(fd1); // create pipe descriptors
	int process1 = fork(); // create first process
	
	// Child process 
	if (process1 > 0)
	{
		char new_str[30];
		
		read(fd1[0],&new_str,30);
		
		printf("Child process 1: %s\n", new_str);

		return 0;
	}

	int fd2[2]; // 1 - 3 diagram
	pipe(fd2); // create pipe descriptos
	int process2 = fork(); // create second process

	// Child process
	if (process2 > 0)
	{
		char new_str[30];
		
		read(fd2[0],&new_str,30);

		int index = 0;
		while(new_str[index] != '\0')
		{
			if ( new_str[index] >= 'a' && new_str[index] <= 'z')
				new_str[index] -= 32;
			++index;
		}

		printf("Child process 2: %s\n", new_str);

		return 0;
	}

	//Parent processes
	if (process1 == 0 && process2 == 0)
	{
		char letters[30];
		char numbers[30];
		int numbers_index = 0;
		int letters_index = 0;

		int index = 0;
		while(input_str[index] != '\0')
		{
			if ((input_str[index] >= 'a' && input_str[index] <= 'z') || 				(input_str[index] >= 'A' && input_str[index] <= 'Z'))
			{
				letters[letters_index++] = input_str[index];
			}
			else if (input_str[index] >= '0' && input_str[index] <= '9')
			{
				numbers[numbers_index++] = input_str[index];
			}
			++index;
		}
		numbers[numbers_index] = '\0';
		letters[letters_index] = '\0';
		write(fd1[1], &numbers, 30);
		write(fd2[1], &letters, 30);
	}
	else
	{
		printf("There was a problem with creating the process! ");
	}

	return 0;
}
