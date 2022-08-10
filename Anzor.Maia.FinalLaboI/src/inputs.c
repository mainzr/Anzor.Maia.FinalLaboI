#include "inputs.h"
#include <stdio.h>
#include <stdlib.h>

int getInteger(int* number, char* message, char* errorMessage, int minNumber, int maxNumber)
{
	int error = -1;
	int auxInt;

	if(message != NULL && errorMessage != NULL )
	{
		printf("%s", message);
		scanf("%d", &auxInt);

		while(auxInt <= minNumber || auxInt >= maxNumber)
		{
			printf("%s", errorMessage);
			scanf("%d", &auxInt);
		}

		*number = auxInt;

		error = 0;
	}

    return error;
}

int validateChar(char character, char firstOption, char secondOption)
{
    int error = -1;

    if(character == firstOption || character == secondOption)
    {
    	error = 0;
    }

    return error;
}
