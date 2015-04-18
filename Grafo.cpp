/* 
 * File:   Grafo.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Grafo.h"

Grafo::Grafo(int cntVrt, int prmAdy) {
}

Grafo::Grafo(const Grafo& orig) {
}

Grafo::Grafo(string nArch) {
}

Grafo::~Grafo() {
}

bool Grafo::xstVrt(int vrt) const {
}

bool Grafo::xstAdy(int vrtO, int vrtD) const {
}

int* Grafo::obtAdy(int vrt) const {
}

int Grafo::obtTotAdy() const {
}

int Grafo::obtTotVrt() const {
}

double Grafo::obtPrmAdy() const {
}

Grafo::E Grafo::obtEst(int vrt) const {
}

bool Grafo::operator==(const Grafo& grf) const {
}

double Grafo::promLongCmnsCrts() const {
}

double Grafo::centralidadIntermedial(int vrt) const {
}

double Grafo::coeficienteAgrupamiento(int vrt) const {
}

void Grafo::modEst(int vrt, E ne) {
}