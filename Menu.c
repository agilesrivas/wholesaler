#include <stdio.h>
#include <stdlib.h>
#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"
#include <windows.h>
#include "math.h"
///FUNCION DE COORDENADAS
/*
void gotoxy( int X, int Y )
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
*/
int printeoPrincipal()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");

    gotoxy(60,6);
    printf("-------------------------------\n");
    gotoxy(60,7);
    printf("|                             |\n");
    gotoxy(60,8);
    printf("  BIENVENIDO A MAYORISTA UTN\n");
    gotoxy(60,9);
    printf("|                             |\n");
    gotoxy(60,10);
    printf("-------------------------------\n");
    gotoxy(60,11);
    printf("\n");
    gotoxy(60,12);
    printf("\n");
    gotoxy(60,13);
    printf("[1]:Administracion del Archivo\n");
    gotoxy(60,14);
    printf("[2]:Administracion del Arbol\n");
    gotoxy(60,15);
    printf("[3]:Administracion de la Caja\n");
    gotoxy(60,16);
    printf("[4]:Administracion de Clientes\n");
    gotoxy(60,17);
    printf("[5]:Salir\n");
    gotoxy(60,18);
    printf("\n");

    gotoxy(60,19);
    printf("Ingrese opcion:");
    gotoxy(75,19);
    scanf("%d",&a);
    return a;
}
int printfMenu1()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Cargue personas al Archivo\n");
    gotoxy(60,6);
    printf("[2]:Mostrar Archivo\n");
    gotoxy(60,7);
    printf("[3]:Salir\n");
    gotoxy(60,8);
    printf("Ingrese Opcion: ");
    gotoxy(75,8);
    scanf("%d",&a);
    return a;
}
int printfMenu2()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Pasar de Archivo al Arbol\n");
    gotoxy(60,6);
    printf("[2]:Mostrar Arbol en Formas Diferentes\n");
    gotoxy(60,7);
    printf("[3]:Salir\n");
    gotoxy(60,8);
    printf("Ingrese Opcion: ");
    gotoxy(75,8);
    scanf("%d",&a);
    return a;
}
int printfMenu3()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Mostrar InOrden\n");
    gotoxy(60,6);
    printf("[2]:Mostrar PreOrden\n");
    gotoxy(60,7);
    printf("[3]:Mostrar PostOrden\n");
    gotoxy(60,8);
    printf("[4]:Salir\n");
    gotoxy(60,9);
    printf("Ingrese Opcion: ");
    gotoxy(75,9);
    scanf("%d",&a);
    return a;
}
int PrinteoMenu4()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Abrir Mayorista\n");
    gotoxy(60,6);
    printf("[2]:Pasar Arbol a Cajas\n");
    gotoxy(60,7);
    printf("[3]:Muestreo de Caja\n");
    gotoxy(60,8);
    printf("[4]:Salir\n");
    gotoxy(60,9);
    printf("Ingrese Opcion: ");
    gotoxy(75,9);
    scanf("%d",&a);
    return a;
}
int AbrirSuper5()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,4);
    printf("[1]:Crear cajas\n");
    gotoxy(60,5);
    printf("[2]:Abrir una Caja\n");
    gotoxy(60,6);
    printf("[3]:Cerrar una Caja\n");
    gotoxy(60,7);
    printf("[4]:Abrir Todas las Cajas\n");
    gotoxy(60,8);
    printf("[5]:Cerrar todas Las cajas\n");
    gotoxy(60,9);
    printf("[6]:Mostrar filas de una caja\n");
    gotoxy(60,10);
    printf("[7]:Mostrar todas las filas\n");
    gotoxy(60,11);
    printf("[8]:Salir\n");
    gotoxy(60,12);
    printf("Ingrese Opcion: ");
    gotoxy(75,12);
    scanf("%d",&a);
    return a;
}
int printfMenu6()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Mostrar una Caja\n");
    gotoxy(60,6);
    printf("[2]:Mostrar Todas las Cajas\n");
    gotoxy(60,7);
    printf("[3]:Salir\n");
    gotoxy(60,8);
    printf("Ingrese Opcion: ");
    gotoxy(75,8);
    scanf("%d",&a);
    return a;
}
int PrintfMenu7()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Agregar Cliente X\n");
    gotoxy(60,6);
    printf("[2]:Mostrar Caja\n");
    gotoxy(60,7);
    printf("[3]:Procesar Tiempos\n");
    gotoxy(60,8);
    printf("[4]:Promedios de Cajas\n");
    gotoxy(60,9);
    printf("[5]:Salir\n");
    gotoxy(60,10);
    printf("Ingrese Opcion: ");
    gotoxy(75,10);
    scanf("%d",&a);
    return a;
}
int PrinteoMenu8()
{
    int a=0;
    SetConsoleTitleA("Alejandro Giles Rivas y Paula Miceli Laboratorio ||");
    system("COLOR B");
    gotoxy(60,5);
    printf("[1]:Recorrer PreOrden\n");
    gotoxy(60,6);
    printf("[2]:Recorrer InOrden\n");
    gotoxy(60,7);
    printf("[3]:Recorrer PostOrden\n");
    gotoxy(60,8);
    printf("[4]:Salir\n");
    gotoxy(60,9);
    printf("Ingrese Opcion: ");
    gotoxy(75,9);
    scanf("%d",&a);
    return a;
}
void MenPrin()
{
    char opcion='s';
    int opcionelegida=0;

    char direccion[30]="Proyect.utn";

    nodoArbol*mayorista=inicArbol();
    Caja arreglodeCajas[8];
    Punteros valores;
    valores.cantTotal=0;
    valores.Debito=0;
    valores.Efectivo=0;
    valores.Todos=0;
    int tiempo=-1;
    do
    {
        system("cls");
        opcionelegida=printeoPrincipal();
        system("cls");
        switch(opcionelegida)
        {
        case 1:
            Men1(direccion);
            break;
        case 2:
            Men2(mayorista,direccion);
            break;
        case 3:
            Men4(mayorista,arreglodeCajas,&valores,tiempo);
            break;
        case 4:
            Men7(arreglodeCajas,&valores);
            break;
        case 5:
            break;
        }
    }
    while(opcionelegida!=5);
}
void Men1(char direccion[])
{
    int opcion;
    do
    {
        system("cls");
        opcion=printfMenu1();
        system("cls");
        switch(opcion)
        {
        case 1:
            precargaPersonas(direccion);
            system("pause");
            break;
        case 2:
            mostrarArchivo(direccion);
            system("pause");
            break;
        case 3:
            break;
        }
    }
    while(opcion!=3);

}
void Men2(nodoArbol*arbol,char direccion[])
{
    int opcion;
    do
    {
        system("cls");
        opcion=printfMenu2();
        system("cls");
        switch(opcion)
        {
        case 1:
            arbol=pasajedePersonas(direccion,arbol);
            system("pause");
            break;
        case 2:
            Men3(arbol);

            break;
        case 3:
            break;
        }
    }
    while(opcion!=3);
}

void Men3(nodoArbol*arbol)
{
    int opcion;
    do
    {
        system("cls");
        opcion=printfMenu3();
        system("cls");
        switch(opcion)
        {
        case 1:
            if(arbol!=NULL)
            {
                mostrarArbolInorder(arbol);

            }
            else
            {
                printf("Porfavor,Cargue el Arbol\n");

            }
            system("pause");

            break;
        case 2:
            if(arbol!=NULL)
            {
                mostrarArbolPostorder(arbol);

            }
            else
            {
                printf("Porfavor Cargue el Arbol\n");

            }
            system("pause");
            break;
        case 3:
           if(arbol!=NULL)
            {
                mostrarArbolPreorder(arbol);

            }
            else
            {
                printf("Porfavor Cargue el Arbol\n");
            }
            system("pause");
            break;
        case 4:

            break;

        }
    }
    while(opcion!=4);
}
void Men4(nodoArbol*arbol,Caja arreglodeCajas[],Punteros*valores,int tiempo)
{
    int opcion;
    do
    {
        system("cls");
        opcion=PrinteoMenu4();
        system("cls");
          switch(opcion)
        {
        case 1:

            Men5(arreglodeCajas,valores);


            break;
        case 2:
            Men8(arbol,arreglodeCajas,valores,tiempo);

            break;
        case 3:

            Men6(arreglodeCajas);

            break;
        case 4:

            break;

        }
    }while(opcion!=4);
}
void Men5(Caja cajitas[],Punteros*valores)
{
    int opcion=0;
     int i=0;
     int posAabrir;
    do
    {
        system("cls");
        opcion=AbrirSuper5();
        system("cls");
        switch(opcion)
        {
        case 1:
            printf("Espere mientras se crean las cajas\n");
            for(i=0; i<200; i++)
            {
                printf("......................................");
            }
            system("pause");
            system("cls");
            printf("\n Las Cajas pueden ser utilizadas,Bienvenidos\n");
            asignacionDeCajas(cajitas);
            system("pause");
            break;
        case 2:
            printf("Ingrese la Caja a Abrir: ");
            scanf("%d",&posAabrir);
            AbrirCaja(cajitas,posAabrir,valores);
            if(cajitas[posAabrir].abiertaOcerrada==1)
            {
                printf("La caja pudo ser abierta\n");
            }
            system("pause");
            break;
        case 3:
            printf("Ingrese la Caja a Cerrar: ");
            posAabrir=0;
            scanf("%d",&posAabrir);
            cerrarCaja(cajitas,posAabrir,valores);
            if(cajitas[posAabrir].abiertaOcerrada==0)
            {
                printf("La caja pudo ser cerrada\n");
            }
            system("pause");

            break;
        case 4:
            for(i=0; i<8; i++)
            {
                AbrirCaja(cajitas,i,valores);
            }
            system("pause");

            break;
        case 5:
            for(i=0; i<8; i++)
            {
                cerrarCaja(cajitas,i,valores);
            }
            system("pause");
            break;

        case 6:
            printf("Ingrese la Caja a mostrar: ");
            int nroCaja = 0;
            scanf("%d", &nroCaja);
            if (nroCaja >= 0 && nroCaja < 8) {
                mostrarCaja(cajitas[nroCaja]);
            }
            else {
                printf("El nro de caja tiene que ser entre 0 y 7..");
            }
            system("pause");

            break;

        case 7:
            mostrarCajas(cajitas);
            system("pause");

            break;

        case 8:

            break;

        }
    }while (opcion!=8);
}
void Men6(Caja cajita[])
{
    int opcion=0;
    int muestreocaja;
    int i=0;
    do
    {
        system("cls");
        opcion=printfMenu6();
        system("cls");
        switch(opcion)
        {
        case 1:
            printf("Ingrese que caja quiere mostrar: ");
            scanf("%d",&muestreocaja);
            mostrarCaja(cajita[muestreocaja]);
            system("pause");
            break;
        case 2:
            for(i=0; i<8; i++)
            {
                mostrarCaja(cajita[i]);
                printf("\n");
            }
            system("pause");
            break;
        case 3:

            break;

        }
    }while(opcion!=3);
}
void Men7(Caja arrayCaja[],Punteros*valores)

{
    float tiempoResp=0;
    float tiempoeje=0;
    int posProm=0;
    int opcion=0;
    do
    {
        system("cls");
        opcion=PrintfMenu7();
        system("cls");
        switch(opcion)
        {
        case 1:
            agregarPersonaNueva(arrayCaja,valores);
            system("pause");
            break;
        case 2:
              Men6(arrayCaja);
            break;
        case 3:
            procesarTodasLasColas(arrayCaja);
            break;
        case 4:
            printf("Ingrese la caja que quiere promediar\n");
            scanf("%d",&posProm);
            tiempoResp=obtenerTiempoRespuesta(arrayCaja[posProm]);
            tiempoeje=obtenerTiempoProcesamiento(arrayCaja[posProm]);
            printf("Tiempo De Respuesta : %d\n",tiempoResp);
            printf("Tiempo de Ejecucion: %d\n",tiempoeje);

            break;
        case 5:
            break;

        }
    }while(opcion!=5);
}
void Men8(nodoArbol*arbol,Caja arreglodeCajas[],Punteros*valores,int tiempo)
{
    int opcion=0;
    do
    {
        system("cls");
        opcion=PrinteoMenu8();
        system("cls");
        switch(opcion)
        {
        case 1:

            recorreInOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause");

            break;
        case 2:
            recorrePreOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause");


            break;
        case 3:
            recorrePostOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause");

            break;
        case 4:

            break;

        }
    }while(opcion!=4);
}

/////////////////////////////////////////////

void ListaDeEju()
{
    int opcion=0;
    char direccion[30]="datos.dat";
    nodoArbol*Bronca=inicArbol();
   Caja cajitas[8];
   Punteros valor;
   valor.Debito=0;
   valor.Efectivo=0;
   valor.Todos=0;
   int tiempo=-1;
   int respuesta=0;
   int ejecucion=0;
   int poscaja;
    do
    {    system("cls");
    system("COLOR E");
        printf("[1]:Manejo de Personas\n");
        printf("[2]:Asignacion a Caja y Abrirlas\n");
        printf("[3]:Recorre en distintas formas\n");
        printf("[4]:Ordena las Colas\n");
        printf("[5]:Agregar persona nueva\n");
        printf("[6]:Promedios\n");
        printf("[7]:Salir\n");
        printf("Cargue Opcion: ");
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:
            precargaPersonas(direccion);
            Bronca=pasajedePersonas(direccion,Bronca);
            mostrarArbolPreorder(Bronca);
            system("pause");
            break;
        case 2:
          asignacionDeCajas(cajitas);
          abrirTodasLasCajas(cajitas,&valor);
          mostrarCajas(cajitas);
          system("pause");
            break;
        case 3:
            recorreInOrderYdestinaCaja(cajitas,Bronca,&valor,tiempo);
         mostrarCajas(cajitas);
            system("pause");
            break;
        case 4:
            ordenarTodasLasColas(cajitas);
            mostrarCaja(cajitas[3]);
            system("pause");
            break;
        case 5:
            agregarPersonaNueva(cajitas,&valor);
             mostrarCajas(cajitas);
            system("pause");
            break;
        case 6:
            printf("Ingrese la caja a Obtener Tiempos: ");
            scanf("%d",&poscaja);
            respuesta=obtenerTiempoRespuesta(cajitas[poscaja]);
            ejecucion=obtenerTiempoProcesamiento(cajitas[poscaja]);
            printf("PROMEDIO DE RESPUESTA : %d\n",respuesta);
            printf("PROMEDIO EJECUCION  :%d\n",ejecucion);
            system("pause");
            break;
             case 7:
            break;
        }
    }while(opcion!=7);
}
