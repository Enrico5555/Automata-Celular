/*
 * File:   main.cpp
 * Author: alan.calderon
 *
 * Created on 15 de abril de 2015, 12:05 PM
 */

// Ejemplo base tomado de cplusplus
// normal_distribution example
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <random>

using namespace std;

void generarArchivoRed(int n, double prbAdy, string nomArch) {
    // Se define y crea el generador de n�mero aleatorios basado en el reloj del sistema.
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generador(seed);
    enum Bit { U, C, }; // U indica que s� hay adyacencia, C indica que no.

    Bit* matBits = new Bit[n*n]; // Guardaremos las adyacencias en una matriz representada por un arreglo.

    // Se inicia la matriz en C.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) matBits[i*n + j] = C; // Fila i, columna j.

    for (int i = 0; i < n; i++) {
        // Esta distribuci�n servir� para generar la cantidad de adyacencias por v�rtice.
        //std::normal_distribution<double> dst_normal(prmAdy, dsvEst);

        for (int j = i; j < n; j++) { // OJO: desde j = i empieza
            //std::default_random_engine generatorUniforme;
            std::uniform_int_distribution<int> dst_uniforme(0, 100);
            int xstAdyI = dst_uniforme(generador); // se genera un valor al azar entre 0 y 100.
	    double xstAdyD = xstAdyI / 100.0; // se genera un valor al azar entre 0 y 1.
            if ( xstAdyD <= prbAdy) { // determinamos si "nace" o no la adyacencia
                    matBits[i*n + j] = U;
                    matBits[j*n + i] = U; // agregamos la adyacencia "espejo"
            }
        }

		int cntAdy = 0;	// Vamos a contar las adyacencias para asegurarnos que al menos hay una por cada v�rtice.
		for (int j = 0; j < n; j++)
			if ( matBits[i*n + j] == U )
			    cntAdy++;

		if ( cntAdy == 0 ) { // no queremos v�rtices aislados
			std::uniform_int_distribution<int> dst_uniforme(0, n-1);
			int indAdy = dst_uniforme(generador); // se genera un valor al azar entre 0 y n-1
			matBits[i*n + indAdy] = U; // agregamos la adyacencia para tener al menos una
            matBits[indAdy*n + i] = U; // agregamos la adyacencia "espejo"
		};
    }

    // Ahora se crea el archivo con base en la matriz de bits
    ofstream archSalida(nomArch.c_str(), ios::out); // se crea flujo de salida
    if (!archSalida) { // operador ! sobrecargado
        cerr << "No se pudo abrir el archivo de salida" << endl;
        exit(1);
    }
    archSalida << n << " " << prbAdy << endl; // En la primera l�nea se anota la cantidad de v�rtices

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (matBits[i*n + j] == U) archSalida << j << ",";
        }
        archSalida << endl; // se cambia de l�nea
    }
    delete[] matBits;
}

int main() {
    // Se construye el generador de n�meros al azar basado en una semilla tomada
    // del reloj del sistema:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // Se construye la funci�n de distribuci�n normal.
    // El primer par�metro es el promedio de la distribuci�n.
    // El segundo par�metro es la distribuci�n est�ndar de la distribuci�n.
    std::normal_distribution<double> distribution(0.0, 1.0);

    std::cout << "Algunos n�meros al azar basados en la distribuci�n normal:" << std::endl;
    for (int i = 0; i < 10; ++i)
        std::cout << distribution(generator) << std::endl;

    /* GENERACI�N DE ARCHIVOS DE DATOS */
    // Genera un archivo de red con 10 v�rtices, con una probabilidad de adyacencia de 0.5.
    generarArchivoRed(10, 0.5, "redMuyPeq.txt");

    // Genera un archivo de red con 100 v�rtices, con una probabilidad de adyacencia de 0.25.
    generarArchivoRed(100, 0.25, "redPeq.txt");

    // Genera un archivo de red con 1000 v�rtices, con una probabilidad de adyacencia de 0.15.
    generarArchivoRed(1000, 0.15, "redGrn.txt");
    return 0;
}

