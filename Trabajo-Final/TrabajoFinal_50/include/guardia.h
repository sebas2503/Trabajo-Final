#ifndef GUARDIA_H
#define GUARDIA_H
#include <iostream>
#include <string>
#include <fstream>
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
        ofstream archivo;
        ifstream lectura;
};

#endif // GUARDIA_H
