#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "estudiante.h"
#include "materia.h"
#include "pila.h"

///IMPLEMENTACION DE ESTRUCTURA
//---------------------------------------------
struct EstudianteE {

    char nombre [20];

    char apellido [20];

    char documento [20];

    PilaP pilaMaterias;
};
//---------------------------------------------

///PRIMITIVAS

//Creacion y muestra del Estudiante
//------------------------------------------------------------------------------------
EstudianteP crearEstudiante () {

    EstudianteP estudiante = malloc (sizeof(struct EstudianteE));

    estudiante->pilaMaterias = crearPila (sizeof(MateriaP));

    printf ("\n----CARGA TUS DATOS----\n");

    printf ("\nIngrese su nombre por favor: ");

    fflush (stdin);

    gets(estudiante->nombre);

    printf ("\nIngrese su apellido por favor: ");

    fflush (stdin);

    gets(estudiante->apellido);

    printf ("\nIngrese su documento por favor: ");

    fflush (stdin);

    gets(estudiante->documento);

    return estudiante;
}

void mostrarEstudiante (EstudianteP estudiante) {

    printf ("\nNombre completo: %s %s --- Documento: %s\n", estudiante->nombre, estudiante->apellido, estudiante->documento);
}
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
PilaP getPilaMaterias (EstudianteP estudiante) {

    return estudiante->pilaMaterias; //Getter de la pila de materias que tiene cada estudiante.
}

char * getNombreEstudiante (EstudianteP estudiante) {

    return estudiante->nombre;
}

char * getApellidoEstudiante (EstudianteP estudiante) {

    return estudiante->apellido;
}
//------------------------------------------------------------------------------------
