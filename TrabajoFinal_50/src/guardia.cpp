#include "guardia.h"
#include <fstream>
#include <iostream>
using namespace std;
void guardia::registro()
{
    ofstream archivo1;
    ifstream lectura1;
    bool verificado=false;
    string codigo_auxiliar;
    archivo1.open("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt",ios::app);
    lectura1.open("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt",ios::in);
    if(lectura1.is_open() && archivo1.is_open())
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

         lectura1.seekg(0);
         getline(lectura1,codigo);
         while(!lectura1.eof())
         {

             getline(lectura1,nombre);
             getline(lectura1,apellido);
             getline(lectura1,dni);
             getline(lectura1,seccion_trabajo);
             getline(lectura1,celular);
             getline(lectura1,turno);
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
             getline(lectura1,codigo);
         }
         if(lectura1.eof() && codigo_auxiliar != codigo)
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
    archivo1<<codigo<<"\n";
    archivo1<<nombre<<"\n";
    archivo1<<apellido<<"\n";
    archivo1<<dni<<"\n";
    archivo1<<seccion_trabajo<<"\n";
    archivo1<<celular<<"\n";
    archivo1<<turno<<"\n";
    }
    archivo1.close();
    lectura1.close();
}
void guardia::mostrar_datos()
{
    string aux_codigo2;
    ifstream lectura2;
    bool encontrar=false;
    lectura2.open("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt",ios::in);
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
                cout<<"Este guardia no esta registrado: "<<aux_codigo2<<endl;
            }
    }
    lectura2.close();

}

void guardia::eliminar_datos()
{
    ofstream dar_baja5;
    ifstream lectura5;
    string aux_codigo;
    string eliminado;
    string si("Si");
    bool codigo_q=false;
    dar_baja5.open("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/dar_baja.txt",ios::out);
    lectura5.open("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt",ios::in);
    if(dar_baja5.is_open() && lectura5.is_open())
    {
        cout<<"Ingrese el codigo del guardia a eliminar: ";
        cin>>aux_codigo;
        getline(lectura5,codigo);
        while(!lectura5.eof())
        {
            getline(lectura5,nombre);
            getline(lectura5,apellido);
            getline(lectura5,dni);
            getline(lectura5,seccion_trabajo);
            getline(lectura5,celular);
            getline(lectura5,turno);
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
            getline(lectura5,codigo);
        }
        if(codigo_q==false)
        {
            cout<<"No se ha encontrado el codigo del guardia ni estan sus datos: "<<aux_codigo<<endl;
        }
    }
    lectura5.close();
    dar_baja5.close();
    remove("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt");
    rename("/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/dar_baja.txt","/Users/luisarroyo/Desktop/C++/TrabajoFinal_50/guardia.txt");
}
