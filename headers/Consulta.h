#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "../headers/Socio.h"
#include "../headers/Mascota.h"

using namespace std;

class Consulta {
    private:
        string descripcion;
    public:
        Consulta();
        Consulta(string);
        //void mostrarInfo();
};

#endif
