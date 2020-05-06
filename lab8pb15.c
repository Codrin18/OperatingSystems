#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Returns the number of letter in a string
int countWords(char *str)
{
	int count = 0;
    
  
    // Scan all characters one by one 
    while (*str) 
    { 
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) 
            ++count; // Count all the letters in the string
  
        // Move to next character 
        ++str; 
    } 
  
    return count; 
}

int main(int argc, char *argv[])
{
	if (argc != 2)
		return -1;
	
	FILE * file;
	char * line = NULL;
	size_t len = 0;
	size_t read;

	file = fopen(argv[1],"r");

	while((read = getline(&line, &len, file)) != -1)
	{
		printf("There are %d letters in line: %s", countWords(line), line);
	}

	fclose(file);

	return 0;
}
