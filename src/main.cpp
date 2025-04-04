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
    int opcion;
    cin >> opcion;
    switch(opcion){
        case 1:
            string ci, nombre;
            int dia, mes, anio;
            string ci, nombre, nombreMascota, tipoMascota;
            int edadMascota;

            cout << "Ingrese CI del socio: ";
            cin >> ci;
            cout << "Ingrese Nombre del socio: ";
            cin.ignore();  // Para evitar problemas con getline
            getline(std::cin, nombre);

            cout << "Ingrese Nombre de la mascota: ";
            getline(cin, nombreMascota);
            cout << "Ingrese Edad de la mascota: ";
            cin >> edadMascota;
            cout << "Ingrese Tipo de mascota (Perro, Gato, etc.): ";
            cin.ignore();
            getline(cin, tipoMascota);

            // Crear el objeto DtMascota con los datos ingresados
            DtMascota dtMascota(nombreMascota, edadMascota, tipoMascota);

            // Registrar al socio con su mascota (sin devolver un puntero)
            registrarSocio(ci, nombre, dtMascota);
            break;

            //void registrarSocio(string ci, string nombre, DtMascota& dtMascota);
        case 0:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opción inválida. Intente nuevamente.\n";
            break;
    }




    cout << "\nA continuación ingrese los datos de su mascota \n"
            " - Nombre: ";
    string n;
    cin >> n;
    cout << 
            "\nSeleccione el género:    0 si es hembra\n"
            "                           1 si es macho: ";
    int g;
    cin >> g;
    cout << "\n - Peso: " ;
    float p;
    cin >> p;
    cout << " kg";
    cout <<        
            "\n - Ración Diaria: ";
    float rD;
    cin >> rD;
    
    cout << " gramos.\n"
            "\nSeleccione el tipo:      0 si es Perro\n"
            "                           1 si es Gato: ";
    int tipoMascot;
    cin >> tipoMascot;                                          //Nos dice el usuario si es perro o gatovich
    if (tipoMascot) {
        cout << 
            "    - Ingrese el tipo de pelo: \n"
            "       1) Corto\n"
            "       2) Mediano\n"
            "       3) Largo\n";
        int auxTPelo;
        cin >> auxTPelo;
        DtGato auxGato = new DtGato(auxTPelo);/////////////////////////////////////
    }
    else {
        " - Tiene vacuna del Cachorro: Si / No\n";///////////////////////////////cambiar
        string vC;
        bool auxBoolVC;
        cin >> vC;
        if (vC == "Si")
            auxBoolVC = true;
        else
            auxBoolVC = false;
        cout << "\n  - Ingrese la Raza:"
                "       1) Labrador\n"
                "       2) Ovejero\n"
                "       3) Bulldog\n"
                "       4) Pitbull\n"
                "       5) Collie\n"
                "       6) Pekines\n"
                "       7) Otro\n";
        int auxRaza;
        cin >> auxRaza;
        DtPerro auxPerro = new DtPerro(auxRaza, auxBoolVC);/////////////////////////
    }
    
    ///////////////////////////como implementar la polimorfica       
    DtMascota auxDtMascota = new DtMascota(n, g, p, rD);/////////////////////////////////////////////////////////en funciones???
    auxDtMascota->setPerroGato(tipoMascot);
    
    
    
        
    
    
    return 0;
}

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota) {
    if (s.tope = MAX_SOCIOS)
        cout << "no hay espacio para mas socios";
    else {
        int i = s.tope;
        Socio* aux = new Socio(nombre, ci, fechaIngreso->getDia(), fechaIngreso->getMes(), fechaIngreso->getAnio());
        s.socios[i] = aux;
        s.tope++;
        if (dtMascota->getPerroGato()){
            Mascota* aux = new Gato(dtMascota->getNombreDtMsc(), dtMascota->getDtGenero(), dtMascota->getDtPeso(), dtMascota->getPerroGato());
        }
        else
            Mascota* aux = new Perro(dtMascota->getNombreDtMsc(), dtMascota->getDtGenero(), dtMascota->getDtPeso(), dtMascota->getPerroGato());
        Socio->setArrM(aux);
}

void agregarMascota(string ci, DtMascota* dtMascota) {
    Mascota* aux;
    int i = 0;
    while (s.socios[i] <= s.tope && s.socios[i]->getCI() != ci)
        i++;
    int j = s.socios[i]->getTopeM();
    if (j <= 9) {
        if (dtMascota->getPerroGato())
            aux = new Gato(dtMascota->getNombreDtMsc(), dtMascota->getDtGenero(), dtMascota->getDtPeso(), dtMascota->getPerroGato());
        else
            aux = new Perro(dtMascota->getNombreDtMsc(), dtMascota->getDtGenero(), dtMascota->getDtPeso(), dtMascota->getPerroGato());
        Socio->setArrM(aux);
    }
    else
        cout << "Este socio no puede tener mas mascotas asociadas";
}

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) {
    
}

void eliminarSocio(string ci) {
    
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    
}
