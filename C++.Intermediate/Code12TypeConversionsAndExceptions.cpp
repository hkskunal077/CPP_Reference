#include<iostream>
#include<sstream>
using namespace std;

//Implicit Conversions, S-I, I-F, D-I
//Promotion-always correct, Demotion-Not always correct

class myexception: public exception
{
    virtual const char* what() const throw(){return "Handeled";}
}myex;

class A{};
class B{
public:
    B(const A& x){}
    B& operator= (const A& x) {return *this;}
    operator A() {return A();}
};

//Type Casting
//dynamic, reinterpret, static and constant casting

int main()
{
    try{
        throw 20;
    }
    catch(int e){cout<<e;}
    catch(char param){throw;}
    catch(...){}

    try{throw myex;}
    catch(exception& e){cout<<"\n"<<e.what();}

    return EXIT_SUCCESS;

}