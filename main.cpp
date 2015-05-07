/* 
 * File:   main.cpp
 * Author: Alan
 *
 * Created on 1 de abril de 2015, 06:52 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"
/*
 * 
 */
int main(int argc, char** argv) {
    Grafo mg(30,6);
    Simulador s(mg);
    Visualizador v(mg);
    Simulador sv(mg,v);
    sv.simular(1000, 1, 0.04, 10, 0.5, 0.001);
    for (int i = 0; i < mg.obtTotVrt(); i++)
    {
        cout << "Estado: " << mg.obtEst(i) << endl;
    }
    cout << "Automata Celular\n";
    while (true)
    {
        string line;
        cout << ">>";
        cin >> line;
        if (line_parse::cantidad_elementos(line) > 0)
        {
            
        }
    }
    return 0;
}

