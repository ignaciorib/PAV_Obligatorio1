#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/DtMascota.h"


DtMascota::DtMascota() {}

DtMascota::DtMascota(string n, int g, float p, int p_g) {                       //1 es gato, 0 es perro
    nombre = n;
    if (g)  
        genero = Genero::Macho;
    else 
        genero = Genero::Hembra;
    peso = p;
    P_G = p_g;
    DtRD = 0;
}


int DtMascota::getPerroGato() {
    return P_G;
}

int DtMascota::getDtGenero() {
    if (genero == Genero::Macho)
        return 1;
    else
        return 0;
}

float DtMascota::getDtPeso() {
    return peso;
}

string DtMascota::getNombreDtMsc(){
    return nombre;
}

void DtMascota::setRacionDiaria(float racion){
    DtRD = racion;
}

DtMascota::~DtMascota(){
    //destructor vacio, para guiar al compilador en el borrado de la herencia
}
