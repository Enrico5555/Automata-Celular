/* 
 * File:   pba_lstady.cpp
 * Author: Konrad
 *
 * Created on Apr 13, 2015, 4:42:18 PM
 */
#include <stdlib.h>
#include <iostream>
#include "LstAdy.h"
#define null 0

/*
 * Simple C++ Test Suite
 */

//Probar que construye bien una lista vacia ---> Cero adyacencias
void testLstAdy1() { 
    LstAdy lstAdy; // crea un objeto
    int cant = lstAdy.obtCntAdy(); //llamar al metodo obtCntAdy
    if (cant != 0) {
        std::cout << "%TEST_FAILED% FALLO EL CONSTRUCTOR ESTANDAR (pba_lstady) message=error message sample" << std::endl;
    }
}

// Probar que construye bien una lista vacia
void testLstAdy2() {
    const LstAdy orig;
    LstAdy lstAdy(orig);// esta raroq ue funcione con lstady y con grafo no
    int cant = lstAdy.obtCntAdy();
    if (cant != 0) {
        std::cout << "%TEST_FAILED% FALLO EL CONTRUCTOR DE COPIAS 1(pba_lstady) message=error message sample" << std::endl;
    }
}

// Probar que copia bien una lista con un elemento
void testLstAdy3() {
    LstAdy orig;
    orig.agr(0);
    LstAdy lstAdy(orig);
    if (!(orig == lstAdy) ) {
    //if (false)
    //{
    std::cout << "%TEST_FAILED% FALLO EL CONTRUCTOR DE COPIAS 2(pba_lstady) message=error message sample" << std::endl;
    }
}

// Probar que copia bien una lista con dos elementos
void testLstAdy4() {
    LstAdy orig;
    orig.agr(3);
    orig.agr(2);
    LstAdy lstAdy(orig);
    if (!(orig == lstAdy) ) {
        std::cout << "%TEST_FAILED% FALLO EL CONTRUCTOR DE COPIAS 3(pba_lstady) message=error message sample" << std::endl;
    }
}

//Probar que agrega bien una adyacencia a una lista vacía
void testAgr1() {
    int nady = 0;
    LstAdy lstAdy;
    lstAdy.agr(nady);
    int cant =lstAdy.obtCntAdy();
    if (cant != 1) {
        std::cout << "%TEST_FAILED% FALLO EL METODO AGR1 (pba_lstady) message=error message sample" << std::endl;
    }
}

//Probar que agrega bien una adyacencia a una lista 
void testAgr2() {
    int nady = 0;
    int nudo = 2; 
    LstAdy lstAdy;
    lstAdy.agr(nady);
    lstAdy.agr(nudo);
    int cant = lstAdy.obtCntAdy();
    if (cant != 2 ) {
        std::cout << "%TEST_FAILED% FALLO EL METODO AGR2(pba_lstady) message=error message sample" << std::endl;
    }
}


//Probar que devuelve false cuando se busca en una lista vacía
void testBus1() {
    int ady = 0;
    LstAdy lstAdy;
    bool result = lstAdy.bus(ady);
    if (result!= false) {
        std::cout << "%TEST_FAILED% FALLO EL METODO BUS1 (pba_lstady) message=error message sample" << std::endl;
    }
}

//Probar que devuelve false cuando se busca una adyacencia que no existe en una lista con una adyacencia
void testBus2() {
    int ady = 0;
    LstAdy lstAdy;
    lstAdy.agr(ady);
    bool result = lstAdy.bus(5);
    if (result != false) {
        std::cout << "%TEST_FAILED% FALLO EL METODO BUS2 (pba_lstady) message=error message sample" << std::endl;
    }
}

//Probar que devuelve false cuando se busca una adyacencia que no existe en una lista con dos adyacencias
void testBus3() {
    int ady = 0;
    LstAdy lstAdy;
    lstAdy.agr(ady);
    lstAdy.agr(6);
    bool result = lstAdy.bus(5);
    if (result != false) {
        std::cout << "%TEST_FAILED% FALLO EL METODO BUS3 (pba_lstady) message=error message sample" << std::endl;
    }
}
 
//Probar que devuelve true cuando se busca una adyacencia que sí existe en una lista con una adyacencia. 
void testBus4() {
   int ady = 0;
    LstAdy lstAdy;
    lstAdy.agr(ady);
    bool result = lstAdy.bus(ady);
    if (result != true) {
        std::cout << "%TEST_FAILED% FALLO EL METODO BUS4 (pba_lstady) message=error message sample" << std::endl;
    }
}
  
//Probar que devuelve true cuando se busca una adyacencia que sí existe en una lista con dos adyacencias.
void testBus5() {
    int ady = 0;
    LstAdy lstAdy;
    lstAdy.agr(ady);
    lstAdy.agr(6);
    bool result = lstAdy.bus(ady);
    if (result != true) {
        std::cout << "%TEST_FAILED% FALLO EL METODO BUS5 (pba_lstady) message=error message sample" << std::endl;
    }
}
   

//Probar que devuelve un apuntador null cuando la lista está vacía.
void testObtAdy1() {
    LstAdy lstAdy;
    int* result = lstAdy.obtAdy();
    if (result != null) { 
        std::cout << "%TEST_FAILED% FALLO EL METODO OBTADY1 (pba_lstady) message=error message sample" << std::endl;
    }
}

 //Probar que devuelve un arreglo de un elemento cuando la lista tiene un elemento.
void testObtAdy2() {
    LstAdy lstAdy;
    lstAdy.agr(0);
    int* result = lstAdy.obtAdy();
    if (result[0] != 0){
        std::cout << "%TEST_FAILED% FALLO EL METODO OBTADY2 (pba_lstady) message=error message sample" << std::endl;
    }
    delete [] result;
}

//Probar que devuelve un arreglo con dos elementos cuando la lista tiene dos elementos
void testObtAdy3() {
    LstAdy lstAdy;
    lstAdy.agr(0);
    lstAdy.agr(1);
    int* result = lstAdy.obtAdy();
    if (result[0] != 0 &&  result[1] != 1){
        std::cout << "%TEST_FAILED% FALLO EL METODO OBTADY3 (pba_lstady) message=error message sample" << std::endl;
    }
      delete [] result;
} 

/* Se supondrá que el método “obtCntAdy�? es correcto.
 *  Se supondrá que el “operator==�? es correcto.
 * Se supondrá que el destructor funciona correctamente.*/ 


int main(int argc, char** argv) {
    std::cout << "%SUITE_STARTING% pba_lstady" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;

    std::cout << "%TEST_STARTED% testLstAdy1 (pba_lstady)" << std::endl;
    testLstAdy1();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy1 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testLstAdy2 (pba_lstady)" << std::endl;
    testLstAdy2();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy2 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testLstAdy3 (pba_lstady)" << std::endl;
    testLstAdy3();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy3 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testLstAdy4 (pba_lstady)" << std::endl;
    testLstAdy4();
    std::cout << "%TEST_FINISHED% time=0 testLstAdy4 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testAgr1 (pba_lstady)" << std::endl;
    testAgr1();
    std::cout << "%TEST_FINISHED% time=0 testAgr1 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testAgr2 (pba_lstady)" << std::endl;
    testAgr2();
    std::cout << "%TEST_FINISHED% time=0 testAgr2 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testBus1 (pba_lstady)" << std::endl;
    testBus1();
    std::cout << "%TEST_FINISHED% time=0 testBus1 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testBus2 (pba_lstady)" << std::endl;
    testBus2();
    std::cout << "%TEST_FINISHED% time=0 testBus2 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testBus3 (pba_lstady)" << std::endl;
    testBus3();
    std::cout << "%TEST_FINISHED% time=0 testBus3 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testBus4 (pba_lstady)" << std::endl;
    testBus4();
    std::cout << "%TEST_FINISHED% time=0 testBus4 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testBus5 (pba_lstady)" << std::endl;
    testBus5();
    std::cout << "%TEST_FINISHED% time=0 testBus5 (pba_lstady)" << std::endl;
    
    std::cout << "%TEST_STARTED% testObtAdy1 (pba_lstady)" << std::endl;
    testObtAdy1();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy1 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testObtAdy2 (pba_lstady)" << std::endl;
    testObtAdy2();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy2 (pba_lstady)" << std::endl;

    std::cout << "%TEST_STARTED% testObtAdy3 (pba_lstady)" << std::endl;
    testObtAdy3();
    std::cout << "%TEST_FINISHED% time=0 testObtAdy3 (pba_lstady)" << std::endl;

   
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;

    return (EXIT_SUCCESS);
}

