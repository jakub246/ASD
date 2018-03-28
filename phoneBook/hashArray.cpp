//
// Created by jakub on 28.03.18.
//

#include "hashArray.h"


int hashFunction(Data data, int m) {

    int hash = 0;

    char *name = data.firstName;
    int a = 31415, b = 27183;

    while (*name != 0) {
        hash = (a * hash + *name) % m;
        a = a * b % (m - 1);
        name++;
    }

    name = data.lastName;

    while (*name != 0) {
        hash = (a * hash + *name) % m;
        a = a * b % (m - 1);
        name++;
    }

    hash = (a * hash + data.age) % m;

    return (hash < 0) ? hash + m : hash;

}