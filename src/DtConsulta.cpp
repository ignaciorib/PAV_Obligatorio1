#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "../headers/DtConsulta.h"


DtConsulta::DtConsulta() {}

DtConsulta::DtConsulta(DtFecha &dF, string m) {
    fechaConsulta = dF;
    motivo = m;
}

DtFecha* DtConsulta::getFechaDtConsulta(){ //////////////////////
    return fechaConsulta;
}

string DtConsulta::getDtMotivo() {
    return motivo;
}

void DtConsulta::mostrarDtC() {
    cout << "\n\nLa fecha de la consulta: (" << getFechaDtConsulta()->getDia() << "/" << getFechaDtConsulta()->getMes() << "/" << getFechaDtConsulta()->getAnio() << ")"
            "\nEl motivo: "
            "       " << getDtMotivo();
}

