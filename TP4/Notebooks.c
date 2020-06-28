#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Notebooks.h"
#include "LinkedList.h"
/** \brief Crea espacio en memoria dinamica para un nuevo empleado
 *
 * \return Empleado vacio
 */
eNotebook* nuevaNotebook()
{
    eNotebook* nuevo = (eNotebook*) malloc(sizeof(eNotebook));

    if(nuevo!= NULL)
    {
        nuevo->id=0;
        nuevo->modelo=0;
        nuevo->precio=0;
        strcpy(nuevo->marca, "");
    }

    return nuevo;
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

eNotebook* nuevaNotebookParam (char* idStr,char* marcaStr,char* modeloStr,char* precioStr)
{

    return nuevaNotebookParamNoStr(atoi(idStr),marcaStr,atoi(modeloStr),atoi(precioStr));
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

eNotebook* nuevaNotebookParamNoStr(int id,char* marca,int modelo,int precio)
{
    eNotebook* nuevo = nuevaNotebook();

    if(nuevo!=NULL)
    {
        if(!(setId(nuevo,id)
           && setMarca(nuevo,marca)
           && setModelo(nuevo,modelo)
           && setPrecio(nuevo,precio)))
        {
            free(nuevo);

            nuevo = NULL;
        }
    }

    return nuevo;
}

/** \brief Asigna un id a un empleado
 *
 * \param Empleado al que se le asigna el id
 * \param id que se le quiere asignar
 * \return 1 si la asignacion fue realizada 0 si no
 *
 */

int setId (eNotebook* lista,int id)
{
    int retorno=0;

    if(lista!=NULL && id>=0)
    {
        lista->id=id;
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
int setMarca(eNotebook* lista,char* marca)
{
    int retorno=0;

    if(lista!=NULL && marca!=NULL && strlen(marca) > 1 && strlen(marca) < 20)
    {
        strcpy(lista->marca,marca);
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
int setModelo(eNotebook* lista,int modelo)
{
    int retorno=0;

    if(lista!=NULL && modelo>0)
    {
        lista->modelo=modelo;
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
int setPrecio(eNotebook* lista,int precio)
{
    int retorno=0;

    if(lista!=NULL && precio>0)
    {
        lista->precio=precio;
        retorno=1;
    }

    return retorno;
}

int getId(eNotebook* lista,int* id)
{
    int retorno=0;

    if(lista!=NULL && id!=NULL)
    {
        *id=lista->id;
        retorno=1;
    }

    return retorno;
}

int getMarca(eNotebook* lista,char* marca)
{
    int retorno=0;

    if(lista!=NULL && marca!=NULL)
    {
        *marca=lista->marca;
        retorno=1;
    }

    return retorno;
}

int getModelo(eNotebook* lista,int* modelo)
{
    int retorno=0;

    if(lista!=NULL && modelo!=NULL)
    {
        *modelo=lista->modelo;
        retorno=1;
    }

    return retorno;
}

int getPrecio(eNotebook* lista,int* precio)
{
    int retorno=0;

    if(lista!=NULL && precio!=NULL)
    {
        *precio=lista->precio;
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

int buscarIdLibre(LinkedList* lista)
{
    int idLibre=1;
    eNotebook* aux = nuevaNotebook();
    int tam;

    tam=ll_len(lista);

    system("cls");

    for(int i=0;i<tam+1;i++)
    {
        if(i<tam)
        {
            aux = ll_get(lista,i);

            if(i+1 != aux->id )
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

int buscarNotebook (LinkedList* lista, int id)
{
    int indice=-1;
    int tam;
    eNotebook* aux = ll_get(lista,id-1);

    tam=ll_len(lista);

    indice=ll_indexOf(lista,aux);

    return indice;
}
/** \brief Compara los ids de dos empleados
 *
 * \param Puntero a void
 * \param Puntero a void
 * \return 1 si el id del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
 *
 */

int compararId  (void* a, void* b)
{
    int retorno=0;
    eNotebook* p1;
    eNotebook* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(eNotebook*) a;
        p2=(eNotebook*) b;

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
 * \return 1 si el marca del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
  *
 */
int compararMarca (void* a, void* b)
{
    int retorno=0;
    eNotebook* p1;
    eNotebook* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(eNotebook*) a;
        p2=(eNotebook*) b;

        retorno= strcmp(p1->marca,p2->marca);

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
int compararModelo (void* a, void* b)
{
    int retorno=0;
    eNotebook* p1;
    eNotebook* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(eNotebook*) a;
        p2=(eNotebook*) b;

        if(p1->modelo > p2->modelo)
        {
            retorno=1;
        }
        else if(p1->modelo < p2->modelo)
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
 * \return 1 si el precio del primer empleado es mayor al del segundo. -1 si es menor. 0 si es igual
 *
 */
int compararPrecio (void* a, void* b)
{
    int retorno=0;
    eNotebook* p1;
    eNotebook* p2;

    if(a!=NULL && b!=NULL)
    {
        p1=(eNotebook*) a;
        p2=(eNotebook*) b;

        if(p1->precio > p2->precio)
        {
            retorno=1;
        }
        else if(p1->precio < p2->precio)
        {
            retorno=-1;
        }

    }

    return retorno;
}
