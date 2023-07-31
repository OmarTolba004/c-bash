#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void gettingTheCommand(char *input, char **command, char *commandSize);

void gettingTheRestOfCommand(char *input, char **restOfCommand, char commandSize, char *restOfCommandSize);

int main(void)
{
    char input[BUFFER_SIZE] ;
    char commandSize;
    char restOfCommandSize;
    char *command;
    char *restOfCommand;

    while (1)
    {
        printf("Ready Ya bash$");

        /* Reading input from user*/
        /* Important Note: 
         * in fgets, If a newline is read, it is stored  into the buffer.  A terminating null byte ('\0') is stored after the last character in
         * the buffer. so to check the end of 
        */
        fgets(input, sizeof(input), stdin);
        gettingTheCommand(input, &command, &commandSize);
        gettingTheRestOfCommand(input, &restOfCommand, commandSize, &restOfCommandSize);

        if (strcmp(command, "echo") == 0)
        {
            printf("%s\n", restOfCommand);
        }
        else if (strcmp(command, "exit") == 0)
        {
            exit(0);
        }
        else
        {
            printf("Command is not found\n");
        }
    }

    return 0;
}

void gettingTheCommand(char *input, char **command, char *commandSize)
{
    /* Calculating the command size*/
    int i = 0; // index used to interate over input string
    while (input[i] != 32 && input[i]!=10) // 10 is the ascii of new line
        i++; // 32 is the ascii value of space
    *commandSize = i;
    *command = (char *)malloc(sizeof(char) * (*commandSize));

    /*assigning command to commandVar*/
    for (i = 0; i < *commandSize; i++)
    {
        (*command)[i] = input[i];
    }
    (*command)[i] = '\0'; // adding null charachter
}

void gettingTheRestOfCommand(char *input, char **restOfCommand, char commandSize, char *restOfCommandSize)
{
    int i = commandSize;
    while (input[i] != 10 && input[i]!= '\0') // 10 is the ascii of new line
        i++;
    char totalCommandSize = i;
    *restOfCommandSize = i - commandSize;
    *restOfCommand = (char *)malloc(sizeof(char) * (*restOfCommandSize));
    /*assigning command to commandVar*/
    for (i = commandSize + 1; i < totalCommandSize; i++)
    {
        (*restOfCommand)[i - (commandSize + 1)] = input[i];
    }
    (*restOfCommand)[i] = '\0'; // adding null charachter
}
