#ifndef DTMASCOTA_H
#define DTMASCOTA_H

#include <iostream>
#include <string.h>
#include <stdbool.h>

#include "Genero.h"

using namespace std;


class DtMascota {
    private:
        string nombre;
        Genero genero;
        float peso;
        float DtRD;
        int P_G;            //1 es gato, 0 es perro
    public:
        DtMascota();
        DtMascota(string, int g, float, int p_g);
        void setRacionDiaria(float racionDiaria);
        int getPerroGato();
        int getDtGenero();
        float getDtPeso();
        string getNombreDtMsc();
        virtual float obtenerDtRD() = 0;
        

};


#endif /* DTMASCOTA_H */