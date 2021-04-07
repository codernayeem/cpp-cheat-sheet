#include <fstream>
#include <iostream>
using namespace std;
 

double division(int a, int b) {
    if( b == 0 )
        throw "Division by zero condition!";
    return (a/b);
}

int main () {
    double z = 0;

    try{
        z = division(50, 0);
    }catch (const char* msg){
        cerr << msg << endl;     // print error message
    }

    try{
        int d = 5.6 / z;
    }catch(...){         // handle any exception
        cout << "Error Found!" << endl;
    }

    return 0;
}