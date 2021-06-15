#include<iostream>
using namespace std;

//We can overload some of the possible operators
//so that basic operators can now be used with classes
class CVector
{
    public:
    int x, y;
    CVector () {}
    CVector (int a, int b): x(a), y(b){}
    CVector operator+ (const CVector&);
};

CVector CVector::operator + (const CVector& param)
{
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

template <class T>
class myContainer {
    T element;
public:
    myContainer (T arg) {element = arg;}
    T increase () {return ++element;}
};

template<>
class myContainer <char> {
    char element;
public:
    myContainer (char arg) {element = arg;}
    char uppercase() 
    {
        if((element>='a')&&(element<='z'))
        element+='A'-'a';
        return element;
    }
};

int main()
{
    myContainer<int>myint(7);
    myContainer<char>mychar('j');

    cout<<myint.increase()<<"\n";
    cout<<mychar.uppercase()<<"\n";
    return EXIT_SUCCESS;
}