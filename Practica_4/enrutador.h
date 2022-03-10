#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <iostream>
#include <map>
#include <vector>

using namespace std;

class enrutador
{
public:
    void modificar_enlace(char _conexion, int _peso);
    void agregar_enlace(char _conexion,int _peso);
    void eliminar_enlace(char _conexion);
    void mostrar_enlaces(int aux);
    void guardar_enlaces(char clave,string filename);

private:
    map <char,int> map1;
};

#endif // ENRUTADOR_H
