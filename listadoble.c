
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"


nodo * inicLista()
{
    return NULL;
}

nodo * crearNodoLista(Persona a)
{
    nodo * nuevo=(nodo*)malloc(sizeof(nodo));
    nuevo->nueva=a;
    nuevo->anterior=NULL;
    nuevo->siguiente=NULL;

    return nuevo;
}

nodo * agregarAlPrincipio(nodo* lista, nodo* nuevoNodo)
{
    nuevoNodo->siguiente=lista;
    if (lista!=NULL)
    {
        lista->anterior=nuevoNodo;
    }
    lista = nuevoNodo;
    return nuevoNodo;
}

nodo * buscarUltimo(nodo * lista)
{
    nodo * ult;
    if(lista==NULL)
    {
        ult=NULL;
    }
    else
    {
        if(lista->siguiente==NULL)
        {
            ult=lista;
        }
        else
        {
            ult=buscarUltimo(lista->siguiente);
        }
    }
    return ult;
}
nodo * agregarAlFinal (nodo * lista, nodo * nuevoNodo)
{
    nodo * ultimo=NULL;
    if (lista==NULL)
    {
        lista=nuevoNodo;
    }
    else
    {
        ultimo=buscarUltimo(lista);
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
    }
    return lista;
}

nodo * agregarEnOrdenTipoCli (nodo * lista, nodo * nuevoNodo)
{
    if (lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->nueva.tipo_cliente < lista->nueva.tipo_cliente)
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * seg  = lista->siguiente;
            nodo * ante = lista;
            while (seg != NULL && seg->nueva.tipo_cliente < nuevoNodo->nueva.tipo_cliente)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            if (seg!=NULL)
            {
                seg->anterior=nuevoNodo;
            }
        }
    }
    return lista;
}

nodo * agregarEnOrdenPorCant (nodo * lista, nodo * nuevoNodo)
{
    if (lista==NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        if (nuevoNodo->nueva.cantArticulos< lista->nueva.cantArticulos)
        {
            lista = agregarAlPrincipio(lista, nuevoNodo);
        }
        else
        {
            nodo * seg  = lista->siguiente;
            nodo * ante = lista;
            while (seg != NULL && seg->nueva.cantArticulos < nuevoNodo->nueva.cantArticulos)
            {
                ante = seg;
                seg = seg->siguiente;
            }
            ante->siguiente=nuevoNodo;
            nuevoNodo->anterior=ante;
            nuevoNodo->siguiente=seg;
            if (seg!=NULL)
            {
                seg->anterior=nuevoNodo;
            }
        }
    }
    return lista;
}

void mostrarLista(nodo*lista)
{
    nodo*seg=lista;
    while(seg!=NULL)
    {
        system("pause>NULL");
        Printeo(seg->nueva);

        seg=seg->siguiente;
    }
}

nodo * borrarPersona(nodo * lista, char nombreApellido [40])
{
nodo * seguidora = lista;
    if (lista != NULL)
    {
        while ((seguidora != NULL) && (strcmp(seguidora->nueva.nombreApellido, nombreApellido) != 0))
        {
            seguidora = seguidora->siguiente;
        }


        if (seguidora != NULL)
        {

            if (lista == seguidora)
            {
                lista = lista->siguiente;
                free(lista->anterior);
                lista->anterior=NULL;
            }

            else
            {
                if (seguidora->siguiente!= NULL)
                {
                    nodo * siguiente = seguidora->siguiente;
                    nodo * anterior = seguidora->anterior;

                    siguiente->anterior=anterior;
                    anterior->siguiente=siguiente;
                }

                else
                {
                    nodo * anterior = seguidora->anterior;
                    anterior->siguiente=NULL;
                }
                free(seguidora);
            }

        }
    }
}
nodo * borrarPrimero (nodo * lista)
{
    if (lista!=NULL)
    {
        if(lista->siguiente==NULL)
        {
            free(lista);
        }
        else
        {
            lista=lista->siguiente;
            free(lista->anterior);
            lista->anterior=NULL;
        }
    }
    return lista;
}

int cuentaPersonas(nodo*lista)
{
    int resp=0;
    nodo*seg=lista;
    while(seg!=NULL)
    {
        resp=resp+1;
        seg=seg->siguiente;
    }
    return resp;
}
