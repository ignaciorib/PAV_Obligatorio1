#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"


DtMascota::DtMascota() {}

DtMascota::DtMascota(string n, int g, float p, float rD) {
    nombre = n;
    if g
        genero = Genero::Macho;
    else
        genero = Genero::Hambra;
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
