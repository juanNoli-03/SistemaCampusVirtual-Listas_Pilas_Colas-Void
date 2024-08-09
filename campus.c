#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "campus.h"
#include "estudiante.h"
#include "materia.h"
#include "pila.h"
#include "cola.h"

///IMPLEMENTACION DE ESTRUCTURA
//---------------------------------------------
struct CampusE {

    char universidad [60];

    char carrera [30];

    int codCarrera;

    ColaP colaEstudiantes;
};
//---------------------------------------------

///PRIMITIVAS

//Creacion y muestra del Campus
//------------------------------------------------------------------------------------
CampusP crearCampus (char universidad [60], char carrera [30], int codCarrera) {

    CampusP campus = malloc (sizeof(struct CampusE)); //Reservamos memoria

    campus->colaEstudiantes = crearCola (sizeof(EstudianteP)); //Creamos cola de estudiantes

    strcpy (campus->universidad, universidad);

    strcpy (campus->carrera, carrera);

    campus->codCarrera = codCarrera;

    return campus;
}

void mostrarCampus (CampusP campus){

    printf ("\n----CAMPUS VIRTUAL-----\n");

    printf ("\nUniversidad: %s --- Carrera: %s --- Codigo carrera: #%d\n", campus->universidad, campus->carrera, campus->codCarrera);
}
//------------------------------------------------------------------------------------

//Getters
//------------------------------------------------------------------------------------
ColaP getColaEstudiantes (CampusP campus) {

    return campus->colaEstudiantes; //Retornamos la cola de estudiantes
}
//------------------------------------------------------------------------------------

//VerificarMateria
//------------------------------------------------------------------------------------
int verificarMateria (EstudianteP estudiante, int codigo) {

    PilaP pilaAux = crearPila (sizeof(MateriaP)); //Creamos pila auxilar

    MateriaP aux; //Creamos materia auxiliar

    int simil = 0; //Variable que utilizamos para verificar si existe una similitud.

    //Mientras que la pila no este vacia, me desapila los elementos, compara su codigo y los apila en una pila auxiliar.
    //En caso de que el codigo sea igual, aumentamos el acumulador de similitudes.
    while (!estaVaciaPila(getPilaMaterias(estudiante))) {

            desapilar (getPilaMaterias(estudiante), &aux);

            if (codigo == getCodMateria(aux)) {

                simil ++;
            }

        apilar (pilaAux, &aux);
    }

    //Desapilamos los elementos de la pila auxiliar y los volvemos a apilar en nuestra pila original.
    while (!estaVaciaPila(pilaAux)) {

        desapilar(pilaAux, &aux);

        apilar (getPilaMaterias(estudiante), &aux);
    }

    return simil;
}
//------------------------------------------------------------------------------------

//Menu
//------------------------------------------------------------------------------------

void desplegarMenuMaterias (ListaP lista, EstudianteP estudiante) {

    MateriaP materia;

    int opcion2 = 0;

    int pos = 0;

    int simil = 0;

    int codigo;

     while (opcion2 != 5) {

        printf ("\n---MENU MATERIAS---\n");
        printf ("\n1- Ver materias disponibles\n");
        printf ("\n2- Apilar una materia\n");
        printf ("\n3- Desapilar una materia\n");
        printf ("\n4- Obtener datos del primer elemento de la pila\n");
        printf ("\n5- Volver a menu estudiantes\n");
        printf ("\nOpcion: ");
        scanf ("%d", &opcion2);

        switch (opcion2) {

                case 1:

                    mostrarListaMaterias (lista);

                break;

                case 2:

                    printf ("\nIngresa el codigo de la materia que deseas apilar: ");

                    scanf ("%d", &codigo); //Ingresamos el codigo de la materia que queremos apilar.

                    pos = busquedaMateria(lista, codigo); //Verificamos si el codigo ingresado corresponde a una materia existente. En caso de no serlo, entramos al while.

                        while (pos == -1) {

                            printf ("\nEl codigo ingresado no corresponde a una materia, ingresalo de nuevo: ");

                            scanf ("%d", &codigo);

                            pos = busquedaMateria(lista, codigo);
                        }

                    simil = verificarMateria (estudiante, codigo); //Verificamos si la materia ingresada se encuentra ya en la pila. En caso de que hayamos ingresado una materia repetida, entramos al while.

                    while (simil > 0) {

                        printf ("\nNo puedes apilar esta materia ya que ya esta en tu pila, ingresa el codigo nuevamente: ");

                        scanf ("%d", &codigo);

                        pos = busquedaMateria(lista, codigo); //Verificamos si el codigo ingresado es valido. De no serlo entramos al while.

                        while (pos == -1) {

                            printf ("\nEl codigo ingresado no corresponde a una materia, ingresalo de nuevo: ");

                            scanf ("%d", &codigo);

                            pos = busquedaMateria(lista, codigo);
                        }

                        simil = verificarMateria (estudiante, codigo); //Verificamos nuevamente si la materia ingresada se encuentra ya en la pila.
                    }

                    materia = *((MateriaP *)getElementoLista(lista, pos));

                    apilar (getPilaMaterias(estudiante), &materia); //Luego de todas las validaciones, apilamos la materia correspondiente.

                    printf ("\nElemento apilado con exito.\n");

                break;

                case 3:
                    //Desapilamos una materia y mostramos sus datos.
                    if (!estaVaciaPila(getPilaMaterias(estudiante))) {

                        desapilar (getPilaMaterias(estudiante), &materia);

                        printf ("\n---Datos de la materia desapilada---\n");

                        mostrarMateria (materia);

                    } else {

                        printf ("\nNo hay elementos para desapilar.\n");
                    }

                break;

                case 4:
                    //Mostramos los datos del primer elemento de la pila
                    if (!estaVaciaPila(getPilaMaterias(estudiante))) {

                        materia = *((MateriaP *)getElementoPilaInicio(getPilaMaterias(estudiante)));

                        printf ("\n---Datos del primer elemento de la pila---\n");

                        mostrarMateria (materia);

                    } else {

                        printf ("\nNo puedes acceder al primer elemento de la pila ya que esta vacia.\n");
                    }

                break;

                case 5:

                    printf ("\nVolviste al menu de estudiantes\n");

                break;

                default:

                    printf ("\nEsa opcion no es valida.\n");

                break;
            }
     }
}
void desplegarMenu (CampusP campus, ListaP lista) {

    int opcion1 = 0;

    EstudianteP estudiante;

    while (opcion1 != -1) {

        printf ("\n---MENU ESTUDIANTES---\n");
        printf ("\n1- Encolar Estudiante\n");
        printf ("\n2- Desencolar Estudiante\n");
        printf ("\n3- Acceder a primer elemento de la cola\n");
        printf ("\n4- Obtener datos del primer elemento de la cola\n");
        printf ("\n-1- Salir del campus\n");
        printf ("\nOpcion: ");
        scanf ("%d", &opcion1);

        switch (opcion1) {

            case 1:

                //Creamos el estudiante y lo encolamos. Desplegamos el menu de materias.
                estudiante = crearEstudiante ();

                encolar (campus->colaEstudiantes, &estudiante);

                printf ("\nElemento encolado con exito.\n");

                desplegarMenuMaterias (lista, estudiante); //Desplegamos menu

            break;

            case 2:
                //Mientras que haya elementos para desencolar, lo desencolamos y mostramos sus datos.
                if (!estaVaciaCola(campus->colaEstudiantes)) {

                    desencolar (campus->colaEstudiantes, &estudiante);

                    printf ("\n---Datos del estudiante desencolado---\n");

                    mostrarEstudiante (estudiante);

                } else {

                    printf ("\nNo hay elementos para desencolar.\n");
                }

            break;

            case 3:
                //Accedemos al primer elemento de la cola, volvemos a desplegar el menu de materias por si el estudiante quiere realizar modificaciones.
                if (!estaVaciaCola(campus->colaEstudiantes)) {

                    estudiante = *((EstudianteP *)getElementoInicioCola(campus->colaEstudiantes));

                    printf ("\nAccediste al primer elemento de la cola (%s %s) que deseas hacer?\n", getNombreEstudiante(estudiante), getApellidoEstudiante (estudiante));

                    desplegarMenuMaterias (lista, estudiante);

                } else {

                    printf ("\nNo puedes acceder al primer elemento de la cola ya que esta vacia.\n");
                }

            break;

            case 4:
                //Obtenemos al primer elemento de la cola.
                if (!estaVaciaCola(campus->colaEstudiantes)) {

                    estudiante = *((EstudianteP *)getElementoInicioCola(campus->colaEstudiantes));

                    printf ("\n---Datos del primer elemento de la cola---\n");

                    mostrarEstudiante (estudiante);

                } else {

                    printf ("\nNo puedes obtener los datos del primer elemento de la cola ya que esta vacia.\n");
                }

            break;

            case -1:

                printf ("\nSaliste del campus.\n");

            break;

            default:

                printf ("\nEsa opcion no es valida.\n");

            break;
        }
    }
}
//------------------------------------------------------------------------------------
