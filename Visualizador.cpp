/*
 * File:   Visualizador.cpp
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 07:42 PM
 */

#include "Visualizador.h"
#include <windows.h>
#include <process.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
#include <algorithm> //max element


#ifndef NULL
#define NULL 0
#endif
using namespace std;

Visualizador *Visualizador::ptr;

Visualizador::Visualizador(const Grafo& g) : grafo(g), simulador(&grafo) {
    cntVrt = grafo.obtTotVrt();
    arrAdy = new int [cntVrt];
    posX = new double [cntVrt];
    posY = new double [cntVrt];
    ptr = this;
    /*this->argc = argc;
    this->argv = argv;*/
    atragantador();
}


Visualizador::~Visualizador() {
 if (arrAdy != NULL) delete [] arrAdy;
 if (posX != NULL) delete[] posX;
 if (posY != NULL) delete[] posY;
}

void Visualizador::visualizar() const {
    glutCreateWindow("Automata-Celular @tete94 @konri9");
    /*glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750, 500);
    int winPos = glutGet(GLUT_SCREEN_WIDTH) / 2;
    winPos = 750 / 2;
    glutInitWindowPosition(winPos, 0);
    glutCreateWindow("Automata-Celular @tete94 @konri9");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();*/
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
}

void Visualizador::visualizar(int cItr, int ios, double vsc, int vcf, double rc, double grc)
{
    simulador.simular(cItr, ios, vsc, vcf, rc, grc);
    sim = true;
    info.cItr = cItr;
    info.grc = grc;
    info.ios = ios;
    info.rc = rc;
    info.vcf = vcf;
    info.vcfmax = vcf;
    info.vsc = vsc;
    visualizar();
}

void Visualizador::simular()
{
    simulador.simular(info.cItr, info.ios, info.vsc, info.vcf, info.rc, info.grc);
    glutPostRedisplay();
}

double Visualizador::generaPos() {
    double rando = (double) rand() / (double) RAND_MAX;
    double rando2 = (double) rand() / (double) RAND_MAX;
    if (rando2 < 0.5) {
        rando = rando *-1;
    }
    return rando;
}

void Visualizador::atragantador() {
    double generadorX, generadorY;
    for (int i = 0; i < cntVrt; i++) {
        generadorX = generaPos();//0.2
        generadorY = generaPos();//-0.3
        posX[i] = generadorX;
        posY[i] = generadorY;
    }

    for (int i = 0; i < cntVrt; i++) {
       int cant = grafo.obtCntAdy(i);
        arrAdy[i] = cant;
    }

}

void Visualizador::dibujar_circulo(double radio, double x, double y) {
    glBegin(GL_POLYGON);
    for (double i = 0; i < 2 * 3.1415; i += (3.1415 / 24))
        glVertex2f(x + cos(i) * radio, y + sin(i) * radio);
    glEnd();
}

void Visualizador::linker(int lineas, int* arrV, int vrt) {
    for (int i = 0; i < lineas; i++) {
        glLineWidth(2.0);
        glColor3f(1.0, 1.0, 1.0); //BLANCO
        glBegin(GL_LINES);
        glVertex2f(posX[vrt], posY[vrt]);
        glVertex2f(posX[arrV[i]], posY[arrV[i]]);
        glEnd();
    }
}

void Visualizador::recurCircles() {
    int cont = 0, cntAdy;
    int *arr;
    while (cont < cntVrt) {
        //int vrt = vrtPopular();
        arr = grafo.obtAdy(cont);
        cntAdy = grafo.obtCntAdy(cont);
        linker(cntAdy, arr, cont);
        cont++;
        delete [] arr;
    }
    for (int i = 0; i < cntVrt; i++) {
        estadoVrt(i);
        dibujar_circulo(0.02, posX[i], posY[i]);
    }
}

int Visualizador::vrtPopular() {
    int vrtPop, cont = 0;
    while (cont < cntVrt) {
        for (int i = 0; i < cntVrt - 1; i++) {
            if (arrAdy[i] > arrAdy[i + 1]) {
                vrtPop = i;
            }
            else
            {
                vrtPop = i+1;
            }
        }
        cont++;
    }
    arrAdy[vrtPop] = 0;
    return vrtPop;
}

void Visualizador::estadoVrt(int vrt) {
    if (grafo.obtEst(vrt) == Grafo::S) {
        glColor3f(0.0, 1.0, 0.0); //Color verde -> vertice suceptible
    }
    if (grafo.obtEst(vrt) == Grafo::I) {
        glColor3f(1.0, 0.0, 0.0); //Color rojo -> vertice infectado
    }
    if (grafo.obtEst(vrt) == Grafo::R) {
        glColor3f(1.0, 0.5, 0.0); //Color naranja-> vertice resistente
    }
}

void Visualizador::keyboard(unsigned char key, int x, int y)
{
    if (ptr->sim)
    {
        if (key == 13)
        {
            ptr->info.ios = 0;
            ptr->info.vcf--;
            if (ptr->info.vcf < 0) ptr->info.vcf = ptr->info.vcfmax;
            ptr->simular();
        }
    }
}

void Visualizador::display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ptr->recurCircles();
    glutSwapBuffers();
}
