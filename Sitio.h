#ifndef SITIO_H_INCLUDED
#define SITIO_H_INCLUDED

struct Sitio{
private:
    string nombre;
    string tipo;
    string descripcion;
    int calificacion;

public:
    Sitio();
    Sitio(string n, string t, string d);

    void setNombre(string nombre);
    void setTipo(string tipo);
    void setDescripcion(string descrip);
    void setCalificacion(int n);
    string getNombre();
    string getTipo();
    int getCalificacion();
    string getDescripcion();
    void imprimir();
    bool operator == (Sitio &a);
};

#include "Sitio.hpp"

#endif // SITIO_H_INCLUDED
