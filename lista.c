#include <stdio.h>
#include <stdlib.h>
#include <string.h>

///INCLUIMOS NUESTROS ARCHIVOS .H
#include "lista.h"

///IMPLEMENTACION DE ESTRUCTURAS
//--------------------------------------------------------------------------------------
struct ListaE {

    NodoP inicio;

    int tam;

    int tamDatoBytes;
};

struct NodoE {

    NodoP proximo;

    void * item;
};
//--------------------------------------------------------------------------------------

///IMPLEMENTACIONES

//Creacion de la lista y del nodo
//--------------------------------------------------------------------------------------
ListaP crearLista (int tamDelDato){

    ListaP lista = malloc (sizeof(struct ListaE));

    lista->inicio = NULL;

    lista->tam = 0;

    lista->tamDatoBytes = tamDelDato;

    return lista;
}

NodoP crearNodoLista (ListaP lista, NodoP proximo, void * item) {

    NodoP node = malloc (sizeof(struct NodoE));

    node->item = malloc (lista->tamDatoBytes);

    memcpy (node->item, item, lista->tamDatoBytes);

    node->proximo = proximo;

    return node;
}
//--------------------------------------------------------------------------------------

//Inserccion de nodos (Inicio - Pos - Final)
//--------------------------------------------------------------------------------------
int insertarInicio (ListaP lista, void * item) {

    //Validacion
    //--------------------------------------------------------------------------------------
    if (lista == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }
    //--------------------------------------------------------------------------------------

    NodoP node = crearNodoLista (lista, lista->inicio, item);

    //Validacion
    //--------------------------------------------------------------------------------------
    if (node == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }
    //--------------------------------------------------------------------------------------

    lista->inicio = node;

    lista->tam ++;

    return OK_LISTA;
}

int insertarPos (ListaP lista, void * item, int pos) {

    //Validaciones
    //--------------------------------------------------------------------------------------
    if (lista == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }

    if (pos < 0 || pos > lista->tam) {

        return PARAMETRO_INVALIDO_LISTA;
    }
    //--------------------------------------------------------------------------------------

    if (pos == 0) {

        return insertarInicio (lista, item);

    } else {

        NodoP aux;

        aux = lista->inicio;

        for (int i = 0; i < pos - 1; i ++) {

            aux = aux->proximo;
        }

        NodoP node = crearNodoLista (lista, aux->proximo, item);

        //Validacion
        //--------------------------------------------------------------------------------------
        if (node == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
        }
        //--------------------------------------------------------------------------------------

        aux->proximo = node;

        lista->tam ++;
    }

    return OK_LISTA;
}

int insertarFinal (ListaP lista, void * item) {

    return insertarPos (lista, item, lista->tam);
}
//--------------------------------------------------------------------------------------

//Eliminacion de nodos (Inicio - Pos - Final)
//--------------------------------------------------------------------------------------
int removerNodoInicio (ListaP lista, void * itemEliminado) {

    //Validaciones
    //--------------------------------------------------------------------------------------
    if (lista == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }

    if (estaVaciaLista (lista)) {

        return LISTA_VACIA;
    }
    //--------------------------------------------------------------------------------------

    NodoP aux;

    aux = lista->inicio;

    lista->inicio = aux->proximo;

    //--------------------------------------------------------------------------------------
    if (itemEliminado != NULL) {

        memcpy (itemEliminado, aux->item, lista->tamDatoBytes);
    }
    //--------------------------------------------------------------------------------------

    free (aux);

    aux = NULL;

    lista->tam --;

    return OK_LISTA;
}

int removerNodoPos (ListaP lista, void * itemEliminado, int pos) {

    //Validaciones
    //--------------------------------------------------------------------------------------
    if (lista == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }

    if (pos < 0 || pos >= lista->tam) {

        return PARAMETRO_INVALIDO_LISTA;
    }

    if (estaVaciaLista (lista)) {

        return LISTA_VACIA;
    }
    //--------------------------------------------------------------------------------------

    if (pos == 0) {

        return removerNodoInicio (lista, itemEliminado);

    } else {

        NodoP actual;

        NodoP anterior;

        actual = lista->inicio;

        anterior = NULL;

        for (int i = 0; i < pos; i ++) {

            anterior = actual;

            actual = actual->proximo;
        }

        anterior->proximo = actual->proximo;

        //Validacion
        //--------------------------------------------------------------------------------------
        if (itemEliminado != NULL) {

            memcpy (itemEliminado, actual->item, lista->tamDatoBytes);
        }
        //--------------------------------------------------------------------------------------

        free (actual);

        actual = NULL;

        lista->tam --;
    }

    return OK_LISTA;
}

int removerNodoFinal (ListaP lista, void * itemEliminado) {

    return removerNodoPos (lista, itemEliminado, lista->tam - 1);
}
//--------------------------------------------------------------------------------------

//Getters
//--------------------------------------------------------------------------------------
void * getElementoLista (ListaP lista, int pos) {

    //Validaciones
    //--------------------------------------------------------------------------------------
    if (lista == NULL) {

        return ESTRUCTURA_NO_INICIALIZADA_3;
    }

    if (pos < 0 || pos >= lista->tam) {

        return NULL;
    }

    if (estaVaciaLista (lista)) {

        return NULL;
    }
    //--------------------------------------------------------------------------------------

    NodoP aux;

    aux = lista->inicio;

    for (int i = 0; i < pos; i ++) {

        aux = aux->proximo;
    }

    return aux->item;
}

int getSizeLista (ListaP lista, int * tam) {

    if (estaVaciaLista(lista)) {

        *tam = 0;

    } else {

        *tam = lista->tam;
    }

    return OK_LISTA;
}
//--------------------------------------------------------------------------------------

//Funciones auxiliares
//--------------------------------------------------------------------------------------
int estaVaciaLista (ListaP lista) {

    if (lista->inicio == NULL) {

        return TRUE_LISTA;

    } else {

        return FALSE_LISTA;
    }
}

int liberarLista (ListaP lista) {

    if (estaVaciaLista(lista)) {

        printf ("\nLa lista no puede ser liberada ya que esta vacia.\n");

    } else {

        int tam;

        getSizeLista (lista, &tam);

        NodoP aux;

        aux = lista->inicio;

        for (int i = 0; i < tam; i ++) {

            free (aux);

            free (aux->item);

            aux = aux->proximo;
        }

        lista->inicio = NULL;

        lista->tam = 0;

        free (lista);

        if (estaVaciaLista (lista)) {

            printf ("\nLista liberada exitosamente.\n");
        }
    }

    return OK_LISTA;
}
//--------------------------------------------------------------------------------------
