#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Mascota.h"
#include "RazaPerro.h"

using namespace std;

class Perro: public Mascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro();
        Perro(string, float, int genero, int raza, bool);
        int getRazaP();
        bool getVacu();
        float obtenerRD();
        ////////~Perro();
};
