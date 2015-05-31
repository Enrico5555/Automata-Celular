#include "Parse.h"
#include<iostream>
#include <stdlib.h>     /* atof */
using namespace std;

namespace line_parse {

    unsigned int cantidad_elementos(const string& linea, char rem) {
        unsigned int count = 0;
        if (linea.size() > 0) count = 1;
        for (int i = 0; i < linea.size(); i++) {
            if (linea[i] == rem) {
                count++;
            }
        }
        return count;
    }

    string remover_comillas(const string& str) {
        string res = "";
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != '\"') res += str[i];
        }
        return res;
    }

    string parametro(string linea, int indice, char rem) {
        unsigned int count = 0;
        unsigned int pos;
        for (int i = 0; i < linea.size(); i++) {
            if (indice == count) {
                size_t pos = linea.find(rem, i);
                if (pos == string::npos) pos = linea.size();
                string buffer = linea.substr(i, pos);
                return buffer;
            }
            if (linea[i] == rem) {
                count++;
            }
        }
        return "";
    }

    // esto lee los vertices

    int elemento(string linea, int indice, char rem) {
        return atoi(parametro(linea, indice, rem).c_str());
    }

    double elemento_double(string linea, int indice, char rem) {
        return atof(parametro(linea, indice, rem).c_str());
    }

    void sacaDatos(string data) {
        pos = data.find(" ");
        string buffer = data.substr(0, pos);
        cantidadVertices = atoi(buffer);
        buffer = data.substr(pos, data.size());
        promedioAdy = atof(buffer);
    }



}
