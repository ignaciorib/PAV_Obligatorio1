#include <cstdlib>
#include <stdlib.h>
#include <iostream>

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

int Socio::getTopeM() {
    return topeM;
}

int Socio::getTopeC() {
    return topeC;
}

void Socio::setArrM(Socio* s[], int i, Mascota* auxM) {
    s[i]->m[s[i]->topeM] = auxM;
    s[i]->topeM++;
}

void Socio::setArrC(Socio* s[], int i, Consulta* auxC) {
    s[i]->c[s[i]->topeC] = auxC;
    s[i]->topeC++;
}

void Socio::delS(Socio* s[], int i) {
    for (int j = 0; j < s[i]->topeM; j++)
        delete s[i]->m[j];
    for (int k = 0; k < s[i]->topeC; k++)
        delete s[i]->c[k];
    delete s[i]->fechaIng;
    delete s[i];
}

DtConsulta** Socio::obtenerArrC(Socio* s[], int posSocio, DtFecha* f, int &cont) {
    for (int iter = 0; iter < s[posSocio]->topeC; iter++) {
        if (comp(s[posSocio]->c[iter]->getFechaConsulta(), f)) {
            cont++;
        }
    }
    if (cont > 0) {
        DtConsulta** result = new DtConsulta*[cont];
        for (int iter = 0; iter < s[posSocio]->topeC; iter++) {
            if (comp(s[posSocio]->c[iter]->getFechaConsulta(), f)) {
                result[iter] = new DtConsulta(s[posSocio]->c[iter]->getFechaConsulta(), s[posSocio]->c[iter]->getMotivo());
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
                Gato* catC = dynamic_cast<Gato*>(s[posSocio]->m[iter]);
                DtGato* auxGato = new DtGato(catC->getNombreMsc(), catC->getGenero(), catC->getPeso(), catC->getPerroGato(), catC->getTipoPelo());
                result[iter] = auxGato;
                auxGato->mostrarInfDtGato();
            }
            else {
                Perro* dogC = dynamic_cast<Perro*>(s[posSocio]->m[iter]);
                DtPerro* auxPerro = new DtPerro(dogC->getNombreMsc(), dogC->getGenero(), dogC->getPeso(), dogC->getPerroGato(), dogC->getRaza(), dogC->getVacu());
                result[iter] = auxPerro;
                auxPerro->mostrarInfDtPerro();
            }
        }
        return result;
    }
    else
        return NULL;
}

bool Socio::comp(DtFecha* f1, DtFecha* f2) {
    if (f1->getAnio() < f2->getAnio())
        return true;
    else if (f1->getAnio() > f2->getAnio())
        return false;
    else if (f1->getMes() < f2->getMes())
        return true;
    else if (f1->getMes() > f2->getMes())
        return false;
    return f1->getDia() < f2->getDia();
}


