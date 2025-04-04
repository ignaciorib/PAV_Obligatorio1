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
        
        Consulta* c[19];
        int topeC;
    public:
        Socio();
        Socio(string, string, int, int, int); //Constructor comun
        string getNombre();
        int getTopeM();
        Mascota* getMascota();
        int getTopeC();
        Consulta* getConsulta();
        string getCI();
        void setNombre(string);
        void setCI(string);
        void setTopeM();
        void setArrM(Mascota*);

};


#endif /* NEWFILE_H */
