#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <string.h>

#include "Genero.h"
#include "DtMascota.h"
#include "RazaPerro.h"
#include "DtPerro.h"
#include "DtGato.h"
#include "DtConsulta.h"
#include "DtFecha.h"

DtConsulta::DtConsulta() {}

DtConsulta::DtConsulta(DtFecha &dF, string m) {
    fechaConsulta = dF;
    motivo = m;
}
