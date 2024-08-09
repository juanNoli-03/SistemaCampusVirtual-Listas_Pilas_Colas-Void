#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include "pila.h"

///DEFINIMOS ESTRUCTURA Y TIPO DE DATO
//---------------------------------------------
struct EstudianteE;

typedef struct EstudianteE * EstudianteP;
//---------------------------------------------

///PRIMITIVAS

//Creacion y muestra del Estudiante
//------------------------------------------------------------------------------------
EstudianteP crearEstudiante ();

void mostrarEstudiante (EstudianteP estudiante);
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
PilaP getPilaMaterias (EstudianteP estudiante);

char * getNombreEstudiante (EstudianteP estudiante);

char * getApellidoEstudiante (EstudianteP estudiante);
//------------------------------------------------------------------------------------


#endif // ESTUDIANTE_H_INCLUDED
