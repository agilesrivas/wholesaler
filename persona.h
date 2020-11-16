#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nombreApellido [40];
    int cantArticulos; // es el tiempo de ejecución
    int tiempoDeEspera; // es el tiempo de respuesta
    int tiempoProcesado; // es el tiempo que ya fue procesado en la línea de caja
    int tipo_cliente; // prioridad (1: embarazada, 2: jubilado y 3: normal)
    int tipo_pago;
    int extra;
} Persona;
int verificarValor(int tipoCoP);
Persona cargaDePersonaNueva();
void cargarArchivodePersonas(char direccion[]);
void Printeo(Persona aux);
void mostrarArchivo(char direccion[]);
int avisoPersonaExtra();
void guardadoDeTiempos(char direccion2[],Persona aAlmacenar);
void PrinteoTiempos(Persona aux);
void MostrarTiempos(char registro[]);
void precargaPersonas(char direccion[]);

#endif // PERSONA_H_INCLUDED
