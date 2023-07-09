// Consigna

// Hacer un programa que mediante un menú de opciones realice las siguientes acciones:
// a. Ingresar los siguientes datos de un stock de materiales compuesto de 100 artículos:
// Código (Según el índice), Descripción (30 caracteres), Cantidad (Pueden ser negativa) y
// Precio Unitario.

// b. Calcular el monto de cada artículo ($total=precio*cantidad) y mostrar el capital actual del Stock.($total=sumatoria(producto[i].cant*producto[i].precio)

// c. Buscar los datos de un artículo determinado por su nombre (Descripción),
// y mostrar a todos los datos incluyendo el monto.

// d. Hacer los listados de los artículos existentes y faltantes, por separado,
// mostrar a todos los datos.

// x. Salir del programa.*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define VISTA "\n****************************************\n"

struct materiales{
    int codigo;
    int cantStock;
    float precio;
    float capTotalArt;
    char desc[30];
};

int main(void){
    struct materiales art[MAX];
    
    //LIMPIO E INICIALIZO EL VECTOR
    for (int i=0;i < MAX; i++){
        art[i].codigo = 0;
        art[i].cantStock = 0;
        art[i].precio = 0;
        art[i].capTotalArt = 0;
        strcpy(art[i].desc,"");
    }
    system("cls");
    printf(VISTA);
    printf("     SISTEMA DE CARGA DE MATERIALES");
    printf(VISTA);
    
    //VARIABLES GLOBALES
    int flag = 0;
    int opcion = -1;
    int cantArt=0;
    float capTotalStock = 0;
    int codigoBusc = 0;
    
    do{
        
        printf(VISTA);
        printf("* * * * * * * * M E N U * * * * * * * *");
        printf(VISTA);
        printf("Por favor ingrese la opcion deseada:\n1- Ingresar Articulo\n2- Capital total por articulo\n3- Capital total en Stock\n4- Buscar Articulo\n5- Listado de Articulos\n0- Salir\n ---> ");
        fflush(stdin);
        scanf("%i",&opcion);
            
        switch (opcion){
            case 1:                                             //CARGA DE ARTÍCULOS
                //OPCIÓN PARA CARGAS INFERIORES AL STOCK MAX
                printf(VISTA);
                printf("Ingrese la cantidad de articulos diferentes que desea cargar (maximo de 100): ");
                fflush(stdin);
                scanf("%i",&cantArt);
                while (cantArt>MAX){                //VALIDACIÓN DE STOCK
                    printf("Recuerde que solo puede ingresar un maximo de %i articulos.\nPor favor ingrese una cantidad valida: ",MAX);
                    fflush(stdin);
                    scanf("%i",&cantArt);
                }
                
                for (int i = 0; i < cantArt; i++){          //FOR DE CARGA
                    art[i].codigo = i+1;
                    printf(VISTA);
                    printf("ARTICULO %i\n\n",i+1);
                    printf("Ingrese descripcion del articulo: ");
                    fflush(stdin);
                    gets(art[i].desc);

                    printf("Ingrese cantidad de unidades disponibles: ");
                    fflush(stdin);
                    scanf("%i",&art[i].cantStock);
                    if (art[i].cantStock<=0) {
                        printf("\aALERTA: Solicitar stock al proveedor\n");
                    }
                    
                    printf("Ingrese valor por unidad: ");
                    fflush(stdin);
                    scanf("%f",&art[i].precio);

                    printf("\nArticulo cargado exitosamente\n");
                    system("pause");
                }
                
                break;

            case 2:                                     //CAPITAL TOTAL POR ARTÍCULO
                
                system("cls");
                printf(VISTA);
                printf("* * * CAPITAL TOTAL POR ARTICULO * * *");
                printf(VISTA);
                for (int i = 0; i < cantArt; i++){
                    art[i].capTotalArt = art[i].cantStock*art[i].precio;
                    printf("--> Articulo %i: %s\nCapital Total: $%.2f\n",art[i].codigo,art[i].desc,art[i].capTotalArt);
                }
                printf(VISTA);
                system("pause");
                break;

            case 3:                                     //CAPITAL TOTAL EN STOCK
                
                system("cls");
                printf(VISTA);
                printf("* * * *CAPITAL TOTAL EN STOCK* * * *");
                printf(VISTA);
                for (int i = 0; i < cantArt; i++){
                    capTotalStock += art[i].capTotalArt;
                }
                printf("\aCapital Total en stock: $%.2f\n",capTotalStock);
                printf(VISTA);
                system("pause");
                break;

            case 4:                                     //BUSCAR ARTÍCULOS POR INDICE
                
                system("cls");
                printf(VISTA);
                printf("* * * *BUSQUEDA DE ARTICULO* * * *");
                printf(VISTA);
                printf("Ingrese el codigo del articulo que desea buscar: ");
                fflush(stdin);
                scanf("%i",&codigoBusc);
                for (int i = 0; i < cantArt; i++){
                    if(codigoBusc == art[i].codigo) {
                        printf("\aARTICULO %i\n\n",art[i].codigo);
                        printf("Descripcion: %s\n",art[i].desc);
                        printf("Stock: %i unidades\n",art[i].cantStock);
                        printf("Capital Total: $%.2f\n",art[i].capTotalArt);
                    }
                    else{                                                                           //***REVISAR
                    printf("No existe ningun articulo correspondiente al codigo ingresado");
                    }
                }
                
                printf(VISTA);
                system("pause");
                break;

            case 5:                                             //IMPRESIÓN DE LISTADO DE ARTÍCULOS
                printf(VISTA);
                printf("* * * *STOCK DE MATERIALES* * * *");
                printf(VISTA);
                for (int i = 0; i < cantArt; i++) {
                    printf("ARTICULO %i\n\n",art[i].codigo);
                    printf("Descripcion: %s\n",art[i].desc);
                    printf("Stock: %i unidades\n",art[i].cantStock);
                    printf("Capital Total: $%.2f\n",art[i].capTotalArt);
                    printf(VISTA);
                }
                break;

            case 0:
                system("cls");
                printf(VISTA);
                printf("* \aGracias por utilizar el sistema *");
                printf(VISTA);
                flag = 1;
                break;
   
            default:
                printf("La opcion seleccionada no es correcta");
                break;
        }

    }while(flag==0);

    return 0;
}


