#ifndef DTGATO_H
#define DTGATO_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"
#include "Socio.h"
#include "Mascota.h"
#include "TipoPelo.h"
#include "RazaPerro.h"
#include "DtMascota.h"

using namespace std;

class DtGato : public DtMascota {
    private:
        TipoPelo pelo;
    public:
        DtGato();
        DtGato(int);
};

#endif /* DTGATO_H */

