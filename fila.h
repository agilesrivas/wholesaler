#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "persona.h"


typedef struct
{
    struct nodo *inicio;
    struct nodo *Final;

} Fila;
void InicFila(Fila*filita);
int FilaVacia(Fila*a);
void agregarAfila(Fila*a,Persona nueva);
void MostrarFila(Fila*a);
int Extraer(Fila a);
void agregarAfilaPrioridadesNoApropiativo(Fila* fila);
void ordenarFilaSJFapropiativo(Fila* fila);
void ordenarRRApropQ8 (Fila *fila);
void RoundRobinPrimeroFila(Fila *fila);
void procesarFila(Fila *fila);

#endif // FILA_H_INCLUDED
