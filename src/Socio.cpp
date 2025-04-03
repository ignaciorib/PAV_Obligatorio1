#include <cstdlib>
#include <stdlib.h>

#include "../headers/Mascota.h"
#include "../headers/Socio.h"
#include "../headers/DtFecha.h"



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
    if(topeM > 0){
        return m[0]; 
    }else{
        return NULL;
    }
}

int Socio::getTopeC() {
    return topeC;
}

Consulta Socio::getConsulta() {
    if(topeC > 0){
        return c[0]; 
    }else{
        return Consulta();
    }
    
}

//prueba
void Socio::agregarMascota(Mascota* mascota){
    if(topeM < 10){
        m[topeM++] = mascota;
    }else{
        throw overflow_error("No se pueden agregar mas mascotas."); //////////verificar
    }
}

/*#include "../headers/Socio.h"
#include <iostream>

Socio::Socio(std::string nombre, int id) : nombre(nombre), id(id) {}

void Socio::mostrarInfo() {
    std::cout << "Socio: " << nombre << ", ID: " << id << std::endl;
}
*/
