#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Deletes all occurences of a word in a string 
void removeAll(char * str, char * toRemove)
{
    int i, j, stringLen, toRemoveLen;
    int found;

    stringLen   = strlen(str);      // Length of string
    toRemoveLen = strlen(toRemove); // Length of word to remove


    for(i=0; i <= stringLen - toRemoveLen; i++)
    {
        /* Match word with string */
        found = 1;
        for(j=0; j<toRemoveLen; j++)
        {
            if(str[i + j] != toRemove[j])
            {
                found = 0;
                break;
            }
        }

        /* If it is not a word */
        if(str[i + j] != ' ' && str[i + j] != '\t' && str[i + j] != '\n' && str[i + j] != '\0') 
        {
            found = 0;
        }

        /*
         * If word is found then shift all characters to left
         * and decrement the string length
         */
        if(found == 1)
        {
            for(j=i; j<=stringLen - toRemoveLen; j++)
            {
                str[j] = str[j + toRemoveLen];
            }

            stringLen = stringLen - toRemoveLen;

            // We will match next occurrence of word from current index.
            i--;
        }
    }
}

int main(int argc, char *argv[])
{
	
	FILE * file;
	FILE * file_out;
	char * line = NULL;
	size_t len = 0;
	size_t read;
	
	char *del = argv[1];
	file = fopen(argv[2],"r");
	file_out = fopen("output.txt","w");
	
	while((read = getline(&line, &len, file)) != -1)
	{
		removeAll(line,del);
		fprintf(file_out, "%s",line);
	}

	fclose(file);
	fclose(file_out);
	return 0;
}
