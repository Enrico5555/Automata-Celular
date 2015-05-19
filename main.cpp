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
int main(int argc, char** argv) {
    Grafo *grafo = NULL;
<<<<<<< HEAD
    Visualizador v(*grafo);
    Simulador sv(grafo,v);
    sv.simular(1000, 1, 0.04, 10, 0.5, 0.001);
=======
    Simulador sv(grafo);
>>>>>>> visualizador
    /*for (int i = 0; i < mg.obtTotVrt(); i++)
    {
        cout << "Estado: " << mg.obtEst(i) << endl;
    }*/
    cout << "Automata Celular\n";
    while (true)
    {
        string linea;
        cout << ">>";
        getline(cin, linea);
        int cant_elementos = cantidad_elementos(linea, ' ');
        if (cant_elementos > 0)
        {
            string prim = parametro(linea, 0, ' ');
            if (prim == "cargar")
            {
                if (cant_elementos == 2)
                {
                    cout << "Cargando grafo...\n";
                    string param = remover_comillas(parametro(linea, 1, ' '));
                    //cout << param;
                    try {
                        if (grafo != NULL) delete grafo;
                        grafo = new Grafo(param.c_str());
                        cout << "Grafo cargado\n";
<<<<<<< HEAD
=======
                        cout << "Vertices: " << grafo->obtTotVrt() << endl;
>>>>>>> visualizador
                    }
                    catch (int exc)
                    {
                        delete grafo;
                        cout << "Error cargando el grafo\n";
                        grafo = NULL;
                    }
                }
                else
                {
                    cout << "Este comando requiere 2 parametros\n";
                }
            }
            else if (prim == "crear")
            {
                if (cant_elementos == 3)
                {
                    int p1 = elemento(linea, 1, ' '), p2 = elemento(linea, 2, ' ');
                    if (p1 >= 10 && p2 >= 1)
                    {
                        if (grafo != NULL) delete grafo;
                        grafo = new Grafo(p1, p2);
                        cout << "Grafo creado\n";
                    }
                    else
                    {
                        cout << "Error creando el grafo\n";
                    }
                }
                else
                {
                    cout << "Este comando requiere 2 parametros\n";
                }
            }
            else if (prim == "simular")
            {
                if (cant_elementos == 7)
                {
                    //if grafo creado
                    if (grafo != NULL)
                    {
                        int it = elemento(linea, 1, ' '), ios = elemento(linea, 2, ' '), vcf = elemento(linea, 4, ' ');
                        double vsc = elemento_double(linea, 3, ' '), rc = elemento_double(linea, 5, ' '), grc = elemento_double(linea, 6, ' ');
<<<<<<< HEAD
                        sv.simular(it, ios, vsc, vcf, rc, grc);
=======
                        Simulador s(grafo);
                        s.simular(it, ios, vsc, vcf, rc, grc);
>>>>>>> visualizador
                    }
                    else
                    {
                        cout << "Error, el grafo no esta creado\n";
                    }
                }
                else
                {
                    cout << "Este comando requiere 6 parametros\n";
                }
            }
            else if (prim == "simular-visualizar")
            {
                if (cant_elementos == 7)
                {
                    if (grafo != NULL)
                    {
<<<<<<< HEAD
=======
                        Visualizador v(*grafo, &argc, argv);
>>>>>>> visualizador
                        int it = elemento(linea, 1, ' '), ios = elemento(linea, 2, ' '), vcf = elemento(linea, 4, ' ');
                        double vsc = elemento_double(linea, 3, ' '), rc = elemento_double(linea, 5, ' '), grc = elemento_double(linea, 6, ' ');
                        sv.simular(it, ios, vsc, vcf, rc, grc);
                        v.visualizar();
                    }
                    else
                    {
                        cout << "Error, el grafo no esta creado\n";
                    }
                }
                else
                {
                    cout << "Este comando requiere 6 parametros\n";
                }
            }
            else if (prim == "visualizar")
            {
                if (cant_elementos == 1)
                {
                    if (grafo != NULL)
                    {
<<<<<<< HEAD
=======
                        Visualizador v(*grafo, &argc, argv);
>>>>>>> visualizador
                        v.visualizar();
                    }
                    else
                    {
                        cout << "Error, el grafo no esta creado\n";
                    }
                }
                else
                {
                    cout << "Este comando no requiere parametros\n";
                }
            }
            else if (prim == "calcular-promedio-longitud-caminos-cortos")
            {
                if (cant_elementos == 1)
                {
                    if (grafo != NULL)
                    {
                        cout << "Promedio: " << grafo->promLongCmnsCrts() << endl;
                    }
                    else
                    {
                        cout << "Error, el grafo no esta creado\n";
                    }
                }
                else
                {
                    cout << "Este comando no requiere parametros\n";
                }
            }
            else if (prim == "calcular-centralidad-intermedial")
            {
                cout << "Este metodo no esta implementado\n";
            }
            else if (prim == "calcular-coeficiente-agrupamiento")
            {
                if (cant_elementos == 2)
                {
                    if (grafo != NULL)
                    {
                        int p1 = elemento(linea, 1, ' ');
                        cout << "Promedio: " << grafo->coeficienteAgrupamiento(p1) << endl;
                    }
                    else
                    {
                        cout << "Error, el grafo no esta creado\n";
                    }
                }
                else
                {
                    cout << "Este comando requiere 1 parametro\n";
                }
            }
<<<<<<< HEAD
            else if (prim == "ayuda")
            {
                if (cant_elementos == 1)
                {
<<<<<<< HEAD
                    cout << "cargar\t-carga el grafo a partir del parametro %nArch" << endl << 
                        "crear\t-fjsdaklfjsdalk" << endl << 
                        "simular " << endl << 
                        "simular-visualizar\t-fjasklf" << endl << 
                        "visualizar" << endl << 
                        "calcular-promedio-longitud-caminos-cortos" << endl << 
                        "calcular-centralidad-intermedial" << endl << 
                        "calcular-coeficiente-agrupamiento" << endl << 
=======
                    cout << "cargar\t-carga el grafo a partir del parametro %nArch" << endl <<
                        "crear\t-fjsdaklfjsdalk" << endl <<
                        "simular " << endl <<
                        "simular-visualizar\t-fjasklf" << endl <<
                        "visualizar" << endl <<
                        "calcular-promedio-longitud-caminos-cortos" << endl <<
                        "calcular-centralidad-intermedial" << endl <<
                        "calcular-coeficiente-agrupamiento" << endl <<
>>>>>>> visualizador
                        "salir" << endl;
                }
                else
                {
                    cout << "Este comando no requiere parametros\n";
                }
            }
            else if (prim == "salir")
            {
                break;
            }
=======
>>>>>>> parent of e7ed289... comando ayuda agregado
            else
            {
                cout << "Comando incorrecto\n";
            }
        }
    }
    return 0;
}

