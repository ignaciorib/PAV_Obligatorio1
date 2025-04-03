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

DtConsulta::DtConsulta() {}

DtConsulta::DtConsulta(DtFecha dF, string m) {
    fechaConsulta = dF;
    motivo = m;
}
