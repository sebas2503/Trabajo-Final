#include <iostream>
#include <prisionero.h>
#include <guardias.h>
using namespace std;

int main()
{
    int opcion;
    prisionero P;
    guardia Q;
    do
    {
        cout<<"1. Prisioneros"<<endl;
        cout<<"2. Guardias"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opcion;
        switch(opcion)
        {
            default:
                cout<<"Opcion invalida bro";
                break;
            case 1:
                P.menu();
                break;
            case 2:
                Q.menu();
            case 3:
                break;

        }
    }
    while(opcion !=3);
}
