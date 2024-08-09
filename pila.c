#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTRO ARCHIVO.H
#include "pila.h"

///IMPLEMENTACION DE ESTRUCTURAS
//-------------------------------------------------------
struct PilaE {

    NodoP inicio;

    int tam;

    int tamDatoBytes;
};

struct NodoE {

    NodoP proximo;

    void * item;
};
//-------------------------------------------------------

///IMPLEMENTACIONES

//Creacion de la pila y del nodo
//-------------------------------------------------------
PilaP crearPila (int tamDato) {

    PilaP pila = malloc (sizeof(struct PilaE));

    pila->inicio = NULL;

    pila->tam = 0;

    pila->tamDatoBytes = tamDato;

    return pila;
}

NodoP crearNodoPila (PilaP pila, NodoP proximo, void * item) {

    NodoP node = malloc (sizeof(struct NodoE));

    node->item = malloc (pila->tamDatoBytes);

    memcpy (node->item, item, pila->tamDatoBytes);

    node->proximo = proximo;

    return node;
}
//-------------------------------------------------------

//Apilar (PUSH) y Desapilar (POP)
//--------------------------------------------------------------------------------------------------------------------
int apilar (PilaP pila, void * item) {

    //Validacion
    //-------------------------------------------------------
    if (pila == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_2;
    }
    //-------------------------------------------------------

    NodoP node = crearNodoPila (pila, pila->inicio, item);

    //Validacion
    //-------------------------------------------------------
    if (node == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_2;
    }
    //-------------------------------------------------------

    pila->inicio = node;

    pila->tam ++;

    return OK_PILA;
}

int desapilar (PilaP pila, void * itemDesapilado) {

    //Validacion.
    //-------------------------------------------------------
    if (pila == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_2;
    }

    if (estaVaciaPila (pila)) {

       return printf ("\nNo se puede desapilar ya que no hay ningun elemento en tu pila.\n");
    }
    //-------------------------------------------------------

    NodoP aux;

    aux = pila->inicio;

    pila->inicio = aux->proximo;

    //Validacion.
    //-------------------------------------------------------
    if (itemDesapilado != NULL) {

        memcpy (itemDesapilado, aux->item, pila->tamDatoBytes);
    }
    //-------------------------------------------------------

    free (aux);

    aux = NULL;

    pila->tam --;

    return OK_PILA;
}
//--------------------------------------------------------------------------------------------------------------------

//Getters
//--------------------------------------------------------------------------------------------------------------------
void * getElementoPilaInicio (PilaP pila) {

    NodoP aux;

    aux = pila->inicio;

    return aux->item;
}

int getSizePila (PilaP pila, int * tam) {

    if (estaVaciaPila(pila)) {

        return PILA_VACIA;

    } else {

        *tam = pila->tam;

    }

    return OK_PILA;
}
//--------------------------------------------------------------------------------------------------------------------

//Auxiliares
//--------------------------------------------------------------------------------------------------------------------
int liberarPila (PilaP pila) {

    if (estaVaciaPila (pila)) {

        printf ("\nLa pila no puede ser liberada ya que no tiene ningun elemento.\n");

    } else {

        NodoP aux;

        aux = pila->inicio;

        int tam;

        getSizePila (pila, &tam);

        for (int i = 0; i < tam; i ++) {

            free (aux);

            free (aux->item);

            aux = aux->proximo;
        }

        pila->inicio = NULL;

        pila->tam = 0;

        free (pila);

        if (estaVaciaPila (pila)) {

            printf ("\nPila liberada exitosamente.\n");
        }
    }

    return OK_PILA;
}

int estaVaciaPila (PilaP pila) {

    if (pila->inicio == NULL) {

        return TRUE_PILA;

    } else {

        return FALSE_PILA;
    }
}
//--------------------------------------------------------------------------------------------------------------------
