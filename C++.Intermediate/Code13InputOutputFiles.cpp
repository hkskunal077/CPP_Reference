#include<iostream>
#include<fstream>
#include<string>
using namespace std;

//C++ internally have a lot of classes defined which works for 
//specific cause, like ofstream, ifstream, fstream which are classes
//they are derived from library like ostream, istream which are general

//We can combine flags since they are a value in mem using Bitwise OR

//Text Files - seekg, seekp, getline etc
//Binary Files - Dynamic 

int main()
{
    ofstream myfile;
    myfile.open("example.txt");
    if(myfile.is_open());cout<<"Proceeding\n";
    myfile<<"Writing to this file.\n";
    myfile.close();

    string line;
    ifstream file("example.txt");
    if(file.is_open())
    {    while(getline(file, line))
            {cout<<line<<"\n";}
        file.close();
    }else {cout<<"Error!! Unable to Open File";}
    //return 0;

    streampos begin, end;
    ifstream file_("example.txt");
    begin = file_.tellg();
    file_.seekg(0, ios::end);
    end = file_.tellg();
    file_.close();
    cout<<"\nFile Size is "<<(end-begin)<<" bytes\n";

    streampos size;
    char* memblock;

    ifstream binFile("example.bin", ios::in|ios::binary|ios::ate);
    if(binFile.is_open())
    {
        size = binFile.tellg();
        memblock = new char [size];
        binFile.seekg(0, ios::beg);
        binFile.read(memblock, size);
        binFile.close();
        cout<<"\nFile Content is in memory";
        cout<<"\n"<<memblock;

        delete[] memblock;
    }else{cout<<"\nUnable to open file";}

    return 0;
}