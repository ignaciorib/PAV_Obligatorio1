#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Mascota.h"
#include "../headers/Genero.h"


Mascota::Mascota() {}

Mascota::Mascota(string n, float p, int g) {
    nombreMsc = n;
    peso = p;
    if g
        GeneroM = Genero::Macho;
    else
        GeneroM = Genero::Hembra;
}

float Mascota::getPeso() {
    return peso;
}

string Mascota::getNombreMsc(){
    return nombreMsc;
}

int Mascota::getGenero() {
    if (GeneroM == Genero::Macho)
        return 1;
    else
        return 0;
}


//virtual float obtenerRD()

/*
#include "../headers/Mascota.h"
#include <iostream>

Mascota::Mascota(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

void Mascota::mostrarInfo() {
    std::cout << "Mascota: " << nombre << ", Edad: " << edad << " años." << std::endl;
}
*/
