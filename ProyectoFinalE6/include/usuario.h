#ifndef USUARIO_H
#define USUARIO_H

using namespace std;

class usuario
{
    public:
        usuario();
        virtual ~usuario();
        void menu();
        void menu1();
        void menu2();
        void login();
        void mantenimientos();
        void insert();
		void display();
		void modify();
		void search();
		void delet();
		void menuprincipal();
		void nuevopuesto();
		void verpuestos();
		void menu3();
		void insert2();
		void display2();
		void modify2();
		void search2();
		void delet2();
		void menu4();
        void insert3();
        void desplegar();
        void calcular();
        void modificar();
        void buscar();
        void borrar();
        void menu5();
		void insert4();
		void display3();
		void modify3();
		void search3();
		void delet3();
		void crearArchivoCredito();
		void menu6();
		void insert5();
		void display4();
		void modify4();
		void search4();
		void delet4();
		void crearArchivoCredito2();

    protected:

    private:
        string id,nombre,telefono;
        string nombrepuesto, area, segmento, salario, vacantes;
        string codigo,nombre1,nombreem;
        string id1, nombre2;
        int sueldo;
        string id2,nombre3,telefono2;
        string id3,nombre4,telefono3;
};

#endif // USUARIO_H
