#include<iostream>
using namespace std;

//to construct using the ideas of OOPS
class Example{
    string data;
public:
    Example(const string& str): data(str) {}
    Example() {}
    //Best way to access, abstract and encapsulated
    const string& content() const {return data;}  
};

class Example4{
    string * ptr;
public:
    Example4(): ptr(new string){}
    //We can initialize the string value as a function
    Example4(const string& str): ptr(new string(str)){}
    ~Example4(){delete ptr;}
    const string& content() const{return *ptr;}
};

class Rectangle_{
    int width, height;
public:
    Rectangle_(){}
    Rectangle_(int x, int y): width(x), height(y) {}
    int area() {return width*height;}
    //Friend Function Definition
    friend Rectangle_ duplicate (const Rectangle_&);
};

Rectangle_ duplicate(const Rectangle_& param)
{
    Rectangle_ res;
    res.width = param.width*2;
    res.height = param.height*2;
    return res;
}



int main()
{
    Example foo;
    
    string data;
    cout<<"Enter String Data\n";
    getline(cin, data);
    
    Example bar(data);

    cout<<"Classes Content\n"<<foo.content()<<"\n"<<bar.content();

    return EXIT_SUCCESS;


}