/* 
 * File:   main.cpp
 * Author: Alan
 *
 * Created on 1 de abril de 2015, 06:52 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Grafo mg(10,6);
    Simulador s(mg);
    Visualizador v(mg);
    Simulador sv(mg,v);
    LstAdy lstAdy();
    return 0;
}

