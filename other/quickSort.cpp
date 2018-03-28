#include <iostream>
using namespace std;

int Partition(int tab[], int first, int last)
{
    int pivot = tab[last];
    int bLine = first-1; // borderline of elements who has swapped
    int i = first;

    while(i<last)
    {
        if(tab[i] <= pivot)
        {
            bLine++;
            swap(tab[bLine], tab[i]);
        }
        i++;
    }
    swap(tab[bLine+1], tab[last]);
    return bLine+1;
}

void quickSort(int tab[], int n)
{
    if(n <= 1)
        return;

    int k = Partition(tab, 0, n-1);
    quickSort(tab, k);
    quickSort(tab+k+1, n-(k+1));
}

int main()
{
    int tab[11] = {32, 2 ,1, 4, 2,43, 4, 7, 8, 23, 100};

    for(int i=0; i<11; i++)
        cout<<tab[i]<<" ";
    cout<<endl;

    cout<<Partition(tab, 0, 9)<<endl;
quickSort(tab, 11);
    for(int i=0; i<11; i++)
        cout<<tab[i]<<" ";
    cout<<endl;
    return 0;
}
