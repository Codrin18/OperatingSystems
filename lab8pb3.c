#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countWords(char *str)
{
	int state = 0; 
    	int wc = 0;  // word count 
  
    // Scan all characters one by one 
    while (*str) 
    { 
        // If next character is a separator, set the  
        // state as 0 
        if (*str == ' ' || *str == '\n' || *str == '\t') 
            state = 0; 
  
        // If next character is not a word separator and  
        // state is 0, then set the state as 1 and  
        // increment word count 
        else if (state == 0) 
        { 
            state = 1; 
            ++wc; 
        } 
  
        // Move to next character 
        ++str; 
    } 
  
    return wc; 
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
		printf("There are %d words in line: %s", countWords(line), line);
	}

	fclose(file);

	return 0;
}
