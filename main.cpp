/* 
 * File:   main.cpp
 * Author: Alan
 *
 * Created on 1 de abril de 2015, 06:52 PM
 */
#include <cstdlib>
#include <iostream>
#include <string>

#include "Parse.h"
#include "Grafo.h"
#include "Simulador.h"
#include "Visualizador.h"

using namespace std;
using namespace line_parse;


/*
 * 
 */

/*cargar “datosGrafo.txt” : que permitirá cargar los datos de un grafo desde un
archivo de texto.
2. crear #vrt #prbAdy : que creará un grafo con cntVrt == #vrt en el que cada
adyacencia (i,j) tenga la probabilidad de existir de prbAdy.
3. simular #cItr #ios #vsc #vcf #rc #grc : que simulará la infección (ver
especificación) sin visualización de los estados intermedios, sólo la
visualización de los estados inicial y final.
4. simular-visualizar #cItr #ios #vsc #vcf #rc #grc : que simulará la infección (ver
especificación) visualizando todos los estados intermedios, el inicial y el final.
5. visualizar : que mostrará gráficamente el grafo previamente cargado o creado.
Si no ha sido cargado ni creado el grafo, se mostrará la advertencia “DEBE
CREAR O CARGAR GRAFO ANTES!!”6. calcular-promedio-longitud-caminos-cortos : que calculará el promedio de las
longitudes de los caminos más cortos del grafo previamente cargado o
asociado. Si no ha sido cargado ni creado el grafo, se mostrará la advertencia
“DEBE CREAR O CARGAR GRAFO ANTES!!”
7. calcular-centralidad-intermedial #vrt : que calculará la centralidad intermedial
del vértice cuyo índice es #vrt (ver especificación) en el grafo asociado. Si no
ha sido cargado ni creado el grafo, se mostrará la advertencia “DEBE CREAR
O CARGAR GRAFO ANTES!!” NOTA: sigue pendiente para último laboratorio.
8. calcular-coeficiente-agrupamiento #vrt : que calculará el coeficiente local de
agrupamiento para vértice cuyo índice es #vrt en el grafo asociado. Si no ha
sido cargado ni creado el grafo, se mostrará la advertencia “DEBE CREAR O
CARGAR GRAFO ANTES!!”*/

int main(int argc, char** argv) {
    Grafo mg(10,0.5); // Crea grafo al azar con 10 vértices y probabilidad de adyacencias de 0.5}
    mg.infectar(3); // Pone en estado de infectados (I) a 3 vértices de mg.
    mg.azarizarTmpChqVrs(5); // Asigna valores al azar entre 1 y 5 de temporizador de chequeo. 
    Simulador s(mg); // Crea una instancia de Simulador.
    Visualizador v(mg,s); // Crea una instancia de Visualizador
    return 0;
}

