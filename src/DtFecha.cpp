#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>


#include "../headers/DtFecha.h"

DtFecha::DtFecha() {}

DtFecha::DtFecha(int d, int m, int a) {
  anio = a;
  mes = m;
  dia = d;
}

DtFecha::DtFecha(DtFecha &dF) {
  anio = dF.anio;
  mes = dF.mes;
  dia = dF.dia;
}

int DtFecha::getAnio() { return anio; }

int DtFecha::getMes() { return mes; }

int DtFecha::getDia() { return dia; }