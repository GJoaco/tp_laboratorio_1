#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED

int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int id, char name[], char lastName[], float salary, int sector, int len);
int findEmployeeById (Employee* list, int id, int len);
int removeEmployee (Employee* list, int id, int len);
int sortEmployees (Employee* list, int order, int len);
int printEmployees (Employee* list, int len);

void modificarEmpleado(Employee* list, int len);
void mostrarSectores();
int buscarIndice(Employee* list, int len);
int Modificar (Employee* list, int len, int indice);
void menuCuatro (Employee* list, int len);
int salarios (Employee* list, int len);
