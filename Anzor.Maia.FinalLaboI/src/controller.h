#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedList.h"

#endif /* CONTROLLER_H_ */
int controller_guardarArchivo(char* path , LinkedList* pArrayList);

int controller_loadFromText(LinkedList* list);

int controller_List(LinkedList* list);

int controller_Filtrado_porGenero(LinkedList* list);

int controller_Filtrado_extraGrande(LinkedList* list);

int controller_modificar(LinkedList* list);

int controller_asignar_map(LinkedList* list);

int controller_batalla(LinkedList* list);
