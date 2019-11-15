#include "Persona.h"
#include <fstream>
Persona::Persona()
{
    Codigo="Codigo";
    Nombre="Nombre";
    Apellido="Apellido";
    FechaNacimiento="Fecha Nacimiento";
    Dni="Dni";
}
Persona::Persona(string Codigo,string Nombre,string Apellido,string FechaNacimiento,string Dni)
{
    this->Codigo=Codigo;
    this->Nombre=Nombre;
    this->Apellido=Apellido;
    this->FechaNacimiento=FechaNacimiento;
    this->Dni=Dni;
}
void Persona::SetDatos()
{
    bool verificado=false;
    ifstream lectura;
    string aux_codigo;
    lectura.open("Registro.txt",ios::in);
    if(lectura.is_open())
    {
        cout<<"\t\t\tRegistrando\t\n";
        cout<<"Codigo: ";
        getline(cin,aux_codigo);
        lectura.seekg(0);
        getline(lectura,Codigo);
        while(!lectura.eof())
        {
        getline(lectura,Nombre);
        getline(lectura,Apellido);
        getline(lectura,FechaNacimiento);
        getline(lectura,Dni);
        }
    }
    Codigo=aux_codigo;
    cout<<"\t\t\tRegistrando\t\n";
    cout<<"Codigo: ";
    cout<<Codigo<<endl;
    cout<<"Nombre: ";
    getline(cin,Nombre);
    cout<<"Apellido: ";
    getline(cin,Apellido);
    cout<<"Fecha de Nacimiento: ";
    getline(cin,FechaNacimiento);
    cout<<"Dni: ",
    getline(cin,Dni);
    lectura.close();
}
void Persona::Registro()
{
    ofstream archivo;
    archivo.open("Registro.txt",ios::app);
    archivo<<Codigo<<endl;
    archivo<<Nombre<<endl;
    archivo<<Apellido<<endl;
    archivo<<FechaNacimiento<<endl;
    archivo<<Dni<<endl;

}
