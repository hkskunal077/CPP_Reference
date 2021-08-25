#include <iostream>
#include <string>
#include<limits>
#include<typeinfo>
#include<string>
#include<sstream>
#include<array>
#include<new>
#include<fstream>

using namespace std;
//using a standard namespace helps us allow 
//use the standard functionalities as part of the code

namespace foo { int value() {return 5;}}
namespace bar { const double pi = 3.1416; double value() {return 2*pi;}}

namespace first {int xs=5; float ys=5.5;}
namespace second {int xs= 6; float ys=6.6;}

#define PI 3.141596;
#define NEWLINE '\n'; 
//Preprocessor Definitions
#define TABLE_SIZE 100
//we can have function macro
#define getmin(a,b) ((a)>(b)?(b):(a))
//Macros are not affected by block structures
//They need to be UNDEF
#undef TABLE_SIZE 
#define TABLE_SIZE 200
//These Macros are not much part of the code 
//but just some directions for compiler toolchain executable
#define glue(a, b) a##b
/* 

#if TABLE_SIZE>200
#undef TABLE_SIZE 
#define TABLE_SIZE 100



#elif TABLE_SIZE<50
#undef TABLE_SIZE
#define TABLE_SIZE 50 */

void duplicate (int& a, int& b, int& c) //These parameters are not the values
//but the reference datatype
{
    a*=2;
    b*=2;
    c*=2;
}

string concatenate (string& x, string& y) {return x+y;}
string const_concatenate (const string& x, const string& y) {return x+y;}
inline string inline_concatenate (const string& x, const string& y) {return x+y;} 

long int factorial (int a)
{
    if (a>1) return (a* factorial(a-1));
    else return 1;
}

int operate (int a, int b) {return a*b;}
double operate (double a, double b) {return a/b;}

//typename or class : same meaning
template <class SomeType>
SomeType sum (SomeType a, SomeType b) {return a+b;}
//SomeType is just for referncing purposes

template <class T, class U>
bool are_equal (T a, U b) {return (a==b);}

template <class T, int N>
T fixed_mul (T a) {return a*N;}

void check_version ();
int default_integer_static_storage;

void printarray (int arg[], int length) 
{   cout<<"\n";
    for (int n=0;  n<length; ++n)
    {
        cout<<arg[n]<<" "; 
    }    
}

//This is passing of array by values
void increment_all (int * start, int * stop)
{
    int * current = start;
    while (current!=stop){
        ++(*current);
        ++current;
    }
}

//This is passing of array by references
void print_all (const int * start, const int * stop)
{
    const int * current = start;
    while (current != stop){
        cout<<*current<<"\t";
        ++current;
    }
}

void increase (void* data, int psize)
{
    if (psize == sizeof(char))
    {char* pchar; pchar = (char*)data; ++(*pchar);} //There is type_casting involved

    if(psize == sizeof(int))
    {int* pint; pint = (int*)data; ++(*pint);}
}

int addition (int a, int b)
{return (a+b);}

int subtraction (int a, int b)
{return (a-b);}

int operation (int x, int y, int (*function_to_call)(int, int))
{
    int new_var;
    new_var = (*function_to_call)(x, y);
    return new_var; 

}

struct movies_t {
    string title;
    int year;
} mine, yours;

void printmovie(movies_t movie); //Prototype


class Rectangle {
    int width, height;
public:
    void set_vals (int, int);
    int area() {return width*height;}
};
void Rectangle::set_vals(int x, int y){
    width = x;
    height = y;
}

class Rectangle2 {
    int width, height;
public:
    Rectangle2 (int, int); //Prototype of Ctor
    int area () {return width*height;}
};
Rectangle2::Rectangle2 (int a, int b)
{
    width = a;
    height = b;
}


class Rectangle3 {
    int width, height;
public:
    Rectangle3 ();
    Rectangle3 (int, int);
    int area (void) {return (width*height);}
};
Rectangle3::Rectangle3()
{
    width = 5;
    height = 5;
}
Rectangle3::Rectangle3(int a, int b)
{
    width = a;
    height = b;
}


class CVector{
    public:
    int x, y;
    CVector () {};
    CVector (int a, int b) : x(a), y(b) {}
    CVector operator + (const CVector&); //Prototype
};
CVector CVector::operator+ (const CVector& param){ //Passed as reference for permanent modifications
    CVector temp;
    temp.x = x+param.x;
    temp.y = y+param.y;
    return temp;
}

class Dummy {
    public:
    bool istime (Dummy& param);
};

bool Dummy::istime (Dummy& param)
{
    if (&param == this) return true;
    else return false;
}


class Dummy2 {
    public:
    static int n;
    Dummy2 () {n++;}
};
int Dummy2::n = 0;


class Mycla {
    public:
    int x;
    Mycla (int a) : x{a} {}
    int get() const {return x;}
};

class Myclass {
    int x;
    public:
    Myclass (int val) : x{val} {}
    int& get() {return x;}
    const int& get() const {return x;}
};
void print (const Myclass& arg) //arg being an object of MyClass
// of type const 
{
    cout<<arg.get()<<"\n";
}


template <class type>
class mypair {
    type values[2];
    public:
    mypair (type first, type second) {
        values[0] = first; values[1] = second;
    }
    type sum_function () {return (values[0] + values[1]);}
    type getmax(); //Prototype for template class
}; 
//If we need to define functions outside then we need to mention
//that we are still following the templates
template <class type>
type mypair<type>::getmax() {
    type retval;
    retval = values[0]>values[1] ? values[0] : values[1];
    return retval;
}

template <class type> class mycontainer {
    type element;
    public:
    mycontainer (type arg) : element {arg} {}
    type increase () {return ++element;}
}; //general template

template<> class mycontainer <char> {
    char element;
    public:
        mycontainer (char arg) : element {arg} {}
        char uppercase () {
            if ((element>='a')&&(element<='z'))
            element+='A'-'a'; //Any letter will get uppercase
            return element;
        }
}; //template specialisation


class Example {
    public:
    int total;
    void accumulate (int x) {total+=x;}
};
//INTERNALLY g++ compiler assumes that there is a Ctor and it can be init
//without mentioning anything so any object can be init without mentioning shit

class Example2 {
    public:
    int total;
    Example2 (int initial_value) : total{initial_value} {}
    void accumulate (int x) {total += x;}
};
//Example2 EX(100); This is the correct way of declaring
//Because we have ocerriden the class properties and involvements of default Ctor


class Example3 {
    string data;
    public:
    Example3 (const string& str) : data{str} {}
    Example3 () {}
    const string& content() const {return data; }
};

//DESTRUCTOR
//Necessary cleanup needed by a class when its lifetime ends.
//takes no argument and returns nothing but not even void.

class Example4 {
    string * ptr;
    public:
    //Cotrs
    Example4 () : ptr(new string) {} //here the string will be created but empty
    Example4 (const string& str) : ptr(new string(str)) {} //created and prefilled with the parameter
    //Dtors
    ~Example4 () {delete ptr;}
    //access content
    const string& content() const {return *ptr;}
};

//Copy Constructors
//A CC is a Ctor whose parameter is of type reference to the class
//itself (possibly const qualified access)
//Shallow Copy and a Deep Copy
//Shallow copy - only members of the class
class Example5 {
    string * ptr;
    public:
    Example5 () : ptr(new string) {}
    Example5 (const string& str) : ptr(new string(str)) {}
    ~Example5 () {delete ptr;}
    //The difference is there is no direct assignment 
    //We provide the value using the content operation and not the actual value
    //passed as a const refernce so there is no change
    Example5 (const Example5& x) : ptr(new string(x.content())) {}
    const string& content () const {return *ptr;}
}; //Deep Copy Method
//So during the copy construction, instead of direct passing
//Do have a function that is solely for content retrieval


//Copy Assignment
//This is required when we assign the object values as parameters
//when they are already initialised
//Myclassrator= (const Myclass&);
/* Example5& operator= (const Example5& x){
    delete ptr;
    ptr = new(string(x.content()));
    return *this;
} */

/* Example5&  operator=  (const Example5& x) {
    *ptr = x.content();& ope
    return *this
} */


//Move Ctor 
//when function returns the type of Myclass
//Move Assignment
//when functios'rv is assigned to an already init class
//rvalue references --

class Example6 {
    string * ptr;
    public:
    Example6 (const string& str) : ptr{new string(str)} {}
    ~Example6 () {delete ptr;}
    //Move Constructor
    Example6 (Example6&& x) : ptr(x.ptr) {x.ptr = nullptr;}
    //Move assignment
    Example6& operator= (Example6&& x) {
        delete ptr;
        ptr = x.ptr;
        x.ptr = nullptr;
        return *this;
    }
    //access content
    const string& content() const {return *ptr;}
    //addition
   /*  Example6 operator+ (const Exampl6& rhs) {
        //return Example6(content()+rhs.content());
    }    */                                     
};

//FRIENDS are functions or classes declared with that keyword
class Rectanglef {
    int width, height;
    public:
    Rectanglef() {}
    Rectanglef(int x, int y): width(x), height(y) {}
    int area() {return width*height;}
    friend Rectanglef duplicate (const Rectanglef& param);
};

Rectanglef duplicate (const Rectanglef& param){
    Rectanglef resf;
    resf.width = param.width; // accessing private members
    resf.height = param.height; //accessgin private members 
    return resf;
}

class Square; //Prototyping so that call is not ambiguous

class Rectanglec {
    int width, height;
    public:
    int area() {return (width*height);}
    void convert (Square a);
};

class Square {
    friend class Rectanglec;
    private:
    int side;
    public:
    Square(int a): side{a} {} 
};

void Rectanglec::convert(Square a) {
    width = a.side;
    height = a.side;
}
//Friendship of classes is not transitive
//Unless explicitly mentioned


//Inheritance between classes 
class Polygon {
    protected:  //These ones can be accessed but not the private data members
    int width, height;
    public:
    void set_values (int a, int b)
        {width =a; height= b;}
};

class irectangle : public Polygon {
    public:
    int area()
        {return width*height;}
};

class itriangle : public Polygon {
    public:
    int area()
        {return width*height/2;}
};
// The members inherited by the derived classes 
//have same access permissions as they had in their base class
//This is happening because the inheritance is of the simplest type
//which is public derivation 

//If we have done PROTECTED inheritance, the members public would have become
//protected in the derived classes from the base class


//A publicly derived class would inherit everything except 
//Ctor and Dtor, (operator=), friends, private members

class mother {
    public:
    mother() {cout<<"\nmother has no parameters";}
    mother(int a) {cout<<"\nmother : int param";}
};

class daughter : public mother {
    public:
    daughter (int a) {cout<<"\ndaughter int param";}
};

class son : public mother {
    public:
    son (int a) : mother (a)
    {cout<<"\nson int param";}
};
//The Ctors are called in a specific sequence
//base class first always, and if it in intermediate
//derived classes Ctor derived access Base_Ctor then
//Base_Ctor will be put first



//Multiple Inheritance
//A class may inherit from more than one class by simply specifying more
//base class separateed by commas, in the list of a class base classes.
/* class rectangle : public ploygon, public output
class triangle: public polygon, public output */


//POLYMORPHISM
/* class poly {
    protected:
    int width, height;
    public:
    void set_values (int a, int b)
    {width=a; height=b;}
    
};

class recta : public poly {
    public:
    int area ()
        {return width*height;}
};

class tri : public poly {
   public:
   int area() 
    {return width*height/2;}
}; */


//Virtual Members
class poly {
    protected:
    int width, height;
    public:
    void set_values (int a, int b)
    {width=a; height=b;}
    virtual int area() {return 0;} //VIRTUAL FUNCTION
}; //Virtual allows us to have multiple definition in the derived classes

class recta : public poly {
    public:
    int area ()
        {return width*height;}
};

class tri : public poly {
   public:
   int area() 
    {return width*height/2;}
};
//If we have not named it virtual base class function would have superseeded


//Absrtact Base Class
//they are classes that can only be used as Base Class
//Pure Base Class, allows us to have virtual member functions
//without definition, just the information
class polygon__{
    protected:
    int width, height;
    public:
    void set_values(int a, int b) {width=a, height=b;}
    virtual int area() = 0; //PURE BASING
    void printarea()
        {cout<<this->area();} //this will become rect and tri in derived classes
};
//Even if we have one virtual function it is called pure base class
//These abstract base classes could not be used to instantiate the 
//objects of their type, we can take advantage of its polymorphic
//capabilitites by declaring pointers of its type and then using

//we can use (this) in base class to access its member 
//functions for helping out the derived classes

class polygon_ {
    protected:
    int width, height;
    public:
    polygon_ (int a, int b) : width(a), height(b) {}
    virtual int area (void) =0; //Pure Basing
    void printarea()
        {cout<<"\n"<<this->area();}
};

class rectangle_ : public polygon_ {
    public:
    rectangle_ (int a, int b) : polygon_(a, b) {}
    int area()
        {return width*height;}
};

class triangle_ : public polygon_ {
    public:
    triangle_ (int a, int b) : polygon_ (a, b) {}
    int area ()
        {return width*height/2;}
};

//Implicity Conversion with classes
class A {};

class B {
    public:
    //Conversion from A (Ctor)
    B (const A& x) {}
    //Conversion form A (Assignment)
    B& operator= (const A& x) {return *this;}
    //Conversion to A (A type-cast operator)
    operator A() {return A();}
};

class Base{virtual void dummy() {}};
class Derived : public Base {int a;};


//const_typeCasting
void printo (char * str){
    cout<<"\n"<<str;
}

class myexception {
    virtual const char* what() const throw()
    {
        return "My Exception Handler";
    }
} myex;


int main()
{
cout<< std::boolalpha;
cout<< "Min and Max value of int: " << std::numeric_limits<int>::min() << "\n"<< std::numeric_limits<int>::max()<<"\n";
int var_name = 0;
//C-like init and Constructor-type init and uniform init
int new_var_name (0);
int new_new_var_name {0};
cout<< var_name<<new_var_name<<new_new_var_name<<"\n";

//Type deduction
int foo = 10;
auto bar = foo;
int new_foo = 10;
decltype(new_foo) new_bar;
cout<<new_foo<<"\t"<<new_bar<<"\t" << typeid(new_foo).name()<<"\t"<<typeid(new_bar).name();
cout<<foo<<"\t"<<bar<<"\t"<<typeid(foo).name()<<"\t"<<typeid(bar).name();

string mystring {"This is my fking string"};
cout<<"\n"<<mystring;

string old_new_string = "\nWe can use line continuation character \
now we have two lines for it";
cout<<old_new_string;

const double pi = 3.1415296;
const char tab = '\t';
const char end = '\n';

double r = 5.0;
double circle;
circle = 2 * pi * r;
cout<<end<<"Finding a circle"<< end << circle;


int ctype_declaration = 100;
int x,y;
x = 5;
y= 2+x;
cout<< x<< end << y<<end;
y = 2 + (x = 6);
cout<< x << end << y << end;

/* short-circuit evaluations
if ((i<10) && (++i < n)){}*/

int a,b,c;
a = 2;
b= 7;
c = (a>b) ? a : b;
cout<< c<<a<<b;

int new_var_value {(b = 3, b+10)};
cout<<new_var_value;

int i, ri;
float float_val = 2.62;
i = (int) float_val;
cout<<end<<float_val<<i;
ri = int(float_val);
cout<<end<<float_val<<ri;

int size_of_char = sizeof(char);
cout<<end<<size_of_char<<end;

ios_base::sync_with_stdio(false);
/* string new_string;
cin>> new_string;
//cin always considers spaces as terminating values.
cout<< new_string; 
 */string new_new_string; 
//getline(cin, new_new_string);
//cout<<new_new_string;
//int string_length = sizeof(new_new_string);
//cout<<"\nThe Size is:"<<string_length;
//cout<<"\n"<<string_length/string_length[0];

//stringstreams
string mystr ("1204");
int myint;
stringstream(mystr) >> myint;
//Taking the input from mystr and storing in myint
cout<<end<<myint<<end;

/* string amount;
float iamount;
getline(cin, amount);
cout<<amount<<end;
stringstream(amount) >> iamount;
cout<<iamount<<end;

int number = 10;
while(number > 0){
    //cout<<number<<end;
    --number;
} */

string st;
/* do{
    cout<<"Enter Text: ";
    getline(cin, st);
    cout<< "You entered: "<<st<<end;
} while(st != "goodbye"); */

//We can manipulate multiple initialization parameter 
//for clever working of loops
int n,in;
for(n=1,in=99 ; n!=in ; ++n, --in){cout<<"Loop Still Working\n";}

//Range based looping is acceptable in C++ also now
//for (declaration (iterator) : range(iterable))
string strin {"Hello!!!"};
for (auto c : strin)
{
    cout<<"["<<c<<"]";
}
cout<<end;
//Tip
//Range Based Loops, you can use <auto iterator> which
//will identify the datatype of the underlying range
//Tip
//We use the Jump statements to work with unknown loops
//also for modifying the flow control of the  loops
//Jumping out loop--break
//skipping an iteration--continue

//Functions necessary 
//Parameters passed are used to initialise the variables in Function
int xn=1, yn=3, zn=7;
duplicate(xn, yn, zn);
cout<<"The values of xn, yn and zn are: "<<xn<<yn<<zn;

//Efficiency Consideration and const references
//Parsing using references requires less computational overhead
string stringa {"Efficiency Considerations"}, stringb {" and Const Refernce"};
string stringc = concatenate(stringa, stringb);
cout<<end<<stringc;

//Since we might accidently change values even when not required
//so we use <const references>
stringc = const_concatenate(stringa, stringb);
cout<<end<<stringc;

//for simple functions that require less computational overhead
//we can instead of <calling>, we define where we require it.
//so there is no control transfer, rather it just becomes 
//a series of statements, kinda like <labels>
stringc = inline_concatenate(stringa, stringb);
cout<<end<<stringc;

//There are 3 parts for a function
//Prototyping, Calling, Declaration
//We always need to declare before calling
//To override that we can use 
//prototype, calling and declaration in that order.
//They can also be used in case where two functions
//call each other, but none of them can be defined earlier.

//After protoyping now we move to recurisvity
int num = 10;
cout<<end<<factorial(num);
//const char tab = '\t';
//Functions 101 is completed
//Overloads and Template 
int xx,yy;
double nn,mm;
//cout<<"Enter two ints\n";
//cin>>xx>>yy;
//cout<<"Enter two doubles\n";
//cin>>nn>>mm;
//int returnint = operate(xx, yy);
//double returndouble = operate(nn, mm);
//cout<<end<<returnint<<tab<<returndouble;
//Function Template 
//Overload functions may have the same definition
//Instantiating a template: applying template to 
//create a function using actual values or types
auto summing = sum<int>(xx, yy);
auto floating = sum<float>(2.3, 3.2);
cout<<end<<summing<<tab<<floating;
//Template created perfectly 
//ctrk +o ctrl + k: chord to terminal 
//we can use the SomeType for variable declaration
auto true_value = are_equal <int, float> (10, 10.00);
//we can omit the datatype as long as
//parameter are unabmiguous
cout<<end<<true_value;
//unless explicitly mentioned 
auto mult = fixed_mul <float, 4> (2.3);
cout<<tab<< mult;
mult = fixed_mul <int, 4> (2);
cout<<tab<<mult;
//Non-Type Template Arguments can also be passed
//Value of Template parameter is determined on
//compile time to generate or instantiate
//The non-template type cannot be passed as arguments
cout<<end<<foo::value()<<end<<bar::value()<<end<<bar::pi;
//:: scope resolution operation
//namespaces can be splitted
/* namespace foo {};
namespace bar {};
namespace foo {}; */
//keyword using intrdouces the name into current declarative region
using namespace first;
cout<<end<<xs<<tab<<ys;
//Two avoid confusion we can use 
//compound blocks and have namespaces there
check_version();
//Storage Classes
//Static vs Automatic Storage
//Automatic storage memory can be reused after 
//the scope expires, automatic initialised with undetermined values
//static storgae vars initliased with determined ZERO value.
int not_default_integer_automatic_storage;
float not_default_float_automatic_storage;

cout<<default_integer_static_storage<<tab<<\
not_default_integer_automatic_storage<<tab<<\
not_default_float_automatic_storage;
/* 
NOW WE MOVE ONTO THE COMPUND DATA TYPES  AND OPS--------
--------------------------------------------------------
-------------------------------------------------------- */

//Arrays
//Size must be a static storage before compiling array into memory
//so the [SIZE] must be known for its static allocation
int foo_array[5] = {16, 2, 77, 40, 12071};
//maximum elem that can be initialised are the number of elems
int foo_new_array[] {16, 2, 77, 40, 12071};

//Multi-Dimensional Array
//Not much difference between pseudo-multdim and multdim
//For better readibility use the <macros definitions>

//Passing arrays to functions
//It would be much more economical to pass the address of array
//instead of passing the whole CMA to the function
//So we need some type of reference, faster and efficient ops.
int firstarray[] {5, 10, 15};
int secondarray[] {2, 4, 6, 8, 10};
printarray(firstarray, 3);
printarray(secondarray, 5);

//instead of passing a multi-dimensional array
//as void func (int myarr [n][m])
//pass it as void func (int myarr [][m], int n)
//This explicit mentioning helps in parsing using pointer 
//and helps compiler to know the first amount of data
//for the rest of the depth in multidimensional array, 
//the data is not lost and thus is passed as it is.
//standard: base_type[][base][base] for passing

//For using the <container library array>
array <int, 3> container_library_array {10, 20, 30};
for (unsigned int i=0; i<container_library_array.size(); ++i) {++container_library_array[i];}
for (int elem : container_library_array) {cout<<end<<elem;}
//Now here the array is not the compund data type but the container type
//Container _library_array with parsing into passing to functions
//as the Contiguous Memory Allocation

//CHARACTER SEQUENCES -----------------------------------
//-------------------------------------------------------
//Strings are definitely usedful for the complete abstraction
//For formating and advance working we need to see them
//as  <Array of chars>
//ONLY when we consider strings as  array of char
//there comes a concept of NULL ELEMENT becuse 
//array can containa whole lot of different size of string.
char myword[] {'H','e','l','l','p','\0'};
char myword_literal[] = "Hello";
//Automatic appending of '\0'
//Both arrays of character using null-terminated strings and
//library strings can be used with std::streams like cout, cin.

//Transformation into one another of
//c-str and lib-str
char myntcs[] = "Some Text";
string mylibstring = myntcs;

cout<<end<<mylibstring<<tab<<mylibstring.c_str();

/* POINTERS -----------------------------------------------
-----------------------------------------------------------
----------------------------------------------------------- */
//Address-of-Operator (&)
int myvariable = 200;
auto addr = &myvariable;
//Relation is <Operator Operand>
cout<<end<<addr<<tab<<typeid(addr).name();
//Pi means the pointer to an integer

//Deference Operator (*), value pointer by
//Relationship is <Operator Operand>
auto val_addr = *addr;
cout<<end<<val_addr<<tab<<typeid(val_addr).name();
//Now we know the whole <Reference-Dereference>
//Every pointer is differenct in a sense that the values that
//it points to are different, so the ways are different, so a pointer
//are inherently different for char, int.

//All pointer are going to occupy the same amount of memory, but the data
//they dereferenced to is not going to occupy the same amount of memory

int first_val, second_val;
int*  mypointer;

mypointer = &first_val;
*mypointer = 10;
mypointer = &second_val;
*mypointer = 20;
cout<<end<<first_val<<tab<<second_val;
//One asterisk (*) per pointer is the thumb rule.
int * pointer_1, * pointer_2;
pointer_1 = nullptr;
pointer_2 = pointer_1;
cout<<end<<pointer_1<<tab<<pointer_2;

//Since we pass on the array to functions by using the poiters inherently
//the concept of pointer and arrays are closely related.
int pointer_array[20];
int * pointer_for_array;
cout<<end<<typeid(pointer_array).name()<<tab\
<<typeid(pointer_for_array).name();
//But when we use the name of the array we actually are talking about the address
//Since all other elements are in form of Contiguous Memory Allocation
pointer_for_array = pointer_array;
//arrays cannot be assigned anything, pointer can take and change values automatic storage

int nar[5];
int * point;
point = nar;
*point = 10;
point++;
*point = 20;
point = &nar[2]; *point = 30;
point = nar + 3; *point = 40;
point = nar; *(point+4) = 50;
cout<<end;
for (auto elem: nar) {cout<<elem<<tab;}

int new_var;
int * new_var_pointer = &new_var;
//always look for whether it is dereference or into definition

//Pointer arithmetics
//Only addition and subtraction are allowed
//Behaviour depends upon the size of the data they point
//When adding one pointer, pointer is made to point to the 
//following element of the same type
char * mychar;
short * myshort_ptr;
long * mylong_ptr;
cout<<end<<mychar<<tab<<myshort_ptr<<tab<<mylong_ptr;
cout<<end<<typeid(mychar).name()<<tab<<typeid(myshort_ptr).name()<<\
tab<<typeid(mylong_ptr).name();

/* *p++ - *(p++) dereference unincremented address
*++p - *(++p) dereference incremented address
++*p - increment the value it points to
(*p)++ - post increment the value it points to */

//Pointers and Constants
int xss;
int yss=10;
const int * p = &yss;
xss = *p; 
//This is a pointer in reading mode
//The values cannot be modified, they are just for printing
//We do not make the variables const, the pointer will point
//to some other variable in future 
//But for every variable it can do so only in reading mode

cout<<end;
int nums[] {10, 20, 30};
increment_all (nums, nums+3);
print_all (nums, nums+3);
//We go to the extra element because of the while loop exit condition

/* There are 4 types of relation of pointer and constant
int var;
int * p1 = &var; non-const ptr non-const var
const int * p2 = &var; non-const ptr to constant var
int * const p3 = &var; const ptr to non-cont var
const int * const p4 = &var; const pointer to const integer
 */

//Pointers and String Literals
//String Literal cannot be modifed so relation no 1 is most suited
const char * foo_pointer = "Hello";
//Now even if we do not explicitly create string array and assign to 
//pointer this defination makes much more sense, foo_pointer means "Hello"
//In other words it is the name of the string literal
cout<<end<<*(foo_pointer+4)<<tab<<foo_pointer[4];
//The poitner to a pointer needs to be of different type than
//a data type or a compound data type 
//hence thre are char, char*, char** 

//void pointers
//just like the templates we can create the 
//pointer ops functions that can be easily overloaded
char char1 = 'a';
int int1 = 1602;
increase (&char1, sizeof(char1));
increase (&int1, sizeof(int1));
cout<<end<<char1<<tab<<int1;


//invalid pointers and null pointers
//no matter there is actual content at the address
//or not pointers are permissible to do so
int * unintpointer;
int mynewarr[10];
int * unintqointer = mynewarr + 20;
cout<<end<<unintpointer<<tab<<unintqointer;

//Special val for ZERO pointer
int * null_pointer = 0;
int * null_new_pointer = nullptr;
cout<<end<<null_pointer<<tab<<null_new_pointer;

//Pointer to Functions
int mmm=100, nnn=85;
int (*minus)(int, int) = subtraction;
int (*add)(int, int)= addition;
mmm = operation (mmm, nnn, addition);
nnn = operation (mmm, nnn, minus);
cout<<end<<mmm<<tab<<nnn;


/* DYNAMIC MEMORY ---------------------------------------
------------------------------------------------------
------------------------------------------------------ */

//There are times when memory needs of a program are made known
//only at the runtime,  <new and delete> for user defined dynamic allocations
int * dynamic_pointer;
dynamic_pointer = new int [5]; //Dynamic, allocation on demand 
//If an exeption is thrown and if it is not handled by EXCEPTION HANDLER
//then program execution is terminated.

cout<<end<<dynamic_pointer<<tab<<typeid(dynamic_pointer).name();
for (int i=0; i<5; i++) {cout<<end<<i<<tab<<*(dynamic_pointer+i);}
//Dynamic memory allocated through memory heap
//Since we cannot make sure whether S?F?
//So we need a feedback mechanism for the memory

int * dynamic_pointer_new = new (nothrow) int [5];
//If alloc fails, it points the pointer to nullptr
//Program continues normally, (nothrow) is type of argument for <new>
if (dynamic_pointer_new == nullptr) {cout<<end<<"ERROR IN DYNAMIC ALLOC";}
else {cout<<end<<"DYNAMIC ALLOC SUCCESSFUL\n";}
//Exception handling is generally preferred 

//DELETE and DELETE[]
//delete pointer, delete[] pointer
//Since we are allocating Contiguous Memory
/* nt j, nel;
int * ptr_array;
cout<<"Num of ele ";
cin>>nel;

ptr_array = new (nothrow) int[nel];
if(ptr_array == nullptr) {cout<<"ERROR ALLOC ";}
else{
    for(int k=0;k<nel;k++)
    {
        cout<<"Enter Num ";
        cin>>ptr_array[k];
    }
    cout<<"Dynamic Mem is"<<end;
    for(int g=0;g<nel;g++)
    {
        cout<<*(ptr_array+g);
    }
    delete[] ptr_array;

    /////////////////////////////////////NEED TO DEBUG;
}   */



//DATA STRUCTURES;
string my_movie;

/* mine.title = "2001 A space odyssey";
mine.year = 1968;

cout<<"Enter Title: \n";
getline(cin, yours.title);
cout<<"Enter Year: \n";
getline(cin, my_movie);
stringstream(my_movie) >> yours.year;

cout<<"MFMIS: ";
printmovie(mine);
cout<<"AYIS: ";
printmovie(yours); */
//The most imp feature of DS is that ability to refer to both
//their members individually and even the whole DS as one unit
//We can instantiate the DS as arrays for multiple structures

/* movies_t amovie;
movies_t * ptr_movie;
ptr_movie = &amovie;

cout<<"Enter Title ";
getline(cin, ptr_movie->title);
cout<<"Enter Year ";
getline(cin, my_movie);
stringstream(my_movie) >> ptr_movie->year;

cout<<"\nYour Data ";
cout<<ptr_movie->title;
cout<<" (" <<ptr_movie->year<< ") "; */
//In Data Type we can use Dereference Operator for getting values
//Since the values are custom here, we need to use special operator
//arrow operator (->)

//Nesting Structure Example
/* struct movies_t {
    string title;
    int year;
};
struct friends_t {
    string name;
    string email;
    movies_t favorite_movie;
} charlie, maria;
friends_t * pfriends = & charlie;

Valid Ops
charlie.name;
maria.favorite_movie.title;
charlie.favorite_movie.year;
pfriends->favorite_movie.year; */

union mix_t{
    int l;
    struct {
        short hi;
        short lo;
    };
    char c[4];
} mix;
//All of the elements are woking on 4-Byte Mem, DATA ALLOCATED WILL BE SAME
//THE WAY WE ACCESS IS DIFFERENT

//This DS is capable of holding the title, author, and a cost in two possible formats
//depending upon the programmer, it can be dollars and yen, price can be in any one of them only
struct book_t {
    char title[50];
    char author[50];
    union {
        float dollars;
        int yen;
    };
} book_2;

//The values inside a UNION, DS are Data Type
//In Enumerations, it is DATA VALUE or LITERAL
/* enum colors_t {black, blue, green, cyan, red};
//Values can be assigned like this, need not be literal in the way they are stored
colors_t mycolor = black;
if (mycolor == black) mycolor = cyan;
cout<<end<<mycolor<<tab<<typeid(mycolor).name(); */
enum class colors : int{blue, red, green};
//we use class so that it does not intrinsicly falls to other values 
//the size of the enum ind data will be explivitly mentioned
colors my_col = colors::green;
cout<<typeid(my_col).name();


//CLASSES and OOPS

//Classes (1)
Rectangle rect;
rect.set_vals(3, 4);
cout<<end<<"Area is: "<<rect.area();
//Definition of any function outside or inside
//Not_inline and inline options for Code Optimisation
//The class acts just like a DS and can be overloaded in a sense


//Constructors
//To allow the class to init member variables and allocate storage
Rectangle2 rect2 (4, 5);
cout<<end<<"Area fir Ctor class: "<<rect2.area();
//Arguments passed at the instance class is created 
//Using Ctor, they never return any values  

//Overloading Ctors
Rectangle3 rect3 {}; //The Default Ctor, we do not use brackets 
Rectangle3 rect31 (6, 2);
cout<<end<<rect3.area()<<tab<<rect31.area();

//We are using Ctors as for init function
//we can also do <Member initialisation into it>
//There is nothing returned from a Ctor
//Instead of 
//Rectangle::Rectangle (int a, int b) {width=a, height=b;}
//we use
//Rectangle::Rectangle (int a, int b) : width(a), height(b) {}


//Pointers to Classes
//We can use pointers the same we used them in DS
//Name refers first identity, use arrow ops for access

//Default access of a class 
//by class PRIVATE, by union and struct is PUBLIC


//CLASSES (2) PROPERTIES
//Overload the operators
//This means that if we want to overload some C++ functionalities
//we can do that for customer DS and Data Types
CVector fooc (3, 1);
CVector barr (1, 2);
CVector resultops;

resultops = fooc + barr;
cout<<end<<resultops.x<<","<<resultops.y;

//Usage of <this> keyword
Dummy ap;
Dummy * bp = &ap;
if (bp->istime(ap)) cout<<end<<"Yes, &a is b";
//<this> refers to the pointer of the object 
//whose member function is being executed


//Static Members
Dummy2 a2;
Dummy2 b2[5];
cout<<end<<a2.n;
Dummy2 * c2 = new Dummy2;
cout<<end<<c2->n;
delete c2;
//Static variable being shared by all variables of class

//const member functions
//The access to its data member from outside the class
//is restricted to read-only, as if al its data members were const
//for access them outside class.
//Ctor still called upon and allowed to work
const Mycla foo_clas(10);
//foo_clas.x = 100;
cout<<end<<foo_clas.x<<tab<<foo_clas.get();
//foo_clas.x = 20;
//Everything is in read mode
//The member functions of a const object
//can only be called if they are themselves 
//specified <const> members

//If i access in const mode or read only mode 
//so the data members are constant for those
//accessing the classs from outside
//Ctor still works 

//From an obbject that does the const access of the class 
//member functions can only be accessed if they themselces
//are const members 


//const(1) int& get () const(2) {};
//1--returns a const int&
//2-- can be accessed using the const data object

//Instead of declaraing an object constant we can make sure that
//we pass it as (const Class& obj)

//The better way is to overload constness
//const callls const and non-const calls non-const only


//Class Templates 
mypair<int> myobjtemp (110, 20);
mypair<double> myobjtemp_double (100.02, 200.01);
//cout<<end<<myobjtemp.values[0]<<tab<<myobjtemp.values[1];
cout<<end<<myobjtemp.sum_function();
cout<<end<<myobjtemp_double.sum_function();
cout<<end<<myobjtemp.getmax();
cout<<end<<myobjtemp_double.getmax();

//Sometimes in addition to <templates> we can 
//define special functions which happen once 
//a particular type is passed in the template

//Template Specialisation
mycontainer<int> myintclass (7);
mycontainer<char> mycharclass ('k');
cout<<tab<<myintclass.increase();
//So for the class class only special case works
//cout<<tab<<mycharclass.increase();
cout<<tab<<mycharclass.uppercase();
//Special Case 
// template <class T> class mycontainer { ... }; General
//template <> class mycontainer <char> { ... }; Special (No automatic inheritance, we build new from ground up)

//Next Topic is Special Members
//Special Member Functions are member functions 
//that are implicitly defined as member of classes 
//under certain circumstances
Example3 foo3;
Example3 bar3 ("Preprocessor Directive");

cout<<end<<bar3.content();


//Dtors
Example4 foo4;
Example4 bar4 ("Concurrency and Parallelism");

cout<<end<<bar4.content()<<tab<<foo4.content();


//Deep Copy
Example5 foo5 {"Polymorphisms and Overloads"};
Example5 bar5  = foo5;
//An object of the same type is passed to init
cout<<end<<foo5.content()<<tab<<bar5.content();
/* Example5 baz5 = foo5;
baz5 = bar5;
*///cout<<end<<baz5.content();


/* //Move Ctor and Move Assignment
Example6 foo6 ("File I/O Ops");
Example6 bar6 = Example6(" and Handling");
foo6 = foo6 + bar6;

cout<<end<<foo6.content();
 */


//Friendship-- Friend Function
Rectanglef foof;
Rectanglef barf (2, 3);
foof = duplicate(barf);
cout<<end<<foof.area();

//Friend Class
Rectanglec rectc;
Square sqrc (4);
rectc.convert(sqrc);
cout<<end<<rectc.area();

//INHERITANCE
irectangle irect;
itriangle itrgl;
irect.set_values(4, 5);
itrgl.set_values(4, 5);
cout<<end<<irect.area();
cout<<end<<itrgl.area();


//CTED
daughter kelly(0);
son bud(0);

//Polymorphism
recta rectanglep;
tri trianglep;

poly * ppoly1 = &rectanglep;
poly * ppoly2 = &trianglep;
//Since classes recta n tri have the properties of polygon
//polygon type pointers can be used to access and modufy the data

ppoly1->set_values(4, 5); //we just assign the values using poitners
ppoly2->set_values(4, 5); //we just assign the values using pointers

cout<<end<<rectanglep.area(); //this cannot be accessed by the
cout<<end<<trianglep.area(); //pointer of type Polygon 

cout<<end<<ppoly1->area();
cout<<end<<ppoly2->area();

//COMPLETE OOPS
polygon_ * ppoly1_ = new rectangle_ (4, 5);
polygon_ * ppoly2_ = new triangle_ (4, 5);
//Both Ctors automatically access Ctor of Polygon

ppoly1_->printarea();
ppoly2_->printarea();

delete ppoly1_;
delete ppoly2_;

//Dynamic Allocation, Referencing, Dereferencing, virtual, pure basing





//Type Conversion
//Standard Conversions (short to int, int to float etc)
//promotion (when go to higher type)

//Arrays and functions can be implicitly convert to a pointer

//Implicit Conversion with classes
A fooA;
B barB = fooA;
barB = fooA;
fooA = barB;

//Type Casting
//Addiiton * padd = (Addition*) &d //This is syntactically correct
//But RUNTIME errors.

//So we have used operators for casting
//like in the above example we wanted to convert the pointer types

//Dynamic_Casting, Reinterpret_cast, Static_casting, Const_Casting
//these are specially deisned casts  CAST_TYPE <NEW> (EXPRESSION)


//Dynamic Cast is for pointers and references to classes (also void*)
//for perfecttly assigning poitners of one type to other
try{
    Base * pba = new Derived;
    Base * pbb = new Base;
    Derived * pd;

    pd = dynamic_cast<Derived*>(pba);
    if (pd==0) cout<<end<<"Null pointers on first type-cast";

    pd = dynamic_cast<Derived*>(pbb);
    if (pd == 0) cout<<end<<"Null pointer on second type-cast";
} catch (exception& e) {cout<<end<<"Exception "<< e.what();}


//static_cast
/* class Base {};
class Derived: public Base {};
Base * a = new Base;
Derived * b = static_cast<Derived*>(a); */


//Reinterpret_Cast
//Converts any pointer type to anyother pointer type_info
/* class A { /* ...  };
class B { /* ...  };
A * a = new A;
B * b = reinterpret_cast<B*>(a);  */


//Const_Typing
const char* chj= "Sample Text";
//C cannot change
printo(const_cast<char*>(chj));
const char* chk = "Not text";
//printo(chk);
//Const_Type can add/remove constness

//Typeid
//It can reveal static type as well as dynamic type 


//EXCEPTIONS
//handle RUNTIME errors -- transferring control to
//special functions called handlers
try {
    throw 20; //We throw only when exception arises
}
catch (int e)
{
    cout<<end<<"An exception has occured"<<tab<<e;
}

try {
    //
}
catch(int param) {/**/}
catch(char param) {/**/}
catch(...) {/**/}

//We can use nested try-catch blocks for better control over the program

//We can specifically modify the throw exception
//double myfunction (char param) throw(int);
//all exceptions instead of int will be handled by std::unexpected
//for int type exceptopn it will look for catch block

//There is std::exception that has virtual function with no info
//for specific exception the info about that is called and put upon

/* try {
    throw myex;
}
catch(exception& e)
{cout<<end<<e.what();} */

try{
    int* myarray = new int[1000];
}
catch(exception& e)
{
    cout<<end<<"Standard Exception: "<<e.what();
}

//Preprocessor Directives
//Next up we have preprocessor directive
//This code is not program statements but directives for
//the preprocessor, single line information, (\) can only extend  

//Macros  (#define, #undef)
glue(co, ut)<<end<<TABLE_SIZE;
//MACROS ARE ALWAYS PRESENT
//There are also conditional inclusions (#ifdef, #ifndef etc.)

//So we have always wondered why the header files are placed inside 
//a separate file, we can include them by NOT #include<header>
//but by #include "filename"
//implementation defined header files are included

//There are certain MACROS that are always declared, we are now going to print them
cout<<end<<"Line Number "<<__LINE__;
cout<<end<<"of File "<<__FILE__;
cout<<end<<"its compilation began "<<__DATE__;
cout<<end<<"at "<<__TIME__;
cout<<end<<"and we are running "<<__cplusplus<<" version of C++ Prgramming Language";



//File Handling
//Input/Output With Files
//These streams are actually implemented as a class
//ofstream -- stream class to write on files
//ifstream -- stream class to read from files
//fstream -- stream class to both read and write from/to files

ofstream myfile_one;
myfile_one.open("exmaple_one.txt");
myfile_one<< "File Handling using C++ in-built classes of type of, if and fstream\n";
//myfile.close();

//There are various mode in which we can access the files we have 
//These flags are implemented as bits, so we can use BITWISE OR (|)
//for combining multiple files

ofstream myfile_two;
myfile_two.open("example_two.bin", ios::out | ios::app | ios::binary);
//there are default flags in all i,o,f cases as i,o,(i/o)

//Since open() function being a Ctor, we could have even avoided it
ofstream myfile_three ("example_three.bin", ios::out | ios::app | ios::binary);

//for cross checking whether file is opened or not
if ((myfile_one.is_open()) && (myfile_two.is_open()) && (myfile_three.is_open()))
{cout<<end<<"All files are successfully opened";}

myfile_one.close(); myfile_two.close(); myfile_three.close();
if (!((myfile_one.is_open()) && (myfile_two.is_open()) && (myfile_three.is_open())))
{cout<<end<<"All files are closed now";}
//if the argument insideis true we go down then only

ofstream myfile_four ("example_four.txt");
if (myfile_four.is_open())
{
    myfile_four<<"\n"<<"This is line one";
    myfile_four<<"\n"<<"This is line two";
    myfile_four.close();
}
else cout<<end<<"Unable to open the file";
/* 
string line4;
ifstream myfile4 ("example4.txt");
if (myfile4.is_open())
{
    while ( getline (myfile4, line4) ) 
    {
        cout<<end<<line4;
    }
    myfile4.close();
    
} */

/* try {
    string line_read;
ifstream file_read;
file_read.open("example_one.txt");
if(file_read.is_open()) {while(getline (file_read, line_read)) {cout<<"\n"<<line_read;}}
}
catch (ifstream::failure e) {throw (file_read + string(e.what()))}
 */

string line_read;
fstream file_read ("exmaple_one.txt", ios::in);
if(file_read.is_open()) {while(getline(file_read, line_read)){cout<<"\n"<<line_read;}}
cout<<end<<file_read.bad();// false as the operation executed perfectly
cout<<end<<file_read.eof(); //true as the file has reached its end
//State_Flags that return Bool_values and check for the specific state in the program

//get and put stream positioning
//All the streams object keepp internally at least one internal position
//get and put positions are kept by istream and ostream, f added makes them file stream

//tellg() and tellp() are member functions with no parameters, they return the 
//type streampos.
//seekg() and seekp() are member functions overloaded in 2 ways, they
//are used for changing the location of the streampos 
//seekg/p (position) AND seekg/p (offset, direction)

streampos begin_pos, end_pos;
ifstream file_pos;
file_pos.open("example2.bin", ios::binary);
begin_pos = file_pos.tellg();
file_pos.seekg(0, ios::end);
end_pos = file_pos.tellg();
file_pos.close();
cout<<end<<"File Size: "<<(end_pos-begin_pos)<<" bytes";

//Binary Files
//write() and read() are specifically designed for .bin files
streampos size_pos;
char * memblock;

ifstream file_bin ("example2.bin", ios::in|ios::binary|ios::ate);
if (file_bin.is_open())
{
    size_pos = file_bin.tellg();
    memblock = new char [size_pos];
    file_bin.seekg(0, ios::beg);
    file_bin.read(memblock, size_pos);
    file_bin.close();
    //We can tinker with <memory_allocated> from the file in which we read the content
    cout<<end<<memblock;
    cout<<end<<"The entire file content is in memory ";
    delete[] memblock;
}

//
//we completed this long C++ Core Langauge Features, so I haven't decided the next step in it, but it is important to go for some projects


else {cout<<end<<"Unable to Open the file";}

vector<int>v;
set<int>s;
map<string, int>map;
bitset<32>b32;


return EXIT_SUCCESS;
}

void check_version () 
{
    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
}

void printmovie(movies_t movie)
{
    cout<<movie.title;
    cout<<" ("<<movie.year<<") "<<"\n";
}
