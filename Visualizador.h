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
};

#endif	/* VISUALIZADOR_H */

