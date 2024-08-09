#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "campus.h"
#include "estudiante.h"
#include "materia.h"
#include "lista.h"
int main()
{
    printf ("\n-----------------------------------------------\n");
    printf ("\n---SISTEMA CAMPUS VIRTUAL---\n");
    printf ("\nRealizado por: Juan Manuel Noli (45233126)\n");
    printf ("\n-----------------------------------------------\n");

    //1- Creamos el campus
    //------------------------------------------------------------------------------------------------
    CampusP campus = crearCampus ("Universidad Nacional de Lanus", "Licenciatura en sistemas", 8505);

    mostrarCampus (campus);
    //------------------------------------------------------------------------------------------------

    //2- Creamos las materias y la lista de las mismas
    //------------------------------------------------------------------------------------------------
    ListaP listaMaterias = crearLista (sizeof(MateriaP));

    MateriaP materia = crearMateria ("AYYED", "Nicolas Perez", 8609);

    insertarInicio (listaMaterias, &materia);

    materia = crearMateria ("Ingenieria de software", "Leandro Rios", 8607);

    insertarFinal (listaMaterias, &materia);

    materia = crearMateria ("Bases de datos", "Nicolas Perez", 8608);

    insertarFinal (listaMaterias, &materia);

    materia = crearMateria ("Matematica 2", "Vanesa Plaul", 8604);

    insertarFinal (listaMaterias, &materia);
    //------------------------------------------------------------------------------------------------

    //3- Desplegamos Menu
    //------------------------------------------------------------------------------------------------
    desplegarMenu (campus, listaMaterias);
    //------------------------------------------------------------------------------------------------

    return 0;
}
