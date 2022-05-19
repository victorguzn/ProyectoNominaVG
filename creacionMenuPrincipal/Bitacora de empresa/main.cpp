#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>

using namespace std;

void limpiarpantalla();
void registrobitacora();
void verentradas();

int main()
{
    int opcion;

    cout<<"______________________________"<<endl;
    cout<<"---------| BITACORA |---------"<<endl;
    cout<<"______________________________"<<endl;

    cout<<"-"<<endl;
    cout<<"Bienvenido al menu de la bitacora ¿que deseas hacer?"<<endl;
    cout<<"Selecciona la opcion 1 o 2"<<endl;
    cout<<"   1. Añadir entrada en la bitacora"<<endl;
    cout<<"   2. Visualizar entradas añadidas"<<endl;
    cin>>opcion;

    if(opcion == 1){

    limpiarpantalla();
    registrobitacora();

    system("pause");
    return 0;
    }

    if(opcion == 2){

        limpiarpantalla();

        cout<<"____________________________________________"<<endl;
        cout<<"---- BITACORA (ENTRADAS REGISTRADAS) ------ "<<endl;
        cout<<"--------------------------------------------"<<endl;

        verentradas();

        system("pause");
        return 0;
    }
}

void limpiarpantalla(){
    system("cls");
}

void verentradas(){
    fstream archivo2;

    int opcion_v;
    string reproducir;

    archivo2.open("BITACORA2.dat", ios::in);

    if(archivo2.fail()){
        cout<<"No se pudo abrir el archivo :/ por favor, comprueba";
        exit(1);
    }

    while(!archivo2.eof()){
        getline(archivo2, reproducir);
        cout<<reproducir<<endl;
    }

    cout<<"______________________________"<<endl;
    cout<<"-"<<endl;
    cout<<"- Escribe 1 y ejecuta para volver al menu principal - "<<endl;
    cin>>opcion_v;

    if(opcion_v = 1){
        limpiarpantalla();
        main();
    }
}

void registrobitacora(){
    fstream archivo( "BITACORA.dat", ios::app | ios::binary);
    fstream archivo2( "BITACORA2.dat", ios::app | ios::binary);

    int opcion_r;
    string fecha, nota_dia, nombre;

    if (archivo.fail()){
      cerr<<"Archivo no encontrado, por favor verifica"<<endl;
      exit( 1 );
    }

    if (archivo2.fail()){
      cerr<<"Archivo no encontrado, por favor verifica"<<endl;
      exit( 1 );
    }

    cout<<"______________________________"<<endl;
    cout<<"------| NUEVA ENTRADA |------"<<endl;
    cout<<"______________________________"<<endl;
    cout<<"-"<<endl;

    archivo2<<"_______________________________________"<<endl;
    archivo2<<"------| ENTRADAS DE LA BITACORA |------"<<endl;
    archivo2<<"---------------------------------------"<<endl;

    cout<<"\nEscribe la fecha: ";
    cin.ignore();
    getline(cin,fecha);
    archivo2<<"------------- FECHA: ";

    archivo2<<fecha<<endl;;

    cout<<"\nEscribe en la bitacora: "<<endl;
    getline(cin,nota_dia);
    archivo2<<"----------------------"<<endl;

    archivo2<<"- ";
    archivo2<<nota_dia<<endl;

    cout<<"\nEscribe tu nombre: ";
    getline(cin,nombre);
    archivo2<<"--- NOMBRE: ";

    archivo2<<"- ";
    archivo2<<nombre<<endl;

    archivo2<<"----------------------\n"<<endl;

    for( int i = 0; i < 50; i++ ){
      archivo.write(
         reinterpret_cast<const char*>(&fecha),
         sizeof( fecha ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo.write(
         reinterpret_cast<const char*>(&nota_dia),
         sizeof( nota_dia ) );
    }

    for( int i = 0; i < 50; i++ ){
      archivo.write(
         reinterpret_cast<const char*>(&nombre),
         sizeof( nombre ) );
    }

    cout<<"----------------------------------------------------------"<<endl;
    cout<<"¡Felicidades! ¡Acabas de poner tu registro en la bitacora!"<<endl;
    cout<<"----------------------------------------------------------"<<endl;

    cout<<"______________________________"<<endl;
    cout<<"-"<<endl;
    cout<<"- Escribe 1 y ejecuta para volver al menu principal - "<<endl;
    cin>>opcion_r;

    if(opcion_r = 1){
        limpiarpantalla();
        main();
    }
}
