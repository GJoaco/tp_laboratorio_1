#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int numeroUno;
    int numeroDos;
    long double resultado;
    int salir = 0;
    int opcion;
    int opcionUno=0;
    int opcionDos=0;
    int opcionTres=0;

    do
    {
        opcion=0;
        fflush(stdin);
        system("cls");
        printf("MENU DE OPCIONES:\n\n");
        opcion=0;
        if(opcionUno==1)
        {
            printf("1) Cambiar 1er numero(%d).\n", numeroUno);
        }
        else
        {
            printf("1) Ingresar 1er numero.\n");
        }
        if(opcionDos==1)
        {
                printf("2) Cambiar 2do numero(%d).\n", numeroDos);
        }
        else
        {
            printf("2) Ingresar 2do numero.\n");
        }
        if(opcionUno==1)
        {
            if(opcionDos==1)
            {
                printf("3) Calcular resultados(%d y %d)\n",numeroUno, numeroDos);
            }
            else
            {
                printf("3) Calcular resultados(%d y X)\n",numeroUno);
            }

        }
        else
        {
            if(opcionDos==1)
            {
                printf("3) Calcular resultados(X y %d)\n",numeroDos);
            }
            else
            {
                printf("3) Calcular resultados(X y X)\n");
            }
        }
        printf("4) Mostrar resultados.\n");
        printf("5) Salir.\n");
        scanf("%d",&opcion);


        switch(opcion)
        {
        case 1:
            system("cls");
            numeroUno = tomarNumero();
            opcionUno=1;
            opcionTres=0;
            break;
        case 2:
            system("cls");
            numeroDos = tomarNumero();
            opcionDos=1;
            opcionTres=0;
            break;
        case 3:
            system("cls");
            if(opcionUno==1 && opcionDos==1)
            {
                printf("\n\nLas operaciones han sido calculadas\n\n");
                opcionTres=1;
            }
            else
            {
                printf("\n\nAntes de calcular las operaciones debe ingresar dos numeros\n\n");
            }

            system("pause");
            break;
        case 4:
            system("cls");
            if(opcionTres==1)
            {
                resultado = sumar(numeroUno,numeroDos);
                printf("%d + %d = %.0lf\n",numeroUno, numeroDos, resultado);

                resultado = restar(numeroUno,numeroDos);
                printf("\n%d - %d = %.0lf\n",numeroUno, numeroDos, resultado);

                if(numeroDos==0)
                {
                    printf("\nNo es posible dividir por cero\n");
                }
                else
                {
                    resultado = dividir(numeroUno,numeroDos);
                    printf("\n%d / %d = %.2lf\n",numeroUno, numeroDos, resultado);
                }


                resultado = multiplicar(numeroUno,numeroDos);
                printf("\n%d * %d = %.0lf\n",numeroUno, numeroDos, resultado);

                resultado = factorial(numeroUno);
                if(resultado!=0)
                {
                    printf("\n!%d = %.0lf\n",numeroUno,resultado);
                }

                resultado = factorial(numeroDos);
                if(resultado!=0)
                {
                    printf("\n!%d = %.0lf\n",numeroDos,resultado);
                }

            }
            else
            {
                printf("\n\nPrimero debes calcular las operaciones\n\n");
            }
            system("pause");
            break;
        case 5:
            salir = 1;
            break;
        default:
            system("cls");
            printf("\n\nNo es una opcion valida\n\n");
            system("pause");
            break;
        }

    }while(salir==0);

    return 0;
}



