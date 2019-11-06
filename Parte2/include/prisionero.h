#ifndef PRISIONERO_H
#define PRISIONERO_H
#include <iostream>
#include <string>
using namespace std;
class prisionero
{
    public:
        void menu();
        void registro();
        void mostrar_datos_prisionero();
        void eliminar_prisionero();
    private:
        string codigo;
        string nombre;
        string apellido;
        string dni;
        string condena;
        string nivel_peligro;
        string fecha_nacimiento;
};

#endif // PRISIONERO_H
