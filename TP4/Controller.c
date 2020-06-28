#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Notebooks.h"
#include "LinkedList.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int cargarDatosCsv(char* file, LinkedList* lista)
{
    int retorno=0;
    FILE* pFile;
    char buffer[4][20];
    eNotebook* aux;

    pFile=fopen(file,"r");

    if(pFile != NULL)
    {
        fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);

            aux = nuevaNotebookParam(buffer[0],buffer[1],buffer[2],buffer[3]);

            if(aux!=NULL)
            {
                ll_add(lista,aux);
            }
            else
            {
                printf("Error\n");
                break;
            }
        }
    }

    if(!(ll_isEmpty(lista)))
    {
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int cargarDatosBin(char* file, LinkedList* lista)
{
    int retorno = 0;
    FILE* pFile;
    eNotebook* aux;

    pFile = fopen(file, "rb");

    if(pFile != NULL)
    {
        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                aux = nuevaNotebook();

                if(fread(aux, sizeof(eNotebook), 1, pFile) == 1)
                {
                    ll_add(lista, aux);
                    retorno = 1;
                }
            }
        }
    }

    fclose(pFile);

    return retorno;
}

/** \brief Alta de empleados
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int agregarNotebook(LinkedList* lista)
{
    int retorno=0;
    eNotebook* aux = nuevaNotebook();

    aux->id=buscarIdLibre(lista);
    utn_getCadena(aux->marca,20,20,"Ingrese marca: ","Error. Vuelva a intentarlo:");
    utn_getEntero(&aux->modelo,20,"Ingrese modelo: ","Error. Vuelva a intentarlo: ",0,999999);
    utn_getEntero(&aux->precio,20,"Ingrese precio: ","Error. Vuelva a intentarlo: ",0,999999);


    if(!(ll_add(lista,aux)))
    {
        retorno=1;
    }

    return retorno;

}

int agregarNotebookIndice(LinkedList* lista)
{
    int retorno=0;
    eNotebook* aux = nuevaNotebook();
    int indice;
    int tam=ll_len(lista);

    utn_getEntero(&indice,20,"Ingrese el indice: ","Error. Vuelva a intentarlo: ",0,999999);
    aux->id=indice;
    utn_getCadena(aux->marca,20,20,"Ingrese marca: ","Error. Vuelva a intentarlo:");
    utn_getEntero(&aux->modelo,20,"Ingrese modelo: ","Error. Vuelva a intentarlo: ",0,999999);
    utn_getEntero(&aux->precio,20,"Ingrese precio: ","Error. Vuelva a intentarlo: ",0,999999);


    if(!(ll_push(lista,indice-1,aux)))
    {

        retorno=1;
        for(int i=indice; i<tam+1; i++)
        {
            aux=ll_get(lista,i);
            if(aux!=NULL)
            {
                aux->id++;
            }
        }


    }

    return retorno;

}

/** \brief Modificar datos de empleado
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int editarNotebook(LinkedList* lista)
{
    int retorno=0;
    int id;
    int indice;
    int opcion;
    eNotebook* aux = nuevaNotebook();

    utn_getEntero(&id,20,"Ingrese el id de la noteook que desea editar: ","Error. Id invalido",1,99999);
    indice=buscarNotebook(lista,id);

    if(indice!=-1)
    {
        aux=ll_get(lista,indice);

        printf("Este es la notebook seleccionada:\n");
        printf("%d %s %d %d\n",aux->id,aux->marca,aux->modelo,aux->precio);
        printf("Que desea modificar?");
        printf("\n1. Marca\n2. Modelo\n3. Precio\n");
        utn_getEntero(&opcion,20,"","Error. Elija una opcion correcta ",1,3);

        switch(opcion)
        {
        case 1:
            utn_getCadena(aux->marca,20,20,"Ingrese nueva marca: ","Error. Vuelva a intentarlo");
            retorno=1;
            printf("Marca modificado con exito\n");
            break;
        case 2:
            utn_getEntero(&aux->modelo,20,"Ingrese nuevo modelo: ","Error. Vuelva a intentarlo",0,99999);
            retorno=1;
            printf("Modelo modificadas con exito\n");
            break;
        case 3:
            utn_getEntero(&aux->precio,20,"Ingrese nuevo precio: ","Error. Vuelva a intentarlo",1,9999999);
            retorno=1;
            printf("Precio modificado con exito\n");
            break;
        }
    }

    return retorno;
}

/** \brief Baja de empleado
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int borrarNotebook(LinkedList* lista)
{
    int retorno=0;
    int id;
    int indice;
    int flag=0;
    char respuesta[2];
    eNotebook* aux = nuevaNotebook();

    utn_getEntero(&id,20,"Ingrese el id de la notebook que desea eliminar: ","Error. Id invalido",1,99999);
    indice=buscarNotebook(lista,id);

    if(indice!=-1)
    {
        aux=ll_get(lista,indice);

        printf("Esta es la notebook seleccionado:\n");
        printf("%d %s %d %d\n",aux->id,aux->marca,aux->modelo,aux->precio);
        utn_getCadena(respuesta,3,20,"Esta seguro de que desea eliminarla? Responda si o no: ","1Error. Responda si o no: ");

        while(flag==0)
        {
            if(strcmp(respuesta,"si")==0)
            {
                ll_remove(lista,indice);
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
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int mostrarNotebooks(LinkedList* lista)
{
    int retorno=0;
    int tam;
    eNotebook* aux;

    tam= ll_len(lista);

    printf("Id   Marca        Modelo        Precio\n");
    for(int i=0; i<tam; i++)
    {
        aux = ll_get(lista,i);
        if(aux!=NULL)
        {
            retorno=1;
        }

        printf("%-4d %-10s   %-4d          %d\n",aux->id,aux->marca,aux->modelo,aux->precio);
    }

    return retorno;
}
int reemplazarNotebook(LinkedList* lista)
{
    int retorno=0;
    eNotebook* aux = nuevaNotebook();
    eNotebook* aux2 = nuevaNotebook();
    int indice;
    int id;
    char respuesta[2];
    int flag=0;

    utn_getEntero(&indice,20,"Ingrese el indice: ","Error. Vuelva a intentarlo: ",0,999999);
    id=indice;
    indice=buscarNotebook(lista,indice);

    if(indice!=-1)
    {
        aux=ll_get(lista,indice);
        printf("Esta es la notebook seleccionado:\n");
        printf("%d %s %d %d\n",aux->id,aux->marca,aux->modelo,aux->precio);
        utn_getCadena(respuesta,3,20,"Esta seguro de que desea reemplazarla? Responda si o no: ","Error. Responda si o no: ");

        while(flag==0)
        {
            if(strcmp(respuesta,"si")==0)
            {
                aux2->id=id;
                utn_getCadena(aux2->marca,20,20,"Ingrese marca: ","Error. Vuelva a intentarlo:");
                utn_getEntero(&aux2->modelo,20,"Ingrese modelo: ","Error. Vuelva a intentarlo: ",0,999999);
                utn_getEntero(&aux2->precio,20,"Ingrese precio: ","Error. Vuelva a intentarlo: ",0,999999);

                if(!(ll_set(lista,id-1,aux2)))
                {
                    retorno=1;
                    flag=1;
                }
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

/** \brief Ordenar empleados
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int ordenarNotebooks(LinkedList* lista)
{
    int opcion;
    int opcion2;
    int retorno=0;

    printf("Ordenar por:\n");
    printf("1. Id\n");
    printf("2. Marca\n");
    printf("3. Modelo\n");
    printf("4. Precio\n");
    utn_getEntero(&opcion,10,"","Error. Opcion invalida: ",1,4);
    utn_getEntero(&opcion2,10,"Ordenar de forma: \n1.Ascendente \n2.Descendente\n","Error. Opcion invalida: ",1,2);

    if(opcion2==2)
    {
        switch(opcion)
        {
        case 1:
            ll_sort(lista,compararId, 0);
            retorno=1;
            break;
        case 2:
            ll_sort(lista,compararMarca, 0);
            retorno=1;
            break;
        case 3:
            ll_sort(lista,compararModelo, 0);
            retorno=1;
            break;
        case 4:
            ll_sort(lista,compararPrecio, 0);
            retorno=1;
            break;
        }
    }
    else
    {
        switch(opcion)
        {
        case 1:
            ll_sort(lista,compararId, 1);
            retorno=1;
            break;
        case 2:
            ll_sort(lista,compararMarca, 1);
            retorno=1;
            break;
        case 3:
            ll_sort(lista,compararModelo, 1);
            retorno=1;
            break;
        case 4:
            ll_sort(lista,compararPrecio, 1);
            retorno=1;
            break;
        }
    }


    return retorno;
}

int compararLocales()
{
    int retorno;
    LinkedList* aux = ll_newLinkedList();
    LinkedList* aux2 = ll_newLinkedList();

    cargarDatosCsv("data.csv",aux);
    cargarDatosCsv("data2.csv",aux2);
    retorno=ll_containsAll(aux,aux2);

    return retorno;
}

int copiarLista()
{
    int retorno=0;
    int opcion;
    LinkedList* aux = ll_newLinkedList();
    LinkedList* aux2 = ll_newLinkedList();

    printf("1. Copiar de local 1 a local 2");
    printf("2. Copiar de local 2 a local 1");
    printf("3. No copiar");
    utn_getEntero(&opcion,20,"Elija una opcion:  ","Error. Vuelva a intentarlo: ",1,3);

    if(opcion)
    {
        cargarDatosCsv("data.csv",aux);
        aux=ll_clone(aux);
        guardarDatosCsv("data2",aux);
        retorno=1;
    }
    else if (opcion==0)
    {
        cargarDatosCsv("data2.csv",aux);
        aux=ll_clone(aux);
        guardarDatosCsv("data1",aux);
        retorno=1;
    }

    return retorno;
}



/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int guardarDatosCsv(char* file, LinkedList* lista)
{
    int retorno=0;
    FILE* f = fopen(file,"w");
    int tam;
    eNotebook* aux;

    tam=ll_len(lista);

    if(lista != NULL && f != NULL)
    {
        retorno=1;

        fprintf(f,"id,marca,modelo,precio\n");

        for(int i=0; i<tam; i++)
        {
            aux = (eNotebook*) ll_get(lista,i);
            if(aux!= NULL)
            {
                fprintf(f,"%d,%s,%d,%d\n",aux->id,aux->marca,aux->modelo,aux->precio );
            }
        }
        fclose(f);
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param file char*
 * \param lista LinkedList*
 * \return int
 *
 */
int guardarDatosBin(char* file, LinkedList* lista)
{
    int retorno = 0;
    FILE* f = fopen(file, "wb");
    eNotebook* aux;
    int tam;

    tam = ll_len(lista);

    if(lista != NULL && f != NULL)
    {
        for(int i = 0; i < tam; i++)
        {
            aux = (eNotebook*) ll_get(lista, i);

            if(aux!= NULL)
            {
                fwrite(aux, sizeof(eNotebook), 1, f);
            }

        }
        printf("Archivo guardado\n");
        fclose(f);
        retorno = 1;
    }

    return retorno;
}

