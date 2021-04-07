#include <iostream>
#include <string> // imports more string's functions
using namespace std;

// Without using template
// here, you can only use int
class Number1{
    public:
        int n1, n2;
        int get_sum(){
            return this->n1 + this->n2;
        }
};

// Using template
// here, you can use any data types
// You don't need to have diferent class for int, float, double etc.
// 'num' is just a representor of the data type
// 'num' can be int, float or anything
template <class num>
class Number2{
    public:
        num n1, n2;
        num get_sum(){
            return this->n1 + this->n2;
        }
};

// more than one custom data types
template <class T1, class T2, class T3>
class Number3{
    public:
        T1 n1;
        T2 n2;
        T3 n3;
        void print_sum(){
            cout << this->n1 + this->n2 + this->n3 << endl;
        }
};

// default data types
template <class num=int> // default : num is int
class Number4{
    public:
        num n1, n2;
        num get_sum(){
            return this->n1 + this->n2;
        }
};

// same process for function
template <class T1, class T2>
float avarage(T1 n1, T2 n2){
    return (n1 + n2) / 2.0;
}


int main(){
    Number1 a;
    a.n1 = 45;
    a.n2 = 34;
    cout << a.get_sum() << endl;
    // here, to use float you need to create an another class


    // here, specify what data type you will use, that's it
    Number2 <float> b;
    b.n1 = 7.56;
    b.n2 = 8.56;
    cout << b.get_sum() << endl;

    Number2 <int> c;
    c.n1 = 75;
    c.n2 = 56;
    cout << c.get_sum() << endl;

    Number3 <int, double, float> d; // using multiple template data types
    d.n1 = 75;
    d.n2 = 57.564778;
    d.n3 = 86.14;
    d.print_sum();

    Number4 <> e; // this will use default data types : int
    e.n1 = 78;
    e.n2 = 23;
    cout << e.get_sum() << endl;

    Number4 <float> f; // not using default data types
    f.n1 = 28.58;
    f.n2 = 75.954;
    cout << f.get_sum() << endl;

    cout << avarage(2, 5) << endl;
    cout << avarage(2.14, 8.69) << endl;
    // one function for all kind of data types

    return 0;
}

// but if we have a func for int and then same named func for templated data types,
// then if we call that func with int, first func will be called
// else second func that means func with template will be called

