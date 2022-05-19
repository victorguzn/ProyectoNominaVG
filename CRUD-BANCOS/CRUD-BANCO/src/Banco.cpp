#include "Banco.h"
#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

Banco::Banco()
{
string id,nombre,telefono;
}

Banco::~Banco()
{
    //dtor
}


void Banco::menu()
{
    int choice;
	char x;
	do
    {
	system("cls");

	cout<<"\t\t\t |||||||||||||||||||||||||||"<<endl;
	cout<<"\t\t\t |   MANTENIMIENTO BANCOS  |"<<endl;
	cout<<"\t\t\t |||||||||||||||||||||||||||"<<endl;

    cout<<"" << endl;

	cout<<"\t\t\t 1. -Ingrese el banco-"<<endl;
	cout<<"\t\t\t 2. -Despliegue de bancos-" << endl;
	cout<<"\t\t\t 3. -Modificar bancos-"<<endl;
	cout<<"\t\t\t 4. -Buscar bancos-"<<endl;
	cout<<"\t\t\t 5. -Borrar bancos-"<<endl;
	cout<<"\t\t\t 6. -Salir-"<<endl;

	cout<<"\t\t\t __________________________"<<endl;
	cout<<"\t\t\t | Opciones: [1/2/3/4/5/6]|"<<endl;
	cout<<"\t\t\t "<<endl;
	cout<<"Ingresa tu Opcion: ";
    cin>>choice;

    switch(choice)
    {
    case 1:
    	do
    	{
    		insert();
    		cout<<"\n\t\t\t ¿Desea agregar otro banco?  (Y,N): ";
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
		cout<<"\n\t\t\t -¡Opcion invalida!-";
	}
	getch();
    }while(choice!= 6);
}

void Banco::insert()
{
	system("cls");
	fstream file;
	cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  AGREGA INFORMACION DE BANCO _________________________________________________"<<endl;

    cout <<""<<endl;
	cout<<"\t\t\t  Ingresa ID del banco         : ";
	cin>>id;
	cout<<"\t\t\t  Ingresa Nombre del banco     : ";
	cin>>nombre;
	cout<<"\t\t\t  Ingresa Telefono del banco   : ";
	cin>>telefono;

    file.open("registroDeBancos.dat", ios::binary | ios::app | ios::out);
	file<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
	file.close();
}

void Banco::display()
{
	system("cls");
	fstream file;
	int total=0;
cout<<"\n________________________________________________________________________________________________________________________"<<endl;
cout<<"\n_________________________________________  INFORMACION GUARDADA DE BANCOS ______________________________________________"<<endl;

    cout <<""<<endl;
    file.open("registroDeBancos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay información...";
		file.close();
	}
	else
	{
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			total++;
			cout<<"\n\n\t\t\t ID banco: "<<id<<endl;
			cout<<"\t\t\t Nombre banco: "<<nombre<<endl;
			cout<<"\t\t\t Telefono banco "<<telefono<<endl;
			file >> id >> nombre >> telefono;
		}
		if(total==0)
		{
			cout<<"\n\t\t\t-No hay informacion-";
		}
	}
	file.close();
}

void Banco::modify()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  MODIFICACION DE BANCOS ______________________________________________________"<<endl;

    cout <<""<<endl;

    file.open("registroDeBancos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese Id del banco que quiere modificar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!=id)
			{
			 file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				cout<<"\t\t\tIngrese Id del banco ";
				cin>>id;
				cout<<"\t\t\tIngrese Nombre del banco: ";
				cin>>nombre;
				cout<<"\t\t\tIngrese Telefono del banco: ";
				cin>>telefono;
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono<< "\n";
				found++;
			}
			file >> id >> nombre >> telefono;

		}
		file1.close();
		file.close();
		remove("registroDeBancos.dat");
		rename("registro.dat","registroDeBancos.dat");
	}
}

void Banco::search()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("registroDeBancos.dat",ios::binary|ios::in);
	if(!file)
	{
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  AGREGA INFORMACION DE BANCO _________________________________________________"<<endl;

    cout <<""<<endl;		cout<<"\n\t\t\tNo hay informacion...";
	}
	else
	{
		string participant_id;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  BUSCAR INFORMACION BANCO ____________________________________________________"<<endl;

    cout <<""<<endl;		cout<<"\nIngrese Id del banco que quiere buscar: ";
		cin>>participant_id;
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id==id)
			{
				cout<<"\n\n\t\t\t Id del banco: "<<id<<endl;
				cout<<"\t\t\t Nombre del banco: "<<nombre<<endl;
				cout<<"\t\t\t Telefono del banco: "<<telefono<<endl;
				found++;
			}
			file >> id >> nombre >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Banco no encontrado...";
		}
		file.close();
	}
}


void Banco::delet()
{
	system("cls");
	fstream file,file1;
	string participant_id;
	int found=0;
    cout<<"\n________________________________________________________________________________________________________________________"<<endl;
	cout<<"\n_________________________________________  BORRAR INFORMACION BANCO ____________________________________________________"<<endl;

    cout <<""<<endl;	file.open("registroDeBancos.dat",ios::binary|ios::in);
	if(!file)
	{
		cout<<"\n\t\t\tNo hay informacion...";
		file.close();
	}
	else
	{
		cout<<"\n Ingrese el Id del banco que quiere borrar: ";
		cin>>participant_id;
		file1.open("registro.dat",ios::binary|ios::app | ios::out);
		file >> id >> nombre >> telefono;
		while(!file.eof())
		{
			if(participant_id!= id)
			{
				file1<<std::left<<std::setw(15)<< id <<std::left<<std::setw(15)<< nombre <<std::left<<std::setw(15)<< telefono << "\n";
			}
			else
			{
				found++;
				cout << "\n\t\t\tBorrado de informacion exitoso";
			}
			file >> id >> nombre  >> telefono;
		}
		if(found==0)
		{
			cout<<"\n\t\t\t Id del banco no encontrado...";
		}
		file1.close();
		file.close();
		remove("registroDeBancos.dat");
		rename("registro.dat","registroDeBancos.dat");
	}
}
