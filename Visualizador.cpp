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
using namespace std;

Visualizador::Visualizador(const Grafo& g) : grafo(g) {
}

Visualizador::~Visualizador() {
}

void Visualizador::visualizar() const {
    int argx;
    char **argx;
    visualizator(argx, **argx);

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
        generadorX = generaPos();
        generadorY = generaPos();
        posX[i] = generadorX;
        posY[i] = generadorY;
    }
}

void Visualizador::dibujar_circulo(double radio, double x, double y) {
    glBegin(GL_POLYGON); //empieza a dibujar puntos, cada llamada a la funcion glVertex dibuja un punto en pantalla
    for (double i = 0; i < 2 * 3.1415; i += (3.1415 / 24))
        glVertex2f(x + cos(i) * radio, y + sin(i) * radio);
    glEnd();
}

void Visualizador::linker(int lineas) {
    for (int i = 0; i < lineas; i++) {
        glLineWidth(2.0);
        glColor3f(1.0, 1.0, 1.0); //BLANCO
        glBegin(GL_LINES);
        glVertex2f(posX[i], posY[i]);
        glVertex2f(posX[i + 1], posY[i + 1]);
        glEnd();
    }
}

void Visualizador::recurCircles(int vrt) {
    // voy a ir dibujando las lineas, luego circulos...
    //pedir el vertice mas popular
    int cont = 0, cntAdy;
    int *arr;
    while (grafo.obtTotVrt() < cont) {
        vrt = vrtPopular();
        arr = grafo.obtAdy(vrt);
        cntAdy = grafo.obtCntAdy(vrt);
        for (int i = 0; i < cntAdy; i++) {
            linker(i); 
        }
        for (int i = 0; i < cntAdy; i++) {
            dibujar_circulo(0.02, posX[i], posY[i]);
        }

    }
}

int Visualizador::vrtPopular() {
    int cant, numVrt, vrtPop;
    int cont = 0;
    numVrt = grafo.obtTotVrt();
    int *arrAdy = new int [numVrt];
    for (int i = 0; i < numVrt; i++) {
        cant = grafo.obtCntAdy(i);
        arrAdy[i] = cant;
    }
    
    while (numVrt>cont) {
        for (int i = 0; i < numVrt; i++) {
            if (arrAdy[i] > arrAdy[i + 1]) {
                vrtPop = i;
            }
            arrAdy[i] = 0;
        }
        cont++;
    }

    if (arrAdy != NULL) delete [] arrAdy;
    return vrtPop;
}

void Visualizador::estadoVrt(int vrt) {
    if (grafo.obtEst(vrt)) {
        glColor3f(0.0, 1.0, 0.0); //Color verde -> vertice suceptible
        recurCircles();
    }

    if (grafo.obtEst(vrt)) {
        glColor3f(1.0, 0.0, 0.0); //Color rojo -> vertice infectado
        recurCircles();
    }
    if (grafo.obtEst(vrt)) {

        glColor3f(1.0, 0.5, 0.0); //Color naranja-> vertice resistente
    }
}

void Visualizador::display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    atragantador();
    recurCircles();
    glutSwapBuffers();
}

void Visualizador::visualizator(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(750, 500);
    int winPos = glutGet(GLUT_SCREEN_WIDTH) / 2;
    winPos = 750 / 2;
    glutInitWindowPosition(winPos, 0);
    glutCreateWindow("Automata-Celular @tete94 @konri9");
    glutDisplayFunc(display);
    glutMainLoop();
    if (posX != NULL) delete[] posX;
    if (posY != NULL) delete[] posY;
    //return 0;
}
