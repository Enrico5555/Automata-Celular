/* 
 * File:   Visualizador.cpp
 * Author: Alan
 * 
 * Created on 2 de abril de 2015, 07:42 PM
 */

#include "Visualizador.h"
//#include<windows.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <string>
using namespace std;


Visualizador::Visualizador(const Grafo& g): grafo(g) {
}

Visualizador::~Visualizador() {
}

    double generaPos()
    {
    double rando = (double) rand() / (double) RAND_MAX;
    double rando2 = (double) rand() / (double) RAND_MAX;
    if (rando2 < 0.5){
        rando = rando *-1;
    }
        return rando;
    }
    
    void atragantador()    
    {
    double generadorX, generadorY;
     for ( int i=0;i<cntVrt;i++)
        {
        generadorX = generaPos();
        generadorY = generaPos();
        posX[i] = generadorX;
        posY[i] = generadorY;
        }
    }  

    void dibujar_circulo(double radio, double x, double y)
    {
      glBegin(GL_POLYGON); //empieza a dibujar puntos, cada llamada a la funcion glVertex dibuja un punto en pantalla
      for(double i = 0; i < 2 * 3.1415; i += (3.1415 / 24))
          glVertex2f(x + cos(i) * radio, y + sin(i) * radio);
      glEnd();
    }

    void linker()
    {
    for(int i=0;i<cntVrt;i++)
        {
        glLineWidth(2.0);
        glColor3f(1.0, 1.0, 1.0); //BLANCO
        glBegin(GL_LINES);
        glVertex2f(posX[i], posY[i]);
        glVertex2f(posX[i+1], posY[i+1]);
        glEnd();
        }
    }
    
    void recurCircles()
    {
    for(int i=0;i<cntVrt;i++){
    dibujar_circulo(0.02, posX[i], posY[i]);
    }

    }

    void estadoVrt()
    {
    glColor3f(0.0, 1.0, 0.0); //Color verde -> vertice suceptible
    glColor3f(1.0, 0.0, 0.0); //Color rojo -> vertice infectado
    glColor3f(1.0, 0.5, 0.0); //Color naranja-> vertice resistente
    }

    void display(void)
    {
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      atragantador();
      linker();
      glColor3f(0.0,1.0,0.0);
      recurCircles();
      glutSwapBuffers();
    }


void Visualizador::visualizar(int argc, char **argv) const {
    {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(750,500);
        int winPos = glutGet(GLUT_SCREEN_WIDTH)/2;
        winPos = 750 /2;
        glutInitWindowPosition(winPos, 0);
        glutCreateWindow("Automata-Celular @tete94 @konri9");
        glutDisplayFunc(display);
        glutMainLoop();
        if (posX != NULL) delete[] posX;
        if (posY != NULL) delete[] posY;
        return 0;
    }