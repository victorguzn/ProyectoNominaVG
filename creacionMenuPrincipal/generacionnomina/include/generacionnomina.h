#include <iostream>
#ifndef GENERACIONNOMINA_H
#define GENERACIONNOMINA_H

using namespace std;

class generacionnomina
{
    public:
        public:
        void menuprincipal();
		void generar();
		void vernominas();
		void transferencia();
		void enviarinformes();
        generacionnomina();
        virtual ~generacionnomina();

    protected:
        private:
            double horast, sueldomedio, iva, sueldofinal, sueldoiva;
};

#endif // GENERACIONNOMINA_H
