#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "Genero.h"
#include "DtMascota.h"


DtMascota::DtMascota() {}

DtMascota::DtMascota(string n, int g, float p, int p_g) {                       //1 es gato, 0 es perro
    nombre = n;
    if (g)  
        genero = Genero::Macho;
    else 
        genero = Genero::Hembra;
    peso = p;
    P_G = p_g;
    if (p_g)
        racionDiaria = p * 0,015;
    else
        racionDiaria = p * 0,025;
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

void DtMascota::setPerroGato(int tipoMascot){
    P_G = tipoMascot;
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

void DtMascota::setRacionDiaria(float racionDiaria){
    racionDiaria = racionDiaria;
}
