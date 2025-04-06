#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Consulta.h"

Consulta::Consulta() {}

Consulta::Consulta(string s, int d, int m, int a) {
    descripcion = s;
    DtFecha* fechaConsulta = new DtFecha(d, m, a);
}

Consulta::Consulta(Consulta &c) {
    descripcion = c.descripcion;
    fechaConsulta = c.fechaConsulta;
}

DtFecha* Consulta::getFechaConsulta(){ //////////////////////
    return fechaConsulta;
}

string Consulta::getMotivo() {
    return descripcion;
}
