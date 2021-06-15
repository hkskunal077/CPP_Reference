#include<iostream>
using namespace std;

void increment_all(int* start, int* stop)
{
    int* current = start;
    while(current!=stop){
        ++(*current);
        ++current;
    }
}
 
void print_all(const int* start, const int* stop)
{
    const int* current = start;
    while (current!=stop){
        cout<<*current<<"\n";
        ++current;
    }
}



//In the formal parameter we can have passed a pointer
//As the actual parameter we can pass the arrary
//keeping in mind, that it will start passing from 1st loc
template <class someType>
bool are_equal(someType a, someType b)
{return a==b;}

//Void pointers: points to value that has no type
void increase(void * data, int psize)
{
    if(psize==sizeof(char))
    {char* pchar; pchar = (char*) data; ++(*pchar);}

    else if(psize==sizeof(int))
    {int* pint; pint = (int*)data; ++(*pint);}
}

//for explicit nullpointing
int* p = 0;
int* q = nullptr;

//pointers to functions: for calling
// g = (*functcall)(x, y)

int main()
{
    int numbers[] = {10,12,16};
    increment_all(numbers, numbers+3);
    print_all(numbers, numbers+3);
    const char * foo = "hello";
    cout<<*foo<<*(foo+2)<<"\n";
    cout<<are_equal(*(foo+2), foo[2])<<"\n";

    char cha = 'x'; int intb = 1602;
    increase(&cha, sizeof(cha));
    increase(&intb, sizeof(intb));
    cout<<cha<<", "<<intb<<", "<<*p<<", "<<q<<"\n";

    return EXIT_SUCCESS;
}

//Just to understand the properties of having access to pointers
int x;
int *  p1 = &x;
const int * p2 = &x; //NON CONST PTR to CONST INT
int * const p3 = &x;
const int * const p4 = &x;


