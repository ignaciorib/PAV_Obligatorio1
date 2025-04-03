#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string>
#include "../headers/Socio.h"
#include "../headers/Genero.h"
#include "../headers/Consulta.h"

#include "Socio.h"
#include "Genero.h"



using namespace std;

class Mascota : public Socio{
    private:
        string nombreMsc;
        float peso;
        int GeneroM;
    public:
        Mascota();
        Mascota(string, float, Genero);
        float getPeso();
        string getNombreMsc();
        virtual float obtenerRD() = 0;
        /////////~Mascota();
};

#endif 
