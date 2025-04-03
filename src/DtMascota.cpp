#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"


DtMascota::DtMascota() {}

DtMascota::DtMascota(string n, Genero g, float p, float rD) {
    nombre = n;
    genero = g;
    peso = p;
    racionDiaria = rD;
}

void DtMascota::setNombre(string DtNombre){
    nombre = DtNombre;
}

void DtMascota::setGenero(int DtGenero){
    if (DtGenero)  
        genero = Genero::Macho;
    else 
        genero = Genero::Hembra;
}

void DtMascota::setPeso(float DtPeso){
    peso = DtPeso;
}
