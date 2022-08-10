#include "parser.h"
#include "pokemon.h"

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

int parser_FromText(FILE* pFile , LinkedList* list)
{

	int todoOk = 1;
	ePokemon* auxVar;
	char buffer[7][30];
	int auxCantidad;

	if(pFile != NULL && list != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

		while(!feof(pFile))
		{

			auxCantidad = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,], %[^,], %[^,],%[^\n]\n",buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

			if(auxCantidad == 7)
			{

				auxVar =  struct_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);

				if(auxVar != NULL)
				{

					auxCantidad = ll_add(list, auxVar);
					if(auxCantidad != 0)
					{
						struct_delete(auxVar);

						break;
					}
					else
					{
						todoOk = 0;
					}
				}
			}
			else
			{
				break;
			}
		}
	}
	return todoOk;
}
