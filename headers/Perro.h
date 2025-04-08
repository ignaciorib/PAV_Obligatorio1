#ifndef PERRO_H
#define PERRO_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"
#include "Mascota.h"
#include "RazaPerro.h"

using namespace std;


class Perro: public Mascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro();
        Perro(string, float, int genero, int, int raza, bool);
        int getRaza();
        bool getVacu();
        virtual float obtenerRD();
        ////////~Perro();
};

#endif /* PERRO_H */

