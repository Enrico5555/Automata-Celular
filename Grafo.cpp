/* 
 * File:   Grafo.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Parse.h"
#include "Grafo.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <random>
#include <iostream>
#include <ctime>
#include <limits> // std::numeric_limits
#include <vector>
#include <list>

#ifndef NULL
#define NULL 0
#endif // NULL

using namespace std;
using namespace line_parse;


#include "Grafo.h"

Grafo::Grafo(int cntVrt, int prbAdy) {
    if ((cntVrt >= 10) && (0 <= prbAdy < 1)) {
        this->cntVrt = cntVrt;
        arrVrt.resize(this->cntVrt);
        srand(time(NULL));
        default_random_engine generador(rand());
        normal_distribution<double> distribucion(prbAdy, 2.0);
        //  std::list<int>::iterator it;
        for (int i = 0; i < this->cntVrt; i++) {
            int rnum = distribucion(generador);
            if (!xstAdy(i, rnum) && xstVrt(rnum)) {
                curr->lstAdy.insert(arrVrt[i], rnum);
                curr->lstAdy.insert(arrVrt[rnum], i);
            }
        }
    }
}

Grafo::Grafo(const Grafo& orig) {
    if (orig.cntVrt > 0) {
        this->cntVrt = orig.cntVrt;
        arrVrt.resize(this->cntVrt);
        for (int i = 0; i < this->cntVrt; i++) {
            curr->e = orig.E;
            curr->tmpChqVrs = orig.obtTmpChqVrs(i);
            // curr->lstAdy[i] = orig.arrVrt[i];
            std::vector<int> myvector(orig.arrVrt[i]);
            std::list<int>::iterator it;
            it = curr->lstAdy.begin();
            curr->lstAdy.insert(it, vector.begin(), vector.end());

        }
    }
}

Grafo::Grafo(string nArch) {
    ifstream file;
    file.open(nArch.c_str(), ios::in);
    if (file.is_open() && file.good()) {
        char line[256];
        // memset(&line, 0, 256);
        file.getline(line, 256); //primera linea
        string inits = line;
        sacaDatos(inits);
        cntVrt = cantidadVertices;
        prmAdy = promedioAdy;
        if (cntVrt < 0) return; // error
        arrVrt.resize(cntVrt);
        int count = 0;
        while (!file.eof() && count < cntVrt) {
            memset(&line, 0, 256);
            file.getline(line, 256);
            string linea = line;
            size_t cant = cantidad_elementos(linea);
            if (cant > 0) {
                // arrVrt[count].e = S;
                // curr->lstAdy[i] = orig.arrVrt[i];
                std::vector<int> vect(arrVrt[count]);
                std::list<int>::iterator it;
                it = curr->lstAdy.begin();
                curr->lstAdy.insert(it, vect.begin(), vect.end());
                count++;
            }
            return;
        }
        throw 1;
    }
}


    //ya no es necesario

    Grafo::~Grafo() {
    }

    bool Grafo::xstVrt(int vrt) const {
        return (vrt < cntVrt && vrt >= 0); // Devuelve true si vrt esta entre 0 y cntVrt
    }

    bool Grafo::xstAdy(int vrtO, int vrtD) const {
        if (xstVrt(vrtO) && xstVrt(vrtD)) // Comprueba que el indice del vertice existe
        {
            int cantidad_adyacencias = arrVrt[vrtO].lstAdy.obtCntAdy();
            if (cantidad_adyacencias == 0) return false; // No hay adyacencias, por lo tanto la adyacencia no existe
            return arrVrt[vrtO].lstAdy.bus(vrtD);
        }
        return false; // No se encontro adyacencia o el vertice no existe

    }

    vector<int>& Grafo::obtAdy(int vrt) const {
        return (curr->lstAdy[vrt]);
    }

    int Grafo::obtTotVrt() const {
        return cntVrt;
    }

    int Grafo::obtTotAdy() const {
        int cant = 0;
        for (int i = 0; i < cntVrt; i++) {
            cant += arrVrt[i].lstAdy.obtCntAdy();
        }
        return cant;
    }

    Grafo::E Grafo::obtEst(int vrt) const {
        if (xstVrt(vrt) == true) {
            return arrVrt[vrt].e;
        }
    }

    int Grafo::obtTmpChqVrs(int vrt) const {

    }

    double Grafo::promLongCmnsCrts() const {
        int sum = 0, total = cntVrt * (cntVrt - 1) / 2;
        int **matriz = Floyd_Warshall();
        for (int i = 0; i < cntVrt; i++) {
            for (int j = i; j < cntVrt; j++) {
                if (xstAdy(i, j))
                    sum += matriz[i][j];
            }
        }
        for (int i = 0; i < cntVrt; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
        return ((double) sum / (double) total);
    }

    int **Grafo::Floyd_Warshall() const {
        int** path;
        path = new int*[cntVrt];
        for (int i = 0; i < cntVrt; i++) {
            path[i] = new int[cntVrt];
            path[i][i] = 0;
        }
        for (int i = 0; i < cntVrt; i++) {
            for (int j = 0; j < cntVrt; j++) {
                if (xstAdy(i, j)) {
                    path[i][j] = 1;
                } else {
                    path[i][j] = std::numeric_limits<int>::max();
                }
            }
        }
        for (int k = 0; k < cntVrt; k++)
            for (int i = 0; i < cntVrt; i++)
                for (int j = 0; j < cntVrt; j++) {
                    if (path[i][k] == std::numeric_limits<int>::max() || path[k][j] == std::numeric_limits<int>::max()) continue;
                    int dt = path[i][k] + path[k][j];
                    if (path[i][j] > dt)
                        path[i][j] = dt;
                }

        return path;
    }

    double Grafo::centralidadIntermedial(int vrt) const {


    }

    double Grafo::coeficienteAgrupamiento(int vrt) const {
        if (xstVrt(vrt)) {
            double cant = (double) obtAdy(vrt), triangles = 0.0;
            if (cant == 0 || cant == 1) return 0;
            double t_g = (cant * (cant - 1)) / 2;
            int *ady = obtAdy(vrt);
            for (int i = 0; i < cant; i++) {
                for (int j = i + 1; j < cant; j++) {
                    if (xstAdy(ady[i], ady[j])) {
                        triangles++;
                    }
                }
            }
            delete[] ady;
            return (triangles / t_g);
        }
        return 0;
    }

    void Grafo::modEst(int vrt, E ne) {
        if (xstVrt(vrt)) {
            arrVrt[vrt].e = ne;
        }
    }

    void Grafo::modTmpChqVrs(int vrt, int nt) {


    }

    void Grafo::actCntChqVrs(int vrt) {


    }

    void Grafo::infectar(int ios) {

    }

    void Grafo::azarizarTmpChqVrs(int maxTmp) {


    }

    void Grafo::modEstados(vector<NdoVrt>& stdAct) {


    }