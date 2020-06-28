#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "Controller.h"
#include "Notebooks.h"
#include "LinkedList.h"

int menu();

int main()
{
    int option = 0;
    LinkedList* lista = ll_newLinkedList();
    int comparacion;

    do
    {
        system("cls");
        option=menu();

        switch(option)
        {
        case 1:
            system("cls");
            if(cargarDatosCsv("data.csv",lista))
            {
                printf("Notebooks cargadas con exito.\n");
            }
            else
            {
                printf("Error al cargar notebooks.\n");
            }
            system("pause");
            break;
        case 2:
            system("cls");
            if(cargarDatosBin("data.bin",lista))
            {
                printf("Notebooks cargadas con exito.\n");
            }
            else
            {
                printf("Error al cargar notebooks.\n");
            }
            system("pause");
            break;
        case 3:
            system("cls");
            if(cargarDatosCsv("data2.csv",lista))
            {
                printf("Notebooks cargadas con exito.\n");
            }
            else
            {
                printf("Error al cargar notebooks.\n");
            }
            system("pause");
            break;
        case 4:
            system("cls");
            if(cargarDatosBin("data2.bin",lista))
            {
                printf("Notebooks cargadas con exito.\n");
            }
            else
            {
                printf("Error al cargar notebooks.\n");
            }
            system("pause");
            break;
        case 5:
            system("cls");
            if(agregarNotebook(lista))
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Error al intentar dar de alta\n");
            }
            system("pause");
            break;
        case 6:
            system("cls");
            if(agregarNotebookIndice(lista))
            {
                printf("Alta exitosa\n");
            }
            else
            {
                printf("Error al intentar dar de alta\n");
            }
            system("pause");
            break;
        case 7:
            system("cls");
            if(editarNotebook(lista)==0)
            {
                printf("No se pudo encontrar la notebook\n");
            }
            system("pause");
            break;
        case 8:
            system("cls");
            if(borrarNotebook(lista))
            {
                printf("Notebook eliminada con exito\n");
            }
            else
            {
                printf("La notebook no a sido eliminado\n");
            }
            system("pause");
            break;
        case 9:
            system("cls");
            if(!(mostrarNotebooks(lista)))
            {
                printf("No hay notebooks que mostrar.\n");
            }
            system("pause");
            break;
        case 10:
            system("cls");
            if(reemplazarNotebook(lista))
            {
                printf("Notebook reemplazada con exito\n");
            }
            else
            {
                printf("No se pudo reemplazar\n");
            }
            system("pause");
            break;
        case 11:
            system("cls");
            if(ordenarNotebooks(lista))
            {
                printf("Notebooks ordenadas con exito\n");
            }
            else
            {
                printf("Los notebooks no han sido ordenadas\n");
            }
            system("pause");
            break;
        case 12:
            system("cls");
            comparacion=compararLocales();
            if(comparacion)
            {
                printf("Las listas son iguales\n");
            }
            else if (comparacion==-1)
            {
                printf("Error.\n");
            }
            else
            {
                printf("Las listas no son iguales\n");
            }
            system("pause");
            break;
        case 13:
            system("cls");
            if(copiarLista())
            {
                printf("Listas copiadas\n");
            }
            else
            {
                printf("No se copiaron las listas,\n");
            }
            system("pause");
            break;
        case 14:
            system("cls");
            if(guardarDatosCsv("data.csv",lista))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("No se pudo guardar el archivo,\n");
            }
            system("pause");
            break;

        case 15:
            system("cls");
            if(guardarDatosBin("data.bin",lista))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("No se pudo guardar el archivo,\n");
            }
            system("pause");
            break;
        case 16:
            system("cls");
            if(guardarDatosCsv("data2.csv",lista))
            {
                printf("Archivo guardado\n");
            }
            else
            {
                printf("No se pudo guardar el archivo,\n");
            }
            system("pause");
            break;
        case 17:
            system("cls");
            if(guardarDatosBin("data2.bin",lista))
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
    }
    while(option != 17);


    ll_deleteLinkedList(lista);
    return 0;
}

int menu()
{
    int opcion;

    printf("                               *****MENU*****\n\n");
    printf("1. Cargar los datos de las notebooks del local 1 desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de las notebooks del local 1 desde el archivo data.csv (modo binario).\n");
    printf("3. Cargar los datos de las notebooks del local 2 desde el archivo data2.csv (modo texto).\n");
    printf("4. Cargar los datos de las notebooks del local 2 desde el archivo data2.csv (modo binario).\n");
    printf("5. Alta de notebook\n");
    printf("6. Alta de notebook en lugar especifico\n");
    printf("7. Modificar datos de notebook\n");
    printf("8. Baja de notebook\n");
    printf("9. Listar notebooks\n");
    printf("10. Reemplazar notebooks\n");
    printf("11. Ordenar notebooks\n");
    printf("12. Comparar locales\n");
    printf("13. Copiar lista de un local a otro\n");
    printf("14. Guardar los datos de las notebooks del local 1 en el archivo data.csv (modo texto).\n");
    printf("15. Guardar los datos de las notebooks del local 1 en el archivo data.csv (modo binario).\n");
    printf("16. Guardar los datos de las notebooks del local 2 en el archivo data2.csv (modo texto).\n");
    printf("17. Guardar los datos de las notebooks del local 2 en el archivo data2.csv (modo binario).\n");
    printf("18. Salir\n");
    utn_getEntero(&opcion,20,"\nElija una opcion: ","Error. Vuelva a intentarlo: ",1,18);

    return opcion;
}
