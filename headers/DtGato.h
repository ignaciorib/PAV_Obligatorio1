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
        tipoPelo pelo;
    public:
        DtGato();
        DtGato(string, int g, float, int p_g, int pelo);
        int getTipoPelo();
        void setTipoPelo(int);
};

#endif /* DTGATO_H */

