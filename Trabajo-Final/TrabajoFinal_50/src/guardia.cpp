#include "guardia.h"
#include <fstream>
#include <iostream>
using namespace std;
void guardia::registro()
{
    bool verificado=false;
    string codigo_auxiliar;
    archivo.open("guardia.txt",ios::app);
    lectura.open("guardia.txt",ios::in);
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
                 while(codigo==codigo_auxiliar)
                 {
                 verificado=true;
                 cout<<"Ese guardia ya se encuentra registrado"<<endl;
                 cout<<"Intentelo nuevamente: ";
                 getline(cin,codigo_auxiliar);
                 }
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
    archivo.close();
    lectura.close();
}
void guardia::mostrar_datos()
{
    string aux_codigo2;
    bool encontrar=false;
    lectura.open("guardia.txt",ios::in);
    if(lectura.is_open())
    {
        fflush(stdin);
        cout<<"\t\tBuscando datos de un guardia\t\t\n";
        cout<<"Ingrese el codigo del guardia que busca: ";
        cin>>aux_codigo2;
        getline(lectura,codigo);
        while(!lectura.eof())
        {
            getline(lectura,nombre);
            getline(lectura,apellido);
            getline(lectura,dni);
            getline(lectura,seccion_trabajo);
            getline(lectura,celular);
            getline(lectura,turno);
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
            getline(lectura,codigo);
        }
            if(encontrar==false)
            {
                cout<<"Este guardia no esta registrado: "<<aux_codigo2<<endl;
            }
    }
    lectura.close();

}

void guardia::eliminar_datos()
{
    ofstream dar_baja5;
    string aux_codigo;
    string eliminado;
    string si("Si");
    bool codigo_q=false;
    dar_baja5.open("dar_baja.txt",ios::out);
    lectura.open("guardia.txt",ios::in);
    if(dar_baja5.is_open() && lectura.is_open())
    {
        cout<<"Ingrese el codigo del guardia a eliminar: ";
        cin>>aux_codigo;
        getline(lectura,codigo);
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
                    dar_baja5<<codigo<<endl;
                    dar_baja5<<nombre<<endl;
                    dar_baja5<<apellido<<endl;
                    dar_baja5<<dni<<endl;
                    dar_baja5<<seccion_trabajo<<endl;
                    dar_baja5<<celular<<endl;
                    dar_baja5<<turno<<endl;
                }
            }
            else
            {
                dar_baja5<<codigo<<endl;
                dar_baja5<<nombre<<endl;
                dar_baja5<<apellido<<endl;
                dar_baja5<<dni<<endl;
                dar_baja5<<seccion_trabajo<<endl;
                dar_baja5<<celular<<endl;
                dar_baja5<<turno<<endl;
            }
            getline(lectura,codigo);
        }
        if(codigo_q==false)
        {
            cout<<"No se ha encontrado el codigo del guardia ni estan sus datos: "<<aux_codigo<<endl;
        }
    }
    lectura.close();
    dar_baja5.close();
    remove("guardia.txt");
    rename("dar_baja.txt","guardia.txt");
}
