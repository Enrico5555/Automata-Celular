/*
 * File:   LstOrdAdy.h
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:32 PM
 */

#ifndef LSTADY_H
#define	LSTADY_H

class LstAdy {
    // Representa la lista ordenada de adyacencias de un v�rtice en Grafo.

public:

    // Construye una lista de adyacencias vac�a.
    LstAdy();

    // Construye una lista de adyacencias id�ntica a orig.
    LstAdy(const LstAdy& orig);

    // Destruye a *this retornando toda la memoria asignada din�micamente.
    ~LstAdy();

    // EFE: agrega el �ndice de adyancencia nady a *this.
    void agr(int nady);

    // EFE: retorna true si el �ndice de adyacencia ady aparece en *this,
    //      de lo contrario retorna false.
    bool bus(int ady);

    // EFE: retorna un arreglo de enteros con las posiciones de los v�rtices
    //      adyacentes al v�rtice asociado a *this.
    int* obtAdy() const;

    // EFE: retorna la cantidad de adyacencias en *this.
    int obtCntAdy() const;

    // EFE: retorna true si lst es id�ntica a *this.
    bool operator==(const LstAdy& lst) const;

private:
    struct NdoLstAdy { // representa el nodo de una lista de adyacencias
        int vrtD; // representa la posici�n del v�rtice destino en Grafo
        NdoLstAdy* sgt; // representa el apuntador inteligente al siguiente
        ~NdoLstAdy(){
        }

    };

    NdoLstAdy* inicio; // representa el apuntador al inicio de la lista
    int cntAdy; // cantidad de adyacencias en la cadena apuntada por inicio
};

#endif	/* LSTADY_H */

