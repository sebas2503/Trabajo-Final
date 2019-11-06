#include <guardias.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void guardia::menu()
{   int opcion;
    do
    {
    cout<<"\t\t\t...Registro de los guardias...\t\t\n\n";
    cout<<"1. Registrar nuevo guardia "<<endl;
    cout<<"2. Mostrar el registro de un guardia "<<endl;
    cout<<"3. Eliminar a un guardia "<<endl;
    cout<<"4. Salir\n"<<endl;
    cout<<"Opcion ";
    cin>>opcion;
    switch(opcion)
        {
        default:
            cout<<"Ha ingresado una opcion invalida\n\n";
            break;
        case 1:
            guardia::registro();
            break;
        case 2:
            guardia::mostrar_datos();
        case 3:
            guardia::eliminar_datos();
            break;
        case 4:
            break;
        }
    }
    while(opcion != 4);
}
void error();
void guardia::registro()
{
    ofstream archivo;
    ifstream lectura;
    bool verificado=false;
    string codigo_auxiliar;
    archivo.open("Users/luisarroyo/Documents/fin_proyecto/Prueba3/guardia.txt",ios::app);
    lectura.open("Users/luisarroyo/Documents/fin_protecto/Prueba3/guardia.txt",ios::in);
    if(lectura.is_open() && archivo.is_open())
    {
        cout<<"\t\t\tRegistrando a nuevo guardia\t\t\n\n";
        cout<<"Ingrese su codigo: ";
        getline(cin,codigo_auxiliar);
        if(codigo_auxiliar=="")
        {
            while(codigo_auxiliar=="")
            {
                cout<<"Codigo invalido intente nuevamente: ";
                getline(cin,codigo_auxiliar);
            }
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
             getline(lectura,seccion_trabajo);
             getline(lectura,celular);
             getline(lectura,turno);
             if(codigo==codigo_auxiliar)
             {
                 verificado=true;
                 cout<<"Ese guardia ya se encuentra registrado"<<endl;
                 cout<<"Intentelo nuevamente: ";
                 getline(cin,codigo_auxiliar);
             }
             getline(lectura,codigo);
         }
         if(lectura.eof() && codigo_auxiliar != codigo)
            {verificado=false;}
    }
    while(verificado==true);

    codigo=codigo_auxiliar;
    cout<<"\t\t\tRegistrando a nuevo guardia\t\t\n\n";
    cout<<"Ingrese codigo del guardia: ";
    cout<<codigo<<endl;
    fflush(stdin);
    cout<<"Ingrese su nombre del guardia: ";
    getline(cin,nombre);
    fflush(stdin);
    cout<<"Ingrese su apellido del guarida: ";
    getline(cin,apellido);
    fflush(stdin);
    cout<<"Ingrese su DNI: ";
    getline(cin,dni);
    fflush(stdin);
    cout<<"Ingrese la seccion donde va a trabajar: ";
    getline(cin,seccion_trabajo);
    fflush(stdin);
    cout<<"Ingrese su numero de celular: ";
    getline(cin,celular);
    fflush(stdin);
    cout<<"Ingrese su turno: ";
    getline(cin,turno);
    cout<<endl;
    cout<<"\t\t\tSu registro se ha completado\t\t\n\n";
    archivo<<codigo<<"\n";
    archivo<<nombre<<"\n";
    archivo<<apellido<<"\n";
    archivo<<dni<<"\n";
    archivo<<seccion_trabajo<<"\n";
    archivo<<celular<<"\n";
    archivo<<turno<<"\n";
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
    cout<<"No se abrio el archivo de la guardia";
}

void guardia::mostrar_datos()
{
    string aux_codigo2;
    ifstream lectura2;
    bool encontrar=false;
    lectura2.open("Users/luisarroyo/Documents/fin_proyecto/Prueba3/guardia.txt",ios::in);
    if(lectura2.is_open())
    {
        fflush(stdin);
        cout<<"\t\tBuscando datos de un guardia\t\t\n";
        cout<<"Ingrese el codigo del guardia que busca: ";
        cin>>aux_codigo2;
        getline(lectura2,codigo);
        while(!lectura2.eof())
        {
            getline(lectura2,nombre);
            getline(lectura2,apellido);
            getline(lectura2,dni);
            getline(lectura2,seccion_trabajo);
            getline(lectura2,celular);
            getline(lectura2,turno);
            if(aux_codigo2==codigo)
            {
                encontrar=true;
                cout<<"\t\tHemos encontrado los datos del guardia\t\n";
                cout<<"El codigo es: "<<codigo<<endl;
                cout<<"Su nombre es: "<<nombre<<endl;
                cout<<"Su apellido es: "<<apellido<<endl;
                cout<<"Su DNI es: "<<dni<<endl;
                cout<<"La seccion donde trabaja es: "<<seccion_trabajo<<endl;
                cout<<"Su numero de celular es: "<<celular<<endl;
                cout<<"Su turno es: "<<turno<<endl;
            }
            getline(lectura2,codigo);
        }
            if(encontrar==false)
            {
                cout<<"Este guardia ya esta registrado: "<<aux_codigo2<<endl;
            }
    }
    lectura2.close();

}

void guardia::eliminar_datos()
{
    ofstream dar_baja;
    ifstream lectura;
    string aux_codigo;
    string eliminado;
    string si("Si");
    bool codigo_q=false;
    dar_baja.open("Users/luisarroyo/Documents/fin_proyecto/Prueba3/dar_baja.txt",ios::out);
    lectura.open("Users/luisarroyo/Documents/fin_proyecto/Prueba3/guarida.txt",ios::in);
    if(dar_baja.is_open() && lectura.is_open())
    {
        cout<<"Ingrese el codigo del guardia a eliminar: ";
        cin>>aux_codigo;
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,dni);
            getline(lectura,seccion_trabajo);
            getline(lectura,celular);
            getline(lectura,turno);
            if(aux_codigo==codigo)
            {
                codigo_q=true;
                cout<<"Guardia encontrado\n\n";
                cout<<"Su codigo es: "<<codigo<<endl;
                cout<<"Su nombre es: "<<nombre<<endl;
                cout<<"Su apellido es: "<<apellido<<endl;
                cout<<"Su DNI es: "<<dni<<endl;
                cout<<"Su seccion en el trabajo es: "<<seccion_trabajo<<endl;
                cout<<"Su numero de celular es: "<<celular<<endl;
                cout<<"Su turno es: "<<turno<<endl;
                cout<<"Realmente quiere eliminar a este guardia"<<endl;
                cout<<"Tendra que responder con un Si o con un No"<<endl;
                cout<<"La primero letra en mayuscula y la segundo en minuscula,por favor: ";
                cin>>eliminado;
                if(eliminado[0]==si[0] && eliminado[1]==si[1])
                {
                    cout<<"\t\tLos datos de este guardia han sido borrados completamente"<<endl;
                }
                else
                {
                    cout<<"\t\tLos datos de este guardia se han guardado"<<endl;
                    dar_baja<<codigo<<endl;
                    dar_baja<<nombre<<endl;
                    dar_baja<<apellido<<endl;
                    dar_baja<<dni<<endl;
                    dar_baja<<seccion_trabajo<<endl;
                    dar_baja<<celular<<endl;
                    dar_baja<<turno<<endl;
                }
            }
            else
            {
                dar_baja<<codigo<<endl;
                dar_baja<<nombre<<endl;
                dar_baja<<apellido<<endl;
                dar_baja<<dni<<endl;
                dar_baja<<seccion_trabajo<<endl;
                dar_baja<<celular<<endl;
                dar_baja<<turno<<endl;
            }
            getline(lectura,codigo);
        }
        if(codigo_q==false)
        {
            cout<<"No se ha encontrado el codigo del guardia ni estan sus datos: "<<aux_codigo<<endl;
        }
    }
    else
    {error();}
    lectura.close();
    dar_baja.close();
    remove("/Users/luisarroyo/Documents/fin_proyecto/Prueba3/guardia.txt");
    rename("/Users/luisarroyo/Documents/fin_proyecto/Prueba3/dar_baja.txt","/Users/luisarroyo/Documents/fin_proyecto/Prueba3/guardia.txt");
}
