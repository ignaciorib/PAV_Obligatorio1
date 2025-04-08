#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string.h>

#include "Genero.h"

using namespace std;


class Mascota {
    private:
        string nombreMsc;
        float peso;
        Genero GeneroM;
        int P_G;
        float rD;
    public:
        Mascota();
        Mascota(string, float, int g, int p_g);
        float getPeso();
        string getNombreMsc();
        int getGenero();
        bool getPerroGato();
        void setRD(float);
        virtual float obtenerRD() = 0;
        
        virtual ~Mascota(); //destructor virtual, correjir warning en delS. Socio.cpp
};



#endif /* MASCOTA_H */

