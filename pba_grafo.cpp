/*
 * File:   pba_lstady.cpp
 * Author: Konrad
 *
 * Created on Apr 13, 2015, 4:42:18 PM
 */

#include <stdlib.h>
#include <iostream>
#include "Grafo.h"
#include "LstAdy.cpp"
#define null 0

#define printbegin(a) std::cout << "%TEST_STARTED% " << a << " (grafo)" << std::endl;
#define printerror(a) std::cout << "%TEST_FAILED% " << a << " (grafo) message=error message sample" << std::endl;
#define printend(a) std::cout << "%TEST_FINISHED% time=0 " << a << " (pba_lstady)" << std::endl;

/*
 * Simple C++ Test Suite
 */

//borrar ifn ocupamos

/* TIPO PÚBLICO DE ESTADOS DE VÉRTICES */
enum E { // representa el tipo de estados de la red de infección
    S, // representa un vértice susceptible de infección
    I, // representa un vértice infectado
    R, // representa un vértice resistente
};

//Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 100 y prmAdy ==15.

void testConstructorGrafo1() {
    Grafo grafo(100, 15); // prom +- desviac ... +-3 (listo)
    if (grafo.obtTotVrt() != 100 || !(15 < grafo.obtPrmAdy() < 18)) {
        std::cout << "%TEST_FAILED% FALLO EL CONNSTRUCTOR GRAFO 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye una red con la cantidad de vértices y el promedio de
//adyacencias por vértice correctos cuando cntVrt == 1000 y prmAdy ==15.

void testConstructorGrafo2() {
    Grafo grafo(1000, 15); // prom +- desviac ... +-3 (listo)
    if (grafo.obtTotVrt() != 1000 || !(15 < grafo.obtPrmAdy() < 18)) {
        std::cout << "%TEST_FAILED% FALLO EL CONNSTRUCTOR GRAFO 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye una copia idéntica a Grafo(100,15).

void testConstGrafo1() {
    Grafo grafo(100, 15); //usar operator ==
    const Grafo& orig;
    Grafo grafo2(orig);
    if (!(grafo == grafo2)) { // listo
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye una copia idéntica a Grafo(1000,15).

void testConstGrafo2() {
    Grafo grafo(1000, 15); // op ==
    const Grafo& orig;
    Grafo grafo2(orig);
    if (!(grafo == grafo2)) { //(listo)
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye el grafo correcto con el “grafo_pequenyo.txt”

void testGrafoString1() {
    string nArch;
    Grafo grafo("redMuyPeq");
    int a[] = {9}; // comparac cantidad y promedio que este en el rango correcto
    int* b = grafo.obtAdy(3);
    if (!(grafo.obtTotVrt() == 10) || (grafo.obtTotAdy(8) == 0) || (b[0] == a[0])) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 1 (newsimpletest) message=error message sample" << std::endl;
    }
    delete []b;
}

//Construye el grafo correcto con el “grafo_grande.txt”.

void testGrafoString2() {
    string nArch;
    Grafo grafo("redGrn");
    if (!(grafo.obtTotVrt() == 1000) || (grafo.obtTotAdy(12) == 54)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando el vértice existe.
// ********REVISAR ESTO**********

void testXstVrt1() {
    int vrt = 0;
    Grafo grafo(1, 0); // se crea el grafo con un vertice sin adyacencias
    bool result = grafo.xstVrt(vrt); // deberia ser true
    if (!(result == true)) { // pues tiene que tener el vertice 0, si es falso entonces falla
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando no existe el vértice

void testXstVrt2() {
    Grafo grafo(1, 0); // como no añadi el vertice me deberia de dar false
    Grafo grafo; // como no añadi el vertice me deberia de dar false
    bool result = grafo.xstVrt(2);
    if (!(result == false)) { // 
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando la adyacencia sí existe.

void testXstAdy1() {
    int vrtO = 3;
    int vrtD = 9;
    Grafo grafo("redMuyPeq");
    bool result = grafo.xstAdy(vrtO, vrtD);
    if (!(result == true)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando la adyacencia no existe.

void testXstAdy2() {
    int vrtO = 3;
    int vrtD = 10;
    Grafo grafo("redMuyPeq"); // usar el pequueño
    bool result = grafo.xstAdy(vrtO, vrtD);
    if (!(result == true)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy2 (newsimpletest) message=error message sample" << std::endl;

    }
}
//Prueba git
//Retorna un apuntador nulo (cero o NULL) cuando la lista de adyacencias está vacía. 

void testObtAdy1() {
    int vrt = 0;
    Grafo grafo;
    int* result = grafo.obtAdy(vrt);
    if (!(result == null)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy1  (newsimpletest) message=error message sample" << std::endl;
    }
}

// Retorna un apuntador a un arreglo de N posiciones cuando la lista de adyacencias tiene N elementos (basarse en Grafo(“grafo_pequenyo.txt”)

void testObtAdy2() {
    int vrt = 5;
    Grafo grafo("redMuyPeq");
    int* result = grafo.obtAdy(vrt);
    if (!(result == 3)) { // not sure
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy2  (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna S cuando el vértice está en dicho estado.

void testObtEst1() {
    int vrt;
    Grafo grafo;
    E res = grafo.obtEst(vrt);
    if (!(res == S)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna I cuando el vértice está en dicho estado.

void testObtEst2() {
    int vrt;
    Grafo grafo;
    E res = grafo.obtEst(vrt);
    if (!(res == I)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna R cuando el vértice está en dicho estado.

void testObtEst3() {
    int vrt;
    Grafo grafo;
    E res = grafo.obtEst(vrt);
    if (!(res == R)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtEst3 (newsimpletest) message=error message sample" << std::endl;
    }
}
//Probando git
//***** voy por aca *******
// Genera el valor correcto con el “grafo_pequenyo.txt”.

void testPromLongCmnsCrts1() {
    Grafo grafo("redMuyPeq");
    double res = grafo.promLongCmnsCrts();
    if (!(res ==)) { // falta añadir el valor
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts1 (newsimpletest) message=error message sample" << std::endl;
    }
}

// Genera el valor correcto con el “grafo_grande.txt”.

void testPromLongCmnsCrts2() {
    Grafo grafo("redGrn");
    double res = grafo.promLongCmnsCrts();
    if (!(res ==)) { // falta añadir el valor
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//El vértice indicado del “grafo_pequenyo.txt”.

void testCoeficienteAgrupamiento1() {
    int vrt = 10;
    Grafo grafo;
    double res = grafo.coeficienteAgrupamiento(vrt);
    if (!(res == 0)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO CoeficienteAgrupamiento1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//El vértice indicado del “grafo_grande.txt”.

void testCoeficienteAgrupamiento2() {
    int vrt = 12;
    Grafo grafo;
    double res = grafo.coeficienteAgrupamiento(vrt);
    if (!(res == 0)) { // aqui seria el resultado... habria que hacerlo a pata
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
    testConstGrafo1();
    std::cout << "%TEST_FINISHED% time=0 testGrafo2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafo3 (newsimpletest)" << std::endl;
    testConstGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testGrafo3 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafoString1(newsimpletest)" << std::endl;
    testGrafoString1
    std::cout << "%TEST_FINISHED% time=0 testGrafoString1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testGrafoString2(newsimpletest)" << std::endl;
    testGrafoString2
    std::cout << "%TEST_FINISHED% time=0 testGrafoString2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstVrt1 (newsimpletest)" << std::endl;
    testXstVrt1();
    std::cout << "%TEST_FINISHED% time=0 testXstVrt1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstVrt2 (newsimpletest)" << std::endl;
    testXstVrt2();
    std::cout << "%TEST_FINISHED% time=0 testXstVrt2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstAdy1 (newsimpletest)" << std::endl;
    testXstAdy1();
    std::cout << "%TEST_FINISHED% time=0 testXstAdy1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testXstAdy2 (newsimpletest)" << std::endl;
    testXstAdy2();
    std::cout << "%TEST_FINISHED% time=0 testXstAdy2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtAdy1 (newsimpletest)" << std::endl;
    testObtAdy1();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtAdy2 (newsimpletest)" << std::endl;
    testObtAdy2();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtEst1 (newsimpletest)" << std::endl;
    testObtEst1();
    std::cout << "%TEST_FINISHED% time=0 testObtEst1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtEst2 (newsimpletest)" << std::endl;
    testObtEst2();
    std::cout << "%TEST_FINISHED% time=0 testObtEst2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testObtEst3 (newsimpletest)" << std::endl;
    testObtEst3();
    std::cout << "%TEST_FINISHED% time=0 testObtEst3 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testPromLongCmnsCrts1 (newsimpletest)" << std::endl;
    testPromLongCmnsCrts1();
    std::cout << "%TEST_FINISHED% time=0 testPromLongCmnsCrts1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testPromLongCmnsCrts2 (newsimpletest)" << std::endl;
    testPromLongCmnsCrts2();
    std::cout << "%TEST_FINISHED% time=0 testPromLongCmnsCrts2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento1 (newsimpletest)" << std::endl;
    testCoeficienteAgrupamiento1();
    std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento2 (newsimpletest)" << std::endl;
    testCoeficienteAgrupamiento2();
    std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento2 (newsimpletest)" << std::endl;

    // el resto de metodos se da porque esten buenos

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
    //pba git
}

