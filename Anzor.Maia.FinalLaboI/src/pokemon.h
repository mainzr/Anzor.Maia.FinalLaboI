/*
 * pokemon.h
 *
 *  Created on: 10 ago. 2022
 *      Author: maiam
 */

#ifndef POKEMON_H_
#define POKEMON_H_
#include "LinkedList.h"
typedef struct
{
	int numero;
	char nombre[30];
	char tipo[30];
	char tamanio[30];
	char ataqueCargado[30];
	int valorAtaque;
	int esVariocolo;

}ePokemon;


#endif /* POKEMON_H_ */
int Menu();

void struct_delete(ePokemon* this);

ePokemon* struct_new();

int struct_set_numero(ePokemon* this,int numero);
int struct_get_numero(ePokemon* this,int* numero);

int struct_set_valorAtaque(ePokemon* this,int valorAtaque);
int struct_get_valorAtaque(ePokemon* this,int* valorAtaque);

int struct_set_esVariocolo(ePokemon* this,int esVariocolo);
int struct_get_esVariocolo(ePokemon* this,int* esVariocolo);

int struct_set_nombre(ePokemon* this,char* nombre);
int struct_get_nombre(ePokemon* this,char* nombre);

int struct_set_tipo(ePokemon* this,char* tipo);
int struct_get_tipo(ePokemon* this,char* tipo);

int struct_set_tamanio(ePokemon* this,char* tamanio);
int struct_get_tamanio(ePokemon* this,char* tamanio);

int struct_set_ataqueCargado(ePokemon* this,char* ataqueCargado);
int struct_get_ataqueCargado(ePokemon* this,char* ataqueCargado);

ePokemon* struct_newParametros(char* numeroStr,char* nombreStr,char* tipoStr, char* tamanioStr, char* ataqueCargadoStr, char* valorAtaqueStr, char*esVariocolo);

void print_struct(ePokemon* this);


int struct_filtro_fuego(void* pElement);
int struct_filtro_extraGrande(void* pElement);

int encontrarPokemon(LinkedList* list,  int nuemero);

void* mapeo(void* pElment);

