#include <iostream>
#ifndef IMPUESTOS_H
#define IMPUESTOS_H

using namespace std;

class impuestos
{
    public:
        impuestos(int = 0, string = "", double = 0);

   void establecerNumeroId( int );
   int obtenerNumeroId() const;

   void establecerUsuario( string );
   string obtenerUsuario() const;

   void establecerSueldo( double );
   double obtenerSueldo() const;

    private:
        int numeroId;
        char usuario[ 10 ];
        double sueldo;

};

#endif // IMPUESTOS_H
