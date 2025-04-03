#ifndef CONSULTA_H
#define CONSULTA_H

#include <string>
#include "../headers/Socio.h"

using namespace std;

class Consulta: public Socio {
    private:
        string descripcion;
    public:
        Consulta();
        Consulta(string);
        //void mostrarInfo();
};

#endif
