/* 
 * File:   Simulador.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 06:46 PM
 */

#include <random>
#include <ctime>

#include "Simulador.h"

bool prob(double probability) // probability < 1
{
    double result = rand() / RAND_MAX;
    if(result < probability)
        return true;
    return false;
}

Simulador::Simulador(Grafo& g):grafo(g),visor(nullptr) {
}

Simulador::Simulador(Grafo& g, Visualizador& v):grafo(g),visor(&v) {
}

Simulador::~Simulador() {
}

//ios: cantidad de vertices infectados
//vsc: probabilidad de infeccion
//vcf: checkeo de virus
//rc: probabilidad de recuperacion
//grc: probabilidad de obtener resistencia
void Simulador::simular(int cntItr, int ios, double vsc, int vcf, double rc, double grc) {
    srand(time(NULL));
    int checkeo = vcf;
    for (int i = 0; i < ios; i++)
    {
        int id = rand() % grafo.obtTotVrt();
        if (grafo.xstVrt(id))
        {
            grafo.modEst(id, Grafo::I);
        }
    }
    for (int i = 0; i < cntItr; i++)
    {
        for (int j = 0; j < grafo.obtTotVrt(); j++)
        {
            if (grafo.obtEst(j) == Grafo::I)
            {
                int *ady = grafo.obtAdy(j);
                for (int k = 0; k < grafo.obtCntAdy(j); k++)
                {
                    if (grafo.obtEst(ady[k]) != Grafo::R && prob(vsc))
                    {
                        grafo.modEst(ady[k], Grafo::I);
                    }
                }
                delete[] ady;
                //checkeo de virus
                if (checkeo <= 0)
                {
                    if (prob(rc))
                    {
                        grafo.modEst(j, Grafo::S);
                        if (prob(grc))
                        {
                            grafo.modEst(j, Grafo::R);
                        }
                    }
                }
            }
        }
        checkeo--;
        if (checkeo <= 0) checkeo = vcf;
    }
}
