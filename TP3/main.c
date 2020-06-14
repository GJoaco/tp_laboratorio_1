#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

int menu();

int main()
{
    int option = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        system("cls");
        option=menu();

        switch(option)
        {
            case 1:
                system("cls");
                if(controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Empleados cargados con exito.\n");
                }
                else
                {
                    printf("Error al cargar empleados.\n");
                }
                system("pause");
                break;
            case 2:
                system("cls");
                if(controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados cargados con exito.\n");
                }
                else
                {
                    printf("Error al cargar empleados.\n");
                }
                system("pause");
                break;
            case 3:
                system("cls");
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("Alta exitosa\n");
                }
                else
                {
                    printf("Error al intentar dar de alta\n");
                }
                system("pause");
                break;
            case 4:
                system("cls");
                if(controller_editEmployee(listaEmpleados)==0)
                {
                    printf("No se pudo encontrar el empleado\n");
                }
                system("pause");
                break;
            case 5:
                system("cls");
                if(controller_removeEmployee(listaEmpleados))
                {
                    printf("Empleado eliminado con exito\n");
                }
                else
                {
                    printf("El empleado no a sido eliminado\n");
                }
                system("pause");
                break;
            case 6:
                system("cls");
                if(!(controller_ListEmployee(listaEmpleados)))
                {
                    printf("No hay empleados que mostrar.\n");
                }
                system("pause");
                break;
            case 7:
                system("cls");
                if(controller_sortEmployee(listaEmpleados))
                {
                    printf("Empleados ordenados con exito\n");
                }
                else
                {
                    printf("Los empleados no han sido ordenados\n");
                }
                system("pause");
                break;
            case 8:
                system("cls");
                if(controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("Archivo guardado\n");
                }
                else
                {
                    printf("No se pudo guardar el archivo,\n");
                }
                system("pause");
                break;
            case 9:
                system("cls");
                if(controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("Archivo guardado\n");
                }
                else
                {
                    printf("No se pudo guardar el archivo,\n");
                }
                system("pause");
                break;
        }
    }while(option != 10);


    ll_deleteLinkedList(listaEmpleados);
    return 0;
}

int menu()
{
    int opcion;

    printf("                               *****MENU*****\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    utn_getEntero(&opcion,20,"\nElija una opcion: ","Error. Vuelva a intentarlo: ",1,10);

    return opcion;
}
