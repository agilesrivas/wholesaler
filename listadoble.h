#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "caja.h"
#include "persona.h"

typedef struct
{
    Persona nueva;
    struct nodo * siguiente;
    struct nodo * anterior;
} nodo;
nodo * inicLista();
nodo * crearNodoLista(Persona a);
nodo * agregarAlPrincipio(nodo * lista, nodo * nuevoNodo);
nodo * buscarUltimo(nodo * lista);
nodo * agregarAlFinal (nodo * lista, nodo * nuevoNodo);
nodo * agregarEnOrdenTipoCli (nodo * lista, nodo * nuevoNodo);
nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevoNodo);
void mostrarLista(nodo*lista);
nodo * borrarPersona(nodo * lista, char nombreApellido [40]);
nodo * borrarPrimero (nodo * lista);
int cuentaPersonas(nodo* lista);

#endif // LISTADOBLE_H_INCLUDED
