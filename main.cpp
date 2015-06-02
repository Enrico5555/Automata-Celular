/*
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 15 de abril de 2015, 12:05 PM
 */

// Ejemplo base tomado de cplusplus
// normal_distribution example
#include <stdlib.h>
#include <iostream>
#include "Grafo.h"
using namespace std;

/*
 * Simple C++ Test Suite
 */


//Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 100 y prmAdy == 15.
//Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 1000 y prmAdy == 15.

void testConstructorGrafo() {
    Grafo grafo(100,0.5);
    Grafo grafo2(1000,0.5);
    if (grafo2.obtTotVrt() != 1000 || grafo.obtTotVrt()!=100){
        cout<< "el total de vertices de grafo 1 es " << grafo.obtTotVrt()<< endl;
        cout<< "el total de vertices de grafo 2 es " << grafo2.obtTotVrt()<< endl;
    //if (grafo.obtTotVrt() == 100) || !(grafo2.obtTotVrt() == 1000 )){//|| !(grafo.obtTotAdy() >= 15) || !(grafo2.obtTotAdy() >= 15)) {
        cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DEL GRAFO(newsimpletest) message=ereror message sample" << endl;
    }
}

//Construye una copia idéntica a Grafo(100,15).
//Construye una copia idéntica a Grafo(1000,15).

void testConstructCopias() {
    Grafo orig(100,15);
    Grafo grafo(orig);
    Grafo orig2(1000,15);
    Grafo grafo2(orig2);
    if (!(grafo == orig) || !(grafo2 == orig2)) {
        cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS (newsimpletest) message=error message sample" << endl;
    }
}

//Construye el grafo correcto con el “redMuyPeq.txt”.
//Construye el grafo correcto con el “redPeq.txt”.

void testConstructorString() {
    Grafo grafo("redMuyPeq.txt");
    Grafo grafo2("redPeq.txt");
    if (grafo.obtTotVrt() != 10 || grafo2.obtTotVrt() != 100 || grafo.obtAdy(0)[0] != 8 || grafo2.obtAdy(0)[0] != 2) {
        cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR A PARTIR DEL STRING (newsimpletest) message=error message sample" << endl;
    }
}


//void infectar(int ios) efectivamente “infecta” la cantidad correcta de vértices

void testInfectar() {
    Grafo grafo("redMuyPeq.txt");
    grafo.infectar(5);
    int cont;
    for(int i=0;i<10;i++) if(grafo.obtEst(i)== Grafo::I)cont++;
    if (cont != 5) {
        cout << "%TEST_FAILED% FALLO EL METODO Infectar (newsimpletest) message=error message sample" << endl;
    }
}

//void azarizarTmpChqVrs(int vcf) efectivamente asigna valores 
//iniciales al temporizador de chequeo en el rango [1..vcf] para todos los vértices.

void testAzarizarTmpChqVrs() {
    int vcf = 1;
    Grafo grafo(10,10);
    grafo.azarizarTmpChqVrs(vcf);
    if (grafo.obtTmpChqVrs(0) != 1) {
        cout << "%TEST_FAILED% FALLO EL METODO AzarizarTmpChqVrs (newsimpletest) message=error message sample" << endl;
    }
}

//Genera el valor correcto con un grafo muy pequeño.

void testPromLongCmnsCrts() {
    Grafo grafo("redMuyPeq.txt");
    double res = grafo.promLongCmnsCrts();
    if (!(0.4 > res > 0)) {
        cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts(newsimpletest) message=error message sample" << endl;
    }
}

//Genera el valor correcto para el vértice indicado de un grafo muy pequeño.

void testCoeficienteAgrupamiento() {
    Grafo grafo("redMuyPeq.txt");
    double res = grafo.coeficienteAgrupamiento(0);
    if (!(res == 1)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO CoeficienteAgrupamiento (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    cout << "%SUITE_STARTING% newsimpletest" << endl;
    cout << "%SUITE_STARTED%" << endl;

    cout << "%TEST_STARTED% testConstructorGrafo (newsimpletest)" << endl;
    testConstructorGrafo();
    cout << "%TEST_FINISHED% testConstructorGrafo (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testConstructCopias(newsimpletest)" << endl;
    testConstructCopias();
    cout << "%TEST_FINISHED% testConstructCopias (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testConstructorString (newsimpletest)" << endl;
    testConstructorString();
    cout << "%TEST_FINISHED% testConstructorString (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testInfectar (newsimpletest)" << endl;
    testInfectar();
    cout << "%TEST_FINISHED% testInfectar (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testAzarizarTmpChqVrs (newsimpletest)" << endl;
    testAzarizarTmpChqVrs();
    cout << "%TEST_FINISHED% testAzarizarTmpChqVrs (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testPromLongCmnsCrts (newsimpletest)" << endl;
    testPromLongCmnsCrts();
    cout << "%TEST_FINISHED% testPromLongCmnsCrts (newsimpletest)" << endl;

    cout << "%TEST_STARTED% testCoeficienteAgrupamiento (newsimpletest)" << endl;
    testCoeficienteAgrupamiento();
    cout << "%TEST_FINISHED% testCoeficienteAgrupamiento (newsimpletest)" << endl;

    cout << "%SUITE_FINISHED% time=0" << endl;

    return (EXIT_SUCCESS);
}


