#ifndef DTMASCOTA_H
#define DTMASCOTA_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"
#include "Socio.h"
#include "Mascota.h"
#include "TipoPelo.h"
#include "RazaPerro.h"

using namespace std;

class DtMascota {
    private:
        string nombre;
        Genero genero;
        float peso;
        float racionDiaria;
    public:
        DtMascota();
        DtMascota(string, int, float, float);
        void setNombre(string);
        void setGenero(int);
        void setPeso(float);


};


#endif /* DTMASCOTA_H */
