#include <iostream>
#ifndef EMPLEADOS_H
#define EMPLEADOS_H
using namespace std;

class empleados
{
    public:
        empleados(int = 0, string = "", int = 0);

   void establecerNumeroId( int );
   int obtenerNumeroId() const;

   void establecerUsuario( string );
   string obtenerUsuario() const;

   void establecerTelefono( int );
   int obtenerTelefono() const;

    private:
        int numeroId;
        char usuario[ 10 ];
        int telefono;
};

#endif // EMPLEADOS_H
