#include "menu.h"
void menu::prisionero()
{
    do
    {
        cout<<"\t\t\tAccediendo a prisionero\t\t\n"<<endl;
        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar datos"<<endl;
        cout<<"3. Eliminar datos"<<endl;
        cout<<"4. Salir\n"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            default:
                {
                    cout<<"Opcion inexistente";
                    break;
                }
            case 1:
                {
                    p1.registro();
                    break;
                }
            case 2:
                {
                    p1.mostrar_datos_prisionero();
                    break;
                }
            case 3:
                {
                    p1.eliminar_prisionero();
                    break;
                }
            case 4:
                {
                    break;
                }
        }
    }
    while(opcion != 4);
}
void menu::guardia()
{
    do
    {
        cout<<"\t\t\tAccediendo a guardia\t\t\n"<<endl;
        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar datos"<<endl;
        cout<<"3. Eliminar datos"<<endl;
        cout<<"4. Check in/Salir"<<endl;
        cout<<"5. Salir\n"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            default:
                {
                    cout<<"Opcion inexistente";
                    break;
                }
            case 1:
                {
                    g1.registro();
                    break;
                }
            case 2:
                {
                    g1.mostrar_datos();
                    break;
                }
            case 3:
                {
                    g1.eliminar_datos();
                    break;
                }
            case 4:
                {
                    break;
                }
        }
    }
    while(opcion != 4);
}
void menu::menu_principal()
{
    do
    {
        cout<<"\t\t\tBienvenido a Arkham\t\t\n"<<endl;
        cout<<"1. Prisioneros"<<endl;
        cout<<"2. Guardias"<<endl;
        cout<<"3. Salir \n"<<endl;
        cout<<"Opcion: ";
        cin>>opcion;
        switch(opcion)
        {
            default:
                {
                    cout<<"Opcion inexistente";
                    break;
                }
            case 1:
                {
                    prisionero();
                    break;
                }
            case 2:
                {
                    guardia();
                    break;
                }
            case 3:
                {
                    cout<<"\t\t\tGracias por usar Arkham\t\t\n";
                    break;
                }
        }
    }
    while(opcion !=3);
}
