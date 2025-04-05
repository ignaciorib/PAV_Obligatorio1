#ifndef CONSULTA_H
#define CONSULTA_H

#include <iostream>
#include <string.h>

#include "DtFecha.h"

using namespace std;


class Consulta {
    private:
        string descripcion;
        DtFecha fechaIngreso;
    public:
        Consulta();
        Consulta(string, int, int, int);
        //void mostrarInfo();
};

#endif
