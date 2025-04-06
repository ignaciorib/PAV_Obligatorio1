#include <cstdlib>
#include <stdlib.h>

#include "../headers/Mascota.h"
#include "../headers/Socio.h"
#include "../headers/DtFecha.h"



Socio::Socio() {}

Socio::Socio(string _nombre, string _CI, int d, int m, int a) {
    nombre = _nombre;
    CI = _CI;
    fechaIng = DtFecha(d, m, a);
}

string Socio::getNombre(){
    return nombre;
}

string Socio::getCI(){
    return CI;
}

void Socio::setNombre(string _nombre) {
    nombre = _nombre;
}

void Socio::setCI(string _CI){
    CI = _CI;
}

int Socio::getTopeM() {
    return topeM;
}

Mascota* Socio::getMascota(Socio s, string nam) { //Devuelva una macota especifica
    int i = 0;
    while (m[i].getNombre() != nam) {
        i++;
    }
    if(i > s.getTopeM()){
        return NULL; 
    }else{
        return m[i];
    }
}

Mascota* Socio::getMascotas(Socio s) { //Devuelve todas las macotas//////////////////////////////profe
    if (s.getTopeM() > 0)
        return m[0];
    else 
        return NULL;
}

int Socio::getTopeC() {
    return topeC;
}

Consulta* Socio::getConsulta() {
    if(topeC > 0){
        return c[0]; 
    }else{
        return Consulta();
    }
    
}

void Socio::setTopeM() {
    topeM++;
}

void Socio::setArrM(Socio* s[], int i, Mascota* auxM) {
    s[i].m[s[i].topeM] = auxM;
    s[i].topeM++;
}

void Socio::setArrC(Socio* s[], int i, Consulta* auxC) {
    s[i].c[s[i].topeC] = auxC;
    s[i].topeC++;
}

void Socio::delM(Socio* s[], int i, int j) {
    delete s[i]->m[j];
}

void Socio::delC(Socio* s[], int i, int k) {
    delete s[i]->m[k];
}

void Socio::delS(Socio* s[], int i) {
    delete s[i];
}

DtConsulta* Socio::obtenerArrC(Socio* s[], int posSocio, DtFecha f, int &cont) {
    for (int iter = 0; iter <= s[posSocio]->topeC; iter++) {
        Consulta* auxDescartable = new Consulta(*s[posSocio]->c[iter]);
        if (DtFecha::comp(auxDescartable->getFechaConsulta(), f)) {
            cont++;
        }
        delete auxDescartable;
    }
    if (cont > 0) {
        DtConsulta* dtc[cont];
        for (int iter = 0; iter <= cont; iter++) {
            Consulta* auxDescartable = new Consulta(*s[posSocio]->c[iter]);
            if (DtFecha::comp(auxDescartable->getFechaConsulta(), f)) {
                DtConsulta auxPosta = new DtConsulta(auxDescartable->getMotivo(), auxDescartable->getFechaConsulta());
                dtc[iter] = auxPosta;
            }
            delete auxDescartable;
        }
        return dtc;
    }
    else
        return NULL;
}

DtMascota* Socio::obtenerArrM(Socio* s[], int posSocio, int &cont) {
    for (int iter = 0; iter <= s[posSocio]->topeM; iter++) {
        cont++;
    }
    if (cont > 0) {
        DtMascota* dtm[cont];
        for (int iter = 0; iter <= cont; iter++) {
            if (s[posSocio].m[iter]->getPerroGato()){
                Gato* gato = dynamic_cast<Gato>(s[posSocio].m[iter]);
                DtGato* cat;
                cat = new DtGato(gato->getNombreMsc(), gato->getPeso(), gato->getGenero(), gato->getTipoPelo());
                dtm[iter] = cat;
            }
            else {
                Perro* perro = dynamic_cast<Perro>(s[posSocio].m[iter]);
                DtPerro* dog;
                dog = new DtPerro(perro->getNombreMsc(), perro->getPeso(), perro->getGenero(), perro->getRaza(), perro->getVacu());///////////////////////
                dtm[iter] = dog;
            }
        }
        return dtm;
    }
    else
        return NULL;
}

/*
//prueba
void Socio::agregarMascota(Mascota* mascota){
    if(topeM < 10){
        m[topeM++] = mascota;
    }else{
        throw overflow_error("No se pueden agregar mas mascotas."); //////////verificar
    }
}

#include "../headers/Socio.h"
#include <iostream>

Socio::Socio(std::string nombre, int id) : nombre(nombre), id(id) {}

void Socio::mostrarInfo() {
    std::cout << "Socio: " << nombre << ", ID: " << id << std::endl;
}
*/
