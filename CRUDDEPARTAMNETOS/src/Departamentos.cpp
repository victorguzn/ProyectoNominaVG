#include <iostream>
#include "Departamentos.h"
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>
using namespace std;

Departamentos::Departamentos()
{
 string codigo,nombre,nombreem;
}
Departamentos::~Departamentos()
{

}

void Departamentos::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t |   SISTEMA DE GESTION DEPARTAMENTOS  |"<<endl;
	cout<<"\t\t\t----------------------------------------"<<endl;
	cout<<"\t\t\t 1. Ingreso Departamnetos"<<endl;
	cout<<"\t\t\t 2. Despliegue Departamnetos"<<endl;
	cout<<"\t\t\t 3. Modificar Departamentos"<<endl;
	cout<<"\t\t\t 4. Buscar Departamentos"<<endl;
	cout<<"\t\t\t 5. Borrar Departamentos"<<endl;
	cout<<"\t\t\t 6. Exit"<<endl;

	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\t|Opcion a escoger:[1/2/3/4/5/6]|"<<endl;
	cout<<"\t\t\t--------------------------------"<<endl;
	cout<<"\t\t\tIngresa tu Opcion: ";
    cin>>choice;

switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t Agrega otra persona(Y,N): ";
    		cin>>x;
		}while(x=='y'||x=='Y');
		break;
	case 2:
		display();
		break;
	case 3:
		modify();
		break;
	case 4:
		search();
		break;
	case 5:
		delet();
		break;
	case 6:
		exit(0);
	default:
		cout<<"\n\t\t\t Opcion invalida...";
	}
	getch();
    }while(choice!= 6);
}

void Departamentos::insert()
{
	system("cls");
	fstream file;
	cout<<"\n                      -----------------------------------------";
	cout<<"\n                      |AGREGAR LA INFORMACION DEL DEPARTAMNETO|"<<endl;
	cout<<"\t\t\tIngresa codigo del Departamento        : ";
	cin>>codigo;
	cout<<"\t\t\tIngresa Nombre del Departamento    : ";
	cin>>nombre;
	cout<<"\t\t\tIngresa Nombre del Empleado   : ";
	cin>>nombreem;
	file.open("registrodedepartamentos.txt", ios::app | ios::out);
	file<<std::left<<std::setw(15)<<codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem<< "\n";
	file.close();
}
void Departamentos::display()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"\n-------------------------Tabla de Informacion de los Departamentos -------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t codigo Departamento: "<<codigo<<endl;
			cout<<"\t\t\t Nombre Departamento: "<<nombre<<endl;
			cout<<"\t\t\t Nombre Empleado: "<<nombreem<<endl;
			file >> codigo >> nombre >> nombreem;
		}
		if(total==0)
		{
			cout<<"\n\t\t\tNo hay informacion...";
		}
	}
	file.close();
}
void Departamentos::modify()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Modificacion de Informacion de Departamnetos-------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese codigo del Departamento que quiere modificar: ";
		cin>>participant_codigo;
		file1.open("registros.txt",ios::app | ios::out);
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo!=codigo)
			{
			 file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese codigo del Departamneto: ";
				cin>>codigo;
				cout<<"\t\t\tIngrese Nombre del Departamento: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Nombre del Empleado: ";
				cin>>nombreem;
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem<< "\n";
				found++;
			}
			file >> codigo >> nombre >> nombreem;

		}
		file1.close();
		file.close();
		remove("registrodedepartamentos.txt");
		rename("registros.txt","registrodedepartamentos.txt");
	}
}
void Departamentos::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n-------------------------Datos del Departamento buscado------------------------"<<endl;
		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_codigo;
		cout<<"\n-------------------------Datos del Departamento buscado------------------------"<<endl;
		cout<<"\nIngrese codigo del Departamento que quiere buscar: ";
		cin>>participant_codigo;
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo==codigo)
			{
				cout<<"\n\n\t\t\t codigo del Departamento: "<<codigo<<endl;
				cout<<"\t\t\t Nombre del Departamento: "<<nombre<<endl;
				cout<<"\t\t\t Nombre del empleado: "<<nombreem<<endl;
				found++;
			}
			file >> codigo >> nombre >> nombreem;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Departamento no encontrado...";
		}
		file.close();
	}
}
void Departamentos::delet()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"\n-------------------------Informacion del Departamento a Borrar-------------------------"<<endl;
	file.open("registrodedepartamentos.txt",ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el codigo del Departamento que quiere borrar: ";
		cin>>participant_codigo;
		file1.open("registros.txt",ios::app | ios::out);
		file >> codigo >> nombre >> nombreem;
		while(!file.eof())
		{
			if(participant_codigo!= codigo)
			{
				file1<<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< nombreem << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> codigo >> nombre  >> nombreem;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t codigo del Departamento no encontrado...";
		}
		file1.close();
		file.close();
		remove("registrodedepartamentos.txt");
		rename("registros.txt","registrodedepartamentos.txt");
		}
}
