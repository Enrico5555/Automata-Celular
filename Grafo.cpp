/* 
 * File:   Grafo.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Grafo.h"

Grafo::Grafo(int cntVrt, int prmAdy) {
    if (cntVrt >= 10 && 1 <= prmGrd)
    {
        this->cntVrt = cntVrt;
        arrVrt = new NdoVrt[cntVrt];
    }
}

Grafo::Grafo(const Grafo& orig) {
}

Grafo::Grafo(string nArch) {
}

Grafo::~Grafo() {
    if (cntVrt > 0)
        delete[] arrVrt;
}

bool Grafo::xstVrt(int vrt) const {
    return (vrt < cntVrt && vrt >= 0); // Devuelve true si vrt esta entre 0 y cntVrt
}

bool Grafo::xstAdy(int vrtO, int vrtD) const {
    if (xstVrt(vrt0)) // Comprueba que el indice del vertice existe
    {
        int cantidad_adyacencias = arrVrt[vrt0].lstAdy.obtCntAdy();
        if (cantidad_adyacencias == 0) return false; // No hay adyacencias, por lo tanto la adyacencia no existe
        int *ady = arrVrt[vrt0].lstAdy.obtCntAdy();
        for (int i = 0; i < cantidad_adyacencias; i++)
        {
            if (ady[i] == vrtD) // Encontró una adyacencia
            {
                delete[] ady; // Libera la memoria
                return true;
            }
        }
        delete[] ady; // Libera la memoria
    }
    return false; // No se encontró adyacencia o el vértice no existe
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
