

#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char marca[128];
    int modelo;
    int precio;
}eNotebook;

eNotebook* nuevaNotebook();
eNotebook* nuevaNotebookParam(char* idStr,char* marcaStr,char* modeloStr,char* precioStr);
eNotebook* nuevaNotebookParamNoStr(int id,char* marca,int modelo,int precio);

int setId(eNotebook* this,int id);
int getId(eNotebook* this,int* id);

int setMarca(eNotebook* this,char* marca);
int getMarca(eNotebook* this,char* marca);

int setModelo(eNotebook* this,int modelo);
int getModelo(eNotebook* this,int* modelo);

int setPrecio(eNotebook* this,int precio);
int getPrecio(eNotebook* this,int* precio);

int buscarIdLibre(LinkedList* lista);
int buscarNotebook (LinkedList* lista, int id);

int compararId (void* a, void* b);
int compararMarca(void* a, void* b);
int compararModelo(void* a, void* b);
int compararPrecio (void* a, void* b);

#endif // employee_H_INCLUDED
