#include "pokemon.h"

#include "controller.h"
#include "LinkedList.h"
#include "parser.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"

int controller_guardarArchivo(char* path , LinkedList* pArrayList)
{
	int error = 1;
	FILE* pFile;
	ePokemon* aux;

	int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVariocolo;


	if(path != NULL && pArrayList != NULL)
	{
		pFile = fopen(path, "w");

		if(pFile == NULL)
		{
			printf("Error al abrir el archivo de texto...\n");
			error = 1;
			exit(1);
		}
		else
		{

			aux = struct_new();

			fprintf(pFile,"numero, nombre, tipo, tamanio,ataqueCargado,valorAtaque,esVariocolo \n");

			for(int i = 0; i < ll_len(pArrayList); i++)
			{

				aux = (ePokemon*)ll_get(pArrayList, i);


				if(aux != NULL)
				{
					struct_get_numero(aux, &numero);
					struct_get_nombre(aux, nombre);
					struct_get_tipo(aux, tipo);
					struct_get_tamanio(aux, tamanio);
					struct_get_ataqueCargado(aux, ataqueCargado);
					struct_get_valorAtaque(aux, &valorAtaque);
					struct_get_esVariocolo(aux, &esVariocolo);


					fprintf(pFile, "%d    %s    %s  %s  %s  %d  %d \n", numero, nombre,tipo,tamanio, ataqueCargado, valorAtaque, esVariocolo);
					error = 0;
				}
				else
				{

					error = 1;
					break;
				}
			}
			printf("\n\nARCHIVOS GUARDADOS CON EXITO...\n");
			fclose(pFile);
		}

	}

    return error;
}

int controller_loadFromText(LinkedList* list)
{
	int error = 1;
	FILE* pFile;
	char path[30];


	if(path != NULL && list != NULL)
	{
		printf("Ingrese el nombre del archivo (Data_Pokemones.csv): ");
		scanf("%s", path);

		if(strcmp(path, "Data_Pokemones.csv"))
		{
			printf("Error al introducir nombre..\n");

		}
		else
		{
			pFile = fopen(path, "r");

			if(pFile == NULL)
			{
				printf("No se pudo abrir el archivo\n");
				error = 1;
				exit(1);
			}
			else
			{
				if(parser_FromText(pFile, list) == 0)
				{
					error = 0;
				}
				else
				{
					printf("\nocurrio un error!\n");
				}
			}
			fclose(pFile);
		}


	}

    return error;
}


int controller_List(LinkedList* list)
{
	int error = 1;
	int flag = 1;
	int len;
	ePokemon*  aux;


	if(list != NULL)
	{



		 printf("\n                                  LISTADO COMPLETO                             \n");
		 printf(" -------------------------------------------------------------------------------------------------------------\n");
		 printf( " numero   nombre            tipo              tamanio        ataqueCargado valorAtaque  esVariocolo\n");
		 printf(" --------------------------------------------------------------------------------------------------------------\n\n");

		 len = ll_len(list);

		 if(len > 0)
		 {
				for(int i = 0; i < len; i++)
				{
					aux = ll_get(list, i);

					print_struct(aux);
					flag = 0;
					printf("\n");
				}
				//printf("\n\n");

				if(flag == 1)
				{
					printf("No hay datos para mostrar.\n");
					error = 1;
				}

				error = 0;
		 }

	}

    return error;
}


int controller_Filtrado_porGenero(LinkedList* list)
{
	int retorno = 0;
	LinkedList* auxList = NULL;

	if(list != NULL)
	{
		auxList = ll_filter(list, struct_filtro_fuego);
		controller_guardarArchivo("filtradoFire.csv", auxList);
		retorno = 1;
	}


	return retorno;
}

int controller_Filtrado_extraGrande(LinkedList* list)
{
	int retorno = 0;
	LinkedList* auxList = NULL;

	if(list != NULL)
	{
		auxList = ll_filter(list, struct_filtro_extraGrande);
	    controller_List(auxList);
		retorno = 1;
	}


	return retorno;
}

int controller_modificar(LinkedList* list)
{
	int error = -1;
	int numero;
	int index;
	char confirm;

	char valorNuevo[30];

	ePokemon* aux;


	if(list != NULL)
	{

		system("cls");

		printf("--------------------------------------------------------------\n");
		printf("                        MODIFICAR POKEMON                   \n");
		printf("--------------------------------------------------------------\n");

		controller_List(list);
		printf("Ingrese numero de pokemon que desea modificar: ");
		scanf("%d", &numero);

		index = encontrarPokemon(list, numero);

		if(index == -1)
		{
			printf("\nNo existe pokemon con ese numero...\n");
		}
		else
		{
			aux = ll_get(list, index);

		    print_struct(aux);


			printf("\n\n¿Desea confirmar la modificacion? (s/n): ");
			fflush(stdin);
			scanf("%c", &confirm);

			if(validateChar(confirm, 's', 'n'))
			{
				printf("Opcion incorrecta...Reintentelo nuevamente: ");
				fflush(stdin);
				scanf("%c", &confirm);
			}

			if(confirm == 's')
			{
				printf("ingrese nuevo valor de ataque cargado: \n");
				scanf("%s", valorNuevo);
				struct_set_ataqueCargado(aux, valorNuevo);

				printf("\n\nLista actualizada: ");
				controller_List(list);

				error = 0;

			}
		}

	}

	return error;
}


int controller_asignar_map(LinkedList* list)
{
	int error = 1;

	if(list != NULL)
	{
		ll_map(list, mapeo);
		controller_List(list);
		error = 0;
	}

	return error;
}


int controller_batalla(LinkedList* list)
{
	int retorno = 0;
    ePokemon* aux = NULL;

    int contador = 0;
	if(list != NULL)
	{
		for (int i = 0;  i < ll_len(list); ++ i)
		{
			aux = ll_get(list, i);

			if(aux != NULL)
			{
				if((strcmp(aux->tipo, "Fire") == 0 && (strcmp(aux->tamanio, "XL") == 0) && (strcmp(aux->ataqueCargado, "Lanzallamas") == 0 ) && (aux->valorAtaque > 80))
						||( ((strcmp(aux->tipo, "Water") == 0) && (strcmp(aux->tamanio, "L") == 0) && strcmp(aux->ataqueCargado, "Hidrobomba") == 0) && (aux->valorAtaque >= 80)))
				{
					contador++;
				}
			}
		}

		printf("\n***CANTIDAD DE POKEMONES PARA LA BATALLA***\n");
		printf("Total de pokemones con caracteristicas pedidas %d\n", contador);

		if(contador >= 3)
		{
			printf("\n***BATTALLA GANADA***\n");
		}
		else
		{
			printf("\n***BATTALLA PERDIDA***\n");

		}


		retorno = 1;

	}

	return retorno;
}
