#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctime>
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
void verificarSocio(string ci);


int main () {
    cout << "Inicio del programa" << endl;
    s.tope = 0;
    int opcion = -1;
    string ci, nombre, nombreMascota, motivo;
    int  generoMascota, tipoMascota, tipoPelo, vacunas, raza, dia, mes, anio, cantConsultas, cantMascotas;
    float pesoMascota;
    DtFecha* dtF;
    
    while (opcion != 0) {
        cout << "\n\n\nElija la opcion: \n"
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
                
                    try {
                        verificarSocio(ci);
                        cout << "El elemento no existe en el arreglo." << endl;
                    } catch (const invalid_argument& e) {
                        cout << "Excepción: " << e.what() << endl;
                    }
                    
                cout << "\nIngrese Nombre del socio: ";
                cin.ignore();  // Para evitar problemas con getline
	        getline(cin, nombre);
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
			delete dtG;
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
			delete dtP;
                }
                break;
            case 2:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                cout << "\nA continuación ingrese los datos de su mascota \n\n";
                cout << "Nombre: ";
                cin >> nombreMascota;
                cout << "\nIndique el número que corresponda al sexo de su mascota: \n  -0 si es hembra.\n  -1 si es macho.\n";
                cin >> generoMascota;
                cout << "\nPeso: ";
                cin >> pesoMascota;
                cout << "\nIndique el número que corresponda al tipo de su mascota: \n  -0 si es perro.\n  -1 si es gato. \n";
                cin >> tipoMascota;
                try{
                    if (tipoMascota) {
                        cout << "\n-Ingrese el tipo de pelo:\n  -1 Corto\n  -2 Mediano\n  -3 Largo\n";
                        cin >> tipoPelo;
                        DtGato* dtG = new DtGato(nombreMascota, generoMascota, pesoMascota, tipoMascota, tipoPelo);
                        agregarMascota(ci, dtG);
			    delete dtG;
                    } else {
                        cout << "\n-¿El cachorro tiene vacunas?\n  -1 Sí.\n  -0 No.\n";
                        cin >> vacunas;
                        bool auxV;
                        if (vacunas)
                            auxV = true;
                        else
                            auxV = false;
                        cout << "\nSeleccione la raza:\n  1- Labrador\n  2- Ovejero\n  3- Bulldog\n  4- Pitbull\n  5- Collie\n  6- Pekines\n  7- Otro\n";
                        cin >> raza;
                        DtPerro* dtP = new DtPerro(nombreMascota, generoMascota, pesoMascota, tipoMascota, raza, auxV);
                        agregarMascota(ci, dtP);
			    delete dtP;
                    }
                    cout << "\nLa mascota se ha agregado exitosamente\n";
                }catch(const invalid_argument &S){
                    cout << "Error:" << S.what() << endl;
                }catch(const overflow_error &m){
                    cout << "Error:" << m.what() << endl;
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
                cin.ignore();  // Para evitar problemas con getline
	            getline(cin, motivo);
                /////////////// manejo de excepciones
                try{
                    ingresarConsulta(motivo, ci, dtF);
                    cout << "\nLa consulta se ha ingresado exitosamente\n";
                }catch(const invalid_argument& S){ //exepcion si el socio no existe
                    cout << "Error:" << S.what() << endl;
                }catch(const overflow_error& c){ //exepcion si el socio tiene 20 consultas
                    cout << "Error:" << c.what() << endl;
                }
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
                DtConsulta** auxC;
                cantConsultas = 0;
                auxC = verConsultasAntesDeFecha(dtF, ci, cantConsultas);
                for (int iter = 0; iter < cantConsultas; iter++)
                    auxC[iter]->mostrarDtC();
                break;
            case 5:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                try{
                    eliminarSocio(ci);
                    cout << "\nEl socio se ha eliminado exitosamente\n";
                }catch(const invalid_argument& q){
                    cout << "Error:" << q.what() << endl;
                }
                break;
            case 6:
                cout << "\nIngrese CI del socio: ";
                cin >> ci;
                try{
                    DtMascota** auxM;
                    auxM = obtenerMascotas(ci, cantMascotas);
                }catch(const invalid_argument& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;
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
        Socio* S = new Socio(nombre, ci, fechaIngreso->getDia(), fechaIngreso->getMes(), fechaIngreso->getAnio());
        s.socios[posSocio] = S;
        s.tope++;
        if (dtMascota->getPerroGato()){
            DtGato* dtgato = dynamic_cast<DtGato*>(dtMascota);
            Gato* catA = new Gato(dtgato->getNombreDtMsc(), dtgato->getDtPeso(), dtgato->getDtGenero(), dtgato->getPerroGato(), dtgato->getTipoPelo());
            s.socios[posSocio]->setArrM(s.socios, posSocio, catA);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
        else {
            DtPerro* dtperro = dynamic_cast<DtPerro*>(dtMascota);
            Perro* dogA = new Perro(dtperro->getNombreDtMsc(), dtperro->getDtPeso(), dtperro->getDtGenero(), dtperro->getPerroGato(), dtperro->getRaza(), dtperro->getVC());
            s.socios[posSocio]->setArrM(s.socios, posSocio, dogA);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
        }
    }
}

void agregarMascota(string ci, DtMascota* dtMascota) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    if (posSocio == s.tope)
        throw invalid_argument("El socio con esa cédula no está registrado.");
    else {
        int j = s.socios[posSocio]->getTopeM();
        if (j <= 9) {
            if (dtMascota->getPerroGato()){
                DtGato* gato = dynamic_cast<DtGato*>(dtMascota);
                Gato* catB = new Gato(gato->getNombreDtMsc(), gato->getDtPeso(), gato->getDtGenero(), gato->getPerroGato(), gato->getTipoPelo());
                s.socios[posSocio]->setArrM(s.socios, posSocio, catB);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            }
            else {
                DtPerro* perro = dynamic_cast<DtPerro*>(dtMascota);
                Perro* dogB = new Perro(perro->getNombreDtMsc(), perro->getDtPeso(), perro->getDtGenero(), perro->getPerroGato(), perro->getRaza(), perro->getVC());
                s.socios[posSocio]->setArrM(s.socios, posSocio, dogB);  //agrega el aux en la posicion topeM del socio i y suma 1 al topeM
            }
        }
        else
            throw overflow_error ("Este socio no puede tener mas mascotas asociadas");
    }
}
    

void ingresarConsulta(string motivo, string ci, DtFecha* fechaConsulta) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;

    ///////////////////////////////// manejo de  excepciones
    if (posSocio == s.tope){
        throw invalid_argument("El socio con esa cédula no está registrado.");
    }else if (s.socios[posSocio]->getTopeC() == 20) {
        throw overflow_error ("Este socio no puede tener mas consultas asociadas");
    }
    /////////////////////////////////
    int j = s.socios[posSocio]->getTopeC();
    if (j <= 20) {
        Consulta* C = new Consulta(motivo, fechaConsulta->getDia(), fechaConsulta->getMes(), fechaConsulta->getAnio());
        s.socios[posSocio]->setArrC(s.socios, posSocio, C);
    }
}

DtConsulta** verConsultasAntesDeFecha(DtFecha* fecha, string ciSocio, int& cantConsultas) { 
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ciSocio)
        posSocio++;
    DtConsulta** result = s.socios[posSocio]->obtenerArrC(s.socios, posSocio, fecha, cantConsultas);
    return result;
}

void eliminarSocio(string ci) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
    if (posSocio < s.tope) {
        s.socios[posSocio]->delS(s.socios, posSocio);
        for (int i = posSocio; i < s.tope - 1; i++) {
            s.socios[i] = s.socios[i + 1];
        }
        s.tope--;
    }
    else
        throw invalid_argument("El socio con esa cédula no está registrado.");
}

DtMascota** obtenerMascotas(string ci, int& cantMascotas) {
    int posSocio = 0;
    while (posSocio < s.tope && s.socios[posSocio]->getCI() != ci)
        posSocio++;
        
    if(posSocio == s.tope)
        throw invalid_argument("El socio con esa cédula no está registrado.");

    DtMascota** result = s.socios[posSocio]->obtenerArrM(s.socios, posSocio, cantMascotas);
    return result;
}

void verificarSocio(string ci) {
    if (s.tope >= 1)
        for (int i = 0; i < s.tope ; ++i) {
            if (s.socios[i]->getCI() == ci) 
                throw invalid_argument("El socio ya esta registrado.");
        }
}
