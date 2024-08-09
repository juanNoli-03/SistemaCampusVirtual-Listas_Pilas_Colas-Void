#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED

#include "lista.h"

///DEFINIMOS ESTRUCTURA Y TIPO DE DATO
//---------------------------------------------
struct MateriaE;

typedef struct MateriaE * MateriaP;
//---------------------------------------------

///PRIMITIVAS

//Creacion y muestra de la materia
//------------------------------------------------------------------------------------
MateriaP crearMateria (char nombre [50], char profesor [20], int codMateria);

void mostrarMateria (MateriaP materia);
//------------------------------------------------------------------------------------

//Mostramos la lista de materias
//------------------------------------------------------------------------------------
void mostrarListaMaterias (ListaP lista);
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
int getCodMateria (MateriaP materia);

int getCodMateriaLista (ListaP lista, int pos);
//------------------------------------------------------------------------------------

//Busqueda de materia
//------------------------------------------------------------------------------------
int busquedaMateria (ListaP lista, int codigo);
//------------------------------------------------------------------------------------


#endif // MATERIA_H_INCLUDED
