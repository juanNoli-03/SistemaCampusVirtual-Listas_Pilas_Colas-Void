#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

///ENUMS
//--------------------------------------------------------------------------------------
enum ESTADOS_LISTA {ESTRUCTURA_NO_INICIALIZADA_3, LISTA_VACIA, PARAMETRO_INVALIDO_LISTA, OK_LISTA, TRUE_LISTA = 1, FALSE_LISTA = 0};
//--------------------------------------------------------------------------------------

///TIPOS DE DATOS DE LA LISTA Y DEL NODO
//--------------------------------------------------------------------------------------
struct ListaE;

typedef struct ListaE * ListaP;

struct NodoE;

typedef struct NodoE * NodoP;
//--------------------------------------------------------------------------------------

///PRIMITIVAS

//Creacion de la lista y del nodo
//--------------------------------------------------------------------------------------
ListaP crearLista (int tamDelDato);

NodoP crearNodoLista (ListaP lista, NodoP proximo, void * item);
//--------------------------------------------------------------------------------------

//Inserccion de nodos
//--------------------------------------------------------------------------------------
int insertarInicio (ListaP lista, void * item);

int insertarPos (ListaP lista, void * item, int pos);

int insertarFinal (ListaP lista, void * item);
//--------------------------------------------------------------------------------------

//Eliminacion de nodos
//--------------------------------------------------------------------------------------
int removerInicio (ListaP lista, void * itemEliminado);

int removerPos (ListaP lista, void * itemEliminado, int pos);

int removerFinal (ListaP lista, void * itemEliminado);
//--------------------------------------------------------------------------------------

//Getters
//--------------------------------------------------------------------------------------
void * getElementoLista (ListaP lista, int pos);

int getSizeLista (ListaP lista, int * tam);
//--------------------------------------------------------------------------------------

//FuncionesAuxiliares
//--------------------------------------------------------------------------------------
int estaVaciaLista (ListaP lista);

int liberarLista (ListaP lista);
//--------------------------------------------------------------------------------------

#endif // LISTA_H_INCLUDED
