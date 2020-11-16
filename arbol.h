#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"
typedef struct
{
    Persona p;
    struct nodoArbol * izq;
    struct nodoArbol * der;
} nodoArbol;

nodoArbol * inicArbol ();
nodoArbol * crearNodoArbol (Persona p);
nodoArbol * insertarNodoArbol (nodoArbol * a,Persona p);
void mostrarArbolPreorder (nodoArbol * a);
void mostrarArbolInorder (nodoArbol * a);
void mostrarArbolPostorder (nodoArbol * a);
nodoArbol* pasajedePersonas(char direccion[],nodoArbol*Familiar);
int recorrePreOrderYdestinaCaja (Caja arregloCajas[],nodoArbol*a,Punteros*valores, int tiempo);
int recorreInOrderYdestinaCaja (Caja arregloCajas[],nodoArbol * a,Punteros*valores, int tiempo);
int recorrePostOrderYdestinaCaja (Caja arregloCajas[],nodoArbol * a,Punteros*valores, int tiempo);
int derivadora (Caja arregloCajas[],Persona aAcomodar,Punteros*valores, int tiempo);
int posMenorEfectivo(Caja cajas[]);
int posMenorDebitoYtodos(Caja arreglocaja [], int a, int b, int c);
void insertaSinAcomodar(Caja ArregloCajas[], Persona aAcomodar, int posicion);
void ordenaLasColas(Caja ArregloCaja[], int posicion);
void ordenarTodasLasColas(Caja cajas[]);
nodo * insertaFifo (Fila*a);
nodo * insertaSjfAprop (Fila*a);
nodo * insertaPrioridadesNoAprop (Fila*a, Persona Aacomodar);
nodo * insertaRRApropQ8 (Fila*a, Persona Aacomodar);
nodo * ubicaExtraPorTiempo(Fila*a, Persona aAcomodar, int tiempo);
int derivarPersona(Caja cajas[], Persona aAcomodar, Punteros* valores, int tiempo);


#endif // ARBOL_H_INCLUDED
