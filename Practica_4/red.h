#ifndef RED_H
#define RED_H

#include "enrutador.h"
#include <map>
#include <vector>

class red
{
public:
    void agregar_enrutador(char nombre);
    void eliminar_enrutador(char nombre);
    void modificar_enrutador(char nombre);
    void print(); //Tabla de enrutamiento
    void guardar_red(string filename);
    void leer_red(string filename);
    void agregar_enrutador_archivo(char nombre,char nombre2,int peso);
    void agregarmapnew(char a,int b);
    void dijkstra(int op);
private:
    map<char,enrutador> nodo;
    map<char,enrutador> map2;
    map<char,vector<int>> mapnew;
    map<char,vector<int>>::iterator ite;
    map<char,int>::iterator it1;
    map<char,enrutador>::iterator it;
    char letra;
};

#endif // RED_H
