#ifndef CAJA_H_INCLUDED
#define CAJA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"
#include "persona.h"

typedef struct
{
    int nro_de_caja;
    char nombreCajero[40];
    int tipo_pago; // 1 efectivo, 2 crédito o débito, 3 todos
    int abiertaOcerrada;
    int CantMov;
    char AlgoritmodePlanificacion[30];

    Fila filita;
} Caja;
typedef struct
{
  int cantTotal;
  int Debito;
  int Efectivo;
  int Todos;
}Punteros;
Caja crearCaja();
void mostrarCaja(Caja cajas);
void mostrarCajas(Caja cajas[8]);
void cuentaCaja(Caja cajas,Punteros*aVariables);
void descuentaCajas(Caja cajas,Punteros*aVariables);
int verificarEstado(Caja cajas[],int posicion);
int AbrirCaja(Caja cajitas[],int posaAbrir,Punteros*valores);
int cerrarCaja(Caja cajitas[],int posAcerrar,Punteros*valores);
void asignacionDeCajas(Caja cajita[]);
int abrirTodasLasCajas(Caja cajas[8], Punteros *valores);
void procesarCola(Caja caja);
void procesarTodasLasColas(Caja cajas[]);
float obtenerTiempoProcesamiento(Caja caja);
float obtenerTiempoRespuesta(Caja caja);
void mostrarCola(Caja caja);

#endif // CAJA_H_INCLUDED
