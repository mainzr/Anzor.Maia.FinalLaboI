/*
 ============================================================================
 Name        : FinalLaboI.c
 Author      : Anzor Maia
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "controller.h"

#include "pokemon.h"

int main(void)
{

	setbuf(stdout, NULL);
	char seguir = 's';
	char respuesta;

	LinkedList* list =  ll_newLinkedList();

	do {
		switch(Menu())
		{
			case 1:
				if(controller_loadFromText(list) == 0)
				{

					printf("lista cargada con exito\n");
				}
				break;
			case 2:

				controller_modificar(list);
				break;
			case 3:
				if(controller_List(list) == 0)
				{
					printf("Lista impresa");
				}
				break;
			case 4:
				controller_Filtrado_porGenero(list);
				break;
			case 5:
				controller_Filtrado_extraGrande(list);
				break;
			case 6:
				controller_asignar_map(list);

				break;
			case 7:
				controller_batalla(list);
				break;

			case 8:
				printf("¿Seguro desea salir? (s/n): ");
				fflush(stdin);
				scanf("%c", &respuesta);
				seguir = 'n';
				break;
			default:
				printf("Opcion incorrecta\n");
				break;

		}
	} while (seguir == 's');


	return EXIT_SUCCESS;
}
