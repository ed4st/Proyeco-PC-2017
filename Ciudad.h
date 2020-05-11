#ifndef CIUDAD_H_INCLUDED
#define CIUDAD_H_INCLUDED

#include "listaT.h"
#include "Sitio.h"

struct Ciudad{
private:
    string nombre;
    string pais;
    Lista<Sitio> listaSitios;

public:
    Ciudad();
    Ciudad(string nombre, string pais, Lista<Sitio> lista);

    void setNombre(string nombre);
    void setPais(string pais);
    string getNombre();
    string getPais();
    Lista<Sitio> getSitios();

    void agregarSitio(Sitio s);
    bool buscarSitio(Sitio s);
    void imprimir();
    bool operator == (Ciudad &a);

};

#include "Ciudad.hpp"

#endif // CIUDAD_H_INCLUDED
