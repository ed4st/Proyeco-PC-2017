#include <iostream>
#include<string.h>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>
//#include "lista.h"
#include "listaT.h"
#include "Sitio.h"
#include "Ciudad.h"
using namespace std;
#define contra "soyadmi"


Nodo<Ciudad>* buscarC(Lista<Ciudad> lCiudades){
     string city;
    bool cont=true;

    cout<<"que cuidad desea consultar?"<<endl<<endl;
    cin>>city;
    Nodo<Ciudad> *aux=lCiudades.cabezaL();
    cout<<"estos son los datos que se encontraron de: "<<city<<endl;
    do{
    if(((aux->dato).getNombre()==city)){
        cont=false;
        (aux->dato).imprimir();
    }else{
        aux=aux->siguiente;
    }

    }while(cont==true&&aux!=NULL);
    return aux;

}
Nodo<Ciudad>* buscarP(Lista<Ciudad> lCiudades){
    string country;
    bool cont=true;
    cout<<"ingrese el pais que desea consultar"<<endl<<endl;
    cin>>country;
    cout<<"estos son los datos que se encontraron de: "<<country<<endl;
    Nodo<Ciudad> *aux=lCiudades.cabezaL();
    do{
    if(((aux->dato).getPais()==country)){
        (aux->dato).imprimir();
        cont=false;
    }else{
        aux=aux->siguiente;
    }
    }while(cont==true&&aux!=NULL);
    return aux;
}
Nodo<Sitio>* buscarS(Lista<Ciudad> lCiudades){
        bool cont=true;
        string sitio;
        string tipo;
        cout<<"ingrese el nombre del sitio que desea consultar"<<endl<<endl;
        cin>>sitio;
        cout<<"ingrese el tipo del sitio que desea consultar"<<endl<<endl;
        cin>>tipo;
        Nodo<Ciudad> *aux=lCiudades.cabezaL();
        if(aux!=NULL){
        Nodo<Sitio>*aux2=(((aux->dato).getSitios()).cabezaL());

        do{
            aux2=(((aux->dato).getSitios()).cabezaL());
                do{
                    if(((aux2->dato).getNombre())==sitio&&((aux2->dato).getTipo())==tipo){
                            (aux2->dato).imprimir();
                            cont=false;
                }else{
                            aux2=aux2->siguiente;
                }
                }while(cont==true&&aux2!=NULL);
                aux=aux->siguiente;

        }while(cont==true&&aux!=NULL);

    return aux2;
        }
    return NULL;
}
void modificarS(Nodo<Sitio>* aux2){
    string help;
    cout<<"ingrese nuevo nombre"<<endl;
        cin>>help;
        if(help!="no"){
        (aux2->dato).setNombre(help);
        }
        cout<<"ingrese nuevo tipo"<<endl;
        cin>>help;
        if(help!="no"){
        (aux2->dato).setTipo(help);
        }
        cout<<"ingrese nueva descripcion"<<endl;
        cin>>help;
        if(help!="no"){
        (aux2->dato).setDescripcion(help);
        }
}

Nodo<Sitio>* menorC(Nodo<Ciudad>* city){
Nodo<Sitio>* aux=((city->dato).getSitios()).cabezaL();
Nodo<Sitio>* menor=aux;
while(aux!=NULL){
    if((aux->dato).getCalificacion()<(menor->dato).getCalificacion()){
        menor=aux;
    }
    aux=aux->siguiente;

}
return menor;
}

Nodo<Sitio>* mayorC(Nodo<Ciudad>* city){
Nodo<Sitio>* aux=((city->dato).getSitios()).cabezaL();
Nodo<Sitio>* mayor=aux;
while(aux!=NULL){
    if((aux->dato).getCalificacion()<(mayor->dato).getCalificacion()){
        mayor=aux;
    }
    aux=aux->siguiente;

}
return mayor;
}
Nodo<Sitio>* menorT(Lista<Ciudad> lCiudades){
    Nodo<Sitio>* menor=(((lCiudades.cabezaL())->dato).getSitios()).cabezaL();
    Nodo<Ciudad>* auxc=lCiudades.cabezaL();
    Nodo<Sitio>* auxs;
    while(auxc!=NULL){
        auxs=menorC(auxc);
        if((auxs->dato).getCalificacion()<(menor->dato).getCalificacion()){
            menor=auxs;
        }
        auxc=auxc->siguiente;
    }
    return menor;
}
Nodo<Sitio>* mayorT(Lista<Ciudad> lCiudades){
    Nodo<Sitio>* mayor=(((lCiudades.cabezaL())->dato).getSitios()).cabezaL();
    Nodo<Ciudad>* auxc=lCiudades.cabezaL();
    Nodo<Sitio>* auxs;
    while(auxc!=NULL){
        auxs=mayorC(auxc);
        if((auxs->dato).getCalificacion()>(mayor->dato).getCalificacion()){
            mayor=auxs;
        }
        auxc=auxc->siguiente;
    }
    return mayor;
}
void modificarC(Nodo<Ciudad>* aux, Lista<Ciudad> lCiudades){
    string help;
    cout<<"ingrese el nuevo nombre (si no lo desea cambiar ingrese no)"<<endl<<endl;
    cin>>help;
    if(help!="no"){
    (aux->dato).setNombre(help);
    }
    cout<<"ingrese el nuevo pais (si no lo desea cambiar ingrese no)"<<endl<<endl;
    cin>>help;
    if(help!="no"){
    (aux->dato).setPais(help);
    }
    cout<<"si desea ingresar un nuevo sitio ingrese -i- si desea modificar un sitio ya existente ingrese -m- (si no lo desea cambiar ingrese no)"<<endl<<endl;
    cin>>help;
    if(help!="no"){
    if(help=="i"){
        do{
        Sitio nuevo;
        cout<<"ingrese nombre"<<endl;
        cin>>help;
        nuevo.setNombre(help);
        cout<<"ingrese tipo"<<endl;
        cin>>help;
        nuevo.setTipo(help);
        cout<<"ingrese descripcion"<<endl;
        cin>>help;
        nuevo.setDescripcion(help);
        nuevo.setCalificacion(0);
        (aux->dato).agregarSitio(nuevo);
        cout<<"desea agregar otro sitio?(si/no)"<<endl;
        cin>>help;
        }while(help=="no");
    }else if(help=="m"){
        cout<<"si no desea cambiar algo ingrese no"<<endl;
        Nodo<Sitio>* aux2;
        do{
        aux2=buscarS(lCiudades);
        modificarS(aux2);
        cout<<"desea modificar otro sitio?(si/no)"<<endl;
        cin>>help;
        }while(help!="no");
    }
    }


}

Lista<Ciudad> consultar(Lista<Ciudad> lCiudades, string verificar){
    bool cont=true;
    string confirmar;
    Nodo<Sitio>* menor;
    Nodo<Sitio>* mayor;
    cout<<"ud desea ver toda la informacion de la base de datos?(si/no)"<<endl;
    cin>>confirmar;
    if(lCiudades.cabezaL()!=NULL){
    if(confirmar=="si"){

    lCiudades.imprimir();
    menor=menorT(lCiudades);
    mayor=mayorT(lCiudades);
    cout<<"el sitio con menor calificacion de toda la base de datos es: "<<endl;
    (menor->dato).imprimir();
    cout<<"el sitio con mayor calificacion de toda la base de datos es: "<<endl;
    (mayor->dato).imprimir();
    }else{

    cout<<"desea consultar una ciudad, un pais o un sitio?(1,2,3)"<<endl;
    cin>>confirmar;
    if(confirmar=="1"){
        Nodo<Ciudad> *aux=buscarC(lCiudades);

        menor=menorC(aux);
        mayor=mayorC(aux);
        cout<<"el sitio con menor calificacion de la ciudad es: "<<endl;
        (menor->dato).imprimir();
        cout<<"el sitio con mayor calificacion de la ciudad es: "<<endl;
        (mayor->dato).imprimir();

    if(verificar==contra){
        cout<<"desea elmininar/modificar la informaci\'on encontrada(e,m,no)"<<endl;
        cin>>confirmar;
        if(confirmar=="e"){
            lCiudades.eliminar(aux->dato);
        }else if(confirmar=="m"){
             modificarC(aux,lCiudades);
        }
    }

    }else if(confirmar=="2"){
        Nodo<Ciudad> *aux=buscarP(lCiudades);
        if(aux!=NULL){
        menor=menorC(aux);
        mayor=mayorC(aux);
        }
        cout<<"el sitio con menor calificacion del pais es: "<<endl;
        (menor->dato).imprimir();
        cout<<"el sitio con mayor calificacion del pais es: "<<endl;
        (mayor->dato).imprimir();
        if(verificar==contra){
        cout<<"desea elmininar/modificar la informaci\'on encontrada(e,m,no)"<<endl;
        cin>>confirmar;
        if(confirmar=="e"){
            lCiudades.eliminar(aux->dato);
        }else if(confirmar=="m"){
             modificarC(aux,lCiudades);
        }
    }

    }else if(confirmar=="3"){
        Nodo<Sitio> *aux2=buscarS(lCiudades);
        if(aux2!=NULL){
        if(verificar==contra){
        cout<<"desea elmininar/modificar la informaci\'on encontrada(e,m,no)"<<endl;
        cin>>confirmar;
        if(confirmar=="e"){
            bool cont=false;
            Nodo<Ciudad> *aux=lCiudades.cabezaL();
            if(!((aux->dato).buscarSitio(aux2->dato))){
            do{
                aux=aux->siguiente;
                cont=((aux->dato).buscarSitio(aux2->dato));

            }while(!cont||aux==NULL);
            }
            ((aux->dato).getSitios()).eliminar(aux2->dato);

        }else if(confirmar=="m"){
            modificarS(aux2);

        }
    }else {
        cout<<"desea agregar una calificacion(c,no)"<<endl;
        cin>>confirmar;
        if(confirmar=="c"){
            int cal;
            cout<< "ingrese nueva calificacion"<<endl;
            cin>>cal;
            (aux2->dato).setCalificacion(cal);
        }
        cout<<"desea agregar una descripcion? (d,no)"<<endl;
        cin>>confirmar;
         if(confirmar=="d"){
            cout<<"ingrese nueva descripcion"<<endl;
            cin>>confirmar;
            (aux2->dato).setDescripcion(confirmar);
        }
    }
    }
    }
    }
    }else{
    cout<<"la lista esta vacia"<<endl;
    }

return lCiudades;
}




Lista<Ciudad> agregar(Lista<Ciudad> lCiudades){
    Ciudad nuevaCiudad;
    Sitio nuevoSitio;
    string continuar;
    string aux;
    do{
    cout<<"ingrese le nombre de la ciudad"<<endl<<endl;
    cin>>aux;
    nuevaCiudad.setNombre(aux);
    cout<<"ingrese le nombre del pais"<<endl<<endl;
    cin>>aux;
    nuevaCiudad.setPais(aux);
    do{
    cout<<"ingrese el nombre del sitio perteneciente a la ciudad"<<endl;
    cin>>aux;
    nuevoSitio.setNombre(aux);
    cout<<"ingrese el tipo del sitio"<<endl<<endl;
    cin>>aux;
    nuevoSitio.setTipo(aux);
    nuevaCiudad.agregarSitio(nuevoSitio);
    cout<<"desea ingresar un nuevo sitio?(si/no)"<<endl<<endl;
    cin>>continuar;
    }while(continuar=="si");
    cout<<"desea ingresar una nueva ciudad?(si/no)"<<endl<<endl;
    cin>>continuar;
    lCiudades.insertarCabeza(nuevaCiudad);

    }while(continuar=="si");
return lCiudades;
}


Lista<Ciudad> menuadmi(int deseo, Lista<Ciudad> lCiudades,string verificar){

    bool confirmar;
    if(deseo==1){//1 se refiere aa agregar
        lCiudades=agregar(lCiudades);
    }else if(deseo==2){//2 se refiere a consultar la cual permitira eliminar o modificar tambien

        lCiudades=consultar(lCiudades, verificar);
    }
    return lCiudades;
}


Lista<Ciudad> cargar(){
    Lista<Ciudad> lCiudades;
    lCiudades.listaVacia();
    ifstream file;
    file.open ("lugares.txt");
    string str;
    Ciudad nuevaCiudad[100];
    int count=0;
    int count2=0;
    while (!file.eof()){
      getline(file, str);
      string strWords[5];
      short counter = 0;
      for(short i=0;i<str.length();i++){
        if (str[i] == ','){
          counter++;
        }else{
          strWords[counter] += str[i];
        }
      }
    if (strWords[0]=="c"){
      count2++;
      if (count2>1){
        lCiudades.insertarCabeza(nuevaCiudad[count2-1]);
      }
      nuevaCiudad[count2].setNombre(strWords[1]);
      nuevaCiudad[count2].setPais(strWords[2]);

    }else if (strWords[0]=="s"){
      Sitio nuevoSitio;
      nuevoSitio.setNombre(strWords[1]);
      nuevoSitio.setTipo(strWords[2]);
      nuevoSitio.setDescripcion(strWords[3]);
      int strWords4=atoi(strWords[4].c_str());
      nuevoSitio.setCalificacion(strWords4);
      //nuevoSitio.imprimir();
      nuevaCiudad[count2].agregarSitio(nuevoSitio);
      //nuevaCiudad[count2].imprimir();
    }
    count++;
  }
  lCiudades.insertarCabeza(nuevaCiudad[count2]);
  file.close();
  return lCiudades;
}

void  guardar(Lista<Ciudad> lCiudades){
    Nodo<Ciudad> *aux=lCiudades.cabezaL();
    ofstream file;
    file.open ("lugares.txt");
    string str;
    string str2;
    int count=0;
    int cal;
    Nodo<Sitio>*aux2=(((aux->dato).getSitios()).cabezaL());
    do{
      str="c,"+(aux->dato).getNombre()+","+(aux->dato).getPais()+"\n";
      file << str ;
      aux2=(((aux->dato).getSitios()).cabezaL());
      while (aux2!=NULL) {
        //char* intStr=itoa((aux2->dato).getCalificacion());
        //string cal=to_string((aux2->dato).getCalificacion());
        string cal="3";
        //str2="s,"+(aux2->dato).getNombre()+","+(aux2->dato).getTipo()+","+" "+","+cal+"\n";
        str2="s,"+(aux2->dato).getNombre()+","+(aux2->dato).getTipo()+","+(aux2->dato).getDescripcion()+","+cal+"\n";
        file << str2;
        aux2=aux2->siguiente;
      }
      aux=aux->siguiente;
    }while (aux!=NULL);

}

int main () {
    Lista<Ciudad> lCiudades;
    lCiudades.listaVacia();
    lCiudades=cargar();
string verificar;
bool bien;

cout<<"Desea ingresar como administrador?(si/no):  ";
getline(cin ,verificar);
if(verificar=="si"){
    cout<<"ingrese contrasenia"<<endl;
        getline(cin, verificar);
    if(verificar==contra){
        do{
        int deseo;
        cout<<"Bienvenido administrador"<<endl;
        cout<< "si desea agrgar una nueva ciudad presione igrese 1"<<endl;
        cout<< "si desea ver la informaci�n de una ciudad, pais o sitio ingrese 2"<<endl;
        cin>>deseo;
        verificar=contra;
        if(lCiudades.cabezaL()!=NULL){
            lCiudades=menuadmi(deseo, lCiudades, verificar);
        }else{
            cout<<"la lista esta vacia"<<endl;
        }
        cout<<"desea volver al menu de administrador?(si/no)"<<endl;
        cin>>verificar;
        guardar(lCiudades);
        }while(verificar!="no");

    }else{
    cout<<"contrasenia equivocada"<<endl;
    }

}else if(verificar=="no"){
    do{
        int deseo;
        bool bien;
        cout<<"Bienvenido usuario"<<endl;
        if(lCiudades.cabezaL()!=NULL){
            lCiudades=consultar(lCiudades,verificar);
        }else{
            cout<<"la lista esta vacia"<<endl;
        }
        cout<<"desea volver al menu de usuario?(si/no)"<<endl;
        cin>>verificar;
    }while(verificar!="no");
}


  return 0;
}
