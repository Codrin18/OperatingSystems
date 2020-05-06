#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <math.h>

// Return if a given number is prime or not
int isPrime(int n)
{
	if ( n <= 1 ) // if n = 0 or n = 1 then it is not prime
		return 0;
	if ( n == 2 ) // if n = 2 it is prime
		return 1;
	if ( n % 2 == 0 ) // if n is an even then it is not prime
		return 0;
	
	for(int i = 3; i <= sqrt(n); ++i)
	{
		if ( n % i == 0 )
			return 0;
	}

	return 1;
}

int main()
{
	int n = 0;

	printf("Enter the number: ");

	scanf("%d",&n);
	
	printf("The number is %d\n", n);	

	for (int i = 2; i <= n; ++i)
	{
		if ( isPrime(i))
		{
			int process = fork();
			
			if (process > 0)
			{
				if (n % i != 0) return 0;
				
				int order = 0;
				while(n % i == 0)
				{
					++order;
					n /= i;
				}
				
				printf("\t%d ^ %d\n", i, order);
				return 0;
			}
		}
	}
	
	return 0;	
}
