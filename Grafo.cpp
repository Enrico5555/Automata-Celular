/*
 * File:   Grafo.cpp
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:25 PM
 */

#include "Grafo.h"
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <random>
#include <iostream>

#ifndef NULL
#define NULL 0
#endif // NULL

using namespace std;

// esto es para 
unsigned int cantidad_elementos(const string& linea)
{
    unsigned int count = 0;
    if (linea.size() > 0) count = 1;
    for (int i = 0; i < linea.size(); i++)
    {
        if (linea[i] == ',')
        {
            count++;
        }
    }
    return count;
}

// esto lee los vertices
int elemento(string linea, int indice)
{
    unsigned int count = 0;
    unsigned int pos;
    for (int i = 0; i < linea.size(); i++)
    {
        if (indice == count)
        {
            size_t pos = linea.find(',');
            if (pos == string::npos) pos = linea.size()-1;
            string buffer = linea.substr(i, pos);
            return atoi(buffer.c_str());
        }
        if (linea[i] == ',')
        {
            count++;
        }
    }
    return -1;
}

Grafo::Grafo(int cntVrt, int prmAdy) {
    if (cntVrt >= 10 && 1 <= prmAdy)
    {
        this->cntVrt = cntVrt;
        arrVrt = new NdoVrt[cntVrt];
        default_random_engine generador;
        normal_distribution<double> distribucion(cntVrt, prmAdy);
        for (int i = 0; i < cntVrt; i++)
        {
            for (int i = 0; i < cntVrt; i++)
            {
                int rnum = distribucion(generador);
                //cout << rnum << endl;
                if (!xstAdy(i, rnum))
                {
                    arrVrt[i].lstAdy.agr(rnum);
                }
            }
        }
    }
}

Grafo::Grafo(const Grafo& orig) {
    if (orig.cntVrt > 0)
    {
        cntVrt = orig.cntVrt;
        arrVrt = new NdoVrt[cntVrt];
        for (int i = 0; i < cntVrt; i++)
        {
            arrVrt[i].e = orig.arrVrt[i].e; // tal vez funciona
            arrVrt[i].tmpChqVrs = orig.arrVrt[i].tmpChqVrs;
            arrVrt[i].lstAdy = LstAdy(orig.arrVrt[i].lstAdy); // tal vez funciona, posiblemente no
            /*for (int j = 0; j < orig.arrVrt[i].lstAdy.obtCntAdy(); j++)
            {
                
            }*/
        }
    }
}

Grafo::Grafo(string nArch) {
    ifstream file;
    file.open(nArch.c_str(), ios::in);
    if (file.is_open())
    {
        char line[256];
        memset(&line, 0, 256);
        file.getline(line, 256); //primera linea
        cntVrt = atoi(line);
        if (cntVrt < 0) return; // error
        arrVrt = new NdoVrt[cntVrt];
        int count = 0;
        do
        {
            memset(&line, 0, 256);
            file.getline(line, 256);
            string linea = line;
            unsigned int cant = cantidad_elementos(linea);
            if (cant > 0)
            {
                switch (elemento(linea, 0))
                {
                case 0:
                    arrVrt[count].e = S;
                    break;
                }
                if (cant > 1)
                {
                    //arrVrt[count].lstAdy = new LstAdy();
                    for (int i = 1; i < cant-1; i++)
                    {
                        arrVrt[count].lstAdy.agr(elemento(linea, i));
                    }
                }
            }
            count++;
        } while (!file.eof() && count < cntVrt);
    }
}

Grafo::~Grafo() {
    if (cntVrt > 0)
        delete[] arrVrt;
}

bool Grafo::xstVrt(int vrt) const {
    return (vrt < cntVrt && vrt >= 0); // Devuelve true si vrt esta entre 0 y cntVrt
}

bool Grafo::xstAdy(int vrtO, int vrtD) const {
    if (xstVrt(vrtO)) // Comprueba que el indice del vertice existe
    {
        int cantidad_adyacencias = arrVrt[vrtO].lstAdy.obtCntAdy();
        if (cantidad_adyacencias == 0) return false; // No hay adyacencias, por lo tanto la adyacencia no existe
        int *ady = arrVrt[vrtO].lstAdy.obtAdy();
        for (int i = 0; i < cantidad_adyacencias; i++)
        {
            if (ady[i] == vrtD) // Encontr� una adyacencia
            {
                delete[] ady; // Libera la memoria
                return true;
            }
        }
        delete[] ady; // Libera la memoria
    }
    return false; // No se encontr� adyacencia o el v�rtice no existe
}

int Grafo::obtCntAdy(int vrt) const
{
    if (xstVrt(vrt))
    {
        return arrVrt[vrt].lstAdy.obtCntAdy();
    }
}

int* Grafo::obtAdy(int vrt) const {
    if (xstVrt(vrt))
    {
        return arrVrt[vrt].lstAdy.obtAdy();
    }
    return NULL;
}

int Grafo::obtTotAdy() const {
    int cant = 0;
    for (int i = 0; i < cntVrt; i++)
    {
        cant += arrVrt[i].lstAdy.obtCntAdy();
    }
    return cant;
}

int Grafo::obtTotVrt() const {
    return cntVrt;
}

double Grafo::obtPrmAdy() const {
    double prom = 0;
    for (int i = 0; i < cntVrt; i++)
    {
        prom += ((double)arrVrt[i].lstAdy.obtCntAdy());
    }
    return prom / (double)cntVrt;
}

Grafo::E Grafo::obtEst(int vrt) const {
    if (xstVrt( vrt) == true){
        return arrVrt[vrt].e;
    }
}

bool Grafo::operator==(const Grafo& grf) const {
    if (this->cntVrt != grf.cntVrt) return false;
    for (int i = 0; i < this->cntVrt; i++)
    {
        int *ady = obtAdy(i), *adygrf = grf.obtAdy(i);
        for (int j = 0; j < arrVrt[i].lstAdy.obtCntAdy(); j++)
        {
            if (ady[j] != adygrf[j])
                return false;
        }
        delete[] ady; delete[] adygrf;
    }
}

double Grafo::promLongCmnsCrts() const {
}

double Grafo::centralidadIntermedial(int vrt) const {
    
}

double Grafo::coeficienteAgrupamiento(int vrt) const {
    if (xstVrt(vrt))
    {
        double cant = (double)obtCntAdy(vrt), triangles = 0.0;
        if (cant == 0 || cant == 1) return 0;
        double t_g = (cant*(cant-1))/2;
        int *ady = obtAdy(vrt);
        for (int i = 0; i < cant; i++)
        {
            for (int j = i+1; j < cant; j++)
            {
                if (xstAdy(ady[i], ady[j]))
                {
                    triangles++;
                }
            }
        }
        delete[] ady;
        return (triangles / t_g);
    }
    return 0;
}

void Grafo::modEst(int vrt, E ne) {
    if (xstVrt(vrt))
    {
        arrVrt[vrt].e = ne;
    }
}

int Grafo::distanciaMasCorta(int vrt1, int vrt2)
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    vector<vector<int>> dist;
    dist.resize(cntVrt);
    for(int i = 0; i < cntVrt; i++)
    {
        dist[i].resize(cntVrt);
        dist[i][i] = 0;
    }
    for (int i = 0; i < cntVrt; i++)
    {
        for (int j = 0; j < cntVrt; j++)
        {
            if (xstAdy(i, j))
                dist[i][j] = 1;
        }
    }
    int i, j, k;
    
    /* Initialize the solution matrix same as input graph matrix. Or 
       we can say the initial values of shortest distances are based
       on shortest paths considering no intermediate vertex. */
    /*for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = (this->xstAdy(i, j) ? 1 : 0);*/
 
    /* Add all vertices one by one to the set of intermediate vertices.
      ---> Before start of a iteration, we have shortest distances between all
      pairs of vertices such that the shortest distances consider only the
      vertices in set {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a iteration, vertex no. k is added to the set of
      intermediate vertices and the set becomes {0, 1, 2, .. k} */
    for (k = 0; k < cntVrt; k++)
    {
        // Pick all vertices as source one by one
        for (i = 0; i < cntVrt; i++)
        {
            // Pick all vertices as destination for the
            // above picked source
            for (j = 0; j < cntVrt; j++)
            {
                // If vertex k is on the shortest path from
                // i to j, then update the value of dist[i][j]
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    for (int i = 0; i < cntVrt; i++)
    {
        for (int j = 0; j < cntVrt; j++)
        {
            cout << dist[i][j] << ",";
        }
        cout << endl;
    }
    return dist[vrt1][vrt2];
}

int main()
{
    Grafo grafo("redPeq.txt");
    /*if (grafo.obtTotVrt() != 1000 || !(15 < grafo.obtPrmAdy() < 18)) {
        cout << "error" << std::endl;
    }
    cout << "totvrt: " << grafo.obtTotVrt() << ", prm:" << grafo.obtPrmAdy() << endl;*/
    for (int i = 0; i < grafo.obtTotVrt(); i++) {
    double peq = grafo.coeficienteAgrupamiento(i);
    cout << "coeficiente: " << peq << endl;
    }
    return 0;
}
