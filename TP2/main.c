#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define TAM 10

int main()
{
    Employee list[TAM];
    Employee aux;
    int options;
    int proximoId=0;
    int todoOk;
    int opcion1=0;

    initEmployees(list,TAM);

    do
    {
        system("cls");

        printf("*****Menu Empleados*****\n\n");
        printf("1)AlTAS\n");
        printf("2)MODIFICAR\n");
        printf("3)BAJA\n");
        printf("4)INFORMAR\n");
        printf("5)SALIR\n\n");
        printf("Elija una opcion: ");
        scanf("%d",&options);

        switch(options)
        {
        case 1:
            system("cls");
            opcion1=1;
            proximoId++;

            utn_getCadena(aux.name,51,2,"Ingrese nombre: ","Error, vuelva a intentarlo: ");
            utn_getCadena(aux.lastName,51,20,"Ingrese apellido: ","Error, vuelva a intentarlo: ");
            utn_getFlotante(&aux.salary,20,"Ingrese salario: ","Error. Vuelva a intentarlo: ",1,99999999);
            mostrarSectores();
            utn_getEntero(&aux.sector,20,"Ingrese sector: ","Error, vuelva a intentarlo: ",1,5);


            todoOk=addEmployee(list,proximoId,aux.name,aux.lastName,aux.salary,aux.sector, TAM);

            if(todoOk==-1)
            {
                printf("\nNo hay espacio disponible\n");
            }
            else
            {
                printf("\nEmpleado dado de alta con exito\n");
            }

            system("pause");
            break;
        case 2:
            if(opcion1==1)
            {
                modificarEmpleado(list,TAM);
            }
            else
            {
                printf("\nPrimero debe ingresar un empleado\n");
                system("pause");
            }

            break;
        case 3:
            if(opcion1==1)
            {
                system("cls");
                utn_getEntero(&proximoId,20,"Ingrese el id del empleado que desea eliminar: ","Error. Vuelva a intentarlo: ",0,1000);
                todoOk=removeEmployee(list,proximoId,TAM);

                if(todoOk==1)
                {
                    printf("\n\nEmpleado eliminado con exito\n\n");
                }
                else
                {
                    printf("\n\nEl empleado no a sido eliminado\n\n");
                }
                system("pause");
            }
            else
            {
                printf("\nPrimero debe ingresar un empleado\n");
                system("pause");

                break;
            case 4:
                if(opcion1==1)
                {
                    menuCuatro(list,TAM);
                }
                else
                {
                    printf("\nPrimero debe ingresar un empleado\n");
                    system("pause");
                }
                break;
            case 5:

                break;
            default:
                printf("\nOpcion invalida, vuelva a intentarlo\n");
            }

        }

    }while(options!=5);

    return 0;
}



