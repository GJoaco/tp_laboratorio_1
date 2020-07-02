#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
/** \brief Crea espacio en memoria dinamica para un nuevo empleado
 *
 * \return Empleado vacio
 */

Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado!= NULL)
    {
        nuevoEmpleado->id=0;
        nuevoEmpleado->horasTrabajadas=0;
        nuevoEmpleado->sueldo=0;
        strcpy(nuevoEmpleado->nombre, "");
    }

    return nuevoEmpleado;
}
/** \brief Recibe datos en forma de cadena y las pasa a employee_newParametrosNoStr para que este cargue el empleado
 *
 * \param Id
 * \param Nombre
 * \param Horas trabajadas
 * \param Sueldo
 * \return Empleado cargado
 *
 */

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{

    return employee_newParametrosNoStr(atoi(idStr),nombreStr,atoi(horasTrabajadasStr),atoi(sueldoStr));
}
/** \brief Asigna los datos pasados como parametros a un nuevo empleado
 *
 * \param Id
 * \param Nombre
 * \param Horas trabajadas
 * \param Sueldo
 * \return Empleado cargado
 *
 */

Employee* employee_newParametrosNoStr(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Employee* nuevoEmpleado = employee_new();

    if(nuevoEmpleado!=NULL)
    {
        if(!(employee_setId(nuevoEmpleado,id)
           && employee_setNombre(nuevoEmpleado,nombre)
           && employee_setHorasTrabajadas(nuevoEmpleado,horasTrabajadas)
           && employee_setSueldo(nuevoEmpleado,sueldo)))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    }

    return nuevoEmpleado;
}

/** \brief Asigna un id a un empleado
 *
 * \param Empleado al que se le asigna el id
 * \param id que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */

int employee_setId (Employee* this,int id)
{
    int retorno=0;

    if(this!=NULL && id>=0)
    {
        this->id=id;
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un nombre a un empleado
 *
 * \param Empleado al que se le asigna el nombre
 * \param nombre que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL && strlen(nombre) > 1 && strlen(nombre) < 20)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un numero de horas a un empleado
 *
 * \param Empleado al que se le asignan las horas
 * \param horas que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas>0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }

    return retorno;
}
/** \brief Asigna un sueldo a un empleado
 *
 * \param Empleado al que se le asigna el sueldo
 * \param sueldo que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }

    return retorno;
}
/** \brief Carga el id del empleado en el puntero que pasemos por parametros
 *
 * \param puntero a empleado
 * \param puntero a la variable en la que la funcion cargara el id
 * \return 01 en caso de error, 1 en caso de exito
 *
 */
int employee_getId(Employee* this,int* id)
{
    int retorno=0;

    if(this!=NULL && id!=NULL)
    {
        *id=this->id;
        retorno=1;
    }

    return retorno;
}
/** \brief Carga el nombre del empleado en el puntero que pasemos por parametros
 *
 * \param puntero a empleado
 * \param cadena de caracteres en la que la funcion cargara el nombre
 * \return 0 en caso de error, o 1 en caso de exito
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;

    if(this!=NULL && nombre!=NULL)
    {
        *nombre=this->nombre;
        retorno=1;
    }

    return retorno;
}

/** \brief Carga las horas trabajadas del empleado en el puntero que pasemos por parametros
 *
 * \param puntero a empleado
 * \param puntero a la variable en la que la funcion cargara las horas trabajadas
 * \return 0 en caso de error, o 1 en caso de exito
 */

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;

    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }

    return retorno;
}
/** \brief Valida y carga el sueldo en el campo del empleado
 *
 * \param puntero a empleado
 * \param sueldo a validar y cargar
 * \return 0 en caso de error, o 1 en caso de exito
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;

    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }

    return retorno;
}
/** \brief Busca un id sin usar
 *
 * \param LinkedList
 * \return Id encontrado o -1 si no encuentra ninguno
 *
 */

int buscarIdLibre(LinkedList* pArrayListEmployee)
{
    int idLibre=1;
    Employee* auxEmployee = employee_new();
    int tam;

    tam=ll_len(pArrayListEmployee);

    system("cls");

    for(int i=0;i<tam+1;i++)
    {
        if(i<tam)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);

            if(i+1 != auxEmployee->id )
            {
                idLibre=i+1;
                break;
            }
        }
        else
        {
            idLibre=i+1;
        }

    }

    return idLibre;
}
/** \brief Busca un empleado por id
 *
 * \param LinkedList en donde esta el empleado
 * \param Id del empleado
 * \return Indice donde se encuentra o -1 si no esta
 *
 */

int buscarEmpleado (LinkedList* pArrayListEmployee, int id)
{
    int indice=-1;
    int tam;
    Employee* auxEmployee;

    tam=ll_len(pArrayListEmployee);

    for(int i=0; i<tam; i++)
    {
        auxEmployee = ll_get(pArrayListEmployee,i);

        if(id==auxEmployee->id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
/** \brief Compara los ids de dos empleados
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return 1 si el id del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
 *
 */

int personaCompararId (void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(Employee*) a;
        p2=(Employee*) b;

         if(p1->id > p2->id)
         {
             retorno=1;
         }
         else if(p1->id < p2->id)
         {
             retorno=-1;
         }

    }



    return retorno;
}
/** \brief Compara los nombres de dos empleados
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return 1 si el nombre del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
  *
 */
int personaCompararNombre (void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(Employee*) a;
        p2=(Employee*) b;

        retorno= strcmp(p1->nombre,p2->nombre);

    }



    return retorno;
}
/** \brief Compara las horas trabajadas de dos empleados
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return 1 si las horas trabajadas del primer empleado son mayores al del segundo. -1 si son menores. 0 si son iguales
 *
 */
int personaCompararHoras (void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(Employee*) a;
        p2=(Employee*) b;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
        {
            retorno=1;
        }
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
        {
            retorno=-1;
        }

    }



    return retorno;
}
/** \brief Compara los sueldos de dos empleados
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return 1 si el sueldo del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
 *
 */
int personaCompararSueldo (void* a, void* b)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(Employee*) a;
        p2=(Employee*) b;

        p1->sueldo=toupper(p1->sueldo);
        p2->sueldo=toupper(p2->sueldo);

        if(p1->sueldo > p2->sueldo)
        {
            retorno=1;
        }
        else if(p1->sueldo < p2->sueldo)
        {
            retorno=-1;
        }

    }



    return retorno;
}
