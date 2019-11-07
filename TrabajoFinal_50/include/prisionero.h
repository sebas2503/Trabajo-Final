#ifndef PRISIONERO_H
#define PRISIONERO_H
#include <string>
#include <iostream>
using namespace std;

class prisionero
{
    public:
        void registro();
        void mostrar_datos_prisionero();
        void eliminar_prisionero();
    protected:
    private:
        string nombre;
        string apellido;
        string dni;
        string nivel_peligro;
        string fecha_nacimiento;
        string codigo;
        string condena;
};

#endif // PRISIONERO_H
