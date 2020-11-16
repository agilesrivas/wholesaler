#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"
void mostrarCaja(Caja cajas)
{
    printf("-----------------------------------------\n");
    printf("Nombre del Cajero:%s\n",cajas.nombreCajero);
    printf("Numero de Caja:%d\n",cajas.nro_de_caja);
    printf("Tipo de Algoritmo:%s\n",cajas.AlgoritmodePlanificacion);
    printf("Tipo de Pago:%d\n",cajas.tipo_pago);
    printf("Estado de la Caja:Abierto/Cerrado:%d\n",cajas.abiertaOcerrada);
    nodo*aux=cajas.filita.inicio;
    mostrarLista(aux);
    printf("-----------------------------------------\n");
    printf("\n");
 system("pause>NULL");
system("cls");
}
void mostrarCajas(Caja cajas[8]) {
    int i;
    for (i=0; i < 8; i++) {
        mostrarCaja(cajas[i]);
    }
}
void cuentaCaja(Caja cajas,Punteros*aVariables)
{


    if(cajas.tipo_pago==1)
    {
        (*aVariables).Efectivo=(*aVariables).Efectivo+1;
                 (*aVariables).cantTotal=(*aVariables).cantTotal+1;


    }
    else if(cajas.tipo_pago==2)
    {
        (*aVariables).Debito=(*aVariables).Debito+1;
                 (*aVariables).cantTotal=(*aVariables).cantTotal+1;


    }
    else
    {
        (*aVariables).Todos=(*aVariables).Todos+1;
         (*aVariables).cantTotal=(*aVariables).cantTotal+1;
    }
}
void descuentaCajas(Caja cajas,Punteros*aVariables)
{
     if(cajas.tipo_pago==1)
    {
        (*aVariables).Efectivo=(*aVariables).Efectivo-1;
        (*aVariables).cantTotal=(*aVariables).cantTotal-1;

    }
    else if(cajas.tipo_pago==2)
    {
        (*aVariables).Debito=(*aVariables).Debito-1;
        (*aVariables).cantTotal=(*aVariables).cantTotal-1;

    }
    else
    {
        (*aVariables).Todos=(*aVariables).Todos-1;
        (*aVariables).cantTotal=(*aVariables).cantTotal-1;
    }

}
int verificarEstado(Caja cajas[],int posicion)
{

    int flag=0;
    if(cajas[posicion].abiertaOcerrada==1)
    {
        flag=1;
    }
    return flag;
}
int AbrirCaja(Caja cajitas[],int posaAbrir,Punteros*valores)
{
    int flag=0;
    if(cajitas[posaAbrir].abiertaOcerrada==0)
    {

        cajitas[posaAbrir].abiertaOcerrada=1;
        cuentaCaja(cajitas[posaAbrir],valores);
        flag=1;
    }
    return flag;
}
int cerrarCaja(Caja cajitas[],int posAcerrar,Punteros*valores)
{
    int flag=0;
    if(cajitas[posAcerrar].abiertaOcerrada==1)
    {
        if(cajitas[posAcerrar].filita.inicio!=NULL)
        {
            printf("La caja no puede ser cerrada ahi gente en ella\n");
        }
        else
        {
            cajitas[posAcerrar].abiertaOcerrada=0;
        descuentaCajas(cajitas[posAcerrar],valores);
        flag=1;
        }
    }
    return flag;

}

void asignacionDeCajas(Caja cajita[])
{
    strcpy(cajita[0].nombreCajero,"Elca Jero");
    cajita[0].nro_de_caja=0;
    cajita[0].tipo_pago=1;
    strcpy(cajita[0].AlgoritmodePlanificacion,"Fifo");
    cajita[0].abiertaOcerrada=0;
    cajita[0].CantMov=0;
    InicFila(&(cajita[0].filita));

    strcpy(cajita[1].nombreCajero, "pedro");
    cajita[1].nro_de_caja=1;
    cajita[1].tipo_pago=1;
    strcpy(cajita[1].AlgoritmodePlanificacion,"Srtf");
    cajita[1].abiertaOcerrada=0;
    cajita[1].CantMov=0;
    InicFila(&(cajita[1].filita));

    strcpy(cajita[2].nombreCajero,"Gonzalo");
    cajita[2].nro_de_caja=2;
    cajita[2].tipo_pago=2;
    strcpy(cajita[2].AlgoritmodePlanificacion,"Srtf");
    cajita[2].abiertaOcerrada=0;
    cajita[2].CantMov=0;
    InicFila(&(cajita[2].filita));

    strcpy(cajita[3].nombreCajero,"Elca Jero");
    cajita[3].nro_de_caja=3;
    cajita[3].tipo_pago=2;
    strcpy(cajita[3].AlgoritmodePlanificacion,"Prioridades No apropiativo");
    cajita[3].abiertaOcerrada=0;
    cajita[3].CantMov=0;
    InicFila(&(cajita[3].filita));

    strcpy(cajita[4].nombreCajero,"Martin");
    cajita[4].nro_de_caja=4;
    cajita[4].tipo_pago=2;
    strcpy(cajita[4].AlgoritmodePlanificacion,"RR Quantum");
    cajita[4].abiertaOcerrada=0;
    cajita[4].CantMov=0;
    InicFila(&(cajita[4].filita));

    strcpy(cajita[5].nombreCajero,"Elca Jero");
    cajita[5].nro_de_caja=5;
    cajita[5].tipo_pago=3;
    strcpy(cajita[5].AlgoritmodePlanificacion,"Fifo");
    cajita[5].abiertaOcerrada=0;
    cajita[5].CantMov=0;
    InicFila(&(cajita[5].filita));

    strcpy(cajita[6].nombreCajero,"Gisela");
    cajita[6].nro_de_caja=6;
    cajita[6].tipo_pago=3;
    strcpy(cajita[6].AlgoritmodePlanificacion,"PrioridadesNoAprop");
    cajita[6].abiertaOcerrada=0;
    cajita[6].CantMov=0;
    InicFila(&(cajita[6].filita));

    strcpy(cajita[7].nombreCajero,"Paula");
    cajita[7].nro_de_caja=7;
    cajita[7].tipo_pago=3;
    strcpy(cajita[7].AlgoritmodePlanificacion,"RR Quatum");
    cajita[7].abiertaOcerrada=0;
    cajita[7].CantMov=0;
    InicFila(&(cajita[7].filita));
}



int abrirTodasLasCajas(Caja cajas[8], Punteros *valores)
{
    int i;
    int flag=0;
    for (i = 0; i < 8; i++) {
        flag=AbrirCaja(cajas, i, valores);
    }
    return flag;
}

void procesarCola(Caja caja)
{
    procesarFila(&(caja.filita));
}

void procesarTodasLasColas(Caja cajas[])
{
    int i;
    for (i = 0; i < 8; i++) {
        procesarCola(cajas[i]);
    }
}

float obtenerTiempoProcesamiento(Caja caja)
{
    float contArticulos = 0;
    float contPersonas = 0;
    float promedio = 0;

    nodo* lista = caja.filita.inicio;

    if (lista != NULL) {
        while (lista != NULL) {
            contArticulos = contArticulos + lista->nueva.cantArticulos;
            contPersonas++;
            lista = lista->siguiente;
        }
        promedio = contArticulos / contPersonas;
    }

    return promedio;
}

float obtenerTiempoRespuesta(Caja caja)
{
    float tiempoDeEspera = 0;
    float contPersonas = 0;
    float promedio = 0;

    nodo* lista = caja.filita.inicio;

    if (lista != NULL) {
        while (lista != NULL) {
            tiempoDeEspera = tiempoDeEspera + lista->nueva.tiempoDeEspera;
            contPersonas++;
            lista = lista->siguiente;
        }
        promedio = tiempoDeEspera / contPersonas;
    }

    return promedio;
}

void mostrarCola(Caja caja)
{
    mostrarLista(caja.filita.inicio);
}
