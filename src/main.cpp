#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>

#include "DtConsulta.h"
#include "Consulta.h"
#include "DtFecha.h"
#include "DtGato.h"
#include "DtMascota.h"
#include "DtPerro.h"
#include "Gato.h"
#include "Genero.h"
#include "Mascota.h"
#include "Perro.h"
#include "RazaPerro.h"
#include "Socio.h"
#include "TipoPelo.h"

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