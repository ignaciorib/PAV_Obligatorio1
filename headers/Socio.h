#ifndef SOCIO_H
#define SOCIO_H

#include <iostream>
#include <string.h>
#include "DtFecha.h"
#include "Consulta.h"

using namespace std;

class Socio{
    private:
        string nombre;
        string CI;
        DtFecha fechaIng;
        Mascota* m[10];
        int topeM;
        Consulta c[20];
        int topeC;
    public:
        Socio();
        Socio(string, string, int, int, int); //Constructor comun
        string getNombre();
        int getTopeM();
        Mascota* getMascota();
        int getTopeC();
        Consulta getConsulta();
        string getCI();
        void setNombre(string);
        void setCI(string);
};

/*#include <string>

class Socio {
private:
    std::string nombre;
    int id;

public:
    Socio(std::string nombre, int id);
    void mostrarInfo();
};*/

#endif
