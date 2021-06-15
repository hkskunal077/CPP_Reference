#include<iostream>
using namespace std;

int operate(int a, int b)
{
    return a*b;
}

double operate(double a, double b)
{
    return a/b;
}

//Function templates
//Functions with generic type inbuilt
template <class someType>
someType sum(someType a, someType b)
{
    return a+b;
}
//There are parameters for templates and
//also for functions in the templates
template <class T, class U>
bool are_equal(T a, U b){return a==b;}

int main()
{
    int x = sum<int>(10, 20);
    cout<< x;
}

 