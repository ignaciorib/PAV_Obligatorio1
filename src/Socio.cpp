#include <cstdlib>
#include <stdlib.h>

#include "../headers/Socio.h"



Socio::Socio() {}

Socio::Socio(string _nombre, string _CI, int d, int m, int a) {
    nombre = _nombre;
    CI = _CI;
    fechaIng = new DtFecha(d, m, a);
    topeM = 0;
    topeC = 0;
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

Mascota* Socio::getMascota(Mascota* s[], string nam) { //Devuelva una macota especifica
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

DtConsulta** Socio::obtenerArrC(Socio* s[], int posSocio, DtFecha* f, int &cont) {
    for (int iter = 0; iter < s[posSocio]->topeC; iter++) {
        cout << "\ngood1.3";
        if (comp(s[posSocio]->c[iter]->getFechaConsulta(), f)) {
            cont++;
            cout << "\ngood1.1";
        }
    }
    if (cont > 0) {
        DtConsulta** result = new DtConsulta*[cont];
        for (int iter = 0; iter < s[posSocio]->topeC; iter++) {
            if (comp(s[posSocio]->c[iter]->getFechaConsulta(), f)) {
                result[iter] = new DtConsulta(s[posSocio]->c[iter]->getFechaConsulta(), s[posSocio]->c[iter]->getMotivo());
                cout << "\ngood1.2";
            }
        }
        return result;
    }
    else
        return NULL;
}

DtMascota** Socio::obtenerArrM(Socio* s[], int posSocio, int &cont) {
    cont = s[posSocio]->topeM;
    if (cont > 0) {
        DtMascota** result = new DtMascota*[cont];
        for (int iter = 0; iter < cont; iter++) {
            if (s[posSocio]->m[iter]->getPerroGato()){
                Gato* gato = dynamic_cast<Gato*>(s[posSocio]->m[iter]);
                result[iter] = new DtGato(gato->getNombreMsc(), gato->getPeso(), gato->getGenero(), gato->getPerroGato(), gato->getTipoPelo());

            }
            else {
                Perro* perro = dynamic_cast<Perro*>(s[posSocio]->m[iter]);
                result[iter] = new DtPerro(perro->getNombreMsc(), perro->getPeso(), perro->getGenero(), perro->getPerroGato(), perro->getRaza(), perro->getVacu());
            }
        }
        return result;
    }
    else
        return NULL;
}

DtFecha* Socio::getDtFecha() {
    return fechaIng;
}

bool Socio::comp(DtFecha* f1, DtFecha* f2) { ///////////////////////////////
    if (f1 == nullptr || f2 == nullptr)
        return false;  // O lanzar excepción si preferís

    if (f1->getAnio() < f2->getAnio())
        return true;
    else if (f1->getAnio() > f2->getAnio())
        return false;

    // Si los años son iguales, comparar meses
    if (f1->getMes() < f2->getMes())
        return true;
    else if (f1->getMes() > f2->getMes())
        return false;

    // Si los meses también son iguales, comparar días
    return f1->getDia() < f2->getDia();
    /*
    if (f1->getAnio() > f2->getAnio())
        return true;
    else if (f1->getAnio() < f2->getAnio())
        return false;
    else if (f1->getMes() > f2->getMes())
        return true;
    else if (f1->getMes() < f2->getMes())
        return false;
    else if (f1->getDia() > f2->getDia())
        return true;
    else if (f1->getDia() < f2->getDia())
        return false;
    else
        return false;*/
}
