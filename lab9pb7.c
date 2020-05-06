#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

int main()
{
	int n = 0; // initialize n
	printf("Enter the length of the array: ");
	scanf("%d",&n);
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		printf("Enter an element of the array: ");
		scanf("%d",&arr[i]);
	}
	int s = 0; // initialize s
	int x = 0; // initialize x
	for (int i = 0; i < n; ++i)
	{
		int process = fork(); // create the process
		if (process > 0)
		{
			s = s + arr[i] * arr[i] * arr[i]; // calculate the sum of the cube
			++x;	
		}
	}
	// verify if x is equal with
	if ( x == n) 
		printf("The sum of cubes of the numbers from the array is: %d\n", s);
	return 0;
}
