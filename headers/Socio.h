#ifndef socio
#define socio

#include <iostream>
#include <string.h>

#include "DtFecha.h"
#include "Consulta.h"
#include "Mascota.h"


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
        Mascota* getMascota(); ///////////////////////////////profe
        Mascota* getMascotas();
        int getTopeC();
        Consulta* getConsulta();
        string getCI();
        void setNombre(string);
        void setCI(string);
        void setTopeM();
        void setArrM(Socio* s[], int i, Mascota*);
        void setArrC(Socio* s[], int i, Consulta*);

};


#endif /* NEWFILE_H */
