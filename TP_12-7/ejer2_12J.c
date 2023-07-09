// 2. Por teclado se ingresa el valor hora de N cantidad de empleados. 
// Posteriormente se ingresa el nombre del empleado, la antigüedad y la cantidad de horas trabajadas en el mes. 

// Se pide calcular el importe a cobrar teniendo en cuenta que al total, que resulta, 
// de multiplicar el valor hora por la cantidad de horas trabajadas, hay que sumarle la cantidad 
// de años trabajados multiplicados por $30, y al total de todas esas operaciones, 
// restarle el 13% en concepto de descuentos. 
//Imprimir el recibo correspondiente con el nombre,la antigüedad, el valor hora, 
// el total a cobrar en bruto, el total de descuentos y el valor neto a cobrar.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#define CANT 10
#define VISTA1 "\n--------------------------------------------------------------------------------\n"     //80
#define VISTA2 "\n********************************************************************************\n"
#define VISTA3 "|---------------|--------------|----------------|-------------|----------------|\n"

//ESTRUCTURA
struct empleados{
    char nombre[30];
    char apellido[30];
    int antiguedad;
    float cantHoras;
    float horasExtra;
    float sueldoBruto;
    float sueldoNeto;
};

//VARIABLES GLOBALES
float valorHora = 0;
int cantEmpleados = 0;
char mesFacturado[10];

//FUNCION PRINCIPAL
int main(void){
    struct empleados empN[CANT];

    for (int i = 0; i < CANT; i++){                         //FOR DE INICIALIZACIÓN
        strcpy(empN[i].nombre,"");
        strcpy(empN[i].apellido,"");
        empN[i].antiguedad = 0;
        empN[i].cantHoras = 0;
        empN[i].sueldoBruto = 0;
        empN[i].sueldoNeto = 0;
        empN[i].horasExtra = 0;
    }

    //CABECERA DEL SISTEMA
    system("cls");
    printf("SISTEMA DE FACTURACION\nRecursos Humanos");
    //INGRESO MES DE FACTURACIÓN
    printf(VISTA2);
    printf("Mes a facturar: ");
    fflush(stdin);
    gets(mesFacturado);
    strupr(mesFacturado);

    //INGRESO CANTIDAD DE EMPLEADOS QUE SE DESEAN CARGAR
    printf("Ingrese la cantidad de empleados que desea cargar: ");
    fflush(stdin);
    scanf("%i",&cantEmpleados);

    //INGRESO VALOR HORA
    printf("Ingrese el valor de la Hora de Trabajo: ");
    fflush(stdin);
    scanf("%f",&valorHora);
    while (valorHora<550){                              //VALIDACION MONTO SEGÚN EL SALARIO MINIMO VITAL Y MOVIL
        printf("\a\nPor SMVM el valor minimo de la hora de trabajo no debe ser inferior a los $550.\nIngrese un monto valido: ");
        fflush(stdin);
        scanf("%f",&valorHora);
    }
    printf(VISTA2);

    printf("CARGA DE FACTURACION");
    for (int i = 0; i < cantEmpleados; i++){            //CARGA DE EMPLEADOS
        printf(VISTA2);
        printf("Empleado %i\n\n",i+1);
        printf("Ingrese el Nombre del empleado: ");
        fflush(stdin);
        gets(empN[i].nombre);
        for (int j = 0; j < strlen(empN[i].nombre); j++){           //arreglo para mayúscula en inicial
            if (j==0){
                empN[i].nombre[j] = toupper(empN[i].nombre[j]);
            }
            else{
                empN[i].nombre[j] = tolower(empN[i].nombre[j]);
            }
        }
        
        printf("Ingrese el Apellido del empleado: ");
        fflush(stdin);
        gets(empN[i].apellido);
        for (int j = 0; j < strlen(empN[i].apellido); j++){           //arreglo para mayúscula en inicial
            if (j==0){
                empN[i].apellido[j] = toupper(empN[i].apellido[j]);
            }
            else{
                empN[i].apellido[j] = tolower(empN[i].apellido[j]);
            }
        }

        printf("Ingrese la Antiguedad del empleado (en anios): ");
        fflush(stdin);
        scanf("%i",&empN[i].antiguedad);

        printf("Ingrese la cantidad de Horas Trabajadas en el mes: ");
        fflush(stdin);
        scanf("%f",&empN[i].cantHoras);
        if(empN[i].cantHoras>160){                 //VALIDACION CANTIDAD DE HORAS SEGÚN LEY LABORAL
            printf("\a\nPor Ley Laboral se establece la jornada de 8hs diarias.\nCualquier excedente horario se abonara en caracter de Hora Extra\n");
            empN[i].horasExtra = empN[i].cantHoras - 160;
            // printf("%f",empN[i].horasExtras);
        }
        printf("\nEmpleado cargado con exito\n\n");
        system("pause");
    }
    
    for (int i = 0; i < cantEmpleados; i++){            //CÁLCULO DE SUELDO
        empN[i].sueldoBruto = valorHora*empN[i].cantHoras + 30*empN[i].antiguedad;      //incluye horas extra
        empN[i].sueldoNeto = empN[i].sueldoBruto*0.87;       
        printf("%.2f\n",empN[i].sueldoBruto);
        printf("%.2f\n",empN[i].sueldoNeto);
    }
    system("cls");

    //IMPRESIÓN RECIBO DE SUELDO
    for (int i = 0; i < cantEmpleados; i++){
        printf(VISTA2);
        printf("FABRICA DE SUENIOS S.A.\n");
        printf(VISTA1);
        printf("Empleado: %s, %s\n\n",empN[i].apellido,empN[i].nombre);
        printf("RECIBO DE HABERES - %s de 2023\n",mesFacturado);
        printf("Horas trabajadas: %i",empN[i].cantHoras);
        printf(VISTA1);
        printf("|   Valor Hora  |  Antiguedad  |  Sueldo Bruto  |  Descuento  |   Sueldo Neto  |\n");
        printf(VISTA3);
        printf("|%15.2f|%14i|%16.2f|%13.2f|%16.2f|\n",valorHora,empN[i].antiguedad,empN[i].sueldoBruto,empN[i].sueldoBruto*0.13,empN[i].sueldoNeto);
    }
    

  return 0;  
}
    


