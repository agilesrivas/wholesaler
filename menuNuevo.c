#include <stdio.h>
#include <stdlib.h>

#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"

#include <windows.h>
#include "math.h"


void menuArbol(nodoArbol *arbol)
{
    int opcionelegida=0;
    do
    {
        system("cls");
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
        printf("[1]: Mostrar Arbol en Preorder\n");
        gotoxy(60,14);
        printf("[2]: Mostrar Arbol en Inorder\n");
        gotoxy(60,15);
        printf("[3]: Mostrar Arbol en Postorder\n");
        gotoxy(60,16);
        printf("[4]: Salir\n");
        gotoxy(60,17);
        printf("\n");
        gotoxy(60,18);
        printf("Ingrese opcion: ");
        scanf("%d",&opcionelegida);
        system("cls");

        switch(opcionelegida)
        {
        case 1:
            if(arbol!=NULL)
            {
                mostrarArbolPreorder(arbol);
            }
            else
            {
                printf("Porfavor,cargue el arbol\n");
            }

            system("pause");
            break;

        case 2:
            if(arbol!=NULL)
            {
                mostrarArbolInorder(arbol);

            }
            else
            {
                printf("Porfavor,cargue el arbol\n");
            }

            system("pause");
            break;

        case 3:
            if(arbol!=NULL)
            {
                mostrarArbolPostorder(arbol);
            }
            else
            {
                printf("Porfavor,cargue el arbol\n");
            }


            system("pause");
            break;



        case 4:
            break;
        }
    }
    while(opcionelegida!=4);

}
nodoArbol*menuArchivo(nodoArbol* arbol, char nombreArchivo[30])
{
    int opcionelegida=0;
    int i=0;
    do
    {
        system("cls");
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
        printf("[1]:Cargar Archivo\n");
        gotoxy(60,14);
        printf("[2]:Mostrar Archivo\n");
        gotoxy(60,15);
        printf("[3]:Pasar Archivo a Arbol\n");
        gotoxy(60,16);
        printf("[4]:Salir\n");
        gotoxy(60,17);
        printf("\n");
        gotoxy(60,18);
        printf("Ingrese opcion: ");
        scanf("%d",&opcionelegida);
        system("cls");

        switch(opcionelegida)
        {
        case 1:
            // Generar Archivo nuevo
            printf("\nGenerando archivo nuevo...");
            precargaPersonas(nombreArchivo);
             for(i=0;i<5;i++)
            {
                printf("...\n");
                system("pause>NULL");
            }
            system("pause>NULL");
            printf("\nArchivo nuevo creado...\n");
            system("pause>NULL");
            break;

        case 2:
            mostrarArchivo(nombreArchivo);
            printf("\n");
            system("pause");
            break;

        case 3:
            printf("\nPasando datos de archivo al arbol...");
            arbol=inicArbol();
            arbol=pasajedePersonas(nombreArchivo, arbol);
             system("pause>NULL");
            if(arbol!=NULL)
            {

                printf("\nListo! Arbol cargado\n");
            }
            else
            {
                printf("No se cargo correctamente\n");
            }

            system("pause>NULL");
            break;
        case 4:
            break;
        }
    }
    while(opcionelegida!=4);
    return arbol;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////


void gotoxy( int X, int Y )
{
    COORD coord;
    coord.X = X;
    coord.Y = Y;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}

void menuPrincipal(nodoArbol* arbol, Caja cajas[], Punteros* valores, int tiempo)
{
    char nombreArchivo[30]="Proyect.utn";

    int opcionelegida=0;
    do
    {
        system("cls");
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
        printf("[4]:Administracion de Colas\n");
        gotoxy(60,17);
        printf("[5]:Salir\n");
        gotoxy(60,18);
        printf("\n");
        gotoxy(60,19);
        printf("Ingrese opcion: ");
        scanf("%d",&opcionelegida);
        system("cls");

        switch(opcionelegida)
        {
        case 1:
            arbol=menuArchivo(arbol, nombreArchivo);
            break;

        case 2:
            menuArbol(arbol);
            break;
        case 3:
            menuCajas(cajas,arbol, valores, tiempo);
            break;
        case 4:
            menuColas(cajas);
            break;
        case 5:
            break;
        }
    }
    while(opcionelegida!=5);
}

///////////////////////////////////////////////////////////////////////////////////////////////////



void menuCajas(Caja cajas[],nodoArbol*arbolito, Punteros* valores, int tiempo)
{
    int opcionelegida=0;
    int nrocaja=0;
    int i=0;
    int flag=0;
    Persona nueva;
    do
    {
        system("cls");
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
        printf("[1]: Crear Cajas\n");
        gotoxy(60,14);
        printf("[2]: Abrir una Caja\n");
        gotoxy(60,15);
        printf("[3]: Abrir todas las Cajas\n");
        gotoxy(60,16);
        printf("[4]: Cerrar la Caja\n");
        gotoxy(60,17);
        printf("[5]: Cerrar todas las Cajas\n");
        gotoxy(60,18);
        printf("[6]: Mostrar una caja\n");
        gotoxy(60,19);
        printf("[7]: Mostrar todas las cajas\n");
        gotoxy(60,20);
        printf("[8]: Procesar cajas\n");
        gotoxy(60,21);
        printf("[9]: Mostrar tiempos de espera y ejecucion\n");
        gotoxy(60,22);
        printf("[10]: Ingresar Persona nueva\n");
        gotoxy(60,23);
        printf("[11]: Pasar del Arbol a Cajas\n");
        gotoxy(60,24);
        printf("[12]: Salir\n");
        gotoxy(60,25);
        printf("\n");
        gotoxy(60,26);
        printf("Ingrese opcion: ");
        scanf("%d",&opcionelegida);
        system("cls");

        switch(opcionelegida)
        {
        case 1:
            printf("\nCreando cajas...");
            asignacionDeCajas(cajas);
            for(i=0;i<5;i++)
            {
                printf("...\n");
                system("pause>NULL");
            }
            system("pause>NULL");
            printf("\nListo! Cajas creadas\n");
            system("pause");
            break;

        case 2:
            printf("\nCual caja desea abrir [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {
                flag=AbrirCaja(cajas, nrocaja, valores);
                system("pause>NULL");
                if(flag==1)
                {
                    printf("\nLa caja nro %i ha sido abierta\n", nrocaja);
                }
                else
                    printf("No se logro abrir la caja N:%d",nrocaja);

            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7 \n");
            }
            system("pause");
            break;

        case 3:
            printf("\nAbriendo todas las cajas...");
            int i = 0;
            for (i = 0; i < 8; i++)
            {
                flag=AbrirCaja(cajas, i, valores);

            }
            system("pause>NULL");
            if(flag==1)
            {
                  printf("\nTodas las cajas han sido abiertas\n");
            }
            else
            {
                printf("No se abrieron las cajas\n");
            }

            system("pause");
            break;
        case 4:
            printf("\nCual caja desea cerrar [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {
                flag=cerrarCaja(cajas, nrocaja, valores);
                system("pause>NULL");
                if(flag==1)
                {
                     printf("\nLa caja nro %i ha sido cerrada\n", nrocaja);
                }

            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7 \n");
            }
            system("pause");
            break;
        case 5:
            printf("Cerrando....\n");
            for(i=0; i<8; i++)
            {
                cerrarCaja(cajas,i,valores);
            }
            system("pause>NULL");
            printf("\nTodas las cajas han sido cerradas\n");
            system("pause");

            break;
        case 6:
            printf("\nCual caja desea mostrar [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {
                mostrarCaja(cajas[nrocaja]);
            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7");
            }
            printf("\n");
            system("pause");
            break;

        case 7:
            mostrarCajas(cajas);
            printf("\n");
            system("pause");
            break;

        case 8:
            printf("\nProcesando las cajas...");
            procesarTodasLasColas(cajas);
             for(i=0;i<5;i++)
            {
                printf("...\n");
                system("pause>NULL");
            }
            system("pause>NULL");
            printf("Cajas procesadas\n");
            system("pause");
            break;

        case 9:
            printf("\nIngresar el nro de caja [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {
                int respuesta = obtenerTiempoRespuesta(cajas[nrocaja]);
                printf("\n- PROMEDIO DE RESPUESTA : %d", respuesta);

                // 4.b Procesar cajas: Mostrar tiempos de ejecucion
                int ejecucion = obtenerTiempoProcesamiento(cajas[nrocaja]);
                printf("\n- PROMEDIO EJECUCION  :%d", ejecucion);

            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7");
            }
            printf("\n");
            system("pause");
            break;

        case 10:
            flag=agregarPersonaNueva(cajas,valores);
            if(flag==1)
            {
                printf("La persona se derivo correctamente\n");
            }
            else
            {
                printf("Error\n");
            }
            system("pause");
            break;

        case 11:
            recorridosHaciaCaja(arbolito,cajas,valores,tiempo);
            break;
        case 12:
            break;
        }
    }
    while(opcionelegida!=12);
}
void recorridosHaciaCaja(nodoArbol*arbol,Caja arreglodeCajas[],Punteros*valores,int tiempo)
{
    int opcion=0;
    int flag=0;
    do
    {
        system("cls");

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
        system("COLOR B");
        gotoxy(60,14);
        printf("[1]:Recorrer PreOrden\n");
        gotoxy(60,15);
        printf("[2]:Recorrer InOrden\n");
        gotoxy(60,16);
        printf("[3]:Recorrer PostOrden\n");
        gotoxy(60,17);
        printf("[4]:Salir\n");
        gotoxy(60,18);
        printf("Ingrese Opcion: ");
        gotoxy(75,19);
        scanf("%d",&opcion);
        system("cls");
        switch(opcion)
        {
        case 1:

            flag=recorreInOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause>NULL");
            if(flag==1)
            {
                printf("Recorrido Exitoso\n");
            }
            else
            {
                printf("Error\n");
            }
            system("pause");

            break;
        case 2:
            flag=recorrePreOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause>NULL");
            if(flag==1)
            {
                printf("Recorrido Exitoso\n");
            }
            else
            {
                printf("Error\n");
            }
            system("pause");


            break;
        case 3:
            flag=recorrePostOrderYdestinaCaja(arreglodeCajas,arbol,valores,tiempo);
            system("pause>NULL");
            if(flag==1)
            {
                printf("Recorrido Exitoso\n");
            }
            else
            {
                printf("Error\n");
            }
            system("pause");

            break;
        case 4:

            break;

        }
    }
    while(opcion!=4);
}

/////////////////////////////////////////////


void menuColas(Caja cajas[])
{
    int nrocaja = 0;
    int opcionelegida=0;
    do
    {
        system("cls");
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
        printf("[1]: Mostrar colas desordenadas\n");
        gotoxy(60,14);
        printf("[2]: Mostrar colas ordenadas\n");
        gotoxy(60,15);
        printf("[3]: Procesar una cola\n");
        gotoxy(60,16);
        printf("[4]: Salir\n");
        gotoxy(60,17);
        printf("\n");
        gotoxy(60,18);
        printf("Ingrese opcion: ");
        scanf("%d",&opcionelegida);
        system("cls");

        switch(opcionelegida)
        {
        case 1:
            printf("\nIngresar el nro de caja [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {
                mostrarCola(cajas[nrocaja]);
            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7");
            }
            printf("\n");
            system("pause");
            break;

        case 2:
            printf("\nIngresar el nro de caja [0-7]: ");
            scanf("%d",&nrocaja);
            if (nrocaja >= 0 && nrocaja < 8)
            {

                // Ordena las colas
                ordenaLasColas(cajas, nrocaja);

                // Muestro la fila de personas (cola)
                mostrarCola(cajas[nrocaja]);
            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7");
            }

            printf("\n");
            system("pause");
            break;

        case 3:
            printf("\nIngresar el nro de caja [0-7]: ");
            scanf("%d",&nrocaja);

            if (nrocaja >= 0 && nrocaja < 8)
            {

                // Proceso la cola
                procesarCola(cajas[nrocaja]);

                // Muestro la fila de personas (cola)
                mostrarCola(cajas[nrocaja]);
            }
            else
            {
                printf("\nEl nro de caja debe ser entre 0 y 7");
            }

            printf("\n");
            system("pause");
            break;

        case 4:
            break;
        }
    }
    while(opcionelegida!=4);
}
