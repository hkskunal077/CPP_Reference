#include<iostream>
using namespace std;

class Example{
    public:
        int total;
        void accumulate(int x){total+=x;}
};
//No explicit mentions, hence contains a default constructor

class Example2{
    public:
        int total;
        Example2 (int initial_values): total(initial_values){}
        void accumulate(int x) {total+=x;}
};

//We need to explicitly define how we want the Constructors to work
class Example3{
    string data;
    public:
        Example3(const string& str): data(str){}
        Example3(){}
        const string& content() const {return data;}
        //we assign this function the constant return type
        //so that overhead is removed and no manipulation
};

class Example4{
    string* ptr;
    public:
        //assigns uninit string
        Example4(): ptr(new string) {}
        //assigns init string
        Example4(const string& str): ptr(new string(str)) {}
        ~Example4(){delete ptr;}
        //access content without modifications
        const string& content() const{return *ptr;}
};

//for copy construction we need deep instead of shallow copy
class Example5{
    string * ptr;
    public:
        Example5(const string& str): ptr(new string(str)){}
        ~Example5(){delete ptr;}
        //CC
        Example5(const Example5& x): ptr(new string(x.content())){}
        //access content
        const string& content() const {return* ptr;}
};

int main()
{   
    Example5 foo {"Example"};
    Example5 bar{foo};
    cout<<foo.content()<<"\n"<<bar.content()<<"\n";  
    return EXIT_SUCCESS;
}