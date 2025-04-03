#include <cstdlib>
#include <stdlib.h>

#include "Socio.h"
#include "DtFecha.h"
#include "../headers/Mascota.h"


Socio::Socio() {}

Socio::Socio(string _nombre, string _CI, int d, int m, int a) {
    nombre = _nombre;
    CI = _CI;
    DtFecha(d, m, a);
}

string Socio::getNombre(){
    return nombre;
}

string Socio::getCI(){
    return CI;
}

void Socio::setNombre(string _nombre) {
    nombre = _nombre;
}

void Socio::setCI(string _CI){
    CI = _CI;
}

int Socio::getTopeM() {
    return topeM;
}

Mascota* Socio::getMascota() {
    return m[0];
}

int Socio::getTopeC() {
    return topeC;
}

Consulta Socio::getConsulta() {
    return c[0];
}


/*#include "../headers/Socio.h"
#include <iostream>

Socio::Socio(std::string nombre, int id) : nombre(nombre), id(id) {}

void Socio::mostrarInfo() {
    std::cout << "Socio: " << nombre << ", ID: " << id << std::endl;
}
*/
