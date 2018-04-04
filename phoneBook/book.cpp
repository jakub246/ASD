//
// Created by jakub on 28.03.18.
//

#include "book.h"
using namespace std;

Book::Book(int capacity) {
    this->capacity = capacity;

//    capacityake array of contacts, contacts are array whith pointer to contact(List)
    contacts = new List *[capacity];
    for (int i = 0; i < capacity; ++i) {
        contacts[i] = nullptr;
    }
}

int Book::hashFunction(const char *firstName, const char *lastName) {
    int hash = 0;
    int a = 31415, b = 27183;

    while (*firstName != 0) {
        hash = (a * hash + *firstName) % capacity;
        a = a * b % (capacity - 1);
        firstName++;
    }

    while (*lastName != 0) {
        hash = (a * hash + *lastName) % capacity;
        a = a * b % (capacity - 1);
        lastName++;
    }

    return (hash < 0) ? hash + capacity : hash;
}

void Book::addContact(char *firstName, char *lastName, int phoneNumber) {
    int hash = hashFunction(firstName, lastName);

    newElemList(contacts[hash], firstName, lastName, phoneNumber);
}

void Book::newElemList(Book::List *&list, char *firstName, char *lastName, int phone) {
    if (list == nullptr) {
//        then, list don't exist
        list = new List;
        list->next = nullptr;
        list->firstName = firstName;
        list->lastName = lastName;
        list->phone = phone;
    } else {
        List *tem = list;
        while(tem->next != nullptr)
            tem = tem->next;
        tem->next = new List;
        tem = tem->next;
        tem->next = nullptr;
        tem->firstName = firstName;
        tem->lastName = lastName;
        tem->phone = phone;
    }
}

int Book::findPhone(string firstName, string lastName) {
    int hash = hashFunction(firstName.c_str(), lastName.c_str());

    List *list = contacts[hash];

    while(list != nullptr){
        if(list->firstName == firstName && list->lastName == lastName){
            return list->phone;
        }
        list = list->next;
    }

    return 0;
}
