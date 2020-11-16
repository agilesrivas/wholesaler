#ifndef MENUNUEVO_H_INCLUDED
#define MENUNUEVO_H_INCLUDED

#include "arbol.h"
#include "caja.h"
nodoArbol*menuArchivo(nodoArbol* arbol, char nombreArchivo[30]);
void menuPrincipal(nodoArbol* arbol, Caja cajas[], Punteros* valores, int tiempo);

#endif // MENUNUEVO_H_INCLUDED
