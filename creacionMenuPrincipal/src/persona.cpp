#include <iostream>
#include "persona.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
/*
using namespace std;

persona::persona()
{
    //ctor
}

persona::~persona()
{
    //dtor
}/*
void persona::menu()
{
    int choice;
    char s;
    do
    {
        system ("cls");

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t    | Sistema de Recursos Humanos - Grupo 6 |"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t  1. Manteniminetos"<<endl;
        cout << "\t\t\t\t  2. Generación de Nomina"<<endl;
        cout << "\t\t\t\t  3. Informes de Nomina"<<endl;
        cout << "\t\t\t\t  4. Transferencia bancaria"<<endl;
        cout << "\t\t\t\t  5. Generación de Poliza"<<endl;
        cout << "\t\t\t\t  6. Impuestos"<<endl;
        cout << "\t\t\t\t  7. Salir"<<endl;

        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Opcion a escoger : [1/2/3/4/5/6/7]"<<endl;
        cout << "\t\t\t\t *********************************************"<<endl;
        cout << "\t\t\t\t Selecciona tu opcion: "<<endl;
        cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		mantenimientos();
    		cout << "\t\t\t\t ¿Quieres seguir en el apartado de Mantenimientos? (S/N)";
    		cin>>s;
		}while(s=='s'||s=='S');
		break;
	case 2:
		generacionN();
		break;
	case 3:
		informesN();
		break;/*
	case 4:
		transferenciaB();
		break;
	case 5:
		generacionP();
		break;
    case 6:
        impuestos();
        break;
	case 7:
		exit(0);
	default:
		cout << "\t\t\t\t Opcion invalida...Por favor prueba otra vez..";
	}
	getch();
    }while(choice!= 7);

}*/

///Menu de generaci�n de Nómina
void persona::generacionN()
{
	int ID;
	float sueldo, horast, horase, resultado, r_iva, r_isr, r_horase;
	float horas_extra = 200.00;
	float IVA = 0.12;
	float ISR = 0.05;
	string nombre;


	system("cls");
	fstream file;
    cout << "\t\t\t\t *********************************************************************"<<endl;
    cout << "\t\t\t\t **************** Generador de Generación Nómina ************"<<endl;
    cout << "\t\t\t\t *********************************************************************"<<endl;

	cout<<"\n Por favor, inserte los datos requeridos para la generación nómina del usuario: "<<endl;

    cout<<"\t\t\t Ingrese ID de Persona: ";
	cin>>ID;

	cout<<"\t\t\t Ingrese Nombre de Persona: ";
	cin>>nombre;

	cout<<"\t\t\t Ingresa el sueldo base actual del empleado en quetzales: ";
	cin>>sueldo;

	cout<<"\t\t\t Ingresa las horas trabajadas por el empleado: ";
	cin>>horast;

	cout<<"\t\t\t Ingresa las horas extra trabajadas por el empleado: ";
	cin>>horase;

	cout << "\t\t\t\t *********************************************************************"<<endl;
    cout << "\t\t\t\t **************** Los datos han sido ingresados exitosamente ************"<<endl;

	r_iva = sueldo * IVA;
	r_isr = sueldo * ISR;
	r_horase = horase * horas_extra;

	resultado = (sueldo - r_iva - r_isr) + r_horase;

	file.open("GeneraciónN.txt", ios::app | ios::out);

	file<<std::left<<std::setw(15)<< ID <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< sueldo <<std::left<<std::setw(15) << r_iva <<std::left<<std::setw(15)<< r_isr <<std::left<<std::setw(15)<< horast <<std::left<<std::setw(15)<< r_horase <<std::left<<std::setw(15)<< resultado <<std::left<<std::setw(15)<< "\n";

	file.close();
}
