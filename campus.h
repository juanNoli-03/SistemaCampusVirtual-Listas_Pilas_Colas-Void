#ifndef CAMPUS_H_INCLUDED
#define CAMPUS_H_INCLUDED

#include "lista.h"

#include "cola.h"

#include "estudiante.h"

///DEFINIMOS ESTRUCTURA Y TIPO DE DATO
//---------------------------------------------
struct CampusE;

typedef struct CampusE * CampusP;
//---------------------------------------------

///PRIMITIVAS

//Creacion y muestra del Campus
//------------------------------------------------------------------------------------
CampusP crearCampus (char universidad [60], char carrera [20], int codCarrera); //Creacion del campus.

void mostrarCampus (CampusP campus); //Muestra del campus.
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
ColaP getColaEstudiantes (CampusP campus); //Getter de la cola de estudiantes que tiene el campus.
//------------------------------------------------------------------------------------

//Menu
//------------------------------------------------------------------------------------
void desplegarMenuMateria (ListaP lista, EstudianteP estudiante); //Mostramos el menu de las materias.

void desplegarMenu (CampusP campus, ListaP lista); //Mostramos menu del campus.
//------------------------------------------------------------------------------------

//VerificarMateria
//------------------------------------------------------------------------------------
int verificarMateria (EstudianteP estudiante, int codogo); //Verificamos si la materia ingresada ya esta en nuestra pila.
//------------------------------------------------------------------------------------


#endif // CAMPUS_H_INCLUDED
