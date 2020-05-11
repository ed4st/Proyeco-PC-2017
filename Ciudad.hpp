#ifndef CIUDAD_HPP_INCLUDED
#define CIUDAD_HPP_INCLUDED

#include<iostream>

#include<string>
#include "Sitio.h"

#include "Ciudad.h"

Ciudad::Ciudad(){
  this->listaSitios.listaVacia();
}

void Ciudad::setNombre(string nombre){
  this->nombre = nombre;
}

string Ciudad::getNombre(){
  return this->nombre;
}

void Ciudad::setPais(string pais){
  this->pais = pais;
}

string Ciudad::getPais(){
  return this->pais;
}

void Ciudad::agregarSitio(Sitio s){
  this->listaSitios.insertarCabeza(s);
}

Lista<Sitio> Ciudad::getSitios(){
  return this->listaSitios;
}

bool Ciudad::buscarSitio(Sitio s){
    Nodo<Sitio>* aux=(this->getSitios()).cabezaL();
    do{
    if(aux->dato==s){
        return true;
    }else{
    aux=aux->siguiente;
    }
    }while(aux==NULL);
    return false;
}

void Ciudad::imprimir(){
    cout<<this->pais<<endl<<endl;
    cout<<this->nombre<<endl<<endl;
    Nodo<Sitio>* aux=this->listaSitios.cabezaL();
    while(aux==NULL){
        cout<<"   ";
        (aux->dato).imprimir();
        aux=aux->siguiente;
    }
}

bool Ciudad::operator==(Ciudad &a){
    if(this->nombre==a.nombre&&this->pais==a.pais){
        return true;
    }else{
        return false;
    }

}

#endif // CIUDAD_HPP_INCLUDED
