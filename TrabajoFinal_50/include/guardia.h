#ifndef GUARDIA_H
#define GUARDIA_H
#include <iostream>
#include <string>
using namespace std;
class guardia
{
    public:
        void registro();
        void mostrar_datos();
        void eliminar_datos();
        void llegar_trabajo();
    private:
        string codigo;
        string nombre;
        string apellido;
        string dni;
        string seccion_trabajo;
        string celular;
        string turno;
};

#endif // GUARDIA_H
