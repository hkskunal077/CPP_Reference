#include<iostream>
using namespace std;

int addition(int a, int b)
{
    int r;
    r = a+b;

    return r;
}

//The way we pass these arguments is important 
//here they are passed by reference having the
//properties of passed values as a refernce to
//some variable, here a, b, c
void duplicate(int& a, int& b, int& c)
{
    a*=2;
    b*=2;
    c*=2;
}

//Efficiency considerations and const refernces
string concatenate(string& a, string& b)
{
    return a+b;
}

//Qualifying these formal referene parameters as
//constants will make us not modify accidently
inline string concatenate_const(const string& a, const string& b)
{
    return a+b;
}

//Case where we need functional declaration before
//calling and definition outside of main.cpp
//We do this so that we can use the function even 
//before calling it, we have declared it.

int protofunction(int, int);

void odd(int);
void even(int);

int main()
{   
   
   int znew = addition(5, 2);
   cout<<"\n"<<znew<<"\n";

    int x=1, y=3, z=7;
    duplicate(x, y, z);
    cout<<x<<y<<z<<"\n";

    string a = "Heya Whatsup!"; 
    string b = " Nah man not enough cool\n";

    string c = concatenate_const(a, b);
    cout<<"\n"<<c;

   return EXIT_SUCCESS;

}

