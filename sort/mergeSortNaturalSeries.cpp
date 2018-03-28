#include <iostream>
using namespace std;

void mergeMy(int *mArray, int left, int mid, int right)
    // first element on array main, first of first array, middle element (first of second sorted list), last element
{
    // make temporary array for first array ( from left to middle)
    int *first = new int[mid-left];
    for(int i=left; i<mid; i++)
        first[i-left] = mArray[i];

    // appropriate merge
    int *mainPtr = mArray + left;
    int *second = mArray + mid;
    int *rightFirstPtr = first + mid-left;
    int *rightSecondPtr = mArray + right;

    while(first != rightFirstPtr && second != rightSecondPtr)
    {
        if( *first < *second )
        {
            *mainPtr = *first;
            first++;
        }
        else
        {
            *mainPtr = *second;
            second++;
        }
        mainPtr++;
    }

    // if( first == rightFirstPtr}
    //      there is ok, because elements are on right place

    if( second == rightSecondPtr)
        while(first < rightFirstPtr)
        {
            *mainPtr = *first;
            first++;
            mainPtr++;
        }
    delete first;
}

void mergeSort(int A[], int n)
{
    bool rise=true;
    bool sorted=false;

    int left=0;

    while(sorted == false)
    {
        int i=left;
        rise=true;
        while(rise == true)
        {
            if(i == n || A[i] > A[i+1])
                rise=false;
            i++;
        }

        if(i<n)
        {
            // mamy pare
            int middle=i;
            rise=true;
            while(rise == true)
            {
                if(i == n || A[i] > A[i+1])
                    rise=false;
                i++;
            }
            int right=i;
            mergeMy(A, left, middle, right);
            left=right;
            if(left == n)
                left=0;
        }
        else
        {
            // nie mamy pary, musimy powróciæ do poptrzedniego, lub gdy takiego nie ma
            // oznacza to ¿e koñczymy program;
            int right=n;
            rise=true;
            i=left-1;
            while(rise == true)
            {
                if(i == 1 || A[i-1] > A[i])
                    rise=false;
                i--;
            }
            if(i == 0)
                sorted=true;
            else
            {

                int middle=left;
                left=i+1;//cout<<"left: "<<left<<"  middle: "<<middle<<"  right: "<<right;
                mergeMy(A, left, middle, right);
                left=0;
            }
        }
    }
}

int main()
{
    int A[12] = {1, 21, -3, 4, 51 ,6 , 6, 45 ,34, 35, 43, 5};
 //int A[6] = {1, 2, 3, -1, 10 ,6};
   // mergeMy(A, 0, 3, 6);
   for(int a: A)
        cout<<a<<" ";
   mergeSort(A, 12);
   cout<<endl;
    for(int a: A)
        cout<<a<<" ";

    return 0;
}
