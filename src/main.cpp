
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
    Socio* socios[MAX_SOCIOS];
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
    int opcion;
    string ci, nombre, nombreMascota, motivo;
    int edadMascota, generoMascota, tipoMascota, tipoPelo, vacunas, raza, dia, mes, anio, cantConsultas, cantMascotas;
    float pesoMascota;
    DtFecha* dtF;
    while (opcion != 0) {
        cout << "\nElija la opcion: \n"
                "   1) Registrar socio\n"
                "   2) Agregar mascota\n"
                "   3) Ingresar consulta\n"
                "   4) Ver consultas antes de fecha\n"
                "   5) Eliminar socio\n"
                "   6) Obtener mascotas\n"
                "   0) Salir\n"
        "Opcion: ";
        cin >> opcion;
        switch (opcion){
            case 1:
                cout << "\nPara comenzar primero indique la fecha del día de hoy, comenzando por el día: (--/xx/xxxx) ";
                cin >> dia;
                cout << "\nA continuación indique el mes: (xx/--/xxxx) ";
                cin >> mes;
                cout << "\nPara finalizar indique el año: (xx/xx/----) ";
                cin >> anio;
                dtF = new DtFecha(dia, mes, anio);
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cout << "\nIngrese Nombre del socio: ";
                cin >> nombre;
                cout << "\nA continuación ingrese los datos de su mascota \n";
                cout << "Nombre: ";
                cin >> nombreMascota;
                cout << "\nIndique el número que corresponda al sexo de su mascota: \n  -0 si es hembra.\n  -1 si es macho.\n";
                cin >> generoMascota;
                cout << "\nPeso: ";
                cin >> pesoMascota;
                cout << "\nIndique el número que corresponda al tipo de su mascota: \n  -0 si es perro.\n  -1 si es gato. \n";
                cin >> tipoMascota;
                if (tipoMascota) {
                    cout << "\n-Ingrese el tipo de pelo:\n  -1 Corto\n  -2 Mediano\n  -3 Largo\n";
                    cin >> tipoPelo;
                    DtGato* dtG = new DtGato(nombreMascota, generoMascota, pesoMascota, tipoMascota, tipoPelo);
                    registrarSocio(ci, nombre, dtF, dtG);
                } else {
                    cout << "\n-¿El cachorro tiene vacunas?\n  -0 Sí.\n  -1 No.\n";
                    cin >> vacunas;
                    bool auxV;
                    if (vacunas == 0)
                        auxV = false;
                    else
                        auxV = true;
                    cout << "\nSeleccione la raza:\n  1- Labrador\n  2- Ovejero\n  3- Bulldog\n  4- Pitbull\n  5- Collie\n  6- Pekines\n  7- Otro\n";
                    cin >> raza;
                    DtPerro* dtP = new DtPerro(nombreMascota, generoMascota, pesoMascota, tipoMascota, raza, auxV);
                    registrarSocio(ci, nombre, dtF, dtP);
                }
                break;
            case 2:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cout << "\nA continuación ingrese los datos de su mascota \n\n";
                cout << "Nombre: ";
                cin >> nombreMascota;
                //dtM->setNombre(nombreMascota);
                cout << "\nIndique el número que corresponda al sexo de su mascota: \n  -0 si es hembra.\n  -1 si es macho.\n";
                cin >> generoMascota;
                //dtM->setGenero(generoMascota);
                cout << "\nPeso: ";
                cin >> pesoMascota;
                //dtM->setPeso(pesoMascota);
                //dtM->setRacionDiaria(0); //Seteamos la racion diaria en 0
                cout << " kg.\nIndique el número que corresponda al tipo de su mascota: \n  -0 si es perro.\n  -1 si es gato. \n";
                cin >> tipoMascota;
                if (tipoMascota) {
                    //dtG = dynamic_cast<DtGato*>(dtM); //gepeto me recomendó usar un *, sin el puntero me sale error
                    cout << "\n-Ingrese el tipo de pelo:\n  -1 Corto\n  -2 Mediano\n  -3 Largo\n";
                    cin >> tipoPelo;
                    //dtG->setTipoPelo(tipoPelo);
                    DtGato* dtG = new DtGato(nombreMascota, generoMascota, pesoMascota, tipoMascota, tipoPelo);
                    agregarMascota(ci, dtG);
                } else {
                    //dtP = dynamic_cast<DtPerro*>(dtM);
                    cout << "\n-¿El cachorro tiene vacunas?\n  -0 Sí.\n  -1 No.\n";
                    cin >> vacunas;
                    bool auxV;
                    if (vacunas == 0)
                        auxV = false;
                    else
                        auxV = true;
                    cout << "\nSeleccione la raza:\n  1- Labrador\n  2- Ovejero\n  3- Bulldog\n  4- Pitbull\n  5- Collie\n  6- Pekines\n  7- Otro\n";
                    cin >> raza;
                    //dtP->setRaza(raza);
                    DtPerro* dtP = new DtPerro(nombreMascota, generoMascota, pesoMascota, tipoMascota, raza, auxV);
                            //string n, int g, float p, int p_g, int r, bool vC
                    agregarMascota(ci, dtP);
                }
                break;
            case 3:
                cout << "\nPara comenzar primero indique la fecha del día de hoy, comenzando por el día: (--/xx/xxxx) ";
                cin >> dia;
                cout << "\nA continuación indique el mes: (xx/--/xxxx) ";
                cin >> mes;
                cout << "\nPara finalizar indique el año: (xx/xx/----) ";
                cin >> anio;
                dtF = new DtFecha(dia, mes, anio);
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cout << "\nA continuacion ingrese el motivo de su consulta:\n\n";
                cin >> motivo; ///////////////////////////////////////////////////////////////////////////////////////
                ingresarConsulta(motivo, ci, dtF);
                break;
            case 4:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cout << "\nIndique la fecha, comenzando por el día: (--/xx/xxxx) ";
                cin >> dia;
                cout << "\nA continuación indique el mes: (xx/--/xxxx) ";
                cin >> mes;
                cout << "\nPara finalizar indique el año: (xx/xx/----) ";
                cin >> anio;
                dtF = new DtFecha(dia, mes, anio);
                cout << "\ngood1";
                DtConsulta** auxC;
                cantConsultas = 0;
                auxC = verConsultasAntesDeFecha(dtF, ci, cantConsultas);
                cout << "\ngood1";
                if (auxC == NULL)
                    cout << "\nlareputa";
                else {
                    for (int iter = 0; iter < cantConsultas; iter++)
                        auxC[iter]->mostrarDtC();
                    cout << "\ngood2";
                }
                break;
            case 5:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                eliminarSocio(ci);
                break;
            /*case 6:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cantMascotas = 0;
                DtMascota** auxM;
                cout << "good1";
                auxM = obtenerMascotas(ci, cantMascotas);
                cout << "good1";
                
                for (int iter = 0; iter < cantMascotas; iter++) {
                    if (auxM[iter]->getPerroGato()){
                        DtGato* gato = dynamic_cast<DtGato*>(auxM[iter]);
                        gato->mostrarInfDtGato();
                        cout << "goodGato";
                    }
                    else {
                        DtPerro* perro = dynamic_cast<DtPerro*>(auxM[iter]);
                        perro->mostrarInfDtPerro();
                        cout << "goodPerro";
                    }
                }
                break;*/
            case 0:
                cout << "\nAdios, vuelva pronto";
                break;
            default:
                cout << "\nOpción inválida. Intente nuevamente.";
                break;
        }
    }
    
    
    return 0;
}

void registrarSocio(string ci, string nombre, DtFecha* fechaIngreso, DtMascota* dtMascota) {
    if (s.tope == MAX_SOCIOS)
        cout << "\nno hay espacio para mas socios";
    else {
        int posSocio = s.tope;
        Socio* auxS = new Socio(nombre, ci, fechaIngreso->getDia(), fechaIngreso->getMes(), fechaIngreso->getAnio());
        s.socios[posSocio] = auxS;
        s.tope++;
        if (dtMascota->getPerroGato()){  ///////////////////hacer una funcion?????????????????
            DtGato* dtgato = dynamic_cast<DtGato*>(dtMascota);
            Gato* cat;
            cat = new Gato(dtgato->getNombreDtMsc(), dtgato->getDtPeso(), dtgato->getDtGenero(), dtgato->getTipoPelo());///////////////////////
            
            s.socios[posSocio]->setArrM(s.socios, posSocio, cat);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            cout << "good";
        }
        else {
            DtPerro* perro = dynamic_cast<DtPerro*>(dtMascota);
            Perro* dog;
            dog = new Perro(perro->getNombreDtMsc(), perro->getDtPeso(), perro->getDtGenero(), perro->getRaza(), perro->getVC());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, dog);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            cout << "good";
        }
        
    }
    
}

void agregarMascota(string ci, DtMascota* dtMascota) {////////////////////////////////////////////////////////////////////////////LEGAL??????????
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    int j = s.socios[posSocio]->getTopeM();
    if (j <= 9) {
        if (dtMascota->getPerroGato()){
            DtGato* gato = dynamic_cast<DtGato*>(dtMascota);
            Gato* cat;
            cat = new Gato(gato->getNombreDtMsc(), gato->getDtPeso(), gato->getDtGenero(), gato->getTipoPelo());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, cat);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            cout << "good";
        }
        else {
            DtPerro* perro = dynamic_cast<DtPerro*>(dtMascota);
            Perro* dog;
            dog = new Perro(perro->getNombreDtMsc(), perro->getDtPeso(), perro->getDtGenero(), perro->getRaza(), perro->getVC());///////////////////////
            s.socios[posSocio]->setArrM(s.socios, posSocio, dog);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            cout << "good";
        }
    }
    else
        //cout << "Este socio no puede tener mas mascotas asociadas";
        throw overflow_error ("Este socio no puede tener mas mascotas asociadas"); 
    cout << "\n" << s.socios[posSocio]->getTopeM();
}

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    int j = s.socios[posSocio]->getTopeC();
    if (j <= 20) {
        Consulta* auxC = new Consulta(motivo, fechaConsulta->getDia(), fechaConsulta->getMes(), fechaConsulta->getAnio());
        s.socios[posSocio]->setArrC(s.socios, posSocio, auxC);
        cout << "good";
    }
    else
        throw overflow_error ("Este socio no puede tener mas consultas asociadas"); 
    cout << "\n" << s.socios[posSocio]->getTopeC();
    
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) { 
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ciSocio)
        posSocio++;
    DtConsulta** result = s.socios[posSocio]->obtenerArrC(s.socios, posSocio, fecha, cantConsultas); //chusmear
    return result;
}

void eliminarSocio(string ci) { ///////////////////false eliminar fecha
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
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
    cout << "good";
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    DtMascota** result = s.socios[posSocio]->obtenerArrM(s.socios, posSocio, cantMascotas);
    return result;
}

