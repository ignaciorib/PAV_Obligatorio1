#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include <string.h>

using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
    public:
        DtFecha();
        DtFecha(int, int, int);
        DtFecha(DtFecha &);
        int getAnio();
        int getMes();
        int getDia();
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        bool comp(DtFecha*, DtFecha*);
        //////////////////////////////////DtFecha getFecha();??????????????????
        ~DtFecha();
};


#endif /* DTFECHA_H */
