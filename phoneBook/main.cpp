#include <iostream>
#include "hashArray.h"
#include "book.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Book book(2);

    book.addContact("Kuba", "sala", 2910); book.addContact("Jakub", "sala", 28130);
    book.addContact("Kuba", "sala", 2910);

    std::cout << book.findPhone("Jakub", "sala");

    return 0;
}