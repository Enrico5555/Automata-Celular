/*
 * File:   LstOrdAdy.cpp
 * Author: Alan
 *
 * Created on 2 de abril de 2015, 02:32 PM
 */

#include "LstAdy.h"
#ifndef NULL
#define NULL 0
#endif // NULL

LstAdy::LstAdy() {
    inicio = NULL;
    cntAdy = 0;
}

LstAdy::LstAdy(const LstAdy& orig) {
    //NdoLstAdy **current = &inicio, **last = &inicio;
    inicio = NULL;
    cntAdy = 0;
    int *ady = orig.obtAdy();
    for (int i = 0; i < orig.cntAdy; i++)
    {
        agr(ady[i]);
    }
    if (ady != NULL)
        delete [] ady;
}

LstAdy::~LstAdy() {
    NdoLstAdy *last = inicio;
    if (last == NULL) return;
    NdoLstAdy *next = inicio->sgt;
    while (last != NULL)
    {
        delete last;
        last = next;
        if (last != NULL)
        {
            next = last->sgt;
        }
    }
}

void LstAdy::agr(int nady) {
    NdoLstAdy **cur = &inicio;
    while ((*cur) != NULL)
    {
        cur = &(*cur)->sgt;
    }
    (*cur) = new NdoLstAdy;
    (*cur)->vrtD = nady;
    (*cur)->sgt = NULL;
    cntAdy++;
}

bool LstAdy::bus(int ady) {
    int i = 0;
    NdoLstAdy *cur = inicio;
    while (i < cntAdy)
    {
        if (cur == NULL) return false;
        if (cur->vrtD == ady) return true;
        cur = cur->sgt;
        i++;
    }
    return false;
}

int* LstAdy::obtAdy() const {
    if (cntAdy == 0) return NULL;
    int *arr = new int[cntAdy];
    NdoLstAdy *cur = inicio;
    for (int i = 0; i < cntAdy; i++)
    {
        arr[i] = cur->vrtD;
        cur = cur->sgt;
    }
    return arr;
}

int LstAdy::obtCntAdy() const {
    return cntAdy;
}

bool LstAdy::operator==(const LstAdy& lst) const {
    if (cntAdy != lst.cntAdy) return false;
    LstAdy lista(lst);
    int *arr = obtAdy();
    for (int i = 0; i < cntAdy; i++)
    {
        if (!(lista.bus(arr[i])))
        {
            delete[] arr;
            return false;
        }
    }
    if (arr != NULL)
        delete [] arr;
    return true;
}
