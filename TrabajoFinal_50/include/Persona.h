#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;
class Persona
{
    public:
        Persona();
        virtual ~Persona();

    protected:

    private:
        string codigo;
        string nombre;
        string apellido;
        string dni;
};

#endif // PERSONA_H
