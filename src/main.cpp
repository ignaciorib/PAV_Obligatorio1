
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
    string ci, nombre, nombreMascota;
    int edadMascota, generoMascota, tipoMascota, tipoPelo, vacunas, raza, dia, mes, anio;
    float pesoMascota;
    DtFecha* dtF;
    DtMascota* dtM;
    DtGato* dtG;
    DtPerro* dtP;
    switch (opcion){
        case 1:
            cout << "\nPara comenzar primero indique la fecha del día de hoy, comenzando por el día: (--/xx/xxxx) ";
            cin >> dia;
            cout << "\nA continuación indique el mes: (xx/--/xxxx) ";
            cin >> mes;
            cout << "\nPara finalizar indique el año: (xx/xx/----)";
            cin >> anio;
            dtF->setDia(dia);
            dtF->setMes(mes);
            dtF->setAnio(anio);
            cout << "Ingrese CI del socio: ";
            cin >> ci;
            cout << "Ingrese Nombre del socio: ";
            cin >> nombre;
            cout << "\nA continuación ingrese los datos de su mascota \n";
            cout << "Nombre: ";
            cin >> nombreMascota;
            dtM-> setNombre(nombreMascota);
            cout << "\nIndique el número que corresponda al sexo de su mascota: \n-0 si es hembra.\n-1 si es macho.";
            cin >> generoMascota;
            dtM->setGenero(generoMascota);
            cout << "\nPeso: ";
            cin >> pesoMascota;
            dtM->setPeso(pesoMascota);
            dtM->setRacionDiaria(0); //Seteamos la racion diaria en 0
            cout << "\nIndique el número que corresponda al tipo de su mascota: \n-0 si es perro.\n-1 si es gato. ";
            cin >> tipoMascota;
            if (tipoMascota) {
                dtG = dynamic_cast<DtGato*>(dtM); //gepeto me recomendó usar un *, sin el puntero me sale error
                cout << "\n-Ingrese el tipo de pelo:\n-1 Corto\n-2 Mediano\n-3 Largo\n";
                cin >> tipoPelo;
                dtG->setTipoPelo(tipoPelo);
                registrarSocio(ci, nombre, dtF, dtG);
            } else {
                dtP = dynamic_cast<DtPerro*>(dtM);
                cout << "\n-¿El cachorro tiene vacunas?\n-0 Sí.\n-1 No.";
                cin >> vacunas;
                if (vacunas == 0)
                    dtP->setVc(0);
                else
                    dtP->setVc(1);
                cout << "\nSeleccione la raza:\n1- Labrador\n2- Ovejero\n3- Bulldog\n4- Pitbull\n5- Collie\n6- Pekines\n7- Otro";
                cin >> raza;
                dtP->setRaza(raza);
                registrarSocio(ci, nombre, dtF, dtP);
            }
            break;
        case 2:
            //Vale me ha dado sueño me quedan pendientes los otros menus, igual siento que el de agregar socio era le más largo, los otros easy peasyy
        default:
            cout << "Opción inválida. Intente nuevamente.\n";
            break;
    }
        
    
    
    return 0;
}

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota) {
    if (s.tope = MAX_SOCIOS)
        cout << "no hay espacio para mas socios";
    else {
        int posSocio = s.tope;
        Socio* auxS = new Socio(nombre, ci, fechaIngreso->getDia(), fechaIngreso->getMes(), fechaIngreso->getAnio());
        s.socios[posSocio] = auxS;
        s.tope++;
        if (dtMascota->getPerroGato()){
            //DtGato* Dtgato = dynamic_cast<DtGato*>(dtMascota); Lo comento acá, creo que va en el main en el momento que el usuario elige el tipo de animal
        if (dtMascota->getPerroGato()){  ///////////////////hacer una funcion?????????????????
            DtGato* dtgato = dynamic_cast<DtGato>(dtMascota);
            Gato* cat;
            cat = new Gato(dtgato->getNombreDtMsc(), dtgato->getDtPeso(), dtgato->getDtGenero(), dtgato->getTipoPelo());///////////////////////
            
            s.socios[posSocio]->setArrM(s.socios, posSocio, cat);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
        else {
            DtPerro* perro = dynamic_cast<DtPerro>(dtMascota);
            Perro* dog;
            dog = new Perro(perro->getNombreDtMsc(), perro->getDtPeso(), perro->getDtGenero(), perro->getRaza(), perro->getVC());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, dog);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
    }
}}

void agregarMascota(string ci, DtMascota* dtMascota) {////////////////////////////////////////////////////////////////////////////LEGAL??????????
    int posSocio = 0;
    while (posSocio <= s.tope <= s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    int j = s.socios[posSocio]->getTopeM();
    if (j <= 9) {
        if (dtMascota->getPerroGato()){
            DtGato* gato = dynamic_cast<DtGato>(dtMascota);
            Gato* cat;
            cat = new Gato(gato->getNombreDtMsc(), gato->getDtPeso(), gato->getDtGenero(), gato->getTipoPelo());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, cat);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
        else {
            DtPerro* perro = dynamic_cast<DtPerro>(dtMascota);
            Perro* dog;
            dog = new Perro(perro->getNombreDtMsc(), perro->getDtPeso(), perro->getDtGenero(), perro->getRaza(), perro->getVC());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, dog);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
    }
    else
        //cout << "Este socio no puede tener mas mascotas asociadas";
        throw overflow_error ("Este socio no puede tener mas mascotas asociadas"); 
}

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    int posSocio = 0;
    while (posSocio <= s.tope <= s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    int j = s.socios[posSocio]->getTopeC();
    if (j <= 20) {
        Consulta* auxC = new Consulta(motivo, fechaConsulta->getDia(), fechaConsulta->getMes(), fechaConsulta->getAnio());
        s.socios[posSocio]->setArrC(s.socios, posSocio, auxC);
    }
    else
        throw overflow_error ("Este socio no puede tener mas consultas asociadas"); 
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) { 
    int posSocio = 0;
    while (posSocio <= s.tope && s.socios[posSocio]->getCI() != ciSocio)
        posSocio++;
    DtConsulta* aux = s.socios[posSocio]->obtenerArrC(s.socios, posSocio, fecha, cantConsultas); //chusmear
    DtConsulta** result = &aux;
    return result;
}

void eliminarSocio(string ci) {
    int posSocio = 0;
    while (posSocio <= s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    for (int j = 0; j <= s.socios[posSocio]->getTopeM(); j++) ///////////////////////poner en una function
        s.socios[posSocio]->delM(s.socios, posSocio, j);
    for (int k = 0; k <= s.socios[posSocio]->getTopeC(); k++)
        s.socios[posSocio]->delC(s.socios, posSocio, k);
    s.socios[posSocio]->delS(s.socios, posSocio);
    if (posSocio < s.tope) {
        for (int r = posSocio + 1; r - s.tope + 1 != 0; r++)
            s.socios[r] = s.socios[r - 1];
        s.tope--;
    }
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    int posSocio = 0;
    while (posSocio <= s.tope <= s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    DtMascota* aux = s.socios[posSocio]->obtenerArrM(s.socios, posSocio, cantMascotas);
    DtMascota** result = &aux;
    return result;
}
*/

