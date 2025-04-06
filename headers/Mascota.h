#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include "../headers/Socio.h"
#include "../headers/Genero.h"
#include "../headers/Consulta.h"

#include "Genero.h"



using namespace std;

class Mascota {
    private:
        string nombreMsc;
        float peso;
        Genero GeneroM;
        bool P_G;
    public:
        Mascota();
        Mascota(string, float, int);
        float getPeso();
        string getNombreMsc();
        int getGenero();
        bool getPerroGato();
        virtual float obtenerRD() = 0;
        /////////~Mascota();
        //virtual ~Mascota
};

#endif 
