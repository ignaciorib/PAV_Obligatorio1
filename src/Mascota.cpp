#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "Mascota.h"
#include "Genero.h"


Mascota::Mascota() {}

Mascota::Mascota(string n, float p, Genero g) {
    nombreMsc = n;
    peso = p;
    GeneroM = g;
}

float Mascota::getPeso() {
    return peso;
}

string Mascota::getNombreMsc(){
    return nombreMsc;
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
