#ifndef socio
#define socio

#include <iostream>
#include <string.h>

#include "DtFecha.h"
#include "Consulta.h"
#include "Mascota.h"
#include "Gato.h"
#include "Perro.h"
#include "DtMascota.h"
#include "DtConsulta.h"
#include "DtGato.h"
#include "DtPerro.h"

using namespace std;


class Socio{
    private:
        string nombre;
        string CI;
        DtFecha* fechaIng;
        
        Mascota* m[9];
        int topeM;
        
        Consulta* c[20];
        int topeC;
    public:
        Socio();
        Socio(string, string, int, int, int); //Constructor comun
        string getNombre();
        int getTopeM();
        int getTopeC();
        DtConsulta** obtenerArrC(Socio* s[], int posSocio, DtFecha* f, int& cont);
        DtMascota** obtenerArrM(Socio* s[], int posSocio, int &cantMascotas);
        string getCI();
        void setArrM(Socio* s[], int i, Mascota*);
        void setArrC(Socio* s[], int i, Consulta*);
        void delS(Socio* s[], int i);
        bool comp(DtFecha*, DtFecha*);
        void verificarSocio(Socio* s[], int, string);
};


#endif /* NEWFILE_H */