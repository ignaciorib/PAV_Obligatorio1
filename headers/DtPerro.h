#ifndef DTPERRO_H
#define DTPERRO_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "RazaPerro.h"
#include "DtMascota.h"

using namespace std;

class DtPerro : public DtMascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        DtPerro();
        DtPerro(string, int g, float, int p_g, int r, bool);
        int getRaza();
        int getVC();
};

#endif /* DTPERRO_H */

