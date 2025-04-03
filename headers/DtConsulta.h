#ifndef DTCONSULTA_H
#define DTCONSULTA_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"
#include "Socio.h"
#include "Mascota.h"
#include "TipoPelo.h"
#include "RazaPerro.h"
#include "DtMascota.h"
#include "DtFecha.h"

using namespace std;

class DtConsulta {
    private:
        DtFecha fechaConsulta;
        string motivo;
    public:
        DtConsulta();
        DtConsulta(DtFecha &, string);
};

#endif /* DTCONSULTA_H */
