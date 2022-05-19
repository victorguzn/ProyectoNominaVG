#ifndef BANCO_H
#define BANCO_H
#include <iostream>

using namespace std;
class Banco
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
        Banco();
        virtual ~Banco();

    protected:
    private:string id,nombre,telefono;

};

#endif // BANCO_H
