#include <iostream>
using namespace std;

inline int left(int i){return 2*i;};
inline int right(int i){return 2*i+1;};

void heapify(int A[], int i)
{
    int largest = i;

    int l = left(i);
    int r = right(i);

    if(l<A[0] && A[l]>A[largest])
        largest = l;
    if(r<A[0] && A[r]>A[largest])
        largest = r;

    if(largest != i)
    {
        swap(A[i], A[largest]);
        heapify(A, largest);
    }
}

void buildHeap(int A[]) // first element had been number of elements
{
    int n=A[0];

    for(int i=n; i>=1; i--)
        heapify(A, i);
}

void heapSort(int A[])
{
    // przypominam na tym etapie ¿e doœæ specyficzne przesy³ana jest informacja o wielkoœci drzewa
    buildHeap(A);
    int remA=A[0];

    for(int i=A[0]; i>=2; i--) // i to index "ostatniego elementu"
    {
        // mamy drzewo maksymalne, wiemy z tego ¿e korzeñ przyjmuje w tym momencie wartoœci max
        // zamieniam korzeñ z ostatnim elementem, oraz pomniejszam drzewo
        swap(A[1], A[i]);
        //zmiana d³ugoœci drzewa
        A[0]=i-1;
        // naprawa drzewa poczynajac od korzenia
        heapify(A, 1);
    }
    // naprawiam to co popsu³em
    A[0]=remA;
}

int main()
{
    int A[11] = {10, 2, 5, 8, 23, 12, 34, 12, 3, 4, 2};

    heapSort(A);
    for(int a: A)
        cout<<a<<" ";

    return 0;
}
