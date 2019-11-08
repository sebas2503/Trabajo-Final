#ifndef MENU_H
#define MENU_H
#include <prisionero.h>
#include <guardia.h>
using namespace std;
class menu
{
    public:
        void prisionero();
        void guardia();
        void menu_principal();
    private:
        class prisionero p1;
        class guardia g1;
        int opcion;
};

#endif // MENU_H
