/* 
 * File:   Visualizador.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 07:42 PM
 */

#ifndef VISUALIZADOR_H
#define	VISUALIZADOR_H

#include "Grafo.h"

class Visualizador {
    // Permite la visualización gráfica de una instancia de Grafo.
    
public:
    Visualizador(const Grafo& g);
    ~Visualizador();

        
    // REQ: que el grafo asociado en el constructor esté bien construido.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar() const;
    
    
private:
    const Grafo& grafo;
    /*Estos son mis metodos*/
	
    /*Genera una posicion aleatoria para las coordenadas)*/
    double generaPos();
    
    /* Rellena los vectores con valores generados al azar*/
    void atragantador();
    
    /*Dibuja un circulo a partir del radio y las coordenadas*/
    void dibujar_circulo(double radio, double x, double y);
    
    /*Genera las lineas entre vertices*/
    void linker(int lineas);
    
    /*Dibuja los circulos, basandose en las posiciones ya generadas */
    void recurCircles (int vrt);
    
    /*Revisa toda la lista de adyacencia y devuelve el indice del vertice con mas adyacencias*/
    int vrtPopular();
    
    /*Asigna el color al circulo, dependiendo de su estado*/
    void estadoVrt(int vrt);
    
    /*Tipo de main para las figuras*/
    static void display(void);
    static Visualizador *ptr;

	
    /*Variables globales que contienen las posiciones asignadas*/
    LstAdy lstAdy;
    //Grafo grafo;
    int vrtA ; // vertice actual
    int cntVrt = 0;
    double *posX = NULL;// vector con las posiciones en X
    double *posY = NULL;// vector con las posiciones en Y
    //int numVrt = grafo.obtTotVrt();
    int *arrAdy = NULL;
    
    friend static void display(void);
};

#endif	/* VISUALIZADOR_H */

