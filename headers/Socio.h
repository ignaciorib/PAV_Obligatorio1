#ifndef socio
#define socio

#include <iostream>
#include <string.h>

#include "DtMascota.h"
#include "DtConsulta.h"
#include "DtPerro.h"
#include "DtGato.h"


using namespace std;


class Socio{
    private:
        string nombre;
        string CI;
        DtFecha fechaIng;
        
        Mascota* m[9];
        int topeM;
        
        Consulta* c[20];
        int topeC;
    public:
        Socio();
        Socio(string, string, int, int, int); //Constructor comun
        string getNombre();
        int getTopeM();
        Mascota* getMascota(Mascota* mas[], string nam); ///////////////////////////////profe
        Mascota* getMascotas();
        int getTopeC();
        Consulta* getConsulta();
        DtConsulta** obtenerArrC(Socio* s[], int posSocio, DtFecha* f, int& cont);
        DtMascota** obtenerArrM(Socio* s[], int posSocio, int &cantMascotas);
        string getCI();
        void setNombre(string);
        void setCI(string);
        void setTopeM(Socio* s[], int i);
        void setArrM(Socio* s[], int i, Mascota*);
        void setArrC(Socio* s[], int i, Consulta*);
        void delM(Socio* s[], int i, int j);
        void delC(Socio* s[], int i, int k);
        void delS(Socio* s[], int i);

};


#endif /* NEWFILE_H */
