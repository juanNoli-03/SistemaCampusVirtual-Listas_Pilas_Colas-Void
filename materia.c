#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "materia.h"

///IMPLEMENTACION DE ESTRUCTURA
//---------------------------------------------
struct MateriaE {

    char nombre [50];

    char profesor [20];

    int codMateria;
};
//---------------------------------------------


///IMPLEMENTACIONES

//Creacion y muestra de la materia
//------------------------------------------------------------------------------------
MateriaP crearMateria (char nombre [50], char profesor [20], int codMateria){

    MateriaP materia = malloc (sizeof(struct MateriaE));

    strcpy(materia->nombre, nombre);

    strcpy(materia->profesor, profesor);

    materia->codMateria = codMateria;

    return materia;
}
void mostrarMateria (MateriaP materia) {

    printf ("\n----DATOS DE LA MATERIA----\n");

    printf ("\nNombre: %s --- Profesor: %s --- Codigo: %d\n", materia->nombre, materia->profesor, materia->codMateria);
}
//------------------------------------------------------------------------------------

//Mostramos la lista de materias
//------------------------------------------------------------------------------------
void mostrarListaMaterias (ListaP lista) {

    int tam;

    getSizeLista(lista, &tam);

    for (int i = 0; i < tam; i ++) {

        MateriaP materia = *((MateriaP *)getElementoLista(lista, i));

        mostrarMateria (materia);
    }
}
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
int getCodMateria (MateriaP materia) {

    return materia->codMateria;
}

int getCodMateriaLista (ListaP lista, int pos) {

    MateriaP materia = *((MateriaP *)getElementoLista(lista, pos));

    return getCodMateria (materia);
}
//------------------------------------------------------------------------------------

//Busqueda de materia
//------------------------------------------------------------------------------------
int busquedaMateria (ListaP lista, int codigo) {

    int pos = -1;

    int tam;

    getSizeLista (lista, &tam);

    for (int i = 0; i < tam; i ++) {

        if (getCodMateriaLista(lista, i) == codigo) {

            pos = i;

            i = i + tam;
        }
    }

    return pos;
}
//------------------------------------------------------------------------------------
