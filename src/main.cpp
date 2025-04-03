#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdexcept>

#include "../headers/DtConsulta.h"
#include "../headers/Consulta.h"
#include "../headers/DtFecha.h"
#include "../headers/DtGato.h"
#include "../headers/DtMascota.h"
#include "../headers/DtPerro.h"
#include "../headers/Gato.h"
#include "../headers/Genero.h"
#include "../headers/Mascota.h"
#include "../headers/Perro.h"
#include "../headers/RazaPerro.h"
#include "../headers/Socio.h"
#include "../headers/TipoPelo.h"

#define MAX_SOCIOS 20

struct Socios{
    Socio* a[MAX_SOCIOS];
    int tope;
};
Socios s;


using namespace std;

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota);
void agregarMascota(string ci, DtMascota* dtMascota);
void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta);
DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas);
void eliminarSocio(string ci);
DtMascota** obtenerMascotas(string ci, int& cantMascotas);


int main () {
    s.tope = 0;
    
    
    
    cout << "Bienvenido! \n"
            "Elija la opcion: \n"
            "   1) Registrar socio\n"
            "   2) Agregar mascota\n"
            "   3) Ingresar consulta\n"
            "   4) Ver consultas antes de fecha\n"
            "   5) Eliminar socio\n"
            "   6) Obtener mascotas\n"
            "   0) Salir\n"
            "Opcion: ";
    



    DtMascota aux;
    cout << "\nA continuación ingrese los datos de su mascota \n"
            " - Nombre: ";
    string n;
    cin >> n;
    aux.setNombre(n);
    cout << 
            "\nSeleccione el género:  0 si es hembra\n            1 si es macho: "; /////////////////////////////////////////////
    int g;
    cin >> g;
    aux.setGenero(g);
    cout << " - Peso: " ;
    float p;
    cin >> p;
    aux.setPeso(p);
    cout << " kg\n"
            " - Ración Diaria: ";

    
    return 0;
}

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota) {
    
}

void agregarMascota(string ci, DtMascota* dtMascota) {
    
}

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) {
    
}

void eliminarSocio(string ci) {
    
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    
}
