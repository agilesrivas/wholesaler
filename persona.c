#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbol.h"
#include "caja.h"
#include "persona.h"
#include "fila.h"
#include "listadoble.h"

int verificarValor(int tipoCoP)
{
    int flag=0;
    if((tipoCoP>0)&&(tipoCoP<=2))
    {
        flag=1;
    }
    else
    {
        if(tipoCoP==3)
        {
            printf("Sera derivado a una caja que admite todos los medios de pago\n");
            flag=1;
        }
        else
        {
            flag=0;
        }
    }
    return flag;
}

Persona cargaDePersonaNueva()
{
    int flag=0;
    int tipoPago=0;
    Persona Nueva;
    int tipoCliente=0;
    system("Color B");
    printf("Ingrese Nombre y Apellido: ");
    fflush(stdin);
    gets(Nueva.nombreApellido);
    printf("Ingrese Cantidad de Articulos: ");
    scanf("%d",&Nueva.cantArticulos);
    Nueva.tiempoDeEspera=0;
    Nueva.tiempoProcesado=0;
    while(flag==0)
    {
        printf("Ingrese Tipo de Cliente: ");
        scanf("%d",&tipoCliente);
        flag=verificarValor(tipoCliente);
        if(flag==0)
        {
            printf("Valor invalido\n");
        }

    }
    Nueva.tipo_cliente=tipoCliente;
    flag=0;
    while(flag==0)
    {
        printf("Ingrese Forma de Pago: ");
        scanf("%d",&tipoPago);
        flag=verificarValor(tipoPago);
        if(flag==0)
        {
            printf("Valor invalido\n");
        }

    }
    flag=0;
    Nueva.tipo_pago=tipoPago;
    Nueva.extra=0;
    return Nueva;
}
void cargarArchivodePersonas(char direccion[])
{
    char opcion='s';
    FILE*buffer;
    Persona nueva;
    while((opcion=='s')||(opcion=='S'))
    {
        if((buffer=fopen(direccion,"rb"))!=NULL)
        {
            buffer=fopen(direccion,"ab");

        }
        else
        {
            buffer=fopen(direccion,"wb");
        }

        nueva=cargaDePersonaNueva();
        fwrite(&nueva,sizeof(Persona),1,buffer);
        printf("Desea Continuar Cargando Personas? S/n \n");
        fflush(stdin);
        scanf("%c",&opcion);
        system("cls");

    }
    fclose(buffer);
}
void Printeo(Persona aux)
{

    printf("-----------------------------------------\n");
    printf(" Nombre y Apellido: %s\n",aux.nombreApellido);
    printf(" Tiempo de Espera: %d \n",aux.tiempoDeEspera);
    printf(" Cantidad de Articulos:%d\n",aux.cantArticulos);
    printf(" Tiempo Procesado:%d \n",aux.tiempoProcesado);
    printf(" Tipo de Cliente:%d \n",aux.tipo_cliente);
    printf(" Tipo de Pago:%d    \n",aux.tipo_pago);
    printf("\n");
     printf("-----------------------------------------\n");
}


void mostrarArchivo(char direccion[])
{
    Persona aux;
    FILE*buff;
    if((buff=fopen(direccion,"rb"))!=NULL)
    {
        while(fread(&aux,sizeof(Persona),1,buff)>0)
        {
            Printeo(aux);
        }
    }
    fclose(buff);

}
int avisoPersonaExtra()
{
    int flag;
    flag=1;
    return flag;
}
void guardadoDeTiempos(char direccion2[],Persona aAlmacenar)
{
    FILE*Buffer;


    if((Buffer=fopen(direccion2,"ab"))!=NULL)
    {
        fwrite(&aAlmacenar,sizeof(Persona),1,Buffer);
    }
    else
    {
        Buffer=fopen(direccion2,"wb");
    }

}

void precargaPersonas(char direccion[])
{
    FILE * archivo;
    srand(time(NULL));
    if ((archivo= fopen(direccion,"wb")) != NULL) {
        Persona p;
        int i;
        for (i = 0; i <= 31; i++) {
            switch (i) {
                case 0: strcpy(p.nombreApellido, "ricky fort");
                    break;
                case 1: strcpy(p.nombreApellido, "ricky martin");
                    break;
                case 2: strcpy(p.nombreApellido, "ricky maravilla");
                    break;
                case 3: strcpy(p.nombreApellido, "ricky sarkani");
                    break;
                case 4: strcpy(p.nombreApellido, "ricky to");
                    break;
                case 5: strcpy(p.nombreApellido, "ricky espinoza");
                    break;
                case 6: strcpy(p.nombreApellido, "Bob Esponja");
                    break;
                case 7: strcpy(p.nombreApellido, "Patricio");
                    break;
                case 8: strcpy(p.nombreApellido, "Calamardo");
                    break;
                case 9: strcpy(p.nombreApellido, "Ed");
                    break;
                case 10: strcpy(p.nombreApellido, "Edd");
                    break;
                case 11: strcpy(p.nombreApellido, "Eddy");
                    break;
                case 12: strcpy(p.nombreApellido, "Tyrion Lannister");
                    break;
                case 13: strcpy(p.nombreApellido, "John Snow");
                    break;
                case 14: strcpy(p.nombreApellido, "Daenerys Targaryen");
                    break;
                case 15: strcpy(p.nombreApellido, "Arya Stark");
                    break;
                case 16: strcpy(p.nombreApellido, "Jerry Seinfeld");
                    break;
                case 17: strcpy(p.nombreApellido, "George Costanza");
                    break;
                case 18: strcpy(p.nombreApellido, "Cosmo Kramer");
                    break;
                case 19: strcpy(p.nombreApellido, "Elaine Benes");
                    break;
                case 20: strcpy(p.nombreApellido, "Dwight Schrute");
                    break;
                case 21: strcpy(p.nombreApellido, "Michael Scott");
                    break;
                case 22: strcpy(p.nombreApellido, "Geralt de Rivia");
                    break;
                case 23: strcpy(p.nombreApellido, "Cirilla de Cintra");
                    break;
                case 24: strcpy(p.nombreApellido, "Aquiles Bailo");
                    break;
                case 25: strcpy(p.nombreApellido, "Armando Esteban Quito");
                    break;
                case 26: strcpy(p.nombreApellido, "Elsa Pallo");
                    break;
                case 27: strcpy(p.nombreApellido, "Azucena Novoy");
                    break;
                case 28: strcpy(p.nombreApellido, "Yamimoto Nokamina");
                    break;
                case 29: strcpy(p.nombreApellido, "Juan Perez");
                    break;
                case 30: strcpy(p.nombreApellido, "Marta Sanchez");
                    break;
                case 31: strcpy(p.nombreApellido, "Rosa de Lejos");
                    break;
            }

            p.cantArticulos = (rand() % 20) + 1;

            // es el tiempo de respuesta
            p.tiempoDeEspera = 0;
            // es el tiempo que ya fue procesado en la línea de caja
            p.tiempoProcesado = 0;

            // prioridad (1: embarazada, 2: jubilado y 3: normal)
            p.tipo_cliente = (rand() % 3) + 1;
            p.tipo_pago = (rand() % 2) + 1;
            p.extra = 0;

            fwrite(&p, sizeof(Persona), 1, archivo);
        }
        fclose(archivo);
    }
}
