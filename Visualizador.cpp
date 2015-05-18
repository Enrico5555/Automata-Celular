/* 
 * File:   Visualizador.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 07:42 PM
 */

#include "Visualizador.h"
#include<windows.h>
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

Visualizador::Visualizador(const Grafo& g) : grafo(g) {
    arrAdy = new int [cntVrt];
    posX = new double [cntVrt];
    posY = new double [cntVrt];
    cntVrt = grafo.obtTotVrt();
    
    int argc = 0;
    glutInit(&argc, NULL);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750, 500);
    int winPos = glutGet(GLUT_SCREEN_WIDTH) / 2;
    winPos = 750 / 2;
    glutInitWindowPosition(winPos, 0);
    glutCreateWindow("Automata-Celular @tete94 @konri9");
    glutDisplayFunc(display);
    ptr = this;
    glutMainLoop();

    //return 0;
}


Visualizador::~Visualizador() {
 if (arrAdy != NULL) delete [] arrAdy;
 if (posX != NULL) delete[] posX;
 if (posY != NULL) delete[] posY;
}

void Visualizador::visualizar() const {

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


void Visualizador::recurCircles(int vrt) {
    int cont = 0, cntAdy;
    int *arr;
    while (cont < cntVrt) {
        vrt = vrtPopular();
        arr = grafo.obtAdy(vrt);
        cntAdy = grafo.obtCntAdy(vrt);
        linker(cntAdy, arr, vrt);
        cont++;
        delete [] arr;
    }
    for (int i = 0; i < cntAdy; i++) {
        estadoVrt(i);
        dibujar_circulo(0.02, posX[i], posY[i]);
    }
}

int Visualizador::vrtPopular() {
    int vrtPop, cont = 0;
    while (cntVrt > cont) {
        for (int i = 0; i < cntVrt; i++) {
            if (arrAdy[i] > arrAdy[i + 1]) {
                vrtPop = i;
            }
            arrAdy[i] = 0;
        }
        cont++;
    }
    return vrtPop;
}

void Visualizador::estadoVrt(int vrt) {
    if (grafo.obtEst(vrt)) {
        glColor3f(0.0, 1.0, 0.0); //Color verde -> vertice suceptible
        recurCircles(vrt);
    }

    if (grafo.obtEst(vrt)) {
        glColor3f(1.0, 0.0, 0.0); //Color rojo -> vertice infectado
        recurCircles(vrt);
    }
    if (grafo.obtEst(vrt)) {
        glColor3f(1.0, 0.5, 0.0); //Color naranja-> vertice resistente
        recurCircles(vrt);
    }
}

void Visualizador::display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ptr->atragantador();
    ptr->vrtA = ptr->vrtPopular();
    ptr->recurCircles(ptr->vrtA);
    glutSwapBuffers();
}
