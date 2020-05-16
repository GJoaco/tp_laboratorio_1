#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

void mostrarSectores()
{
    printf("1) Sistemas.\n");
    printf("2) Recursos Humamos.\n");
    printf("3) Relaciones.\n");
    printf("4) Recepcion.\n");
    printf("5) Marketing.\n");
}
int findEmployeeById (Employee* list, int id, int len)
{
    int indice=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].id==id && list[i].isEmpty==0)
        {
            indice=i;
        }
    }
        return indice;
}

int buscarIndice(Employee* list, int len)
{
    int indice=-1;
    int indiceLibre;

    for(int i=0; i<len; i++)
    {
        indiceLibre=findEmployeeById(list,i,len);
        if(indiceLibre==-1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

int initEmployees(Employee* list,int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
    }
}

int addEmployee(Employee* list, int id, char name[], char lastName[], float salary, int sector, int len)
{
    int indice;

    indice=buscarIndice(list,len);

    if(indice==-1)
    {
    }
    else
    {
        list[indice].id=id;
        strcpy(list[indice].name,name);
        strcpy(list[indice].lastName,lastName);
        list[indice].salary=salary;
        list[indice].sector=sector;
        list[indice].isEmpty=0;
    }

    return indice;
}

int printEmployees (Employee* list, int len)
{
    Employee aux;
    int todoOk=-1;

    for(int i=0; i<len-1; i++)
    {
        for(int j=i+1; j<len; j++)
        {
            if(strcmp(list[i].lastName, list[j].lastName) >  0)
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
            else if(strcmp(list[i].lastName, list[j].lastName) ==  0 && list[i].sector > list[j].sector  )
            {
                aux=list[i];
                list[i]=list[j];
                list[j]=aux;
            }
        }
    }


    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            todoOk=1;
            printf("%d   %-10s   %-10s   %5.2f   %d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }

    return todoOk;
}

void modificarEmpleado(Employee* list, int len)
{
    int id;
    int indice;
    char respuesta[3];
    int flag=0;

    system("cls");

    utn_getEntero(&id,20,"Ingrese el id del empleado a modificar: ","Error. Vuelva a intentarlo: ",0,1000);

    indice=findEmployeeById(list,id,len);

    if(indice==-1)
    {
        printf("\n\nEse id no corresponde a ningun empleado\n");
    }
    else
    {
        printf("\n\nEl empleado que a seleccionado es el siguiente:\n");
        printf("%d   %-10s   %-10s   %5.2f   %d\n",list[indice].id,list[indice].name,list[indice].lastName,list[indice].salary,list[indice].sector);
        do
        {
            if(flag==0)
            {
                utn_getCadena(respuesta,3,20,"Esta seguro que desea modificar este empleado? Responda si o no ","Error. Responda si o no ");
            }
            else
            {
                utn_getCadena(respuesta,3,20,"Error. Responda si o no ","Error. Responda si o no ");
            }

            flag=1;

            if(strcmp(respuesta,"si")==0)
            {
                printf("1)Nombre \n");
                printf("2)Apellido \n");
                printf("3)Salario \n");
                printf("4)Sector \n");
                Modificar(list,len,indice);
            }
            else if(strcmp(respuesta,"no")==0)
            {
                printf("\nEl empleado no a sido modificado\n");
            }

        }while(strcmp(respuesta,"si")!=0 && strcmp(respuesta,"no")!=0);
    }

    system("pause");
}

int Modificar (Employee* list, int len, int indice)
{
    Employee aux;
    int opciones;
    int flag=0;

    utn_getEntero(&opciones,20,"Que desea modificar? ","Error. Vuelva a intentarlo: ",1,4);

    do
    {
        switch(opciones)
        {
        case 1:
            utn_getCadena(aux.name,20,20,"Ingrese nuevo nombre: ","Error. Vuelva a intentarlo: ");
            strcpy(list[indice].name,aux.name);
            printf("\nNombre modificado con exito\n");
            flag=1;
            break;
        case 2:
            utn_getCadena(aux.lastName,20,20,"Ingrese nuevo apellido: ","Error. Vuelva a intentarlo: ");
            strcpy(list[indice].lastName,aux.lastName);
            printf("\nApellido modificado con exito\n");
            flag=1;
            break;
        case 3:
            utn_getFlotante(&aux.salary,20,"Ingrese nuevo salario: ","Error. Vuelva a intentarlo",0,999999);
            list[indice].salary=aux.salary;
            printf("\nSalario modificado con exito\n");
            flag=1;
            break;
        case 4:
            utn_getEntero(&aux.sector,20,"Ingrese nuevo sector: ","Error. Vuelva a intentarlo",1,5);
            list[indice].sector=aux.sector;
            printf("\nSector modificado con exito\n");
            flag=1;
            break;
            }
    }while(flag==0);


}

int removeEmployee(Employee* list,int id,int len)
{
    int indice;
    char respuesta[3];
    int flag=0;
    int todoOk=-1;

    indice=findEmployeeById(list,id,len);

    if(indice==-1)
    {
        printf("\n\nEse id no corresponde a ningun empleado\n");
    }
    else
    {
        printf("\n\nEl empleado que a seleccionado es el siguiente:\n");
        printf("%d   %-10s   %-10s   %5.2f   %d\n",list[indice].id,list[indice].name,list[indice].lastName,list[indice].salary,list[indice].sector);

        do
        {
            if(flag==0)
            {
                utn_getCadena(respuesta,3,20,"Esta seguro que desea eliminar este empleado? Responda si o no ","Error. Responda si o no ");
            }
            else
            {
                utn_getCadena(respuesta,3,20,"Error. Responda si o no ","Error. Responda si o no ");
            }
            flag=1;

            if(strcmp(respuesta,"si")==0)
            {
                list[indice].isEmpty=1;
                todoOk=1;
            }

        }while(strcmp(respuesta,"si")!=0 && strcmp(respuesta,"no")!=0);
    }

    return todoOk;
}

void menuCuatro (Employee* list, int len)
{
    int opcion;
    int todoOk;

    system("cls");

    printf("1) Mostrar empleados\n");
    printf("2) Salarios\n");

    utn_getEntero(&opcion,20,"Que accion desea realizar: ","Error. Vuelva a intentarlo: ",1,2);

    switch(opcion)
    {
    case 1:
        todoOk=printEmployees(list,len);

        if(todoOk==-1)
        {
            printf("\nNo hay empleados que mostrar\n");
        }

        break;
    case 2:
        todoOk=salarios(list,len);

        if(todoOk==-1)
        {
            printf("\nNo hay salarios que mostrar\n");
        }
        break;

    }

    system("pause");
}

int salarios(Employee* list, int len)
{
    float total;
    float promedio;
    int empleadosQueSuperanPromedio=0;
    int contador=0;
    int todoOk=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            todoOk=1;
            contador++;
            total+=list[i].salary;
        }
    }

    promedio= total/contador;

    for(int i=0; i<len+1; i++)
    {
        if(list[i].isEmpty==0 && list[i].salary>promedio)
        {
            empleadosQueSuperanPromedio++;
        }
    }
    if(todoOk==1)
    {
        printf("Total salarios: $%.2f\nPromedio salarios: $%.2f\nCantidad de empleados que superan el salario promedio: %d\n",total,promedio,empleadosQueSuperanPromedio);
    }

    return todoOk;
}
