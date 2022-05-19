#ifndef EMPRESA_H
#define EMPRESA_H
#include <iostream>

using namespace std;
class Empresa
{
    public:
        public:
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
		void crearArchivoCredito();
        Empresa();
        virtual ~Empresa();

    protected:
    private:string id,nombre,telefono;

};

#endif // EMPRESA_H
