#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "usuario.h"

using namespace std;

usuario::usuario()
{
    //ctor
}

usuario::~usuario()
{
    //dtor
}
void usuario::menu()
{
    int choice;
    char s;
    do

    {
    system("cls");
    cout << "*********************************************"<<endl;
    cout << "   | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
    cout << "*********************************************"<<endl;
    cout << " 1. Registrarse"<<endl;
    cout << " 2. Ingresar"<<endl;
    cout << " 3. Informacion Usuarios"<<endl;
    cout << " 4. Salir"<<endl;

    cout << "*********************************************"<<endl;
    cout << "Opcion a escoger : [1/2/3/4]"<<endl;
    cout << "*********************************************"<<endl;
    cout << "Selecciona tu opcion: "<<endl;
    cin>>choice;

    switch(choice)
        {
                case 1:
                    do
                    {
                        registrar();
                        cout << "¿Quieres seguir registrando personas? (S/N)";
                        cin>>s;
                    }while(s=='s'||s=='S');
                        break;
                case 2:
                        login();
                        break;
                case 3:
                        lectura();
                        break;
                case 4:
                        exit(0);
                        break;
                default:

                        cout<<"Hiciste algo mal, prueba otra vez"<<endl;

        }
        getch();
    }while(choice!= 4);
}

void usuario::registrar()
{

        string rnombre, rcontra, rn, rc;
        system("cls");
        cout << "*********************************************"<<endl;
        cout << "             | Area de Registro |"<<endl;
        cout << "*********************************************"<<endl;
        cout << "Ingresa tu Nombre de Usuario:"<<endl;
        cin >>rnombre;
        cout << "Ingresa tu Contraseña:"<<endl;
        cin >>rcontra;

        ofstream reg("RegistroUP.txt",ios::app);
        reg<<rnombre<<' '<<rcontra<<endl;
        system("cls");
        cout<<"\nRegistro Exitoso\n";
}
void usuario::login()
{
    int count;
    string nombre, contra, n, c;
    system("cls");
    cout << "*********************************************"<<endl;
    cout << "          | Ingresar al Sistema |"<<endl;
    cout << "*********************************************"<<endl;
    cout << " Nombre de Usuario:"<<endl;
    cin >>nombre;
    cout << " Contraseña:"<<endl;
    cin >>contra;

    ifstream input("RegistroUP.txt");
        while(input>>n>>c)
        {
                if(n==nombre && c==contra)

                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nHola "<< nombre<<"\nTu Ingreso ha sido Exitoso!";
                cin.get();
                cin.get();
        }
        else
        {
                cout<<"\nError en el accesos\nEl usuario o contraseña son invalidos\n";
        }
}
void usuario::lectura()
{
    ifstream archivo;
    string info;
    system("cls");

    cout << "*********************************************"<<endl;
    cout << "          | Informacion de Usuarios |"<<endl;
    cout << "*********************************************"<<endl;
    cout<<"Nombre-contra"<<endl;

    archivo.open("RegistroUP.txt", ios::in);
    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo";
        exit(1);
    }

    while(!archivo.eof())
    {
        getline(archivo, info);
        cout<<info<<endl;
    }
    archivo.close();
}
