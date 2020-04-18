#include "funciones.h"

int tomarNumero()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d",&numero);
    //validar si es un numero

    return numero;
}
int sumar (int a,int b)
{
    int resultado;
    resultado = a + b;
    return resultado;
}
int restar (int a,int b)
{
    int resultado;
    resultado = a - b;
    return resultado;
}
float dividir (int a,int b)
{
    float resultado;

    resultado = (float)a / b;

    return resultado;
}
int multiplicar(int a,int b)
{
    int resultado;
    resultado = a * b;
    return resultado;
}
long double factorial (int a)
{
    unsigned long long fact=0;

    if(a<0)
    {
        printf("\nNo se puede calcular !%d ya que el numero debe ser positivo\n",a);
    }
    else if(a>20)
    {
        printf("\nNo se puede calcular !%d ya que la calculadora solo puede factoriar hasta el numero 20\n", a);
    }
    else
    {
        if( a==1 || a==0)
        {
            fact = 1;
        }
        else
        {
            fact = a * factorial(a - 1);
        }
    }

    return fact;
}
