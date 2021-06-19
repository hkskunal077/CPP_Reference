#include<iostream>
using namespace std;

void mighGoWrong(){
    bool error = true;
    if(error){throw "Exception handling error went down";}
}

int main()
{   
    try{
        mighGoWrong();
    }
    catch(int e){cout<<"\nThe error code is "<<e<<"\n";}
    catch(const char * ptr){cout<<"\nError msg is "<<ptr<<"\t"<<*ptr;}
    //Value of poitner is whole address
    //Value of the derefenced pointer is the first element to which it points

    return EXIT_SUCCESS;
}