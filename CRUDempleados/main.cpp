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
#include "empleados.h"

int escribirOpcion();
void crearArchivoCredito();
void nuevoRegistro( fstream& );
void consultarRegistro( fstream& );
void buscarRegistro(fstream&);
int obtenerId( const char * const );
void mostrarLineaPantalla( const empleados &);
void actualizarRegistro( fstream& );
void mostrarLinea( ostream&, const empleados & );
void eliminarRegistro( fstream& );

enum Opciones { Ingresar = 1, Consultar, Buscar, Borrar, FIN };

int main()
{
    fstream creditoEntradaSalida( "RegistroEmpleados.dat", ios::in | ios::out | ios::binary);

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
        << "\t\t\t           | Menu de Empleados |" << endl
        << "\t\t\t *********************************************" << endl
        << "\t\t\t 1 - Ingresar empleados" << endl
        << "\t\t\t 2 - Desplegar empleados" << endl
        << "\t\t\t 3 - Buscar empleados" << endl
        << "\t\t\t 4 - Borrar empleados "<< endl
        << "\t\t\t 5 - Salir "<<endl;
    cout<< "\t\t\t *********************************************"<<endl;
    cout<< "\t\t\t Ingresa tu opcion [1/2/3/4/5]"<<endl;
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
      ( numeroId - 1 ) * sizeof( empleados ) );

   empleados persona;
   insertarEnArchivo.read( reinterpret_cast< char * >( &persona ), sizeof( empleados ) );

   if ( persona.obtenerNumeroId() == 0 ) {

      char usuario[ 10 ];
      int telefono;

      cout << "Escriba el nombre del empleado: " << endl;
      cin >> setw( 10 ) >> usuario;
      cout << "Escriba el numero de telefono: " << endl;
      cin >> telefono;

      persona.establecerUsuario( usuario );
      persona.establecerNumeroId( numeroId );
      persona.establecerTelefono( telefono );

      insertarEnArchivo.seekp( ( numeroId - 1 ) *
         sizeof( empleados ) );

      insertarEnArchivo.write(
         reinterpret_cast< const char * >( &persona ),
         sizeof( empleados ) );

   }
   else
      cerr << "La cuenta # " << numeroId
           << " ya contiene informacion." << endl;
    system("cls");

}

void consultarRegistro( fstream &leerDeArchivo )
{
    system("cls");
   cout << left << setw( 10 ) << "ID" << setw( 14 ) << "Usuario" << right<< setw( 10 ) << endl;

   leerDeArchivo.seekg( 0 );

   empleados persona;
   leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( empleados ) );

   while ( !leerDeArchivo.eof() ) {

      if ( persona.obtenerNumeroId() != 0 )
         mostrarLineaPantalla(persona);

      leerDeArchivo.read( reinterpret_cast< char * >( &persona ),
         sizeof( empleados ) );

   }

}

void buscarRegistro( fstream &buscarArchivo )
{
    system("cls");
   int numeroId = obtenerId( "Escriba el Id del empleado a buscar: " );

    buscarArchivo.seekg(
      ( numeroId - 1 ) * sizeof( empleados ) );

    empleados persona;
   buscarArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( empleados ) );

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
   int numeroId = obtenerId( "Escriba el Id del empleado a eliminar: " );

   eliminarDeArchivo.seekg(
      ( numeroId - 1 ) * sizeof( empleados ) );

   empleados persona;
   eliminarDeArchivo.read( reinterpret_cast< char * >( &persona ),
      sizeof( empleados ) );

   if ( persona.obtenerNumeroId() != 0 ) {
      empleados clienteEnBlanco;

      eliminarDeArchivo.seekp( ( numeroId - 1 ) *
         sizeof( empleados ) );

      eliminarDeArchivo.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( empleados ) );

      cout << "Informacion #" << numeroId << " eliminada.\n";

   }

   else
      cerr << "La posicion #" << numeroId << " esta vacia.\n";

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

void mostrarLinea( ostream &salida, const empleados &registro )
{
   salida << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << registro.obtenerTelefono()<< endl;

}

void mostrarLineaPantalla( const empleados &registro )
{
   cout << left << setw( 10 ) << registro.obtenerNumeroId()
          << setw( 14 ) << registro.obtenerUsuario().data()
          << setw( 10 ) << setprecision( 2 ) << right << fixed
          << showpoint << endl;

}

void crearArchivoCredito()
{
    ofstream creditoSalida( "RegistroEmpleados.dat", ios::out | ios::binary );
   if ( !creditoSalida ) {
      cerr << "No se pudo abrir el archivo." << endl;
      exit( 1 );

   }

   empleados clienteEnBlanco;

   for ( int i = 0; i < 100; i++ )
      creditoSalida.write(
         reinterpret_cast< const char * >( &clienteEnBlanco ),
         sizeof( empleados ) );
}
