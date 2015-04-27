/*
 * File:   Grafo.cpp
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Grafo.h"
#include <fstream>
#include <cstdlib>

#ifndef NULL
#define NULL 0
#endif // NULL

using namespace std;

unsigned int cantidad_elementos(string linea)
{
    unsigned int count = 0;
    if (linea.size() > 0) count = 1;
    for (int i = 0; i < linea.size(); i++)
    {
        if (linea[i] == ',')
        {
            count++;
        }
    }
    return count;
}

int elemento(string linea, int indice)
{
    unsigned int count = 0;
    unsigned int pos;
    for (int i = 0; i < linea.size(); i++)
    {
        if (indice == count)
        {
            size_t pos = linea.find(',');
            if (pos == string::npos) pos = linea.size()-1;
            string buffer = linea.substr(i, pos);
            return atoi(buffer.c_str());
        }
        if (linea[i] == ',')
        {
            count++;
        }
    }
    return -1;
}

Grafo::Grafo(int cntVrt, int prmAdy) {
    if (cntVrt >= 10 && 1 <= prmAdy)
    {
        this->cntVrt = cntVrt;
        arrVrt = new NdoVrt[cntVrt];
    }
}

Grafo::Grafo(const Grafo& orig) {
    
}

Grafo::Grafo(string nArch) {
    ifstream file;
    file.open(nArch.c_str(), ios::in);
    if (file.is_open())
    {
        char line[256];
        //memset(&line, 0, 256);
        do
        {
            file.getline(line, 256);
            string linea = line;
            size_t t = linea.find(',');
        } while (file.good());
    }
}

Grafo::~Grafo() {
    if (cntVrt > 0)
        delete[] arrVrt;
}

bool Grafo::xstVrt(int vrt) const {
    return (vrt < cntVrt && vrt >= 0); // Devuelve true si vrt esta entre 0 y cntVrt
}

bool Grafo::xstAdy(int vrtO, int vrtD) const {
    if (xstVrt(vrtO)) // Comprueba que el indice del vertice existe
    {
        int cantidad_adyacencias = arrVrt[vrtO].lstAdy->obtCntAdy();
        if (cantidad_adyacencias == 0) return false; // No hay adyacencias, por lo tanto la adyacencia no existe
        int *ady = arrVrt[vrtO].lstAdy->obtAdy();
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
    if (xstVrt(vrt))
    {
        return arrVrt[vrt].lstAdy->obtAdy();
    }
    return NULL;
}

int Grafo::obtTotAdy() const {
}

int Grafo::obtTotVrt() const {
    return cntVrt;
}

double Grafo::obtPrmAdy() const {
}

Grafo::E Grafo::obtEst(int vrt) const {
}

bool Grafo::operator==(const Grafo& grf) const {
    if (this->cntVrt != grf.cntVrt) return false;
    for (int i = 0; i < this->cntVrt; i++)
    {
        int *ady = obtAdy(i), *adygrf = grf.obtAdy(i);
        for (int j = 0; j < arrVrt[i].lstAdy->obtCntAdy(); j++)
        {
            if (ady[j] != adygrf[j])
                return false;
        }
        delete[] ady; delete[] adygrf;
    }
}

double Grafo::promLongCmnsCrts() const {
}

double Grafo::centralidadIntermedial(int vrt) const {
}

double Grafo::coeficienteAgrupamiento(int vrt) const {
}

void Grafo::modEst(int vrt, E ne) {
}
