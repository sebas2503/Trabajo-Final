#include "prisionero.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void prisionero::menu()
{   int opcion;
    do
    {
    cout<<"\t\t\t...Registro de los prisioneros...\t\t\n\n";
    cout<<"1. Registrar nuevo prisionero "<<endl;
    cout<<"2. Mostrar el registro de un prisionero"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion ";
    cin>>opcion;
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
            prisionero::eliminar_prisionero();
            break;
        case 4:
            break;
        }
    }
    while(opcion != 4);
}
void error();
void prisionero::registro()
{
   ofstream archivo;
   ifstream lectura;
   bool mismo_codigo=false;
   string aux_codigo;
   archivo.open("/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt",ios::app);
   lectura.open("/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt",ios::in);
   if(archivo.is_open() && lectura.is_open())
   {
        cout<<"\n\t\t\t---Registrando a Prisionero---\n\n";
        cout<<"Ingrese el codigo del prisionero ";
        getline(cin,aux_codigo);
        if(aux_codigo == "")
            {
                while(aux_codigo == "")
                    {
                        cout<<"Codigo invalido intente nuevamente: ";
                        getline(cin,aux_codigo);}
            }
    do
    {
        lectura.seekg(0);
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,fecha_nacimiento);
            getline(lectura,dni);
            getline(lectura,nivel_peligro);
            getline(lectura,condena);

            if(codigo==aux_codigo)
            {
                mismo_codigo=true;
                cout<<"\nEse prisionero ya esta registrado bro\n\n"<<endl;
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
    cout<<codigo<<endl;
    fflush(stdin);
    cout<<"Ingrese el nombre del prisionero ";
    getline(cin,nombre);
    fflush(stdin);
    cout<<"Ingrese el apellido del prisionero ";
    getline(cin,apellido);
    fflush(stdin);
    cout<<"Ingrese fecha de nacimiento del prisionero ";
    getline(cin,fecha_nacimiento);
    fflush(stdin);
    cout<<"Ingrese numero de D.N.I del prisionero ";
    getline(cin,dni);
    fflush(stdin);
    cout<<"Ingrese nivel de peligro del prisionero ";
    getline(cin,nivel_peligro);
    fflush(stdin);
    cout<<"Ingrese la condena del prisionero ";
    getline(cin,condena);
    cout<<endl;
    cout<<"\t\t\t---Registro completado--\n\n";
    archivo<<codigo<<"\n";
    archivo<<nombre<<"\n";
    archivo<<apellido<<"\n";
    archivo<<fecha_nacimiento<<"\n";
    archivo<<dni<<"\n";
    archivo<<nivel_peligro<<"\n";
    archivo<<condena<<"\n";
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
    string aux_codigo2;
    ifstream lectura2;
    bool encontrado=false;
    lectura2.open("/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt",ios::in);
    if(lectura2.is_open())
        {
            fflush(stdin);
            cout<<"\t\tConsultando datos de un prisionero\t\t"<<endl;
            cout<<"Ingrese el codigo del prisionero que desee ver sus datos: ";
            cin>>aux_codigo2;
            getline(lectura2,codigo);
            while(!lectura2.eof())
                {
                    getline(lectura2,nombre);
                    getline(lectura2,apellido);
                    getline(lectura2,fecha_nacimiento);
                    getline(lectura2,dni);
                    getline(lectura2,nivel_peligro);
                    getline(lectura2,condena);

                    if(aux_codigo2 == codigo)
                        {
                            encontrado=true;
                            cout<<"\t\tDatos del prisionero encontrado\t"<<endl;
                            cout<<"Codigo: "<<codigo<<endl;
                            cout<<"Nombres: "<<nombre<<endl;
                            cout<<"Apellidos: "<<apellido<<endl;
                            cout<<"Fecha de nacimiento: "<<fecha_nacimiento<<endl;
                            cout<<"DNI: "<<dni<<endl;
                            cout<<"Nivel de peligro: "<<nivel_peligro<<endl;
                            cout<<"Condena: "<<condena<<endl;
                            cout<<"\n";
                        }
                    getline(lectura2,codigo);
                }
                    if(encontrado == false)
                        {cout<<"Ese prisionero no se encuentra registrado: "<<aux_codigo2<<endl;}
        }
    lectura2.close();
}
void prisionero::eliminar_prisionero()
{
    ofstream dar_baja1;
    ifstream lectura2;
    string aux_codigo3;
    string dar_baja;
    string si("Si");
    bool verificar = false;
    dar_baja1.open("/Users/luisarroyo/Documents/fin_proyecto/Parte2/dar_baja1.txt",ios::out);
    lectura2.open("/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt",ios::in);;
    if(dar_baja1.is_open() && lectura2.is_open())
    {
        cout<<"Ingrese el codigo del prisionero para eliminarlo de la prision: ";
        cin>>aux_codigo3;
        getline(lectura2,codigo);
        while(!lectura2.eof())
        {
            getline(lectura2,nombre);
            getline(lectura2,apellido);
            getline(lectura2,fecha_nacimiento);
            getline(lectura2,dni);
            getline(lectura2,nivel_peligro);
            getline(lectura2,condena);
            if(aux_codigo3 == codigo)
            {
                verificar=true;
                cout<<"Prisionero Encontrado\n\n";
                cout<<"Su codigo es: "<<codigo<<endl;
                cout<<"Su nombre es: "<<nombre<<endl;
                cout<<"Su apellido es: "<<apellido<<endl;
                cout<<"Su fecha de nacimiento es: "<<fecha_nacimiento<<endl;
                cout<<"Su DNI es: "<<dni<<endl;
                cout<<"Su nivel de peligro: "<<nivel_peligro<<endl;
                cout<<"Su condena es: "<<condena<<endl;
                cout<<"Realmente quiere elimiar al prisionero"<<endl;
                cout<<"Tendra que responder con un Si o con un No"<<endl;
                cout<<"La primera letra en mayuscuala y la segunda letra en minuscula,por favor"<<endl;
                cin>>dar_baja;
                if(dar_baja[0]==si[0] && dar_baja[1]==si[1])
                {
                    cout<<"El prisionero ha sido eliminado de los datos completamente"<<endl;
                }
                else
                {
                    cout<<"El prisionero no ha sido eliminado"<<endl;
                    dar_baja1<<codigo<<endl;
                    dar_baja1<<nombre<<endl;
                    dar_baja1<<apellido<<endl;
                    dar_baja1<<fecha_nacimiento<<endl;
                    dar_baja1<<dni<<endl;
                    dar_baja1<<nivel_peligro<<endl;
                    dar_baja1<<condena<<endl;
                }
            }
            else
            {
                dar_baja1<<codigo<<endl;
                dar_baja1<<nombre<<endl;
                dar_baja1<<apellido<<endl;
                dar_baja1<<fecha_nacimiento<<endl;
                dar_baja1<<dni<<endl;
                dar_baja1<<nivel_peligro<<endl;
                dar_baja1<<condena<<endl;
            }
            getline(lectura2,codigo);
        }
        if(verificar==false)
        {
            cout<<"No se ha encontrado el codigo del prisionero"<<"ni esta registrado bro: "<<aux_codigo3<<endl;;
        }
    }
    else
        {error();}
    lectura2.close();
    dar_baja1.close();
    remove("/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt");
    rename("/Users/luisarroyo/Documents/fin_proyecto/Parte2/dar_baja1.txt","/Users/luisarroyo/Documents/fin_proyecto/Parte2/registro.txt");
}
