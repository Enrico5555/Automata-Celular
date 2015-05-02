/*
 * File:   Grafo.cpp
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Grafo.h"
#include <fstream>
#include <iostream>
#include <cstring>
#include <stdlib.h>//sorry por lo lento.. tranquilo jaja

#ifndef NULL
#define NULL 0
#endif // NULL

using namespace std;

// esto es para 
unsigned int cantidad_elementos(const string& linea)
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

// esto lee los vertices
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
    if (orig.cntVrt > 0)
    {
        cntVrt = orig.cntVrt;
        arrVrt = new NdoVrt[cntVrt];
        for (int i = 0; i < cntVrt; i++)
        {
            arrVrt[i].e = orig.arrVrt[i].e; // tal vez funciona
            arrVrt[i].tmpChqVrs = orig.arrVrt[i].tmpChqVrs;
            arrVrt[i].lstAdy = LstAdy(orig.arrVrt[i].lstAdy); // tal vez funciona, posiblemente no
            /*for (int j = 0; j < orig.arrVrt[i].lstAdy.obtCntAdy(); j++)
            {
                
            }*/
        }
    }
}

Grafo::Grafo(string nArch) {
    ifstream file;
    file.open(nArch.c_str(), ios::in);
    if (file.is_open())
    {
        char line[256];
        memset(&line, 0, 256);
        file.getline(line, 256); //primera linea
        cntVrt = atoi(line);
        if (cntVrt < 0) return; // error
        arrVrt = new NdoVrt[cntVrt];
        int count = 0;
        do
        {
            memset(&line, 0, 256);
            file.getline(line, 256);
            string linea = line;
            unsigned int cant = cantidad_elementos(linea);
            if (cant > 0)
            {
                switch (elemento(linea, 0))
                {
                case 0:
                    arrVrt[count].e = E::S;
                    break;
                }
                if (cant > 1)
                {
                    //arrVrt[count].lstAdy = new LstAdy();
                    for (int i = 1; i < cant; i++)
                    {
                        arrVrt[count].lstAdy.agr(elemento(linea, i));
                    }
                }
            }
            count++;
        } while (!file.eof() && count < cntVrt);
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
    if (xstVrt(vrtO)&& xstVrt(vrtD)) // Comprueba que el indice del vertice existe
    {
        int cantidad_adyacencias = arrVrt[vrtO].lstAdy.obtCntAdy();
        if (cantidad_adyacencias == 0) return false; // No hay adyacencias, por lo tanto la adyacencia no existe
        int *ady = arrVrt[vrtO].lstAdy.obtAdy();
        for (int i = 0; i < cantidad_adyacencias; i++)
        {
            if (ady[i] == vrtD) // Encontrï¿½ una adyacencia
            {
                delete[] ady; // Libera la memoria
                return true;
            }
        }
        delete[] ady; // Libera la memoria
    }
    return false; // No se encontrï¿½ adyacencia o el vï¿½rtice no existe
}

int Grafo::obtCntAdy(int vrt) const
{
    if (xstVrt(vrt))
    {
        return arrVrt[vrt].lstAdy.obtCntAdy();
    }
}

int* Grafo::obtAdy(int vrt) const {
    if (xstVrt(vrt))
    {
        return arrVrt[vrt].lstAdy.obtAdy();
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
    if (xstVrt( vrt) == true){
        //retorna el estado del vertice con indice vrt
        
    }
}

bool Grafo::operator==(const Grafo& grf) const {
    if (this->cntVrt != grf.cntVrt) return false;
    for (int i = 0; i < this->cntVrt; i++)
    {
        int *ady = obtAdy(i), *adygrf = grf.obtAdy(i);
        for (int j = 0; j < arrVrt[i].lstAdy.obtCntAdy(); j++)
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
