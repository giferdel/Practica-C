// 1. Del registro de partes meteorológico, de un mes de 30 días, se registra la fecha,
//  temperatura máxima y temperatura mínima.
//  Diseñar un algoritmo que permita informar:
//  A- el día más frío y cual fue su temperatura.
//  B- el día más  cálido y cual fue su temperatura.


//LIBRERIAS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10
#define VISTA "\n****************************************\n"

//ESTRUCTURA
struct registroMes{
    int fecha;
    int tempMax;
    int tempMin;
};

//VARIABLES GLOBALES
char mes[10];
int opcion = -1;

//FUNCION PRINCIPAL (MAIN)
int main(void){
    struct registroMes diaN[TAM];
    struct registroMes aux[2];                  //VECTOR DE ORDENAMIENTO

    for (int i = 0; i < TAM; i++){              //INICIALIZACION DEL VECTOR DE CARGA
        diaN[i].fecha = 0;
        diaN[i].tempMax = 0;
        diaN[i].tempMin = 0;
    }
    for (int i = 0; i < 2; i++){              //INICIALIZACION DE VECTOR AUXILIAR
        aux[i].fecha = 0;
        aux[i].tempMax = 0;
        aux[i].tempMin = 0;
    } 
    
    //INGRESO DE MES PARA EL REGISTRO
    system("cls");
    printf(VISTA);
    printf("  SISTEMA DE REGISTRO DE TEMPERATURAS");
    printf(VISTA);
    printf("\nIngresar mes para registro (de 30 dias): ");
    fflush(stdin);
    gets(mes);
    strcpy(mes,strupr(mes));
    
    //VALIDACION DE MES INGRESADO (MES DE 30 DÍAS)
    while (strcmp(mes,"ABRIL")!=0 && strcmp(mes,"JUNIO")!=0 && strcmp(mes,"SEPTIEMBRE")!=0 && strcmp(mes,"NOVIEMBRE")!=0){
        printf("\aEl mes ingresado no corresponde a un registro de %i dias.\nIngrese un mes que corresponda al registro: ",TAM);
        fflush(stdin);
        gets(mes);
        strcpy(mes,strupr(mes));
    }

    //CARGA DE TEMPERATURAS POR DÍA
    system("pause");
    system("cls");
    printf("CARGA DE TEMPERATURAS DIARIAS\n");
    for (int i = 0; i < TAM; i++){              
        diaN[i].fecha =i+1;
        printf(VISTA);
        printf("Dia %i de %s\n\n",diaN[i].fecha,mes);
        printf("Ingrese la Temperatura Minima: ");
        fflush(stdin);
        scanf("%i",&diaN[i].tempMin);

        printf("Ingrese la Temperatura Maxima: ");
        fflush(stdin);
        scanf("%i",&diaN[i].tempMax);

        printf("\n\nCarga exitosa\n\n");
    }
    
    //MENÚ DE OPCIONES
    
    do{
        printf(VISTA);
        printf("* * * * * * * * M E N U * * * * * * * *");
        printf(VISTA);
        printf("\nSeleccione la accion que desea realizar:\n1- Mostrar dia de TEMPERATURA MAXIMA\n2- Mostrar dia de TEMPERATURA MINIMA\n3- Imprimir temperaturas diarias\n4- Salir\n ---> ");
        fflush(stdin);
        scanf("%i",&opcion);
        switch (opcion) {
            case 1:
                system("cls");
                printf(VISTA);
                for (int i = 0; i < TAM; i++){              //BÚSQUEDA DE TEMPERATURA MÁXIMA
                    for (int j = i+1; j < TAM; j++){
                        if(diaN[j].tempMax>diaN[i].tempMax){
                            aux[0]=diaN[i];
                            diaN[i]=diaN[j];
                            diaN[j]=aux[0];

                            aux[0].fecha = 0;
                            aux[0].tempMax = 0;
                            aux[0].tempMin = 0;
                        }
                    }
                }
                printf("Temperatura Maxima del mes de %s\n\n",mes);
                printf("Fecha: %i de %s\n",diaN[0].fecha,mes);
                printf("Temperatura: %i grados\n",diaN[0].tempMax);
                printf(VISTA);
                system("pause");
                break;

            case 2:
                system("cls");
                printf(VISTA);
                for (int i = 0; i < TAM; i++){              //BÚSQUEDA DE TEMPERATURA MÍNIMA
                    for (int j = i+1; j < TAM; j++){
                        if(diaN[j].tempMin<diaN[i].tempMin){
                            aux[0]=diaN[i];
                            diaN[i]=diaN[j];
                            diaN[j]=aux[0];

                            aux[0].fecha = 0;
                            aux[0].tempMax = 0;
                            aux[0].tempMin = 0;
                        }
                    }
                }
                printf("Temperatura Minima del mes de %s\n\n",mes);
                printf("Fecha: %i de %s\n",diaN[0].fecha,mes);
                printf("Temperatura: %i grados\n",diaN[0].tempMin);
                printf(VISTA);
                system("pause");
                break;

            case 3:
                //IMPRESION FORMATO TABLA
                for (int i = 0; i < TAM; i++){              //ORDENAMIENTO POR DIA
                    for (int j = i+1; j < TAM; j++){
                        if(diaN[j].fecha<diaN[i].fecha){
                            aux[0]=diaN[i];
                            diaN[i]=diaN[j];
                            diaN[j]=aux[0];

                            aux[0].fecha = 0;
                            aux[0].tempMax = 0;
                            aux[0].tempMin = 0;
                        }
                    }
                }
                system("cls");
                printf(VISTA);
                printf("TEMPERATURAS DE %s\n",mes);
                printf("__________________________________\n");
                printf("|   FECHA  |  MINIMA  |  MAXIMA  |\n");
                for (int i = 0; i < TAM; i++){
                    printf("|%10i|%10i|%10i|\n",diaN[i].fecha,diaN[i].tempMin,diaN[i].tempMax);
                }
                system("pause");
                break;

            case 4:
                printf("Gracias por utilizar el sistema");
                opcion = 0;
                break;

            default:
                printf("\a\nLa opcion ingresada no es valida");
                break;

        }//FIN SWITCH
    }while(opcion!=0);
    

    return 0;
}


