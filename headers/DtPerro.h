#ifndef DTPERRO_H
#define DTPERRO_H

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

class DtPerro : public DtMascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        DtPerro();
        DtPerro(int, bool);
};

#endif /* DTPERRO_H */

