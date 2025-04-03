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
        genero = Genero::Macho;
    else
        genero = Genero::Hambra;
}

float Mascota::getPeso() {
    return peso;
}

string Mascota::getNombreMsc(){
    return nombreMsc;
}

string Mascota::getGenero() {
    return genero;
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
