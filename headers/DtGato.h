#ifndef DTGATO_H
#define DTGATO_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "DtMascota.h"
#include "TipoPelo.h"


using namespace std;

class DtGato : public DtMascota {
    private:
        TipoPelo pelo;
    public:
        DtGato();
        DtGato(string, int g, float, int p_g, int pelo);
        int getTipoPelo();
};

#endif /* DTGATO_H */

