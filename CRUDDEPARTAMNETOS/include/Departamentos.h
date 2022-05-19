#include <iostream>
#ifndef DEPARTAMENTOS_H
#define DEPARTAMENTOS_H
using namespace std;

class Departamentos
{
    public:
        public:
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();
        Departamentos();
        virtual ~Departamentos();

    protected:
    private:string codigo,nombre,nombreem;
    ;
};

#endif // DEPARTAMENTOS_H
