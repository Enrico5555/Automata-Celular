/*
 * File:   pba_lstady.cpp
 * Author: Konrad
 *
 * Created on Apr 13, 2015, 4:42:18 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"
#define null 0

#define printbegin(a) std::cout << "%TEST_STARTED% " << a << " (grafo)" << std::endl;
#define printerror(a) std::cout << "%TEST_FAILED% " << a << " (grafo) message=error message sample" << std::endl;
#define printend(a) std::cout << "%TEST_FINISHED% time=0 " << a << " (pba_lstady)" << std::endl;

/*
 * Simple C++ Test Suite
 */
 
 //papas
 
//Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 100 y prmAdy ==15.
void testConstructorGrafo1(){
     Grafo grafo(100, 15);// prom +- desviac ... +-3
     if (grafo.obtTotVrt() != 100 || grafo.obtPrmAdy() != 15){
      std::cout << "%TEST_FAILED% FALLO EL CONNSTRUCTOR GRAFO 1 (newsimpletest) message=error message sample" << std::endl;
     }
 }
 
  //Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 1000 y prmAdy ==15.
 void testConstructorGrafo2(){
     Grafo grafo(1000, 15);
     if (grafo.obtTotVrt() != 1000 || grafo.obtPrmAdy() != 15)
     {
      std::cout << "%TEST_FAILED% FALLO EL CONNSTRUCTOR GRAFO 2 (newsimpletest) message=error message sample" << std::endl;
     }
 }
 
//Construye una copia idéntica a Grafo(100,15).
 void testConstGrafo1() {
    Grafo grafo(100, 15); //usar operator ==
    Grafo grafo2(grafo);
    if (!(grafo == grafo2) ) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 1 (newsimpletest) message=error message sample" << std::endl;
    }
}
 
 //Construye una copia idéntica a Grafo(1000,15).
 void testConstGrafo2() {
  Grafo grafo(1000, 15);// op ==
    Grafo grafo2(grafo);
    if (!(grafo== grafo2) ) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye el grafo correcto con el “grafo_pequenyo.txt”
void testGrafoString1() {
    string nArch;
    Grafo grafo("redMuyPeq");
    int a[] = {9}; // comparac cnt y promedio que este en el rango correcto
    int* b = grafo.obtAdy(3);
    if (!(grafo.obtTotVrt()==10)|| (grafo.obtTotAdy(8) == 0) ||(b[0]== a[0] ) ) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 1 (newsimpletest) message=error message sample" << std::endl;
    }
    delete []b;
}

//Construye el grafo correcto con el “grafo_grande.txt”.
void testGrafoString2() {
    string nArch;
    Grafo grafo("redGrn");
    if (!(grafo.obtTotVrt()==1000)|| (grafo.obtTotAdy(12) == 54) ) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando el vértice existe.
void testXstVrt1() {
    int vrt = 0;
    Grafo grafo;
    bool result = grafo.xstVrt(vrt);
    if (result == true) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando no existe el vértice
void testXstVrt2() {
    int vrt = 0;
    Grafo grafo;
    bool result = grafo.xstVrt(2);
    if (result == true) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando la adyacencia sí existe.
void testXstAdy1() {
    int vrtO;
    int vrtD;
    Grafo grafo;
    bool result = grafo.xstAdy(vrtO, vrtD);
    if (result == false ) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando la adyacencia no existe.
void testXstAdy2() {
    int vrtO;
    int vrtD = 0;
    Grafo grafo; // usar el pequueño
    bool result = grafo.xstAdy(vrtO, 2);
    if (result == true ) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna un apuntador nulo (cero o NULL) cuando la lista de adyacencias está vacía. 
void testObtAdy1() {
    int vrt;
    Grafo grafo;
    int* result = grafo.obtAdy(vrt);
    if (!(result ==0)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy1  (newsimpletest) message=error message sample" << std::endl;
    }
}

// Retorna un apuntador a un arreglo de N posiciones cuando la lista de adyacencias tiene N elementos (basarse en Grafo(“grafo_pequenyo.txt”)
void testObtAdy2() {
    int vrt;
    Grafo grafo;
    int* result = grafo.obtAdy(vrt);
    if (!(result ==) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy2  (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna S cuando el vértice está en dicho estado.
void testObtEst1() {
    int vrt;
    Grafo grafo;
    E result = grafo.obtEst(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna I cuando el vértice está en dicho estado.
void testObtEst2() {
    int vrt;
    Grafo grafo;
    E result = grafo.obtEst(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna R cuando el vértice está en dicho estado.
void testObtEst3() {
    int vrt;
    Grafo grafo;
    E result = grafo.obtEst(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst3 (newsimpletest) message=error message sample" << std::endl;
    }
}


void testPromLongCmnsCrts1() {
    Grafo grafo;
    double result = grafo.promLongCmnsCrts();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts1 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testPromLongCmnsCrts2() {
    Grafo grafo;
    double result = grafo.promLongCmnsCrts();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts2 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testPromLongCmnsCrts3() {
    Grafo grafo;
    double result = grafo.promLongCmnsCrts();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts3 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCoeficienteAgrupamiento1() {
    int vrt;
    Grafo grafo;
    double result = grafo.coeficienteAgrupamiento(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO CoeficienteAgrupamiento1 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCoeficienteAgrupamiento2() {
    int vrt;
    Grafo grafo;
    double result = grafo.coeficienteAgrupamiento(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% FALLO EL METODO CoeficienteAgrupamiento2  (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (newsimpletest)" << std::endl;
    testConstructorGrafo1();
    std::cout << "%TEST_FINISHED% time=0 testGrafo (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (newsimpletest)" << std::endl;
    testConstructorGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testGrafo (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo2 (newsimpletest)" << std::endl;
    testGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testGrafo2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo3 (newsimpletest)" << std::endl;
    testGrafo3();
    std::cout << "%TEST_FINISHED% time=0 testGrafo3 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCentralidadIntermedial (newsimpletest)" << std::endl;
    testCentralidadIntermedial();
    std::cout << "%TEST_FINISHED% time=0 testCentralidadIntermedial (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento (newsimpletest)" << std::endl;
    testCoeficienteAgrupamiento();
    std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testModEst (newsimpletest)" << std::endl;
    testModEst();
    std::cout << "%TEST_FINISHED% time=0 testModEst (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtAdy (newsimpletest)" << std::endl;
    testObtAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtEst (newsimpletest)" << std::endl;
    testObtEst();
    std::cout << "%TEST_FINISHED% time=0 testObtEst (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtPrmAdy (newsimpletest)" << std::endl;
    testObtPrmAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtPrmAdy (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtTotAdy (newsimpletest)" << std::endl;
    testObtTotAdy();
    std::cout << "%TEST_FINISHED% time=0 testObtTotAdy (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtTotVrt (newsimpletest)" << std::endl;
    testObtTotVrt();
    std::cout << "%TEST_FINISHED% time=0 testObtTotVrt (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testPromLongCmnsCrts (newsimpletest)" << std::endl;
    testPromLongCmnsCrts();
    std::cout << "%TEST_FINISHED% time=0 testPromLongCmnsCrts (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstAdy (newsimpletest)" << std::endl;
    testXstAdy();
    std::cout << "%TEST_FINISHED% time=0 testXstAdy (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstVrt (newsimpletest)" << std::endl;
    testXstVrt();
    std::cout << "%TEST_FINISHED% time=0 testXstVrt (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

