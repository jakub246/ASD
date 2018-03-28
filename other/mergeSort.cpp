#include <iostream>
using namespace std;

void mergeSort(int A[], int n)
{
    if(n == 1)
        return;

    // podzia� na po�owy i uruchominie rekurencyjnie merge sort
    int k=n/2;
    mergeSort(A, k);
    mergeSort(A+k, n-k);

    // scalanie
    // wpierw stworzenie tablicy pomocniczej
    // dla element�w od 0 do k

    int *pom = new int[k];
    for(int i=0; i<k; i++)
        pom[i]=A[i];

    // w�a�ciwe scalanie

    int p1=0; int p2=k;

    for(int i=0; i<n; i++)
    {
        // po przepe�nieniu sie jednego z licznik�w
        // tzn wykorzystaniu wszystkich element�w tablic pomocniczych
        if(p1 == k)
            break;
        if(p2 == n)
        {
            while(i<n)
            {
                A[i] = pom[p1];
                p1++;
                i++;
            }
            break;
        }


        // scalania w�asciwe, rosnaco
        if(pom[p1] < A[p2])
        {
            A[i] = pom[p1];
            p1++;
        }
        else
        {
            A[i] = A[p2];
            p2++;
        }
    }

    delete pom;
}

int main()
{
    int tab[11] = {32, 2 ,1, 4, 2,43, 4, 7, 8, 23, 100};

    for(int i=0; i<11; i++)
        cout<<tab[i]<<" ";
    cout<<endl;

    mergeSort(tab, 11);

    for(int i=0; i<11; i++)
        cout<<tab[i]<<" ";
    cout<<endl;

    return 0;
}
