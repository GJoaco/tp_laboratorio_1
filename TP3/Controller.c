#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* f;

    f=fopen(path,"r");

    if(f != NULL)
    {
        {
            if(parser_EmployeeFromText(f,pArrayListEmployee))
            {
                retorno=1;

            }
        }
    }

    fclose(f);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			retorno = 1;
		}

	fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    Employee* auxEmployee = employee_new();

    auxEmployee->id=buscarIdLibre(pArrayListEmployee);
    utn_getCadena(auxEmployee->nombre,20,20,"Ingrese nombre: ","Error. Vuelva a intentarlo:");
    utn_getEntero(&auxEmployee->horasTrabajadas,20,"Ingrese horas trabajadas: ","Error. Vuelva a intentarlo: ",0,999999);
    utn_getEntero(&auxEmployee->sueldo,20,"Ingrese sueldo: ","Error. Vuelva a intentarlo: ",0,999999);


    if(!(ll_add(pArrayListEmployee,auxEmployee)))
    {
        retorno=1;
    }

    return retorno;

}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int id;
    int indice;
    int opcion;
    Employee* auxEmployee = employee_new();

    utn_getEntero(&id,20,"Ingrese el id del empleado que desea editar: ","Error. Id invalido",1,99999);
    indice=buscarEmpleado(pArrayListEmployee,id);

    if(indice!=-1)
    {
        auxEmployee=ll_get(pArrayListEmployee,indice);

        printf("Este es el empleado seleccionado:\n");
        printf("%d %s %d %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        printf("Que desea modificar?");
        printf("\n1. Nombre\n2. Horas trabajadas\n3. Sueldo\n");
        utn_getEntero(&opcion,20,"","Error. Elija una opcion correcta ",1,3);

        switch(opcion)
        {
        case 1:
            utn_getCadena(auxEmployee->nombre,20,20,"Ingrese nuevo nombre: ","Error. Vuelva a intentarlo");
            retorno=1;
            printf("Nombre modificado con exito\n");
            break;
        case 2:
            utn_getEntero(&auxEmployee->horasTrabajadas,20,"Ingrese nueva cantidad de horas trabajadas: ","Error. Vuelva a intentarlo",0,99999);
            retorno=1;
            printf("Horas trabajadas modificadas con exito\n");
            break;
        case 3:
            utn_getEntero(&auxEmployee->sueldo,20,"Ingrese nuevo sueldo: ","Error. Vuelva a intentarlo",1,9999999);
            retorno=1;
            printf("Sueldo modificado con exito\n");
            break;
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int id;
    int indice;
    int flag=0;
    char respuesta[2];
    Employee* auxEmployee = employee_new();

    utn_getEntero(&id,20,"Ingrese el id del empleado que desea eliminar: ","Error. Id invalido",1,99999);
    indice=buscarEmpleado(pArrayListEmployee,id);

    if(indice!=-1)
    {
        auxEmployee=ll_get(pArrayListEmployee,indice);

        printf("Este es el empleado seleccionado:\n");
        printf("%d %s %d %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        utn_getCadena(respuesta,3,20,"Esta seguro de que desea eliminarlo? Responda si o no: ","1Error. Responda si o no: ");

        while(flag==0)
        {
            if(strcmp(respuesta,"si")==0)
            {
                ll_remove(pArrayListEmployee,indice);
                retorno=1;
                flag=1;
            }
            else if (strcmp(respuesta,"no")==0)
            {
                flag=1;
            }
            else
            {
                utn_getCadena(respuesta,3,20,"Error. Responda si o no: ","Error. Responda si o no: ");
            }
        }
    }

    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=0;
    int tam;
    Employee* aux;

    tam= ll_len(pArrayListEmployee);

    printf("Id   Nombre     Horas Trabajadas   Sueldo\n");
    for(int i=0; i<tam; i++)
    {
        aux = ll_get(pArrayListEmployee,i);
        if(aux!=NULL)
        {
            retorno=1;
        }

        printf("%-4d %-10s      %-4d          %d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
    }

    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int opcion2;
    int retorno=0;

    printf("Ordenar por:\n");
    printf("1. Id\n");
    printf("2. Nombre\n");
    printf("3. Horas Trabajadas\n");
    printf("4. Sueldo\n");
    utn_getEntero(&opcion,10,"","Error. Opcion invalida: ",1,4);
    utn_getEntero(&opcion2,10,"Ordenar de forma: \n1.Ascendente \n2.Descendente\n","Error. Opcion invalida: ",1,2);

    if(opcion2==2)
    {
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,personaCompararId, 0);
            retorno=1;
            break;
        case 2:
            ll_sort(pArrayListEmployee,personaCompararNombre, 0);
            retorno=1;
            break;
        case 3:
            ll_sort(pArrayListEmployee,personaCompararHoras, 0);
            retorno=1;
            break;
        case 4:
            ll_sort(pArrayListEmployee,personaCompararSueldo, 0);
            retorno=1;
            break;
        }
    }
    else
    {
        switch(opcion)
        {
        case 1:
            ll_sort(pArrayListEmployee,personaCompararId, 1);
            retorno=1;
            break;
        case 2:
            ll_sort(pArrayListEmployee,personaCompararNombre, 1);
            retorno=1;
            break;
        case 3:
            ll_sort(pArrayListEmployee,personaCompararHoras, 1);
            retorno=1;
            break;
        case 4:
            ll_sort(pArrayListEmployee,personaCompararSueldo, 1);
            retorno=1;
            break;
        }
    }


    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    FILE* f = fopen(path,"w");
    int tam;
    Employee* aux;

    tam=ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && f != NULL)
    {
        retorno=1;

        fprintf(f,"id,nombre,horasTrabajadas,sueldo\n");

        for(int i=0; i<tam; i++)
        {
            aux = (Employee*) ll_get(pArrayListEmployee,i);
            if(aux!= NULL)
            {
                fprintf(f,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo );
            }
        }
        fclose(f);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	FILE* f = fopen(path, "wb");
	Employee* aux;
	int tam;

	tam = ll_len(pArrayListEmployee);

	if(pArrayListEmployee != NULL && f != NULL)
	{
		for(int i = 0; i < tam; i++)
		{
			aux = (Employee*) ll_get(pArrayListEmployee, i);

            if(aux!= NULL)
            {
                fwrite(aux, sizeof(Employee), 1, f);
            }

		}
		printf("Archivo guardado\n");
		fclose(f);
		retorno = 1;
	}

    return retorno;
}

