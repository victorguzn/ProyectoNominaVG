#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include "generacionnomina.h"

using namespace std;

generacionnomina::generacionnomina(){
 double horast, sueldomedio, iva, sueldofinal, sueldoiva;
}

generacionnomina::~generacionnomina(){

}

void generacionnomina::menuprincipal()
{
    int opcion;
	int x;

	do{

	system("cls");

	cout<<"------------------------------------------------------"<<endl;
	cout<<"\t\t ||||          GENERACION DE NOMINAS           ||||"<<endl;
	cout<<"------------------------------------------------------"<<endl;

	cout<<"\t 1. Ingresar datos de nueva nomina"<<endl;
	cout<<"\t 2. Ver nominas actuales"<<endl;
	cout<<"\t 3. Transferir nominas"<<endl;
	cout<<"\t 4. Enviar nominas"<<endl;
	cout<<"\t 5. Salir"<<endl;

    cout<<"-"<<endl;

    cout<<"\n\t RESPUESTA: ";
    cin>>opcion;

    switch(opcion)
    {
    case 1:
    	do
    	{
    		generar();
    		cout<<"\n\t ¿Deseas generar una nueva nomina?"<<endl;
    		cout<<"\n\t 1. Si"<<endl;
    		cout<<"\n\t 2. No"<<endl;
    		cout<<"-"<<endl;
    		cout<<"\n\t RESPUESTA:";
    		cin>>x;
		}while(x==1);
		break;
	case 2:
		vernominas();
		break;
    case 3:
        transferencia();
        break;
    case 4:
        enviarinformes();
        break;
    case 5:
        exit(5);
	default:
		cout<<"\n\t Por favor, elegir un numero del 1 al 5 segun dice la pantalla";
	}
	getch();
    }while(opcion!= 2);
}

void generacionnomina::generar()
{
	system("cls");
	fstream archivo, archivo2;
	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n----------------------------------- INGRESO DE DATOS ----------------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	cout<<"\tIngresa el sueldo medio: ";
	cin>>sueldomedio;

	cout<<"\tIngresa las horas trabajadas durante el mes: ";
	cin>>horast;

	iva = 0.12;
	sueldoiva = sueldomedio - (sueldomedio * iva);
	sueldofinal = sueldoiva;

	if(horast > 160){
        sueldofinal = sueldoiva + ((horast - 160) * 50);
	}

    archivo.open("nominasgeneradas.dat", ios::binary | ios::app | ios::out);
    archivo2.open("nominasgeneradas2.dat", ios::binary | ios::app | ios::out);


	archivo<<std::left<<std::setw(15)<< sueldomedio <<std::left<<std::setw(15)<< horast <<std::left<<std::setw(15)<< iva <<std::left<<std::setw(15)<< sueldoiva <<std::left<<std::setw(15)<< sueldofinal<<"\n";

	archivo.close();

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldomedio),
         sizeof( sueldomedio ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&horast),
         sizeof( horast ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&iva),
         sizeof( iva ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
         reinterpret_cast<const char*>(&sueldoiva),
         sizeof( sueldoiva ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo2.write(
        reinterpret_cast<const char*>(&sueldofinal),
        sizeof( sueldofinal ) );
    }
}

void generacionnomina::vernominas()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- VISUALIZACION DE NOMINAS GENERADAS --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;

	archivo.open("nominasgeneradas.dat",ios::binary|ios::in);

	if(!archivo)
	{
		cout<<"\n\t No has generado ninguna nomina al sistema";
		archivo.close();
	}

	else
	{
		archivo >> sueldomedio >> horast >> iva >> sueldoiva >> sueldofinal;

		while(!archivo.eof())
		{
			total++;
			cout<<"\n\n\t Sueldo medio: "<< sueldomedio <<endl;
			cout<<"\t Horas trabajadas: "<< horast <<endl;
			cout<<"\t IVA: "<< iva <<endl;
			cout<<"\t Sueldo con IVA: "<< sueldoiva <<endl;
			cout<<"\t Sueldo final: "<< sueldofinal <<endl;
			archivo >> sueldomedio >> horast >> iva >> sueldoiva >> sueldofinal;
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

void generacionnomina::transferencia()
{
	system("cls");

	fstream archivo;

	int total=0;
	int opcion, opcion2;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- TRANSFERENCIA DE ARCHIVOS --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-"<<endl;
    cout<<"\n¿Deseas transferir las nominas generadas? Escribe 1 para confirmar"<<endl;
    cin>>opcion;

	if(opcion = 1){
        cout<<"¡Felicidades! Los archivos han sido transferidos al sistema"<<endl;
	}

	cout<<"Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion2;

    if(opcion2 = 1){
        menuprincipal();
    }
}

void generacionnomina::enviarinformes(){
	system("cls");

	fstream archivo;

	int total=0;
	int opcion, opcion2;

	cout<<"\n______________________________________________________________________________________"<<endl;
	cout<<"\n------------------------- ENVÍO DE ARCHIVOS --------------------------"<<endl;
	cout<<"\n--------------------------------------------------------------------------------------"<<endl;
    cout<<"\n-"<<endl;
    cout<<"\n¿Deseas enviar las nominas generadas? Escribe 1 para confirmar"<<endl;
    cin>>opcion;

	if(opcion = 1){
        cout<<"¡Felicidades! Los archivos han sido enviados al sistema"<<endl;
	}

	cout<<"Escribe 1 para regresar al menu principal"<<endl;
	cin>>opcion2;

    if(opcion2 = 1){
        menuprincipal();
    }
}
