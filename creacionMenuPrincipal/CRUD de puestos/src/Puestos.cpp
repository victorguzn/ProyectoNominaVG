#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
#include "Puestos.h"

using namespace std;

Puestos::Puestos(){
 string nombrepuesto, area, segmento, salario, vacantes;
}

Puestos::~Puestos(){

}

void Puestos::menuprincipal()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"----------------------------------------"<<endl;
	cout<<"\t\t |   GDUR DE PUESTOS DE TRABAJO  |"<<endl;
	cout<<"----------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nuevos puestos de trabajo"<<endl;
	cout<<"\t 2. Ver puestos de trabajo actuales"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		nuevopuesto();
    		cout<<"\n\t ¿Agregar un nuevo puesto?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		verpuestos();
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 3 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void Puestos::nuevopuesto()
{
	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	cout<<"\tIngresa nombre del puesto de trabajo: ";
	cin>>nombrepuesto;

	cout<<"\tIngresa el area de trabajo de dicho puesto: ";
	cin>>area;

	cout<<"\tIngresa el segmento de dicho puesto: ";
	cin>>segmento;

	cout<<"\tIngresa el salario minimo de dicho puesto: ";
	cin>>salario;

	cout<<"\t¿Hay vacantes disponibles? ¿Cuantas? ";
	cin>>vacantes;

    archivo.open("puestosdetrabajo.dat", ios::binary | ios::app | ios::out);
    archivo2.open("puestosdetrabajo2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< nombrepuesto <<std::left<<std::setw(15)<< area <<std::left<<std::setw(15)<< segmento <<std::left<<std::setw(15)<< salario <<std::left<<std::setw(15)<< vacantes<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&nombrepuesto),
         sizeof( nombrepuesto ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&area),
         sizeof( area ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&segmento),
         sizeof( segmento ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&salario),
         sizeof( salario ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&vacantes),
        sizeof( vacantes ) );
    }
}

void Puestos::verpuestos()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE PUESTOS ACTUALES --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("puestosdetrabajo.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has añadido ninguna informacion al sistema";
		archivo.close();
	}

	else
	{
		archivo >> nombrepuesto >> area >> segmento >> salario >> vacantes;

		while(!archivo.eof())
		{
			total++;
			cout<<"\n\n\t Puesto de trabajo: "<< nombrepuesto <<endl;
			cout<<"\t Area: "<< area <<endl;
			cout<<"\t Segmento: "<< segmento <<endl;
			cout<<"\t Salario minimo: "<< salario <<endl;
			cout<<"\t Vacantes: "<< vacantes <<endl;
			archivo >> nombrepuesto >> area >> segmento >> salario >> vacantes;
		}
		if(total==0)
		{
			cout<<"\n\t No ha insertado informacion, por favor verifica o empieza a ingresar datos";
		}
	}

	cout<<"Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion;

    if(opcion = 1){
        menuprincipal();
    }
}
