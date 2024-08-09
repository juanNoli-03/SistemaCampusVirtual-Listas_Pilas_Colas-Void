#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "cola.h"

///IMPLEMENTAMOS NUESTRAS ESTRUCTURAS
//--------------------------------------------------------------------------------------------------------------------
struct ColaE {

    NodoP inicio;

    int tam;

    int tamDatoBytes;
};

struct NodoE {

    NodoP proximo;

    void * item;
};
//--------------------------------------------------------------------------------------------------------------------

///IMPLEMENTACIONES

//Creacion de la cola y del nodo
//--------------------------------------------------------------------------------------------------------------------
ColaP crearCola (int tamDato) {

    ColaP cola = malloc (sizeof(struct ColaE));

    cola->inicio = NULL;

    cola->tam = 0;

    cola->tamDatoBytes = tamDato;

    return cola;
}

NodoP crearNodoCola (ColaP cola, NodoP proximo, void * item) {

    NodoP node = malloc (sizeof(struct NodoE));

    node->item = malloc (cola->tamDatoBytes);

    memcpy (node->item, item, cola->tamDatoBytes);

    node->proximo = proximo;

    return node;
}
//--------------------------------------------------------------------------------------------------------------------

//Encolar y desencolar
//--------------------------------------------------------------------------------------------------------------------
int encolar (ColaP cola, void * item) {

   //Validacion
    //----------------------------------------
    if (cola == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_1;
    }
    //----------------------------------------

    if (estaVaciaCola(cola)) {

        NodoP node = crearNodoCola (cola, cola->inicio, item);

        //Validacion
        //----------------------------------------
        if (node == NULL) {

            return ESTRUCTURA_NO_INICIALIZADA_1;
        }
        //----------------------------------------

        cola->inicio = node;

    } else {

        NodoP aux;

        aux = cola->inicio;

        int tam;

        getSizeCola(cola, &tam);

        for (int i = 0; i < tam; i ++) {

            aux = aux->proximo;
        }

        NodoP node = crearNodoCola (cola, aux->proximo, item);

        //Validacion
        //----------------------------------------
        if (node == NULL) {

            return ESTRUCTURA_NO_INICIALIZADA_1;
        }
        //----------------------------------------

        aux->proximo = node;

        cola->tam ++;

    }

    return OK_COLA;
}

int desencolar (ColaP cola, void * itemDesencolado) {

    if (estaVaciaCola (cola)) {

        return COLA_VACIA;

    } else {

        NodoP aux;

        aux = cola->inicio;

        cola->inicio = aux->proximo;

         //Validacion
        //----------------------------------------
        if (itemDesencolado != NULL) {

            memcpy (itemDesencolado, aux->item, cola->tamDatoBytes);
        }
        //----------------------------------------

        free (aux);

        aux = NULL;

        cola->tam --;
    }

    return OK_COLA;
}

//--------------------------------------------------------------------------------------------------------------------

//Getters
//--------------------------------------------------------------------------------------------------------------------
void * getElementoInicioCola (ColaP cola) {

    NodoP aux;

    aux = cola->inicio;

    return aux->item;
}

int getSizeCola (ColaP cola, int * tam) {

    if (estaVaciaCola(cola)) {

        return COLA_VACIA;

    } else {

        *tam = cola->tam;
    }

    return OK_COLA;
}
//--------------------------------------------------------------------------------------------------------------------

//Auxiliares
//--------------------------------------------------------------------------------------------------------------------
int liberarCola (ColaP cola) {

    if (estaVaciaCola (cola)) {

        printf ("\nLa cola no puede ser liberada ya que no tiene ningun elemento.\n");

    } else {

        NodoP aux;

        aux = cola->inicio;

        int tam;

        getSizeCola (cola, &tam);

        for (int i = 0; i < tam; i ++) {

            free (aux);

            free (aux->item);

            aux = aux->proximo;
        }

        cola->inicio = NULL;

        free (cola);

        if (estaVaciaCola (cola)) {

            printf ("\nCola liberada exitosamente.\n");
        }

    }

    return OK_COLA;
}

int estaVaciaCola (ColaP cola) {

    if (cola->inicio == NULL) {

        return TRUE_COLA;

    } else {

        return FALSE_COLA;
    }
}
//--------------------------------------------------------------------------------------------------------------------
