#ifndef GUARDIAS_H
#define GUARDIAS_H
#include <iostream>
#include <string>
using namespace std;

class guardia
{
    public:
        void menu();
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
#endif // GUARDIAS_H
