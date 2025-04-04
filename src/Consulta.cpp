#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "../headers/Consulta.h"

Consulta::Consulta() {}

Consulta::Consulta(string s, int d, int m, int a) {
    descripcion = s;
    fechaIngreso = DtFecha(d, m, a);
}
