#include <iostream>
#include "red.h"
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    red rd;
    int opc,nodos;
    float proba;
    char aux, ini, fin;
    string filename;
    srand(time(NULL));
    while(true){
        cout<<"Seleccione la opcion que desea:\n1. Agregar enrutador\n2. Eliminar enrutador\n3. Modificar enrutador\n4. Mostrar tabla de enrutamiento\n5. Guardar red en archivo\n6. Cargar red desde archivo\n0. Salir\n";
        cin>>opc;
        if(opc==0) break;
        else{
            switch (opc) {
                case 1:
                cout<<"Ingrese el nombre del enrutador que desea agregar: ";
                cin>>aux;
                rd.agregar_enrutador(aux);
                break;

                case 2:
                cout<<"Ingrese el nombre del enrutador que desea eliminar: ";
                cin>>aux;
                rd.eliminar_enrutador(aux);
                break;

                case 3:
                cout<<"Ingrese el nombre del enrutador que desea modificar: ";
                cin>>aux;
                rd.modificar_enrutador(aux);
                break;

                case 4:
                rd.print();
                break;

                case 5:
                remove("RED.txt");
                rd.guardar_red("RED.txt");
                break;

                case 6:
                cout<<"Ingrese el nombre del archivo: ";
                cin>>filename;
                rd.leer_red(filename);
                break;

            }
        }
        cout<<"Proceso finalizado\n\n";
    }
    return 0;
}
