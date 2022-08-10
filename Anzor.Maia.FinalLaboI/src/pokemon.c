#include  "pokemon.h"

#include "parser.h"
#include "LinkedList.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int Menu()
{

	int opcion;
	printf("\n********************\n");
	printf("  MENU DE OPCIONES      \n");
	printf("********************\n");

	printf("1) Cargar archivo pokemones:\n");
	printf("2)Modificar valor ataque:\n");
	printf("3) Imprimir Pokemones:\n");
	printf("4) Filtrar tipo Fuego:\n");
	printf("5) Filtrar Extra Grandes de tipo Veneno:\n");
	printf("6) Mapear ataque cargado:\n");
	printf("7) Batalla pokemon:\n");
	printf("8) Salir.\n\n");


	printf("Elegir opcion: ");
	scanf("%d", &opcion);

	return opcion;

}


void struct_delete(ePokemon* this)
{
	if(this != NULL)
	{
		free(this);
	}


}

ePokemon* struct_new()
{
	ePokemon* new;

    new = (ePokemon*) malloc(sizeof(ePokemon));

    if(new != NULL)
    {
    	new->numero = 0;
    	strcpy(new->nombre, " ");
    	strcpy(new->tipo, " ");
    	strcpy(new->tamanio, " ");
    	strcpy(new->ataqueCargado, " ");
    	new->valorAtaque = 0;
    	new->esVariocolo = 0;

    }

    return new;
}

int struct_set_numero(ePokemon* this,int numero)
{

    int todoOK = 0;

    if(this != NULL && numero > 0)
    {
    	this->numero = numero;

        todoOK = 1;
    }

    return todoOK;
}

int struct_get_numero(ePokemon* this,int* numero)
{
	int error = 1;

	if(this != NULL && numero != NULL)

	{
		*numero = this->numero;

		error = 0;
	}

	return error;
}

//-

int struct_set_valorAtaque(ePokemon* this,int valorAtaque)
{

    int todoOK = 0;

    if(this != NULL)
    {
    	this->valorAtaque = valorAtaque;

        todoOK = 1;
    }

    return todoOK;
}

int struct_get_valorAtaque(ePokemon* this,int* valorAtaque)
{
	int error = 1;

	if(this != NULL && valorAtaque != NULL)

	{
		*valorAtaque = this->valorAtaque;

		error = 0;
	}

	return error;
}

///-
int struct_set_esVariocolo(ePokemon* this,int esVariocolo)
{

    int todoOK = 0;

    if(this != NULL)
    {
    	this->esVariocolo = esVariocolo;

        todoOK = 1;
    }

    return todoOK;
}

int struct_get_esVariocolo(ePokemon* this,int* esVariocolo)
{
	int error = 1;

	if(this != NULL && esVariocolo != NULL)

	{
		*esVariocolo = this->esVariocolo;

		error = 0;
	}

	return error;
}


int struct_set_nombre(ePokemon* this,char* nombre)
{
	int todoOk = 0;

	if(this != NULL && nombre != NULL)
	{
		if(strlen(nombre) < 30)
		{
			strcpy(this->nombre, nombre);

			todoOk = 1;
		}
	}

	return todoOk;
}

int struct_get_nombre(ePokemon* this,char* nombre)
{
	int error = 1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);

		error = 0;
	}

	return error;
}



//-
int struct_set_tipo(ePokemon* this,char* tipo)
{
	int todoOk = 0;

	if(this != NULL && tipo != NULL)
	{
		if(strlen(tipo) < 30)
		{
			strcpy(this->tipo, tipo);

			todoOk = 1;
		}
	}

	return todoOk;
}

int struct_get_tipo(ePokemon* this,char* tipo)
{
	int error = 1;

	if(this != NULL && tipo != NULL)
	{
		strcpy(tipo, this->tipo);

		error = 0;
	}

	return error;
}

//-
int struct_set_tamanio(ePokemon* this,char* tamanio)
{
	int todoOk = 0;

	if(this != NULL && tamanio != NULL)
	{
		if(strlen(tamanio) < 30)
		{
			strcpy(this->tamanio, tamanio);

			todoOk = 1;
		}
	}

	return todoOk;
}

int struct_get_tamanio(ePokemon* this,char* tamanio)
{
	int error = 1;

	if(this != NULL && tamanio != NULL)
	{
		strcpy(tamanio, this->tamanio);

		error = 0;
	}

	return error;
}

int struct_set_ataqueCargado(ePokemon* this,char* ataqueCargado)
{
	int todoOk = 0;

	if(this != NULL && ataqueCargado != NULL)
	{

		strcpy(this->ataqueCargado, ataqueCargado);

		todoOk = 1;

	}

	return todoOk;
}

int struct_get_ataqueCargado(ePokemon* this,char* ataqueCargado)
{
	int error = 1;

	if(this != NULL && ataqueCargado != NULL)
	{
		strcpy(ataqueCargado, this->ataqueCargado);

		error = 0;
	}

	return error;
}

ePokemon* struct_newParametros(char* numeroStr,char* nombreStr,char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char*esVariocoloStr )
{
	ePokemon* new = NULL;

	new = struct_new();

    if(new != NULL)
    {
        if(!(struct_set_numero(new,atoi( numeroStr))
          && struct_set_nombre(new, nombreStr)
		  && struct_set_tipo(new, tipoStr)
		  && struct_set_tamanio(new, tamanioStr)
		  && struct_set_ataqueCargado(new, ataqueCargadoStr)
		  && struct_set_valorAtaque(new, atoi(valorAtaqueStr))
		  && struct_set_esVariocolo(new, atoi(esVariocoloStr))
		   ))
           {
        	free(new);
        	new = NULL;
           }
    }
    return new;
}

void print_struct(ePokemon* this)
{
	if(this != NULL)
	{
		int numero;
		char nombre[30];
		char tipo[30];
		char tamanio[30];
		char ataqueCargado[30];
		int valorAtaque;
		int esVariocolo;

		struct_get_numero(this, &numero);
		struct_get_nombre(this, nombre);
		struct_get_tipo(this, tipo);
		struct_get_tamanio(this, tamanio);
		struct_get_ataqueCargado(this, ataqueCargado);
		struct_get_valorAtaque(this, &valorAtaque);
		struct_get_esVariocolo(this, &esVariocolo);



		printf("%5d    %-15s    %-18s  %-10s  %-15s  %-10d  %-10d ", numero, nombre,tipo,tamanio, ataqueCargado, valorAtaque, esVariocolo);
	}

}

int struct_filtro_fuego(void* pElement)
{
	int retorno = 0;
	ePokemon* aux = (ePokemon*) pElement;

	if(aux != NULL  )
	{
		if(strcmp(aux->tipo, "Fire") == 0)
		{
			retorno = 1;
		}
	}

	return retorno;
}
int struct_filtro_extraGrande(void* pElement)
{
	int retorno = 0;
	ePokemon* aux = (ePokemon*) pElement;

	if(aux != NULL  )
	{
		if(strcmp(aux->tamanio, "XL") == 0 && strcmp(aux->tipo, "Poison") == 0)
		{

				retorno = 1;


		}
	}

	return retorno;
}


int encontrarPokemon(LinkedList* list,  int nuemero)
{

	int numeroPoke = -1;
	ePokemon* indice;
	int idRetornado;


	if(list != NULL)
	{
		for(int i = 0; i < ll_len(list); i++)
		{

			indice = ll_get(list, i);

			if(indice != NULL)
			{
				struct_get_numero(indice, &idRetornado);

				if(idRetornado == nuemero)
				{
					numeroPoke = i; //retorna indice, si falla retorna -1
				}
			}

		}
	}

	return numeroPoke;
}



void* mapeo(void* pElment)
{
	int min = 1;
	int max = 4;
	ePokemon* aux;
	int ataqueMas;
	int ataqueTotal;

	if(pElment != NULL)
	{
		aux = (ePokemon*) pElment;
		if(aux != NULL)
		{

			if((strcmp(aux->tipo, "Bug") == 0) || strcmp(aux->tipo, "Fire") == 0 || strcmp(aux->tipo, "Grass") == 0)
			{
				if(strcmp(aux->tamanio, "XL") == 0)
				{
					struct_get_valorAtaque(aux, &ataqueMas);
					ataqueTotal = ataqueMas + (ataqueMas * 0.2);
					struct_set_valorAtaque(aux, ataqueTotal);
				}
				else if(strcmp(aux->tamanio, "L") == 0)
				{
					struct_get_valorAtaque(aux, &ataqueMas);
					ataqueTotal = ataqueMas + (ataqueMas * 0.1);
					struct_set_valorAtaque(aux, ataqueTotal);
				}
				else
				{

					struct_get_valorAtaque(aux, &ataqueMas);
					ataqueTotal = ataqueMas + (ataqueMas * 0.5);
					struct_set_valorAtaque(aux, ataqueTotal);

				}
			}
		}

	}

	return aux;
}
