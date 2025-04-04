#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"
#include "Socio.h"
#include "Mascota.h"
#include "TipoPelo.h"
#include "RazaPerro.h"

using namespace std;

class Perro: public Mascota {
    private:
        RazaPerro raza;
        bool vacunaCachorro;
    public:
        Perro();
        Perro(RazaPerro, bool);
        RazaPerro getRazaP();
        bool getVacu();
        float obtenerRD();
        ////////~Perro();
};
