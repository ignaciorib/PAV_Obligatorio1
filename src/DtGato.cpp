#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/DtGato.h"

DtGato::DtGato() {}

DtGato::DtGato(string n, int g, float p, int p_g, int tP) : DtMascota(n, g, p, p_g) {
    switch (tP) {
        case 1:
            pelo = tipoPelo::Corto;
            break;
        case 2:
            pelo = tipoPelo::Mediano;
            break;
        case 3:
            pelo = tipoPelo::Largo;
            break;
    }
    setRacionDiaria(p * 0.015);
}

int DtGato::getTipoPelo () {
    switch (pelo) {
        case tipoPelo::Corto:
            return 1;
            break;
        case tipoPelo::Mediano:
            return 2;
            break;
        case tipoPelo::Largo:
            return 3;
            break;
        default:
            return 0;
            break;
    }
}

float DtGato::obtenerDtRD() {
    return getDtPeso() * 0.015;
}

void DtGato::mostrarInfDtGato() {
    cout << "\nNombre: " << getNombreDtMsc() <<
            "\nTipo: Gato"
            "\nGenero: " << getDtGenero() <<
            "\nPeso: " << getDtPeso() <<
            " kg\nRacion diaria: " << obtenerDtRD() <<
            " g\nTipo de pelo: ";
    switch (getTipoPelo()) {
        case 1:
            cout << "Corto\n";
            break;
        case 2:
            cout << "Mediano\n";
            break;
        case 3:
            cout << "Largo\n";
            break;
        default:
            break;
    }
}


DtGato::~DtGato() {
    
}
