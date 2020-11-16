#include "arbol.h"
#include "caja.h"
#include "menuNuevo.h"

int main()
{
    nodoArbol* arbol = inicArbol();

    Caja cajas[8];
    asignacionDeCajas(cajas);

    Punteros punteros;
    punteros.cantTotal=0;
    punteros.Debito=0;
    punteros.Efectivo=0;
    punteros.Todos=0;
    Punteros* valores = &punteros;

    int tiempo=-1;

    menuPrincipal(arbol, cajas, valores, tiempo);

    return 0;
}
