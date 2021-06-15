#include<iostream>
using namespace std;

// [address of] operator
int myVar;
auto foo = &myVar;

// [reference] operator
int myVarp;
auto foop = &myVarp;
auto baz = *foop;

int main()
{
//Declaring some Pointers
int * number;
char * character;
double * decimals;
//the type is not the type itself
//but the type of data that it points
int * mempointer1, * mempointer2;

int arr[20]; int * arrptr;
arrptr = arr;//we can use the offset 
//to assign values to array elements 
// *p++ == (*)(p++)


return EXIT_SUCCESS;
}