#include "prisionero.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void prisionero::menu()
{   int opcion;
    do
    {
    cout<<"\t\t\t...Registro de los prisioneros...\t\t\n\n";
    cout<<"1. Registrar nuevo prisionero "<<endl;
    cout<<"2. Mostrar el registro de un cliente"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion ";
    cin>>opcion;
    system("clear");
    switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion invalida\n\n";
            break;
        case 1:
            prisionero::registro();
            break;
        case 2:
            prisionero::mostrar_datos_prisionero();
        case 3:
            break;
        }
    }
    while(opcion != 3);
}
void error();
void prisionero::registro()
{
   ofstream archivo;
   ifstream lectura;
   bool mismo_codigo=false;
   string aux_codigo;
   archivo.open("/Users/luisarroyo/Documents/fin_proyecto/Parte1/registro.txt",ios::app);
   lectura.open("/Users/luisarroyo/Documents/fin_proyecto/Parte1/registro.txt",ios::in);
   if(archivo.is_open() && lectura.is_open())
   {
        cout<<"\n\t\t\t---Registrando a Prisionero---\n\n";
        cout<<"Ingrese el codigo del prisionero ";
        cin>>aux_codigo;

        if(aux_codigo == "")
        {
                do
                {
                    cout<<"Codigo no valido esta vacio,intentar de nuevo ";
                    getline(cin,aux_codigo);
                }
                while(aux_codigo == "");
        }
    do
    {
        lectura.seekg(0);
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,dni);
            getline(lectura,fecha_nacimiento);
            getline(lectura,nivel_peligro);
            getline(lectura,condena);

            if(codigo==aux_codigo)
            {
                mismo_codigo=true;
                cout<<"\n\nEse prisionero ya esta registrado bro\n\n";
                cout<<"Intentalo nuevamente ";
                getline(cin,aux_codigo);
            }

            getline(lectura,codigo);
        }
        if(lectura.eof() && aux_codigo != codigo)
            mismo_codigo=false;

     }
     while(mismo_codigo==true);

    codigo=aux_codigo;
    cout<<"\n\t\t\t---Registrando nuevo prisionero---\n\n";
    cout<<"Ingrese el codigo del prisionero ";
    cout<<codigo;
    cout<<endl;
    cout<<"Ingrese el nombre del prisionero: ";
    getline(cin,nombre);
    cout<<"Ingrese el apellido del prisionero ";
    getline(cin,apellido);
    cout<<"Ingrese fecha de nacimiento del prisionero ";
    getline(cin,fecha_nacimiento);
    cout<<"Ingrese numero de D.N.I del prisionero ";
    getline(cin,dni);
    cout<<"Ingrese nivel de peligro del prisionero ";
    getline(cin,nivel_peligro);
    cout<<"Ingrese la condena del prisionero ";
    getline(cin,condena);
    archivo<<codigo<<"\n"<<nombre<<"\n"<<apellido<<"\n"<<fecha_nacimiento<<"\n"<<dni<<"\n"<<nivel_peligro<<"\n"<<condena<<"\n";
    cout<<"\t\t\t---Registro completado--\t\t\t\n\n";
   }
   else
   {
       error();
   }
   archivo.close();
   lectura.close();
}
void error()
{
    cout<<"No se abrio el archivo de registro"<<endl;
}
void prisionero::mostrar_datos_prisionero()
{
    cout<<"hi";
}
