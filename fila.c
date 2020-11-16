#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"

void InicFila(Fila*filita)
{
    filita->inicio=NULL;
    filita->Final=NULL;
}

int filaVacia(Fila*a)
{
    int flag=0;
    if(a->inicio!=NULL)
    {
        flag=1;
    }
    return flag;
}

void MostrarFila(Fila*a)
{
    Persona ab;
    nodo*aux;
    aux=a->inicio;
    ab=aux->nueva;
    printf("Principio\n");
    printf("---------------------------------\n");
    Printeo(ab);
    aux=a->Final;
    ab=aux->nueva;
    printf("Final\n");
    printf("--------------------------------\n");
    Printeo(ab);
}

void agregarAfila(Fila* fila, Persona nueva)
{
    nodo* aux = crearNodoLista(nueva);

    if(fila->inicio == NULL)
    {
        fila->inicio=aux;
    }
    else
    {
        fila->inicio=agregarAlFinal(fila->inicio, aux);
    }
    fila->Final=buscarUltimo(fila->inicio);
}

int extraer(Fila*a)
{
    nodo*aux;
    nodo*aux2;
    int resp=0;
    if(a->inicio!=NULL)
    {
        aux=a->inicio;
        aux2=aux->siguiente;
    }
    else
    {
        if(a->inicio!=a->Final)
        {
            aux2->anterior=NULL;
            a->inicio=aux2;
        }
        else
        {
            a->Final=NULL;
            a->inicio=NULL;
        }
        resp=aux->nueva.tipo_cliente;
        free(aux);
    }
    return resp;
}

void agregarAfilaPrioridadesNoApropiativo(Fila* fila)
{
    nodo* listaOrdenada = inicLista();
    nodo* lista = fila->inicio;

    while (lista != NULL)
    {
        nodo* actual = lista;
        lista = lista->siguiente;
        actual->siguiente = NULL;
        listaOrdenada = agregarEnOrdenTipoCli(listaOrdenada, actual);
    }

    fila->inicio = listaOrdenada;
    fila->Final = buscarUltimo(listaOrdenada);
}

void ordenarFilaSJFapropiativo(Fila* fila)
{
    nodo* listaOrdenada = inicLista();
    nodo* lista = fila->inicio;

    while (lista != NULL)
    {
        nodo* actual = lista;
        lista = lista->siguiente;
        actual->siguiente = NULL;
        listaOrdenada = agregarEnOrdenPorCant(listaOrdenada, actual);
    }

    fila->inicio = listaOrdenada;
    fila->Final = buscarUltimo(listaOrdenada);
}

void RoundRobinPrimeroFila(Fila *fila)
{
    nodo* lista = fila->inicio;
    if (lista != NULL) {

        // Resto articulos en funcion al quantum
        lista->nueva.cantArticulos = lista->nueva.cantArticulos - 8;
        if (lista->nueva.cantArticulos < 0) {
            lista->nueva.cantArticulos = 0;
        }

        // Si quedan articulos, lo mando a lo ultimo
        if (lista->nueva.cantArticulos > 0) {
            nodo* ultimo = buscarUltimo(lista);

            if (ultimo != lista) {
                ultimo->siguiente = lista;
                fila->inicio = lista->siguiente;
                lista->siguiente = NULL;
                lista->anterior = ultimo;
            }
        }

        // Si no quedan articulos, lo elimino de la lista
        else {
            if (lista->siguiente == NULL) {
                fila->inicio = NULL;
            }
            else {
                nodo* nuevaLista = lista->siguiente;
                nuevaLista->anterior = NULL;
                fila->inicio = nuevaLista;
            }
        }
    }
}

void procesarFila(Fila *fila)
{
    nodo* lista = fila->inicio;

    int contArticulos = 0;
    while (lista != NULL) {

        // Asigno la cantidad de tiempo de espera
        lista->nueva.tiempoDeEspera = contArticulos;
        contArticulos = contArticulos + lista->nueva.cantArticulos;

        // Tiempo de procesado
        lista->nueva.tiempoProcesado = lista->nueva.cantArticulos;

        // Avanzo con la lista
        lista = lista->siguiente;
    }
}

//////////////////////////////////////////////////////////////////////

void ordenarRRApropQ8(Fila *fila)
{

    nodo* lista = fila->inicio;
    while (lista != NULL)
    {
        // Resto articulos en funcion al quantum
        lista->nueva.cantArticulos = lista->nueva.cantArticulos - 8;
        if (lista->nueva.cantArticulos < 0) {
            lista->nueva.cantArticulos = 0;
        }

        // Si a la persona le quedaron articulos
        if (lista->nueva.cantArticulos > 0)
        {


            lista = agregarAlFinal(lista, crearNodoLista(lista->nueva));
            lista=borrarPrimero(lista);
            int cantEnFila=extraer(fila);
        }
        else
        {
            lista=borrarPrimero(lista);
            int cantEnFila=extraer(fila);

        }

    }

    return lista;

}

/////////////////////////////////////////////////////////////////////////////////

/*void ordenarRRApropQ8Complejo (Fila *fila)
{

    nodo *lista = fila->inicio;
    while (listaOrdenada !=NULL)
    {
        tmpDeEspera=tmpDeEspera+tiempoEnLaCaja;
        tiempoEnLaCaja=0;
        int quantum=0;
        while (listaOrdenada->nueva.cantArticulos!=0 && quantum<8)
        {
            listaOrdenada->nueva.cantArticulos--;

            tiempoEnLaCaja=tiempoEnLaCaja+1;

            listaOrdenada->nueva.tiempoDeEspera=tmpDeEspera;
            listaOrdenada->nueva.tiempoProcesado=tiempoEnLaCaja;

            quantum++;

        }
        if (listaOrdenada->nueva.cantArticulos!=0)
        {
            listaOrdenada=agregarAlFinal(listaOrdenada, crearNodoLista(listaOrdenada->nueva));
            listaOrdenada=borrarPrimero(listaOrdenada);
            int cantEnFila=extraer(fila);
        }
        else
        {
            listaOrdenada=borrarPrimero(listaOrdenada);
            int cantEnFila=extraer(fila);

        }

    }

    return listaOrdenada;
    */

