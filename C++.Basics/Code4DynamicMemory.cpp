#include<iostream>
using namespace std;

// pointer  = new type
// pointer = new type [no_of_elem]

int main()
{   
    int * fPointer;
    fPointer = new (nothrow) int [5];
    if(fPointer != nullptr)cout<<"\nDynamic Allocation\n";

    return EXIT_SUCCESS;
}