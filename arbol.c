#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "persona.h"
#include "listadoble.h"


nodoArbol * inicArbol ()
{
    return NULL;
}
nodoArbol * crearNodoArbol (Persona p)
{
    nodoArbol * nuevo=(nodoArbol*)malloc(sizeof(nodoArbol));
    nuevo->p=p;
    nuevo->der=NULL;
    nuevo->izq=NULL;

    return nuevo;
}
nodoArbol * insertarNodoArbol (nodoArbol * a,Persona p)
{

    if(a==NULL)
    {
        a=crearNodoArbol(p);
    }
    else
    {
        if((strcmp(a->p.nombreApellido,p.nombreApellido))>0)
        {
            a->der=insertarNodoArbol(a->der, p);
        }
        else
        {
            a->izq=insertarNodoArbol(a->izq, p);
        }
    }
    return a;
}

void mostrarArbolPreorder (nodoArbol * a)
{
   int i=0;
    if (a!=NULL)
    {
         system("COLOR E");
        Printeo(a->p);
        system("pause>NULL");
        system("cls");
        mostrarArbolPreorder(a->izq);
        mostrarArbolPreorder(a->der);

    }
}

void mostrarArbolInorder (nodoArbol * a)
{

    if (a!=NULL)
    {
        mostrarArbolInorder(a->izq);

         system("COLOR C");
        Printeo(a->p);
        system("pause>NULL");
        system("cls");

        mostrarArbolInorder(a->der);
    }
}

void mostrarArbolPostorder (nodoArbol * a)
{

    if (a!=NULL)
    {
        mostrarArbolPostorder(a->izq);
        mostrarArbolPostorder(a->der);
 system("COLOR D");
        Printeo(a->p);
        system("pause>NULL");
        system("cls");
    }
}
nodoArbol*pasajedePersonas(char direccion[],nodoArbol*Familiar)
{
    Persona aux;
    FILE* buff;
    if ((buff=fopen(direccion,"rb"))!=NULL)
    {

        while(fread(&aux,sizeof(Persona),1,buff)>0)
        {
            Familiar=insertarNodoArbol(Familiar,aux);
        }
    }
    fclose(buff);
    return Familiar;

}


nodoArbol * nodoMasDerecho(nodoArbol * a)
{
    nodoArbol * aux;
    if(a->der==NULL)
    {
        aux=a;
    }
    else
    {
        aux=nodoMasDerecho(a->der);
    }
    return aux;
}

nodoArbol * nodoMasIzquierdo(nodoArbol * a)
{
    nodoArbol * aux;
    if(a->izq==NULL)
    {
        aux=a;
    }
    else
    {
        aux=nodoMasIzquierdo(a->izq);
    }
    return aux;
}

nodoArbol * borrarUnNodoArbol(nodoArbol * a, char nYa [40])
{

    if(a!=NULL)
    {
        if(strcmp(nYa, a->p.nombreApellido)>0)
        {
            a->der=borrarUnNodoArbol(a->der, nYa);
        }
        else if (strcmp(nYa, a->p.nombreApellido)<0)
        {
            a->izq=borrarUnNodoArbol(a->izq, nYa);
        }

        else
        {
            if(a->izq!=NULL)
            {
                nodoArbol * nmd = nodoMasDerecho(a->izq);

                a->p = nmd->p;

                a->izq=borrarUnNodoArbol(a->izq, a->p.nombreApellido);
            }
            else if(a->der!=NULL)
            {
                nodoArbol * nmi = nodoMasIzquierdo(a->der);

                a->p = nmi->p;

                a->der=borrarUnNodoArbol(a->der, a->p.nombreApellido);

            }
            else
            {
                free(a);
                a=NULL;
            }
        }
    }
    return a;
}


int  recorrePreOrderYdestinaCaja (Caja arregloCajas[],nodoArbol*a,Punteros*valores, int tiempo)
{
    int flag;
    if (a != NULL)
    {
        Persona aAcomodar=a->p;
        flag=derivadora(arregloCajas,aAcomodar, valores, tiempo);
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->izq, valores, tiempo);
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->der, valores, tiempo);
    }
    return flag;
}

int  recorreInOrderYdestinaCaja (Caja arregloCajas[],nodoArbol * a,Punteros*valores, int tiempo)
{
    int flag;
    if (a!=NULL)
    {
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->izq,valores, tiempo);
        Persona aAcomodar=a->p;
        flag=derivadora(arregloCajas,aAcomodar,valores, tiempo);
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->der,valores, tiempo);
    }
    return flag;
}

int recorrePostOrderYdestinaCaja (Caja arregloCajas[],nodoArbol * a,Punteros*valores, int tiempo)
{
    int flag=0;
    if (a!=NULL)
    {
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->izq,valores, tiempo);
        flag=recorrePreOrderYdestinaCaja(arregloCajas,a->der,valores, tiempo);
        Persona aAcomodar=a->p;
        flag=derivadora (arregloCajas,aAcomodar,valores, tiempo);
    }
    return flag;
}

int derivadora(Caja arregloCajas[],Persona aAcomodar,Punteros*valores, int tiempo)
{
    int resp=aAcomodar.tipo_pago;
    int posicion=-1;
    int flag=0;

    if ((*valores).cantTotal==0)
    {
        printf("No hay cajas abiertas. Abra cajas para empezar a operar\n Presione una tecla para continuar\n");
    }
    else
    {
        // Si el pago es en efectivo
        if (resp==1)
        {
            // Me fijo si hay cajas abiertas en efectivo y en las de todos los medios de pago

            // Si estan abiertas las 2
            if (((*valores).Efectivo)>0 && ((*valores).Todos)>0 )
            {
                // Busco la caja que tiene la menor cantidad de personas
                int menorEfect=posMenorEfectivo(arregloCajas);

                // Obtengo el comienzo de la fila
                nodo*lista=arregloCajas[menorEfect].filita.inicio;

                // Cuento cuantas personas hay en la fila
                int cuantosEfectivo=cuentaPersonas(lista);

                //
                int menorTodos = posMenorDebitoYtodos(arregloCajas, 5,6,7);
                nodo* lista2 = arregloCajas[menorTodos].filita.inicio;
                int cuantosTodos = cuentaPersonas(lista2);

                if (cuantosEfectivo <=cuantosTodos)
                {
                    posicion=menorEfect;
                    if (tiempo > 0 && posicion == 1)
                    {
                        ubicaExtraPorTiempo(&(arregloCajas[posicion].filita),aAcomodar,tiempo);
                        flag=1;
                    }
                    else
                    {
                        insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                        flag=1;
                    }
                }
                else
                {
                    posicion = menorTodos;
                    insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                    flag=1;
                }
            }
            else if (((*valores).Efectivo)>0 && ((*valores).Todos)<=0 )
            {
                int menorEfect=posMenorEfectivo(arregloCajas);
                posicion=menorEfect;
                insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                flag=1;
            }
            else
            {
                if (((*valores).Todos)>0 && ((*valores).Efectivo)<=0)
                {
                    int menorTodos=posMenorDebitoYtodos(arregloCajas, 5,6,7);
                    posicion=menorTodos;
                    insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                    flag=1;
                }
                else
                {
                    printf("No hay cajas disponibles que operen con su medio de pago.Seleccione otro medio o vuelva luego!\n");
                }
            }
        }

        else if (resp==2)
        {
            // Si hay cajas de debito abiertas y ademas hay cajas abiertas de todos los medios de pago...
            if (((*valores).Debito)>0 && ((*valores).Todos)>0 )
            {
                // Cuantas personas en la caja de DEBITO que menos personas tiene
                int menorDebito = posMenorDebitoYtodos(arregloCajas, 2,3,4);
                nodo* lista = arregloCajas[menorDebito].filita.inicio;
                int cuantosDebito = cuentaPersonas(lista);

                // Cuantas personas en la caja de TODOS que menos personas tiene
                int menorTodos = posMenorDebitoYtodos(arregloCajas, 5,6,7);
                nodo* lista2 = arregloCajas[menorTodos].filita.inicio;
                int cuantosTodos = cuentaPersonas(lista2);

                if (cuantosDebito <= cuantosTodos)
                {
                    posicion = menorDebito;
                    if (tiempo > 0 && posicion == 2)
                    {
                        ubicaExtraPorTiempo(&(arregloCajas[posicion].filita), aAcomodar, tiempo);
                        flag=1;
                    }
                    else
                    {
                        insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                        flag=1;
                    }
                }
                else
                {
                    posicion = menorTodos;
                    insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                    flag=1;
                }
            }

            // Si la caja de debito esta abierta y la de todos esta cerrada
            else if (((*valores).Debito)>0 && ((*valores).Todos)<=0)
            {
                int menorDebito = posMenorDebitoYtodos(arregloCajas,2,3,4);
                posicion = menorDebito;
                insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                flag=1;
            }
            else
            {
                // Si la caja de debito esta cerrada y la de todos los medios de pago esta abierta
                if ((*valores).Todos>0 && (*valores).Debito<=0)
                {
                    int menorTodos = posMenorDebitoYtodos(arregloCajas, 5,6,7);
                    posicion = menorTodos;
                    insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                    flag=1;
                }
                else
                {
                    printf("No hay cajas disponibles que operen con su medio de pago.Seleccione otro medio, o vuelva luego!\n");
                }
            }
        }
        else
        {
            // Si la de todos los medios de pago esta abierta, y las cajas de debito y efectivo estan cerradas
            if (( (*valores).Todos > 0 && (*valores).Debito == 0) && ((*valores).Todos > 0 &&(*valores).Efectivo == 0))
            {
                int menorTodos = posMenorDebitoYtodos(arregloCajas, 5,6,7);
                posicion = menorTodos;
                insertaSinAcomodar(arregloCajas, aAcomodar, posicion);
                flag=1;
            }
            else
            {
               // printf("No hay cajas disponibles que operen con su medio de pago.Seleccione otro medio, o vuelva luego!\n");
            }
        }
    }
}

int posMenorEfectivo(Caja cajas[])
{
    //retorna la posicion del arreglo con menos personas
    int rta=0;

    if (cajas[0].abiertaOcerrada==1 && cajas[1].abiertaOcerrada==1)
    {
        nodo*lista1=cajas[0].filita.inicio;
        nodo*lista2=cajas[1].filita.inicio;

        int cuantosCaja1=cuentaPersonas(lista1);
        int cuantosCaja2=cuentaPersonas(lista2);

        if (cuantosCaja1 > cuantosCaja2)
        {
            rta=1;
        }
    }
    else if (cajas[0].abiertaOcerrada==1 && cajas[1].abiertaOcerrada==0)
    {
        rta=0;
    }
    else if (cajas[0].abiertaOcerrada==0 && cajas[1].abiertaOcerrada==1)
    {
        rta=1;
    }

    return rta;
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////PASAR A FILA/////////////////////////////////////////////////////////////
// devuelve posicion del arreglo donde hay menos personas
int posMenorDebitoYtodos(Caja cajas [], int a, int b, int c)
{
    // Respuesta por defecto
    int rta = a;


    int cuantosCajaA = 0;
    int cuantosCajaB = 0;
    int cuantosCajaC = 0;

    nodo*lista1=inicLista();
    lista1=cajas[a].filita.inicio;

    nodo*lista2=inicLista();
    lista2=cajas[b].filita.inicio;
    nodo*lista3=cajas[c].filita.inicio;

    if (cajas[a].abiertaOcerrada==1)
    {
        cuantosCajaA = cuentaPersonas(lista1);
    }
    if (cajas[b].abiertaOcerrada==1)
    {
        cuantosCajaB=cuentaPersonas(lista2);
    }
    if (cajas[c].abiertaOcerrada==1)
    {
        cuantosCajaC=cuentaPersonas(lista3);
    }

    // Comparando para obtener donde ubicar a las personas
    if ((cuantosCajaA <= cuantosCajaB) && (cuantosCajaA <= cuantosCajaC))
    {
        rta=a;
    }
    else if ((cuantosCajaB < cuantosCajaA) && (cuantosCajaB <= cuantosCajaC))
    {
        rta=b;
    }
    else if ((cuantosCajaC < cuantosCajaB) && (cuantosCajaC < cuantosCajaA))
    {
        rta=c;
    }
    return rta;
}
//// no se q pasar de parametrooo (el arreglo, la lista o la fila)
/////////////////////////////////////////////////////////////////////


void insertaSinAcomodar(Caja ArregloCajas[], Persona aAcomodar, int posicion)
{
    agregarAfila(&(ArregloCajas[posicion].filita), aAcomodar);
}

void ordenarTodasLasColas(Caja cajas[])
{
    int i;
    for (i = 0; i < 8; i++) {
        ordenaLasColas(cajas, i);
    }
}

void ordenaLasColas(Caja ArregloCaja[], int posicion)
{
    if (posicion == 0 || posicion == 5) {
        // En FiFo no hay que hacer nada...
    }
    else if (posicion == 3 || posicion == 6) {
        agregarAfilaPrioridadesNoApropiativo(&(ArregloCaja[posicion].filita.inicio));
    }
    else if (posicion == 1 || posicion == 2) {
        ordenarFilaSJFapropiativo(&(ArregloCaja[posicion].filita));
    }
    else if (posicion == 4 || posicion == 7) {
        RoundRobinPrimeroFila(&(ArregloCaja[posicion].filita));
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////ACA ARMO LOS ALGORITMOS///////////////////////////////////////////////////

///////////////////////////VER DONDE SE AGREGA EL NUEVO, PORQUE HASTA Q NO SE AGREGUE EL NUEVO NO HAY Q HACER MODIFICACIONES

nodo * insertaSjfAprop (Fila*a)
{
    nodo * listaOrdenada=inicLista();
    nodo * lista=a->inicio;

    while (lista->siguiente!=NULL)
    {
        nodo * aOrdenar=lista;
        aOrdenar->siguiente=NULL;
        lista=borrarPrimero(lista);

        nodo * listaOrdenada=agregarEnOrdenPorCant(listaOrdenada, aOrdenar);
    }

    int tmpDeEspera=0;
    int tiempoEnLaCaja=0;

    while (listaOrdenada !=NULL)
    {
        tmpDeEspera=tmpDeEspera+tiempoEnLaCaja;
        tiempoEnLaCaja=0;
        int articulos=lista->nueva.cantArticulos;
        while (articulos!=0)
        {
            articulos--;

            tiempoEnLaCaja=tiempoEnLaCaja+1;

            listaOrdenada->nueva.tiempoDeEspera=tmpDeEspera;
            listaOrdenada->nueva.tiempoProcesado=tiempoEnLaCaja;
        }
    }

    return listaOrdenada;

}

nodo * insertaPrioridadesNoAprop (Fila* fila, Persona Aacomodar)
{
    nodo * listaOrdenada = inicLista();
    nodo * lista = fila->inicio;
    while (lista != NULL)
    {
        nodo* aOrdenar = lista;
        aOrdenar->siguiente = NULL;
        lista=borrarPrimero(lista);

        nodo * listaOrdenada=agregarEnOrdenTipoCli(listaOrdenada, aOrdenar);
    }
    int tmpDeEspera=0;
    int tiempoEnLaCaja=0;

    while (lista !=NULL)
    {
        tmpDeEspera=tmpDeEspera+tiempoEnLaCaja;
        tiempoEnLaCaja=0;
        int articulos=lista->nueva.cantArticulos;
        while (articulos!=0)
        {
            articulos--;

            tiempoEnLaCaja=tiempoEnLaCaja+1;

            listaOrdenada->nueva.tiempoDeEspera=tmpDeEspera;
            listaOrdenada->nueva.tiempoProcesado=tiempoEnLaCaja;
        }
    }

    return listaOrdenada;
}
//la derivadora identificaba si entraba alguien nuevo por el tiempo
//asiq aca lo inserto donde vaya y en la q agrego a la persona llamo a derivadora

nodo * ubicaExtraPorTiempo(Fila* fila, Persona aAcomodar, int tiempo)
{
    nodo* nuevo = crearNodoLista(aAcomodar);

    if (fila->inicio == NULL) {
        fila->inicio = nuevo;
        fila->Final = nuevo;
    }
    else {

        nodo* lista = fila->inicio;

        int tiempoTotal = 0;
        while (lista != NULL && (tiempoTotal + lista->nueva.cantArticulos) <= tiempo)
        {
            tiempoTotal = tiempoTotal + lista->nueva.cantArticulos;
            lista = lista->siguiente;
        }

        // ahora lista tiene al que estaba siendo atendido cuando entro el nuevo
        // o al que estaba a punto de ser atendido si en ese momento habia terminado alguien.
        while (lista != NULL && lista->nueva.cantArticulos <= aAcomodar.cantArticulos)
        {
            lista = lista->siguiente;
        }

        // Agrego al final
        if (lista == NULL) {
            nuevo->anterior = fila->Final;
            nodo *nodoFinal = fila->Final;
            nodoFinal->siguiente = nuevo;
            fila->Final = nuevo;
        }
        else {

            nodo * anterior = lista->anterior;

            // Agrego al principio
            if (anterior == NULL) {
                nuevo->anterior = NULL;
                fila->inicio = nuevo;
            }
            else {
                anterior->siguiente = nuevo;
                nuevo->anterior = anterior;
                lista->anterior = nuevo;
            }

            nuevo->siguiente = lista;
        }
    }

    return fila->inicio;
}
//estas tambien las tendria q mover a otra libreria
int agregarPersonaNueva(Caja cajas[], Punteros* valores)
{
    Persona persona = cargaDePersonaNueva();
    int tiempo = 0;
    int flag=0;
    printf("En que tiempo desea ingresarlo?: ");
    scanf("%d", &tiempo);
    flag=derivarPersona(cajas, persona, valores, tiempo);
    return flag;
}

int derivarPersona(Caja cajas[], Persona aAcomodar, Punteros* valores, int tiempo)
{
    int flag=0;
    flag=derivadora(cajas, aAcomodar, valores, tiempo);
    return flag;
}
