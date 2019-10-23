#include "prisionero.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;
void prisionero::obtencion_codigo(string *dni)
{

}
void prisionero::registro()
{
   ofstream archivo;
   archivo.open("registro.txt",ios::out);
   archivo<<"\t\t\tRegistrando Prisionero\t\t\t\t\n\n";
   archivo<<"Sus Nombres ";
   getline(cin,nombre);
   archivo<<"Sus Apellidos";
   getline(cin,apellido);
   archivo<<"Fecha de Nacimiento";
   getline(cin,fecha_nacimiento);
   archivo<<"Su D.N.I";
   getline(cin,dni);
   archivo<<"Nivel de Peligro";
   getline(cin,nivel_peligro);
   archivo<<"Condena";
   getline(cin,condena);
   archivo.close();
}
