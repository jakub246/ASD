//
// Created by jakub on 28.03.18.
//

#ifndef PHONEBOOK_BOOK_H
#define PHONEBOOK_BOOK_H

#include <string>

class Book {
public:
    struct List {
        std::string firstName;
        std::string lastName;
        int phone;

        List *next;
    };

    Book(int capacity);

//    contacts are array whith pointer to contact(List)
    List **contacts;

    void newElemList(List *&list, char *firstName, char *lastName, int phone);

    int hashFunction(const char *firstName, const char *lastName);

    void addContact(char *firstName, char *lastName, int phoneNumber);

    int findPhone(std::string firstName, std::string lastName);

private:
    int capacity;
};

#endif //PHONEBOOK_BOOK_H
