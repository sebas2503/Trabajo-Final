#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;
#include <string.h>
class Persona
{
    public:
        Persona();
        Persona(string,string,string,string,string);
        void SetDatos();
        void Registro();
        void MostrarDatos();
        void Eliminar();

    protected:
        string Codigo;
        string Nombre;
        string Apellido;
        string FechaNacimiento;
        string Dni;
};

#endif // PERSONA_H
