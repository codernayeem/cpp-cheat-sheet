#include <iostream>
#include <string>   // imports more string's functions
using namespace std;

#define pi 3.1416   // defining global constant

class Employee{
    public:
        string name;
        int age;
        int salary;

        Employee(){} // by this, you can create an instance of this class without giving anything

        Employee(string name, int age, int salary){
            // by this, you can create an instance of this class by giving these inputs
            this->name = name;
            this->age = age;
            this->salary = salary;
        }

        void print_salary(){
            cout << "Salary of " << this->name << " : " << this->salary << endl;
        }

        void increase_salary(int quantity){
            this->salary += quantity;
        }
};

// Inheritance
class Desginer : public Employee{
    public:
        int desginer_code;
    
        Desginer(int desginer_code){
            this->desginer_code = desginer_code;
        }

        // overriting methods of Employee
        void increase_salary(int quantity){
            this->salary += quantity + 1000;
        }
};

// function
int sum(int a, int b){
    return a + b;
}


void increase_number(int input[], int output[], int size){
    // if 'input' or 'output' is changed, then it will be also changed where it was declared
    // so, we will use 'input' as input and 'output' as output
    // we will not change 'input'. But using 'input', we will change 'output'
    for (int i=0; i < size; i++)
        output[i] = input[i] + 10; // increase 10
}

int main(){
    cout << "Hi" << endl;

    int a = 8160390;                  // -2147483648 to 2147483647
    short int b = 4586;               // -32768 to 32767
    long int c = 98816030;          // -2,147,483,648 to 2,147,483,647
    long long int d = 455458626467;   // -(2^63) to (2^63)-1

    /* 
        These kind of int has more 2 types:
        unsigned : same range
        signed : 0 to (double range + 1)
    */

    float f1 = 56.898;                // 4 Bytes
    double f2 = 56.898645;            // 8 Bytes
    long double f3 = 56.8987875454;   // 12 Bytes


    char c1 = 't';           // -127 to 127 or 0 to 255
    unsigned char c2 = 'c';  // 0 to 255
    signed char c3 = 'j';    // -127 to 127

    // get the bytes of any types
    cout << "Size of short int : " << sizeof(short int) << endl;
    // Size of short int : 2

    // set constant
    const float i = 56.7; // now value of 'i' can not be changed


    // taking input
    int age;
    cout << "How old are you? " << endl;
    cin >> age;
    cout << "Your age : " << age << endl;
    
    short int number1, number2;
    cout << "A Number => ";
    cin >> number1 >> number2;
    cout << "Addition : " << number1 + number1 << endl;

    // typecast
    int abc = 45;
    float cd = (float) abc / 4;

    // typedef Declarations
    // You can create a new name for an existing type using typedef. Following is the simple syntax to define a new type using typedef −
    // typedef type newname; 
    // For example, the following tells the compiler that feet is another name for int −
    typedef int feet;
    // Now, the following declaration is perfectly legal and creates an integer variable called distance −
    feet distance;


    // enum : special type
    enum color { red, green, blue=5, fail } enum_go;  // defult red = 0
    // each one is 1 greater than the previous
    enum_go = fail;  
    // green = 1, blue=5, fail=6
    cout << enum_go << endl; // print : 6

    // condition
    int n = 5;
    if (n == 0)
        cout << "Zero" << endl;
    else if (n < 0){
        cout << "Negative" << endl;
        cout << "Sorry" << endl;
        // if more than one line, then needs {}
    }else
        cout << "Positive" << endl;


    // switch
    char ch = 'y';
    switch (ch)
    {
    case 'y':
        cout << "Yes" << endl;
        break;
    
    case 'n':
        cout << "No" << endl;
        break;

    default:
        cout << "Ouch" << endl;
        break;
    }

    // while loop
    int nn = 5;
    while (nn < 50)
    {
        nn++;
        cout << nn << endl;
    }

    // do-while loop
    int nnn = 8;
    do{
        nnn--;
        cout << nnn << endl;
    }while (nnn > 0);


    // for loop
    for (int i = 0; i < 9; i++)
        cout << i << endl; // one line, so don't need {}


    // array
    int arr[3] = {5, 7, 3};
    cout << arr[1] << endl; // print 2 no. element : 7 (1 no. index)
    
    // 2D array
    int num[2][3] = {
        {4, 5, 6},
        {8, 9, 15}
    };
    cout << num[0][1] << endl; // print : 5
    
    
    // string
    string name = "Nayeem";
    cout << "My Name : " << name << endl;
    cout << "Length : " << name.length() << endl; // Length : 6
    cout << "My Name : " << name.substr(1, 4) << endl; // aye

    // pointer
    int k = 75;
    int* ptr_k = &k; // store the address of k in ptr_k
    cout << ptr_k << endl; // print the address of k stored in ptr_k
    cout << *ptr_k << endl; // print the value stored at the address : 75
    

    // array can not be passed in function or recived from a function
    // we will use pointer to do that

    int size = 3; // we need to know the size
    int input [size] = {4, 8, 9};
    int output [size]; // we will use this as output
    increase_number(input, output, size);
    // In the function we do not changed input, but we changed output
    // So, here the output variable will also modified
    // That's how we can get an array from a function


    // class and object
    Employee nayeem;
    nayeem.name = "Nayeem";
    nayeem.age = 18;
    nayeem.salary = 10000;
    nayeem.increase_salary(5000);
    nayeem.print_salary();
    cout << "Age : " << nayeem.age << endl;

    Employee rafi = Employee("Rafi", 19, 6000);
    rafi.print_salary();

    // Inherited class
    Desginer korim = Desginer(15);
    korim.name = "Korim";
    korim.salary = 7500;
    korim.increase_salary(500);
    korim.print_salary();

    return 0;
}