#include <iostream>

using namespace std;

#include <cstring>
#include "empleados.h"

empleados::empleados(int valorNumeroId, string valorUsuario, int valorTelefono)
{
    establecerNumeroId(valorNumeroId);
    establecerUsuario(valorUsuario);
    establecerTelefono(valorTelefono);
}
int empleados::obtenerNumeroId() const
{
    return numeroId;
}
void empleados::establecerNumeroId(int valorNumeroId)
{
    numeroId = valorNumeroId;
}
string empleados::obtenerUsuario() const
{
    return usuario;
}
void empleados::establecerUsuario(string usuarioString)
{
    const char *valorUsuario = usuarioString.data();
    int longitud = strlen( valorUsuario );
    longitud = ( longitud < 10 ? longitud : 9 );
    strncpy( usuario, valorUsuario, longitud );

    usuario [longitud] = '\0';
}
int empleados::obtenerTelefono() const
{
    return telefono;
}
void empleados::establecerTelefono(int valorTelefono)
{
    telefono = valorTelefono;
}
