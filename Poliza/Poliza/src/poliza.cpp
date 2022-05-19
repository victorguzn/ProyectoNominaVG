#include "poliza.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>

using namespace std;

poliza::poliza()
{
    //ctor
}

poliza::~poliza()
{
    //dtor
}

void poliza::menu()
{
    int choice;
    char s;
    do

    {
    system("cls");
    cout << "________________________________________________________________________________________________________________________\n"<<endl;
    cout << "                                               | GENERACION DE POLIZA |"                              <<endl;
    cout << "________________________________________________________________________________________________________________________\n"                                <<endl;

    cout << " \t\t\t  ° 1. Ingresar datos para la generacion de poliza"<<endl;
    cout << " \t\t\t  ° 2. Generacion de Poliza"<<endl;
    cout << " \t\t\t  ° 3. Salir"<<endl;


    cout << "________________________________________________________________________________________________________________________\n"<<endl;
    cout << "\tOpcion a escoger : [1/2/3]"<<endl;
    cout << "_________________________________________________________________________________________________________________________"<<endl;
    cout << "\tSelecciona tu opcion: "<<endl;
    cin>>choice;

    switch(choice)
        {
                case 1:
                        insert();
                        break;
                case 2:
                        search();
                        break;
                case 3:
                        exit(0);
                        break;
                default:

                        cout<<"Hiciste algo mal, prueba otra vez"<<endl;

        }
        getch();
    }while(choice!= 3);
}


void poliza::insert()

{
    string id, nombre, fecha, letra, cifra;
    system("cls");
    fstream archivo, archivo2;

    cout << "________________________________________________________________________________________________________________________\n"<<endl;
    cout << "                                       | INGRESO DE DATOS PARA GENERACION DE POLIZA |"                              <<endl;
    cout << "________________________________________________________________________________________________________________________\n"                                <<endl;

    cout << "  ° Ingrese ID de Poliza: "<<endl;
    cin >> id;
    cout << "  ° Ingrese Nombre de Empleados"<<endl;
    cin >> nombre;
    cout << " ° Ingrese fecha de Poliza"<<endl;
    cin >> fecha;
    cout << "  ° Ingrese Monto en letras"<<endl;
    cin >> letra;
    cout << "  ° Ingrese Monto en Q "<<endl;
    cin >> cifra;

    archivo.open("poliza.dat", ios::binary | ios::app | ios::out);
    archivo2.open("poliza2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< fecha <<std::left<<std::setw(15)<< letra <<std::left<<std::setw(15)<< cifra<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&id),
         sizeof( id ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&fecha),
         sizeof( fecha ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&letra),
         sizeof( letra ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&cifra),
        sizeof( cifra ) );
    }
}

void poliza::search()
{
    string id, nombre, fecha, letra, cifra;
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;




	cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n                                              |GENERACION DE POLIZA DE CHEQUE|                    "<<endl;
	cout<<"\n________________________________________________________________________________________________________________________"<<endl;

	archivo.open("poliza.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has añadido ninguna informacion al sistema";
		archivo.close();
	}

	else
	{
		string participant_id;
		cout<<"\nIngrese Id de poliza de cheque a generar: ";
		cin>>participant_id;
        system("cls");

        archivo >> id >> nombre >> fecha >> letra >> cifra;
		while(!archivo.eof())
	{



            if(participant_id==id)

		{

            cout<<" \n\n\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ";
            cout<<"\n\n\t BANCO NACIONAL  ";        cout<<"\t Fecha de poliza:  "<< fecha <<endl;
            cout<<" \t Id Poliza: "<< id <<endl;

            cout<<" ________________________________________________________________________ ";


            cout<<"\n  Paguese este cheque a:  "<< nombre;
            cout<<" \t\t\t cifra en Q: "<< cifra<< endl;
			cout<<" \n La cantidad de: "<< letra <<endl;
            cout<<"\t\t\t\t\t\t MONEDA NACIONAL ";
            cout<<"\t\t\t\t\t\t\n\n FIRMA ";
            cout<<"_______________________ "<< endl;


            cout<<"\n°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°  ";
            cout<<"\t\t\t\t\t\t\t\n\n CONCEPTO DE PAGO";
            cout<<"\t\t\t\t\t\t\n\n Pago de sueldo a empleado ";
             cout<<"\t\t\t\t\t\t\t\n\n FIRMA CHEQUE RECIBIDO ______________________";

             cout<<"\t\t\t\t\t\t\t\n\n °HECHO POR JUAREZ";
             cout<<"\t\t\t\t\t\t\t\n\n °REVISADO" ;
             cout<<"\t\t\t\t\t\t\t\n\n °AUTORIZADO";




			total++;


		}
		        archivo >> id >> nombre >> fecha >> letra >> cifra;
	}

		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
		archivo.close();
	}


    }






