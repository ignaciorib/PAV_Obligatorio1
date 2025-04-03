#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>
#include <string.h>

#include "Genero.h"
#include "Socio.h"

using namespace std;

class Mascota: public Socio {
    private:
        string nombreMsc;
        float peso;
        Genero GeneroM;
    public:
        Mascota();
        Mascota(string, float, Genero);
        float getPeso();
        string getNombreMsc();
        virtual float obtenerRD() = 0;
        /////////~Mascota();
};

/*
#include <string>

class Mascota {
private:
    std::string nombre;
    int edad;

public:
    Mascota(std::string nombre, int edad);
    void mostrarInfo();
};
*/
#endif
