#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <string.h>


#include "../headers/DtConsulta.h"

DtConsulta::DtConsulta() {}

DtConsulta::DtConsulta(DtFecha *dF, string m) {
  fechaConsulta = new DtFecha(dF->getDia(), dF->getMes(), dF->getAnio());
  motivo = m;
}

DtFecha *DtConsulta::getFechaDtConsulta() { return fechaConsulta; }

string DtConsulta::getDtMotivo() { return motivo; }

void DtConsulta::mostrarDtC() {
  cout << "\n\nLa fecha de la consulta: (" << getFechaDtConsulta()->getDia()
       << "/" << getFechaDtConsulta()->getMes() << "/"
       << getFechaDtConsulta()->getAnio()
       << ")"
          "\nEl motivo: "
          "       "
       << getDtMotivo() << "\n";
}
