#include <iostream>
#ifndef PUESTOS_H
#define PUESTOS_H
using namespace std;

class Puestos
{
    public:
        public:
        void menuprincipalpuestos();
		void nuevopuesto();
		void verpuestos();
        Puestos();
        virtual ~Puestos();

    protected:
        private:
            string nombrepuesto, area, segmento, salario, vacantes;
};

#endif
