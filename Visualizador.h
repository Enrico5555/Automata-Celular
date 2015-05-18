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

    /*Genera una posicion aleatoria para las coordenadas)*/
    double generaPos();
    
    /* Rellena los vectores con valores generados al azar*/
    void atragantador();
    
    /*Dibuja un circulo a partir del radio y las coordenadas*/
    void dibujar_circulo(double radio, double x, double y);
    
    /*Genera las lineas entre vertices*/
    void linker();
    
    /*Dibuja los circulos, basandose en las posiciones ya generadas */
    void recurCircles ();
    
    /*Asigna el color al circulo, dependiendo de su estado*/
    void estadoVrt();
    
    /*Tipo de main para las figuras*/
    void display(void);
        
    // REQ: que el grafo asociado en el constructor esté bien construido.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar(int argc, char **argv) const;
    
    
private:
    const Grafo& grafo;
    
    /*Variables globales que contienen las posiciones asignadas*/
    int cntVrt = 10;
    double *posX = new double [cntVrt];// vector con las posiciones en X
    double *posY = new double [cntVrt];// vector con las posiciones en Y
    
    
};

#endif	/* VISUALIZADOR_H */

