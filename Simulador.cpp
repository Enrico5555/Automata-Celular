/* 
 * File:   Simulador.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 06:46 PM
 */

#include "Simulador.h"

Simulador::Simulador(Grafo& g):grafo(g),visor(nullptr) {
}

Simulador::Simulador(Grafo& g, Visualizador& v):grafo(g),visor(&v) {
}

Simulador::~Simulador() {
}

void Simulador::simular(int cntItr, int ios, double vsc, int vcf, double rc, double grc) {
}