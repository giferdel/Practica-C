// 3. Un profesor de matemática de un establecimiento educativo registra de cada alumno,
// Nº de legajo, nombre y promedio. Según el promedio desea saber cuántos alumnos aprobaron
// (promedio mayor o igual a 7), cuantos rinden en diciembre (promedio menor a 7 y mayor o igual a 4)
// y cuantos rinden examen en marzo (promedio menor a 4). Además desea conocer el Nº de legajo y nombre
// de los alumnos con mejor promedio.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define MAX 40
#define CANTNOT 10
#define VISTA1 "\n--------------------------------------------------------------------------------\n"     //80
#define VISTA2 "\n********************************************************************************\n"
#define VISTA3 "|---------------|--------------|----------------|-------------|----------------|\n"

//ESTRUCTURA
struct estudiantes{
    long legajo;
    char nombre[20];
    char apellido[20];
    int notas[CANTNOT];
    float promedio;
};

//VARIABLES GLOBALES
int suma=0;
int cantEst=0;
int curso=0;
int cantNot=0;
char division[1];
int contA=0;
int contD=0;
int contM=0;


//FUNCIÓN PRINCIPAL
int main(void){
    struct estudiantes estudN[MAX];
    struct estudiantes aux[2];

    for (int i = 0; i < MAX; i++){          //INICIALIZO VECTORES
        estudN[i].legajo=0;
        strcpy(estudN[i].nombre,"");
        strcpy(estudN[i].apellido,"");
        estudN[i].promedio=0;
        for (int j = 0; j < CANTNOT; j++){
            estudN[i].notas[j]=0;
        }        

        aux[i].legajo=0;
        strcpy(aux[i].nombre,"");
        strcpy(aux[i].apellido,"");
        aux[i].promedio=0;
        for (int j = 0; j < CANTNOT; j++){
            aux[i].notas[j]=0;
        }   
    }

    //CABECERA
    system("cls");
    printf("INSTITUTO EDUCATIVO LA PATRIA ES EL OTRX\nRegistro de calificaciones\n");
    printf(VISTA2);

    //INGRESO INFORMACIÓN GENERAL
    printf("Ingrese cantidad de estudiantes del curso: ");
    fflush(stdin);
    scanf("%i",&cantEst);
    while (cantEst>MAX){                        //VALIDACIÓN POR CUPO MAXIMO
        printf("\aLa cantidad de estudiantes ingresada excede el cupo.\nPor favor ingrese una cantidad valida: ");
        fflush(stdin);
        scanf("%i",&cantEst);
    }

    printf("Ingrese Curso (1 a 6): ");
    fflush(stdin);
    scanf("%i",&curso);
    while (curso<1 || curso>6){      //VALIDACIÓN CURSO
        printf("\a\nIngrese un Curso existente (1 a 6): ");
        fflush(stdin);
        scanf("%i",&curso);
    }

    printf("Ingrese Division (A - B - C): ");
    fflush(stdin);
    scanf("%s",division);
    strupr(division);
    while (strcmp(division,"A")!=0 && strcmp(division,"B")!=0 && strcmp(division,"C")!=0){      //VALIDACIÓN DIVISION
        printf("\a\nNo existe un Curso con esa Division.\nIngrese una Division existente (A - B - C): ");
        fflush(stdin);
        scanf("%s",division);
        strupr(division);
    }
    system("pause");
    system("cls");

    printf("Ingrese cantidad de Notas: ");
    fflush(stdin);
    scanf("%i",&cantNot);
    while (cantNot>CANTNOT){                        //VALIDACIÓN POR LIMITE MAXIMO DE NOTAS
        printf("\aLa cantidad de notas ingresada excede el limite de 10 notas por estudiante.\nPor favor ingrese una cantidad valida: ");
        fflush(stdin);
        scanf("%i",&cantNot);
    }
    
    //CARGA DE DATOS
    printf("\nCARGA DE ESTUDIANTES");
    printf(VISTA2);

    for (int i = 0; i < cantEst; i++){              //CARGA DE ESTUDIANTES
        printf("Estudiante %i\n\n",i+1);

        printf("Ingrese Legajo: ");
        fflush(stdin);
        scanf("%ld",&estudN[i].legajo);
        while (estudN[i].legajo==0){
            printf("\aIngrese un Legajo numerico: ");
            fflush(stdin);
            scanf("%ld",&estudN[i].legajo);
        }
        
        printf("Ingrese Nombre: ");
        fflush(stdin);
        gets(estudN[i].nombre);
        for (int j = 0; j < strlen(estudN[i].nombre); j++){           //arreglo para mayúscula en inicial
            if (j==0){
                estudN[i].nombre[j] = toupper(estudN[i].nombre[j]);
            }
            else{
                estudN[i].nombre[j] = tolower(estudN[i].nombre[j]);
            }
        }

        printf("Ingrese Apellido: ");
        fflush(stdin);
        gets(estudN[i].apellido);
        for (int j = 0; j < strlen(estudN[i].apellido); j++){           //arreglo para mayúscula en inicial
            if (j==0){
                estudN[i].apellido[j] = toupper(estudN[i].apellido[j]);
            }
            else{
                estudN[i].apellido[j] = tolower(estudN[i].apellido[j]);
            }
        }

        printf(VISTA1);

        for (int j = 0; j < cantNot; j++){          //CARGA DE NOTAS
            printf("\nNota %i\n\n",j+1);
            printf("Ingrese Nota %i: ",j+1);
            fflush(stdin);
            scanf("%i",&estudN[i].notas[j]);
            while (estudN[i].notas[j]>10){                        //VALIDACIÓN DE NOTA
            printf("\aPor favor ingrese una nota valida: ");
            fflush(stdin);
            scanf("%i",&estudN[i].notas[j]);
            }
        }
        
        printf("\nEstudiante cargado!\n");
        printf(VISTA1);
        system("pause");
    }
    
    //CÁLCULO PROMEDIO POR ESTUDIANTE
    for (int i = 0; i < cantEst; i++){
        for (int j = 0; j < cantNot; j++){
            suma += estudN[i].notas[j];
        }
        // printf("%i\n",suma);
        estudN[i].promedio=suma/cantNot;
        // printf("%.2f\n",estudN[i].promedio);
        suma=0;  
    }
    
    //CONTABILIZA EST. APROBADOS, DESAPROBADOS A DICIEMBRE, DESAPROBADOS A MARZO
    for (int i = 0; i < cantEst; i++){
        if (estudN[i].promedio>=7){
            contA+=1;
        }
        else if (estudN[i].promedio>=4 && estudN[i].promedio<7){
            contD+=1;
        }
        else{
            contM+=1;
        }  
    }
    system("cls");
    printf("\nRESUMEN Y ESTADISTICAS");
    printf("\nCurso: %i   Division: %s",curso,division);
    printf(VISTA2);                                             //agregar calculo de porcentaje
    printf("\nCantidad de estudiantes APROBADOS: %i\n\n",contA);
    for (int i = 0; i < cantEst; i++){
        if (estudN[i].promedio>=7){
            printf("Apellido y Nombre: %s, %s - Promedio: %.2f\n",estudN[i].apellido,estudN[i].nombre,estudN[i].promedio);
        }
    }
    printf(VISTA1);
    
    printf("\nCantidad de estudiantes DESAPROBADOS A DICIEMBRE: %i\n\n",contD);
    for (int i = 0; i < cantEst; i++){
        if (estudN[i].promedio>=4 && estudN[i].promedio<7){
            printf("Apellido y Nombre: %s, %s - Promedio: %.2f\n",estudN[i].apellido,estudN[i].nombre,estudN[i].promedio);
        }
    }
    printf(VISTA1);

    printf("\nCantidad de estudiantes DESAPROBADOS A MARZO: %i\n\n",contM);
    for (int i = 0; i < cantEst; i++){
        if (estudN[i].promedio<4){
            printf("Apellido y Nombre: %s, %s - Promedio: %.2f\n",estudN[i].apellido,estudN[i].nombre,estudN[i].promedio);
        }
    }
    
    printf(VISTA2);

    //MEJOR PROMEDIO
    for (int i = 0; i < cantEst; i++){
        for (int j = i+1; j < cantEst; j++){
            if(estudN[j].promedio>estudN[i].promedio){
                aux[0]=estudN[j];
                estudN[j]=estudN[i];
                estudN[i]=aux[0];
            }
        }  
    }
    printf("Ver los Mejores Promedios --> ");
    system("pause");
    
    //impresión mejores promedios (orden decreciente, promedos >=7)
    printf("\nMEJORES PROMEDIOS");
    printf("\nCurso: %i   Division: %s",curso,division);
    printf(VISTA2);
    for (int i = 0; i < cantEst; i++){
        if (estudN[i].promedio>=7){
            printf("Posicion %i",i+1);
            printf("\nLegajo: %ld\n",estudN[i].legajo);
            printf("Apellido y Nombre: %s, %s\n",estudN[i].apellido,estudN[i].nombre);
            printf("Promedio: %.2f\n",estudN[i].promedio);
            printf(VISTA1);
        }
    }
    
   
    return 0;
}
