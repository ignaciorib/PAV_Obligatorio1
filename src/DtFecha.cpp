#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/Genero.h"
#include "../headers/DtMascota.h"
#include "../headers/RazaPerro.h"
#include "../headers/DtPerro.h"
#include "../headers/DtGato.h"
#include "../headers/DtConsulta.h"
#include "../headers/DtFecha.h"

DtFecha::DtFecha() {}

DtFecha::DtFecha(int d, int m, int a){
    anio = a;
    mes = m;
    dia = d;
}

DtFecha::DtFecha(DtFecha &dF) {
    anio = dF.anio;
    mes = dF.mes;
    dia = dF.dia;
}

int DtFecha::getAnio() {
    return anio;
}

int DtFecha::getMes() {
    return mes;
}

int DtFecha::getDia() {
    return dia;
}

////////DtFecha DtFecha::
