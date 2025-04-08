#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Perro.h"


Perro::Perro() {}

Perro::Perro(string n, float p, int genero, int p_g, int razaRef, bool v) : Mascota(n, p, genero, p_g) {
    switch (razaRef) {
        case 1:
            raza = RazaPerro::labrador;
            break;
        case 2:
            raza = RazaPerro::ovejero;
            break;
        case 3:
            raza = RazaPerro::bulldog;
            break;
        case 4:
            raza = RazaPerro::pitbull;
            break;
        case 5:
            raza = RazaPerro::collie;
            break;
        case 6:
            raza = RazaPerro::pekines;
            break;
        case 7:
            raza = RazaPerro::otro;
            break;
    }
    vacunaCachorro = v;
    setRD(p * 0.025);
}

float Perro::obtenerRD() {
    return getPeso() * 0.025;
}

int Perro::getRaza() {
    switch (raza) {
        case RazaPerro::labrador:
            return 1;
            break;
        case RazaPerro::ovejero:
            return 2;
            break;
        case RazaPerro::bulldog:
            return 3;
            break;
        case RazaPerro::pitbull:
            return 4;
            break;
        case RazaPerro::collie:
            return 5;
            break;
        case RazaPerro::pekines:
            return 6;
            break;
        case RazaPerro::otro:
            return 7;
            break;
        default:
            return 0;
            break;
    }
}

bool Perro::getVacu() {
    return vacunaCachorro;
}
