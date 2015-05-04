/*
 * File:   pba_lstady.cpp
 * Author: Konrad
 *
 * Created on Apr 13, 2015, 4:42:18 PM
 */

#include "Grafo.h" 
#include <stdlib.h>
#include <iostream>
#define null 0

/*
 * Simple C++ Test Suite
 */


/*Construye una red con la cantidad de vértices y el promedio de
adyacencias por vértice correctos cuando cntVrt == 100 y prmAdy ==15.*/

void testConstGrafo1() {
    Grafo grafo(100, 15); // prom +- dmeesviac ... +-3 (listo)
    if (grafo.obtTotVrt() != 100 || !(15 < grafo.obtPrmAdy() < 18)) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR GRAFO 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

/*Construye una red con la cantidad de vértices y el promedio de
adyacencias por vértice correctos cuando cntVrt == 1000 y prmAdy ==15.*/
void testConstGrafo2() {
    Grafo grafo(1000, 15); // prom +- desviac ... +-3 (listo)
    if (grafo.obtTotVrt() != 1000 || !(15 < grafo.obtPrmAdy() < 18)) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR GRAFO 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye una copia idéntica a Grafo(100,15).
void testConstCopiasGrafo1() {
    Grafo orig(100, 15); // construyo orig
    Grafo grafo(orig);// copio orig
    if (!(orig == grafo)) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye una copia idéntica a Grafo(1000,15).
void testConstCopiasGrafo2() {
    Grafo orig(1000, 15); 
    Grafo grafo(orig); 
    if (!(orig == grafo)) { 
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR DE COPIAS 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Construye el grafo correcto con el “redMuyPeq.txt”
void testConstGrafoString1() {
    string nArch = "redMuyPeq.txt";
    Grafo grafo(nArch); 
    /*int a[] = {9}; // comparac cantidad y promedio que este en el rango correcto
    int* b = grafo.obtAdy(9);*/
    if (!(grafo.obtTotVrt() == 10) || (grafo.obtCntAdy(8) == 0)){ // || (b[0] == a[0])) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 1 (newsimpletest) message=error message sample" << std::endl;
    }
    //delete []b;
}

//Construye el grafo correcto con el “redGrn.txt”.
void testConstGrafoString2() {
    string nArch = "redGrn.txt";
    Grafo grafo(nArch);
    if (!(grafo.obtTotVrt() == 1000) || (grafo.obtCntAdy(12) == 54)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO STRING 2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando el vértice existe.
void testXstVrt1() {
    int vrt = 1;
    Grafo grafo(10, 1); // Devuelve true si vrt esta entre 0 y cntVrt
    bool res = grafo.xstVrt(vrt); 
    if (!(res == true)) { 
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando no existe el vértice
void testXstVrt2() {    
    int vrt = 11;
    Grafo grafo(10, 1); 
    bool res = grafo.xstVrt(vrt);
    if (!(res == false)) { // 
        std::cout << "%TEST_FAILED% FALLO EL METODO XstVrt2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna true cuando la adyacencia sí existe.
void testXstAdy1() {
    int vrtO = 1, vrtD = 9;
    Grafo grafo("redMuyPeq.txt");
    bool res = grafo.xstAdy(vrtO, vrtD);
    if (!(res == true)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy1 (newsimpletest) message=error message sample" << std::endl;
    }
}

//Retorna false cuando la adyacencia no existe.
void testXstAdy2() {
    int vrtO = 1,vrtD = 5;
    Grafo grafo("redMuyPeq.txt"); // usar el pequueño
    bool res = grafo.xstAdy(vrtO, vrtD);
    if (!(res == false)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO XstAdy2 (newsimpletest) message=error message sample" << std::endl;

    }
}

//Retorna un apuntador nulo (cero o NULL) cuando la lista de adyacencias está vacía. 
void testObtAdy1() {
    int vrt = 0;
    Grafo grafo("redMuyPeq.txt"); 
    int* res = grafo.obtAdy(vrt);
    if (!(res == 0)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy1  (newsimpletest) message=error message sample" << std::endl;
    }
    delete[] res;
}

/*Retorna un apuntador a un arreglo de N posiciones cuando la lista de adyacencias 
tiene N elementos (basarse en Grafo(“grafo_pequenyo.txt”)*/
void testObtAdy2() {
    int vrt = 5;
    Grafo grafo("redMuyPeq.txt"); 
    int* res = grafo.obtAdy(vrt);   
    if (!(res[0] == 3)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO ObtAdy2  (newsimpletest) message=error message sample" << std::endl;
    }
    delete[] res ;
}


// Genera el valor correcto con el “grafo_pequenyo.txt”.
void testPromLongCmnsCrts1() {
    Grafo grafo("redMuyPeq.txt");
    double res = grafo.promLongCmnsCrts();
    if (!(res == )) { // falta añadir el valor
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts1 (newsimpletest) message=error message sample" << std::endl;
   }
}

// Genera el valor correcto con el “grafo_grande.txt”.
void testPromLongCmnsCrts2() {
    Grafo grafo("redGrn.txt");
    double res = grafo.promLongCmnsCrts();
    if (!(res ==)) { // falta añadir el valor
        std::cout << "%TEST_FAILED% FALLO EL METODO PromLongCmnsCrts2 (newsimpletest) message=error message sample" << std::endl;
    }
}

//El vértice indicado del “grafo_pequenyo.txt”.
void testCoeficienteAgrupamiento1() {
    int vrt = 8;
    Grafo grafo("redMuyPeq.txt");
    double res = grafo.coeficienteAgrupamiento(vrt);
    if (!(res == 0)) {
        std::cout << "%TEST_FAILED% FALLO EL METODO CoeficienteAgrupamiento1 (newsimpletest) message=error message sample" << std::endl;
    }
}

int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% newsimpletest" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% tesConstGrafo1(newsimpletest)" << std::endl;
    testConstGrafo1();
    std::cout << "%TEST_FINISHED% time=0 testConstGrafo1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testConstGrafo2 (newsimpletest)" << std::endl;
    testConstGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testConstGrafo2(newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testConstCopiasGrafo1 (newsimpletest)" << std::endl;
   testConstCopiasGrafo1();
    std::cout << "%TEST_FINISHED% time=0 testConstCopiasGrafo1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testConstCopiasGrafo2 (newsimpletest)" << std::endl;
    testConstCopiasGrafo2();
    std::cout << "%TEST_FINISHED% time=0 testConstCopiasGrafo2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testConstGrafoString1(newsimpletest)" << std::endl;
    testConstGrafoString1();
    std::cout << "%TEST_FINISHED% time=0 testConstGrafoString1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testConstGrafoString2(newsimpletest)" << std::endl;
    testConstGrafoString2();
    std::cout << "%TEST_FINISHED% time=0 testConstGrafoString2 (newsimpletest)" << std::endl;

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

    std::cout << "%TEST_STARTED% testPromLongCmnsCrts1 (newsimpletest)" << std::endl;
    testPromLongCmnsCrts1();
    std::cout << "%TEST_FINISHED% time=0 testPromLongCmnsCrts1 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testPromLongCmnsCrts2 (newsimpletest)" << std::endl;
    testPromLongCmnsCrts2();
    std::cout << "%TEST_FINISHED% time=0 testPromLongCmnsCrts2 (newsimpletest)" << std::endl;

    std::cout << "%TEST_STARTED% testCoeficienteAgrupamiento1 (newsimpletest)" << std::endl;
    testCoeficienteAgrupamiento1();
    std::cout << "%TEST_FINISHED% time=0 testCoeficienteAgrupamiento1 (newsimpletest)" << std::endl;

    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);

}

