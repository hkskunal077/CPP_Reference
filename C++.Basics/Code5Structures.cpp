#include<iostream>
#include<string>
using namespace std;

struct movies_t
{
    string title;
    int year;

}mine, yours;

void printmovie(movies_t);

int main()
{   
    string myStr;

    mine.title = "21"; mine.year = 324;

    cout<<"Enter name\n";
    getline(cin, yours.title);
    return EXIT_SUCCESS;
}

void printmovie(movies_t movie)
{
    cout<<movie.title<<"\n";
    cout<<movie.year<<"\n";
}