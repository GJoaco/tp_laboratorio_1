#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno=0;
    char buffer[4][20];
    Employee* aux;

    fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

    while(!feof(pFile))
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        aux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

        if(aux!=NULL)
        {
            retorno=1;
            ll_add(pArrayListEmployee,aux);
        }
        else
        {
            printf("Error\n");
            break;
        }
    }

    return retorno;


}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = 0;
	Employee* aux;

	if(pFile != NULL)
	{
		while(!feof(pFile))
        {
            aux = employee_new();

			if(fread(aux, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, aux);
				retorno = 1;
			}
        }
	}

    return retorno;
}
