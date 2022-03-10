#include "red.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <time.h>

void red::agregar_enrutador(char nombre)
{
    enrutador rou;
    if(map2.find(nombre)==map2.end()) rou.agregar_enlace(nombre,0);
    map2.insert(pair<char,enrutador>(nombre,rou));
}

void red::eliminar_enrutador(char nombre)
{
    map<char,enrutador>::iterator it;
    if(map2.find(nombre)!=map2.end()) map2.erase(nombre);
    for(it=map2.begin();it!=map2.end();it++){
            it->second.eliminar_enlace(nombre);
    }
}

void red::modificar_enrutador(char nombre)
{
    map<char,enrutador>::iterator it;
    int a,aux;
    char b;
    if(map2.find(nombre)!=map2.end()){
        cout<<"Ingrese: \n 0. Para modificar enlace \n 1. Para agregar enlace \n 2. Para eliminar enlace \n";
        cin>>a;
        cout << "Ingrese la letra del enrutador a modificar: ";
        cin >> b;
        if(a==0){
            cout<<"Ingrese el peso del enlace: ";
            cin>>aux;
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==nombre){ //verifico que el nombre exista
                    it->second.modificar_enlace(b,aux); //tendra un peso con el nombre destino
                }
            }
        }
        else if (a==1) {
            cout<<"Ingrese el peso del enlace: ";
            cin>>aux;
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==nombre){
                    it->second.agregar_enlace(b,aux);
                }
            }
        }
        else{
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==nombre){
                    it->second.eliminar_enlace(b);
                }
            }
        }
        if(a==0){
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==b){ //verifico que el nombre destino existe y modifico el peso
                    it->second.modificar_enlace(nombre,aux);
                }
            }
        }
        else if (a==1) {
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==b){
                    it->second.agregar_enlace(nombre,aux);
                }
            }
        }
        else{
            for(it=map2.begin();it!=map2.end();it++){
                if(it->first==b){
                    it->second.eliminar_enlace(nombre);
                }
            }
        }
    }
}

void red::dijkstra(int op){
    bool t;
    char v1,v2;
    int costo,costofinal;
    do{
        cout<<"ingrese el nodo de partida"<<endl;
        cin>>v1;
        cout<<"ingrese el nodo de llegada"<<endl;
        cin>>v2;
        if(nodo.find(v1)!=nodo.end()){
            if(nodo.find(v2)!=nodo.end())t=1;
            else cout<<"el segundo nodo no existe, vuela a ingresarlos"<<endl;
        }
        else cout<<"el primer nodo no existe, vuela a ingresarlos"<<endl;
    }while(t==0);


    if(op==2)cout<<"el costo minimo desde "<<v1<<" hasta "<<v2<<" es de: "<<costofinal<<endl;
    else if(op==3)cout<<"la ruta que debe seguir es: "<<endl;
}

void red::print()
{
    int aux=0;
    map<char,enrutador>::iterator it;
    cout<<"Tabla de enrutamiento para cada nodo: "<<endl;
    for(it=map2.begin();it!=map2.end();it++){
        cout<<"  "<<it->first;
    }
    cout<<"\n---------------------"<<endl;
    for(it=map2.begin();it!=map2.end();it++){
        it->second.mostrar_enlaces(aux);
        cout<<"---------------------"<<endl;
        aux++;
    }
    cout<<endl;
}

void red::guardar_red(string filename)
{
    map<char,enrutador>::iterator it;
    for(it=map2.begin();it!=map2.end();it++){
        it->second.guardar_enlaces(it->first,filename);
    }
    cout<<"\nLa red ha sido guardada en el archivo "<<filename<<"\n";
}

void red::leer_red(string filename)
{
    enrutador rou;
    string linea;
    char rout1,rout2;
    int peso;
    fstream ifs(filename,ifstream::in);   //String de lectura
    if(!ifs.good()){cout<<"\nError abriendo archivo\n";return;}
    cout<<"\nCargando red del archivo "<<filename<<":\n";
    while(getline(ifs,linea)){
        if(linea.size()>0){
            rout1=char(linea[0]);
            rout2=char(linea[2]);
            peso=int(linea[4])-48;
            if(int(linea[5])>=48 && int(linea[5])<=57) peso=(int(linea[4])-48)*10+(int(linea[5])-48);
            if(int(linea[6])>=48 && int(linea[6])<=57) peso=((int(linea[4])-48)*10+(int(linea[5])-48))*10+(int(linea[6])-48);
            agregar_enrutador(rout1);
            agregar_enrutador(rout2);
            agregar_enrutador_archivo(rout1,rout2,peso);
        }
    }
    ifs.close();
}

void red::agregar_enrutador_archivo(char nombre,char nombre2,int peso)
{
    map<char,enrutador>::iterator it;
    for(it=map2.begin();it!=map2.end();it++){
        if(it->first==nombre){
            it->second.agregar_enlace(nombre2,peso);
        }
    }
    for(it=map2.begin();it!=map2.end();it++){
        if(it->first==nombre2){
            it->second.agregar_enlace(nombre,peso);
        }
    }
}

void red::agregarmapnew(char a, int b)
{
    for(ite=mapnew.begin();ite!=mapnew.end();ite++){
        if(ite->first==a){
            ite->second.push_back(b);
        }
    }
}


