#include <cstdlib>
#include <iostream>
#include <stdlib.h>

#include "../headers/Mascota.h"

Mascota::Mascota() {}

Mascota::Mascota(string n, float p, int g, int p_g) {
  nombreMsc = n;
  peso = p;
  if (g)
    GeneroM = Genero::Macho;
  else
    GeneroM = Genero::Hembra;
  P_G = p_g;
  rD = 0;
}

float Mascota::getPeso() { return peso; }

string Mascota::getNombreMsc() { return nombreMsc; }

int Mascota::getGenero() {
  if (GeneroM == Genero::Macho)
    return 1;
  else
    return 0;
}

bool Mascota::getPerroGato() { return P_G; }

void Mascota::setRD(float racion) { rD = racion; }