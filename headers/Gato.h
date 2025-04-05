#ifndef GATO_H
#define GATO_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Mascota.h"
#include "TipoPelo.h"

using namespace std;

class Gato: public Mascota {
    private:
        TipoPelo TipoPeloG;
    public:
        Gato();
        Gato(string, float, int genero, TipoPelo);
        float obtenerRD();
        /////////~Gato();
};

#endif /* GATO_H */
