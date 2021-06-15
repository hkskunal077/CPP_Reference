#include<iostream>
#include<sstream>
using namespace std;

class rectangle {
    int width, height;
    public:
        void set_values(int, int);
        int area(){return width*height;}
};

void rectangle::set_values(int x, int y){
    width = x;height = y;
}

class circle{
    double radius;
    public:
    circle(double r){radius = r;}
    //circle(double r):radius = r{}
    double circum(){return 2*radius*3.14159;}
};

int main()
{   
    rectangle rect;
    rect.set_values(2, 1);
    cout<<"\nArea "<<rect.area();

    circle foo(10.0);
    circle baz {10.0};

    cout<<foo.circum()<<"\n"<<baz.circum();
    return EXIT_SUCCESS;
}