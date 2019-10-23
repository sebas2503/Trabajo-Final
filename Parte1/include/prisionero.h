#ifndef PRISIONERO_H
#define PRISIONERO_H
#include <iostream>
using namespace std;
class prisionero
{
    public:
        void registro();
        void obtencion_codigo(string *);
        void lugar(string *);

    private:
        string nombre;
        string apellido;
        string dni;
        string condena;
        string nivel_peligro;
        int anios_prision;
        string fecha_nacimiento;
};

#endif // PRISIONERO_H
