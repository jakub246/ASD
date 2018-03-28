#include <iostream>
using namespace std;

struct Node{
    int value;
    Node * next;
};

Node * makeList(int A[], int n)
{
    if(n == 0)
        return nullptr;

    Node * elem = new Node;
    elem->value = A[n-1];
    elem->next = nullptr;
    for(int i=n-2; i>=0; i--)
    {
        Node * elem2 = new Node;
        elem2->value = A[i];
        elem2->next = elem;
        elem = elem2;
    }

    return elem;
}

void writeList(Node * first)
{
    while(first != nullptr)
    {
        cout<<first->value<<" ";
        first = first->next;
    }
    cout<<endl;
}

Node * scal(Node * node1, Node * node2)
{
    // zak³adam ¿e listy zosta³y podane prawid³owo, nie sa puste

    // inicjalizacja nowa, oraz wskazanie na pierwszy element
    // tak by mo¿liwe by³o u¿ywanie next
    Node * nowa;
    if(node1->value < node2->value)
    {
        nowa = node1;
        node1 = node1->next;
    }
    else
    {
        nowa = node2;
        node2 = node2->next;
    }
    Node *first = nowa;

    // w³aœciwe doklejanie
    while(node1 != nullptr && node2 != nullptr)
    {
        if(node1->value < node2->value)
        {
            nowa->next = node1;
            node1 = node1->next;
        }
        else
        {
            nowa->next = node2;
            node2 = node2->next;
        }
        nowa = nowa->next;
    }

    // koncowe doklejenie
    if(node1 != nullptr)
        nowa->next = node1;
    if(node2 != nullptr)
        nowa->next = node2;

    return first;
}

Node * mergeSort(Node * node)
{
    // warunek analogiczny do warunku gdy tablica jest jedno elementowa
    if(node->next == nullptr)
        return node;

    Node * list1; Node * list2;

    // split
    list1 = node;
    list2 = node;
    Node * tem;
    while(node != nullptr && node->next != nullptr)
    {
        tem = list2;
        list2 = list2->next;
        node = node->next->next;
    }
    tem->next = nullptr;

    list1 = mergeSort(list1);
    list2 = mergeSort(list2);

    return scal(list1, list2);
}

int main()
{
    int tab[10] = {1, -23, 12, 23, -5, -100, 2, 16, 8, 10};

    int A[3] = {4, 12, 15};
    int B[4] = {1, 2, 13, 90};


  //  writeList(scal(makeList(A, 3), makeList(B, 4)));

    Node * first = makeList(tab, 10);
    writeList(first);

    writeList(mergeSort(first));

    return 0;
}
