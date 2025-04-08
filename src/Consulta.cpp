#include <cstdlib>
#include <stdlib.h>

#include "../headers/Consulta.h"

Consulta::Consulta() {}

Consulta::Consulta(string s, int d, int m, int a) {
  descripcion = s;
  fechaConsulta = new DtFecha(d, m, a);
}

DtFecha *Consulta::getFechaConsulta() { //////////////////////
  return fechaConsulta;
}

string Consulta::getMotivo() { return descripcion; }