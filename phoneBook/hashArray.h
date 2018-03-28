//
// Created by jakub on 28.03.18.
//

#ifndef PHONEBOOK_HASHARRAY_H
#define PHONEBOOK_HASHARRAY_H

struct Data {
    char *firstName;
    char *lastName;
    int age;
};

int hashFunction(Data data, int m);

#endif //PHONEBOOK_HASHARRAY_H
