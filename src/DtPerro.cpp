#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/DtPerro.h"


DtPerro::DtPerro() {}

DtPerro::DtPerro(string n, int g, float p, int p_g, int r, bool vC) : DtMascota(n, g, p, p_g) {
    switch (r) {
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
    vacunaCachorro = vC;
}

int DtPerro::getRaza() {
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
    }
}

int DtPerro::getVC() {
    return vacunaCachorro;
}

void DtPerro::setVc(int x){
    if (x == 0)
        vacunaCachorro == true;
    else
        vacunaCachorro == false; 
}

void DtPerro::setRaza(int x){
    switch (x) {
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
        default: 
    }
}

float DtPerro::obtenerRD() {
    return getDtPeso() * 0,025;
}

void DtPerro::mostrarInfDtPerro() {
    cout << "\nNombre: " << getNombreDtMsc() <<
            "\nTipo: Perro"
            "\nGenero: " << getDtGenero() <<
            "\nPeso: " << getDtPeso() <<
            " kg\nRacion diaria: " << obtenerDtRD();
    if (getVC())
        cout << "\nTiene la vacuna de cachorro";
    else
        cout << "\nNo tiene la vacuna de cachorro";
}

float DtPerro::obtenerDtRD() {
    return getDtPeso() * 0,025;
}
