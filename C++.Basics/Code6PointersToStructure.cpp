#include<iostream>
#include<string>
#include<sstream>
using namespace std;

struct movies_t{
    string title;
    int year;
};

movies_t amovie;
movies_t* pmovie;

int main()
{   string myStr;
    pmovie = &amovie;

    cout<<"EnterName\n"; getline(cin, pmovie->title);
    cout<<"EnterYear\n";getline(cin, myStr);
    (stringstream) myStr >> pmovie->year;
    
    return EXIT_SUCCESS;
}