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
 
//Construye el grafo correcto con el “grafo_pequenyo.txt”. 
 void testConstructorGrafo1()
 {
     Grafo grafo(100, 15);
     if (grafo.obtTotVrt() != 100 || grafo.obtPrmAdy() != 15)
     {//imi
         printerror("testConstructorGrafo1");
     }
 }
 
 //Construye una red con la cantidad de vértices y el promedio de adyacencias por vértice correctos cuando cntVrt == 1000 y prmAdy == 15.
 void testConstructorGrafo2()
 {
     Grafo grafo(1000, 15);
     if (grafo.obtTotVrt() != 1000 || grafo.obtPrmAdy() != 15)
     {
         printerror("testConstructorGrafo2");
     }
 }

 void testGrafo2() {
    const Grafo& orig;
    Grafo grafo(orig);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo2 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testGrafo3() {
    string nArch;
    Grafo grafo(nArch);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testGrafo3 (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCentralidadIntermedial() {
    int vrt;
    Grafo grafo;
    double result = grafo.centralidadIntermedial(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCentralidadIntermedial (newsimpletest) message=error message sample" << std::endl;
    }
}

void testCoeficienteAgrupamiento() {
    int vrt;
    Grafo grafo;
    double result = grafo.coeficienteAgrupamiento(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testCoeficienteAgrupamiento (newsimpletest) message=error message sample" << std::endl;
    }
}

void testModEst() {
    int vrt;
    E ne;
    Grafo grafo;
    grafo.modEst(vrt, ne);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testModEst (newsimpletest) message=error message sample" << std::endl;
    }
}

void testObtAdy() {
    int vrt;
    Grafo grafo;
    int* result = grafo.obtAdy(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtAdy (newsimpletest) message=error message sample" << std::endl;
    }
}

void testObtEst() {
    int vrt;
    Grafo grafo;
    E result = grafo.obtEst(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtEst (newsimpletest) message=error message sample" << std::endl;
    }
}

void testObtPrmAdy() {
    Grafo grafo;
    double result = grafo.obtPrmAdy();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtPrmAdy (newsimpletest) message=error message sample" << std::endl;
    }
}

void testObtTotAdy() {
    Grafo grafo;
    int result = grafo.obtTotAdy();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtTotAdy (newsimpletest) message=error message sample" << std::endl;
    }
}

void testObtTotVrt() {
    Grafo grafo;
    int result = grafo.obtTotVrt();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testObtTotVrt (newsimpletest) message=error message sample" << std::endl;
    }
}

void testPromLongCmnsCrts() {
    Grafo grafo;
    double result = grafo.promLongCmnsCrts();
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testPromLongCmnsCrts (newsimpletest) message=error message sample" << std::endl;
    }
}

void testXstAdy() {
    int vrtO;
    int vrtD;
    Grafo grafo;
    bool result = grafo.xstAdy(vrtO, vrtD);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testXstAdy (newsimpletest) message=error message sample" << std::endl;
    }
}

void testXstVrt() {
    int vrt;
    Grafo grafo;
    bool result = grafo.xstVrt(vrt);
    if (true /*check result*/) {
        std::cout << "%TEST_FAILED% time=0 testname=testXstVrt (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo (newsimpletest)" << std::endl;
    testGrafo();
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

