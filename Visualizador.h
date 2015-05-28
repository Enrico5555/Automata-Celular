/* 
 * File:   Visualizador.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 07:42 PM
 */

#ifndef VISUALIZADOR_H
#define	VISUALIZADOR_H

#include "Simulador.h"
#include "Grafo.h"

class Visualizador {
    // Permite la visualización gráfica de una instancia de Grafo.

public:
    // EFE: construye un visualizador para g.
    Visualizador(Grafo& g, Simulador& s);

    ~Visualizador();

    // REQ: *this haya sido construido con un grafo y un simulador asociado.
    // MOD: el grafo asociado por medio del simulador miembro.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar() const;

    // REQ: *this haya sido construido con un grafo y un simulador asociado.
    // MOD: el grafo asociado por medio del simulador miembro.
    // EFE: aplica al grafo asociado cntItr transformaciones con base en los 
    //      siguientes parámetros (por medio del simulador asociado):
    //      cItr > 1000: cantidad de iteraciones.
    //      NOTA: ios se traslada como parámetro a método de Grafo. 
    //      vsc o virus-spread-chance [0..0.1]: probabilidad de infección.
    //      NOTA: vcf se traslada como parámetro a método de Grafo.
    //      rc o recovery-chance [0..0.1]: probabilidad de recuperación de infección.
    //      grc o gain-resistance-chance [0..1]: probabilidad de lograr resistencia.
    //      Aplica la siguiente regla de cambio de estado para los vértices:
    //      1. un vértice sólo puede ser infectado por alguno de sus vecinos infectados
    //         con probabilidad vsc.
    //      2. sólo un vértice infectado cuyo temporizador de chequeo de virus está en cero
    //         puede recuperarse con probabilidad rc.
    //      3. sólo un vértice recuperado puede ganar resistencia con probabilidad grc.
    //      4. Sólo las transformaciones #2 y #3 pueden ser simultáneas.
    // EFE: muestra gráficamente al grafo asociado diferenciando con distintos
    //      colores los estados de los vértices.
    void visualizar(int cItr, double vsc, double rc, double grc);

private:
    Grafo& grafo;
    Simulador& simulador;


    void simular();



    // Genera una posicion aleatoria para las coordenadas)
    double generaPos();

    // Rellena los vectores con valores generados al azar
    void atragantador();

    // Dibuja un circulo a partir del radio y las coordenadas
    void dibujar_circulo(double radio, double x, double y);

    // Genera las lineas entre vertices
    void linker(int lineas, int* arrV, int vrt);

    // Dibuja los circulos, basandose en las posiciones ya generadas 
    void recurCircles();

    // Revisa toda la lista de adyacencia y devuelve el indice del vertice con mas adyacencias
    int vrtPopular();

    // Asigna el color al circulo, dependiendo de su estado
    void estadoVrt(int vrt);

    // Tipo de main para las figuras
    static void display(void);
    static void keyboard(unsigned char key, int x, int y);
    static Visualizador *ptr;

    int *argc;
    char **argv;

    // Variables globales que contienen las posiciones asignadas
    int cntVrt = 0;
    double *posX = NULL; // vector con las posiciones en X
    double *posY = NULL; // vector con las posiciones en Y
    //int numVrt = grafo.obtTotVrt();
    int *arrAdy = NULL;
    Simulador simulador;

    struct infosim {
        int cItr, ios, vcf, vcfmax;
        double vsc, rc, grc;
    };

    bool sim = false;
    infosim info;
};


#endif	/* VISUALIZADOR_H */