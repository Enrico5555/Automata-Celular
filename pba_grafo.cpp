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
 
 void testConstructorGrafo1()
 {
     Grafo grafo(100, 15);
     if (grafo.obtTotVrt != 100 || grafo.obtPrmAdy() != 15)
     {
         printerror("testConstructorGrafo1");
     }
 }
 
 void testConstructorGrafo2()
 {
     Grafo grafo(1000, 15);
     if (grafo.obtTotVrt != 1000 || grafo.obtPrmAdy() != 15)
     {
         printerror("testConstructorGrafo2");
     }
 }

int main()
{
    std::cout << "%SUITE_STARTING% pba_lstady" << std::endl;
    std::cout << "%SUITE_STARTED%" << std::endl;
    printbegin("testConstructorGrafo1");
    testConstructorGrafo1();
    printend("testConstructorGrafo1");
    printbegin("testConstructorGrafo1");
    testConstructorGrafo2();
    printend("testConstructorGrafo1");
    
    std::cout << "%SUITE_FINISHED% time=0" << std::endl;
    return (EXIT_SUCCESS);
}
