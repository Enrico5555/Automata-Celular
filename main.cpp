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
    sv.simular(1001, 2, 0.1, 10, 0.1, 0.2);
    for (int i = 0; i < mg.obtTotVrt(); i++)
    {
        cout << "Estado: " << mg.obtEst(i) << endl;
    }
    LstAdy lstAdy();
    return 0;
}

