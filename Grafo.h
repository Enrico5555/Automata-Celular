/* 
 * File:   Grafo.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:25 PM
 */

#ifndef GRAFO_H
#define	GRAFO_H

#include <string>
using namespace std;

#include "LstAdy.h"

class Grafo {
    // Representa la red de computadores sobre la cual se diseminará el virus.
public:
    //class Visualizador; // declaración adelantada para evitar #include mutuo.
    //friend class Visualizador; // permite que el visualizador acceda la sección
                               // privada de Grafo para hacer más eficientemente
                               // la visualización.

    /* TIPO PÚBLICO DE ESTADOS DE VÉRTICES */
    enum E{ // representa el tipo de estados de la red de infección
        S, // representa un vértice susceptible de infección
        I, // representa un vértice infectado
        R, // representa un vértice resistente
    };

    
    /* CONSTRUCTORES */
    // REQ: ( cntVrt >= 10 ) && ( 1 <= prmGrd )
    // Construye una red al azar no vacía. 
    // Se basa en la distribución normal: std::normal_distribution en <random>
    Grafo(int cntVrt, int prmAdy);
    
    // Construye una copia idéntica a orig.
    Grafo(const Grafo& orig);
    
    // Construye una red con base en los datos en el archivo de nombre nArch.
    // El archivo debe ser *.txt con datos separados por comas.
    // En la primera línea aparecerá un entero que representa la cantidad de vértices.
    // Luego en cada línea aparecerá primero el estado de un vértice y las posiciones
    // de los adyacentes, todo separado por comas.
    Grafo(string nArch);
    
    // Destruye a *this retornando toda la memoria asignada dinámicamente.
    ~Grafo();
    
    /* MÉTODOS OBSERVADORES BÁSICOS */
    
    // EFE: retorna true si existe un vértice con índice vrt.
    bool xstVrt(int vrt) const;
    
    // REQ: existan en *this vértices con índices vrtO y vrtD.
    // EFE: retorna true si existe un arco entre los vértices con índice vrtO y vrtD.
    bool xstAdy(int vrtO, int vrtD) const;
    
    // REQ: que exista en *this un vértice con índice vrt.
    // EFE: retorna la cantidad de adyacencias del vértice vrt.
    int obtCntAdy(int vrt) const;
    
    // REQ: que exista en *this un vértice con índice vrt.
    // EFE: retorna un arreglo de enteros con las posiciones de los vértices
    //      adyacentes al vértice indicado por vrt.
    int* obtAdy(int vrt) const;
    
    // EFE: retorna el total de adyacencias en *this.
    int obtTotAdy() const;    
 
    // EFE: retorna el total de vértices en *this.
    int obtTotVrt() const;
    
    // EFE: retorna el promedio simple de adyacencias por vértice.
    double obtPrmAdy() const;
    
    // REQ: que exista en *this un vértice con índice vrt.
    // EFE: retorna el estado del vértice con índice vrt.
    E obtEst(int vrt) const;
    
    // EFE: retorna true si grf es idéntico a *this y false en caso contrario.
    //      Compara vértice a vértice según su índice.
    bool operator==(const Grafo& grf) const;
    
    /* MÉTODOS OBSERVADORES ESPECIALES */
    
    // EFE: retorna el promedio de las longitudes de los caminos más cortos
    //      entre cada pareja de vértices de *this.
    double promLongCmnsCrts() const;
    
    // REQ: vrt sea un índice de vértice válido.
    // EFE: retorna la "betweeness centrality" o centralidad intermedial del vértice con índice vrt.
    //      La definición aparece en: http://en.wikipedia.org/wiki/Betweenness_centrality
    //      Para cada par de vértices que no incluyan al indicado por vrt se calcula
    //      la proporción de los caminos más cortos que pasan por el vértice indicado
    //      por vrt.
    // NOTA: ver algoritmo en http://es.wikipedia.org/wiki/Algoritmo_de_Floyd-Warshall
    double centralidadIntermedial(int vrt) const;
    
    // REQ: que exista en *this un vértice con índice vrt.
    // EFE: retorna el "local clustering coefficient" o coeficiente local de agrupamiento
    //      para el vértice indicado por vrt.
    //      La definición aparece en: http://en.wikipedia.org/wiki/Clustering_coefficient
    //      Se calcula como el cociente entre la cantidad efectiva de arcos entre los
    //      vecinos del vértice indicado por vrt dividida por la cantidad total de posibles
    //      arcos entre todos los vecinos del vértice indicado por vrt.
    double coeficienteAgrupamiento(int vrt) const;
    
    /* MÉTODOS MODIFICADORES */
    
    // REQ: que exista en *this un vértice con índice vrt.
    // MOD: *this.
    // EFE: cambia el estado del vértice cuyo índice es vrt a ne.
    void modEst(int vrt, E ne);
    
private:
    struct NdoVrt {
        E e; // representa el estado del vértice
        int tmpChqVrs; // representa el temporizador de chequeo de virus
        LstAdy lstAdy; // representa la lista de adyacencias del vértice
        NdoVrt(): e(S), tmpChqVrs(1) {};
        ~NdoVrt(){ };
    };
    
    int cntVrt; // representa la cantidad total de vértices
    NdoVrt* arrVrt; // representa el arreglo dinámico de nodos de vértices
};

#endif	/* GRAFO_H */

