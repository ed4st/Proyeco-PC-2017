#ifndef SITIO_HPP_INCLUDED
#define SITIO_HPP_INCLUDED

#include "Sitio.h"

Sitio::Sitio(){
  this->nombre="";
  this->tipo="";
  this->descripcion="";
}

void Sitio::setNombre(string n){
  this->nombre = n;
}
void Sitio::setDescripcion(string descrip){
    this->descripcion=descrip;
}
string Sitio::getDescripcion(){
  return this->descripcion;
}

void Sitio::setCalificacion(int n){
    this->calificacion=n;
}
string Sitio::getNombre(){
  return this->nombre;
}

void Sitio::setTipo(string tipo){
  this->tipo = tipo;
}
void Sitio::imprimir(){
    cout<<this->nombre<<endl<<endl;
    cout<<this->tipo<<endl<<endl;
    cout<<this->descripcion<<endl<<endl;
    cout<<this->calificacion<<endl<<endl;
}

string Sitio::getTipo(){
  return this->tipo;
}
int Sitio::getCalificacion(){
return this->calificacion;
}
bool Sitio::operator==(Sitio &a){
    if(this->nombre==a.nombre&&this->tipo==a.tipo&&this->descripcion==a.descripcion){
        return true;
    }else{
        return false;
    }

}
#endif // SITIO_HPP_INCLUDED
