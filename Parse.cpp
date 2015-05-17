#include "Parse.h"

using namespace std;

namespace line_parse {
    unsigned int cantidad_elementos(const string& linea, char rem)
    {
        unsigned int count = 0;
        if (linea.size() > 0) count = 1;
        for (int i = 0; i < linea.size(); i++)
        {
            if (linea[i] == rem)
            {
                count++;
            }
        }
        return count;
    }
    
    string remover_comillas(const string& str)
    {
        string res = "";
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] != '\"') res += str[i];
        }
        /*unsigned int char_count = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '\"') char_count++;
        }
        res.reserve(str.length()-char_count);
        for (int i = 0, j = 0; i < str.length(); i++)
        {
            if (str[i] != '\"') 
            {
                res[j] += str[i];
                j++;
            }
        }*/
        return res;
    }
    
    string parametro(string linea, int indice, char rem)
    {
        unsigned int count = 0;
        unsigned int pos;
        for (int i = 0; i < linea.size(); i++)
        {
            if (indice == count)
            {
                size_t pos = linea.find(rem, i);
                if (pos == string::npos) pos = linea.size();
                string buffer = linea.substr(i, pos);
                return buffer;
            }
            if (linea[i] == rem)
            {
                count++;
            }
        }
        return "";
    }

    // esto lee los vertices
    int elemento(string linea, int indice, char rem)
    {
        return atoi(parametro(linea, indice, rem).c_str());
    }
    
    double elemento_double(string linea, int indice, char rem)
    {
        return atof(parametro(linea, indice, rem).c_str());
    }
}
