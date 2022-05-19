#include <iostream>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::ios;
using std::left;
using std::right;
using std::fixed;
using std::showpoint;

#include <fstream>

using std::ofstream;
using std::ostream;
using std::fstream;

#include <iomanip>

using std::setw;
using std::setprecision;

#include <cstdlib>
#include "impuestos.h"

int escribirOpcion();
void crearArchivoCredito();
void nuevoRegistro( fstream& );
void consultarRegistro( fstream& );
void buscarRegistro(fstream&);
int obtenerId( const char * const );
void mostrarLineaPantalla( const impuestos &);
void actualizarRegistro( fstream& );
void mostrarLinea( ostream&, const impuestos & );
void eliminarRegistro( fstream& );
void calcularSueldo(fstream&);
void obtenerSueldo( const char * const);
void conceptosS();

enum Opciones { Ingresar = 1, Consultar, Buscar, Borrar, Conceptos, FIN };

int main()
{
    fstream creditoEntradaSalida( "Informacion.dat", ios::in | ios::out | ios::binary);

    if ( !creditoEntradaSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      crearArchivoCredito();
      cout <<  "Archivo creado satisfactoriamente, pruebe de nuevo";
      exit ( 1 );

    }
    int opcion;

   while ( ( opcion = escribirOpcion() ) != FIN ) {

      switch ( opcion ) {

         case Ingresar:
            nuevoRegistro( creditoEntradaSalida );
            break;

         case Consultar:
            consultarRegistro( creditoEntradaSalida );
            break;

         case Buscar:
            buscarRegistro(creditoEntradaSalida);
            break;

         case Borrar:
            eliminarRegistro( creditoEntradaSalida );
            break;

         case Conceptos:
            conceptosS();
            break;

         default:
            cerr << "Opcion incorrecta" << endl;
            break;

      }

      creditoEntradaSalida.clear();

   }

   return 0;
}
int escribirOpcion()
{

   cout << "\t\t\t *********************************************" << endl
        << "\t\t\t           | Menu de Conceptos |" << endl
        << "\t\t\t *********************************************" << endl
        << "\t\t\t 1 - Ingresar informacion salarial" << endl
        << "\t\t\t 2 - Desplegar informacion salarial" << endl
        << "\t\t\t 3 - Buscar inforacion salarial" << endl
        << "\t\t\t 4 - Borrar informacion salarial "<< endl
        << "\t\t\t 5 - Conceptos "<< endl
        << "\t\t\t 6 - Salir "<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\t\t\t Ingresa tu opcion [1/2/3/4/5/6]"<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\n\t\t\t Opcion: ";

   int opcionMenu;
   cin >> opcionMenu;

   return opcionMenu;

}

void nuevoRegistro( fstream &insertarEnArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el ID que desea asignar: " );

   insertarEnArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   impuestos persona;
   insertarEnArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() == 0 ) {

      char usuario[ 10 ];
      double sueldo;

      cout << "Escriba el nombre de usuario: " << endl;
      cin >> setw( 10 ) >> usuario;
      cout << "Escriba el sueldo: " << endl;
      cin >> sueldo;

      persona.establecerUsuario( usuario );
      persona.establecerSueldo( sueldo );
      persona.establecerNumeroId( numeroId );

      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &persona ),
         sizeof( impuestos ) );

   }

   else
      cerr << "La cuenta # " << numeroId
           << " ya contiene informacion." << endl;
    system("cls");

}

void consultarRegistro( fstream &leerDeArchivo )
{
    system("cls");
   cout << left << setw( 10 ) << "ID" << setw( 14 ) << "Usuario" << right<< setw( 10 ) << "Sueldo" << endl;

   leerDeArchivo.seekg( 0 );

   impuestos persona;
   leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   while ( !leerDeArchivo.eof() ) {

      if ( persona.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(persona);

      leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
         sizeof( impuestos ) );

   }

}

void buscarRegistro( fstream &buscarArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el Id de la persona a buscar: " );

    buscarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

    impuestos persona;
   buscarArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() != 0 ) {
      mostrarLinea( cout, persona );
   }

   else
      cerr << "La cuenta #" << numeroId
         << " no tiene informacion." << endl;

}

void eliminarRegistro( fstream &eliminarDeArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el Id de la persona a eliminar: " );

   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( impuestos ) );

   impuestos persona;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( impuestos ) );

   if ( persona.obtenerNumeroId() != 0 ) {
      impuestos clienteEnBlanco;

      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( impuestos ) );

      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );

      cout << "Informacion #" << numeroId << " eliminada.\n";

   }

   else
      cerr << "La posicion #" << numeroId << " esta vacia.\n";

}

void conceptosS()
{
    system("cls");

    cout<<" Cantidades a calcular: "<<endl;
    cout<<" Mensual: "<<endl;
    cout<<" - 4.83% IGSS "<<endl;
    cout<<" + Q250  Bono Incentivo "<<endl;
    cout<<" Anual: "<<endl;
    cout<<" + 100% Bono 14 "<<endl;
    cout<<" + 100% Aguinaldo "<<endl;

}

int obtenerId( const char * const indicador )
{
   int numeroId;

   do {
      cout << indicador << " (1 - 100): ";
      cin >> numeroId;

   } while ( numeroId < 1 || numeroId > 100 );

   return numeroId;

}

void mostrarLinea( ostream &salida, const impuestos &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

}

void mostrarLineaPantalla( const impuestos &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerSueldo() << endl;

}

void crearArchivoCredito()
{
    ofstream creditoSalida( "Informacion.dat", ios::out | ios::binary );
   if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   impuestos clienteEnBlanco;

   for ( int i = 0; i < 100; i++ )
      creditoSalida.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( impuestos ) );
}
