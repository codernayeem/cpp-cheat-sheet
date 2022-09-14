#include <iostream>
#include <vector> // a container of STL
using namespace std;

/*
vector is just like array, but it has capacity handling and some other things
    * Random Access        : Fast
    * Insertion / Deletion : Slow
    * Insertion at the end : Fast
More about vector : https://www.cplusplus.com/reference/vector/vector/
*/

template <class T>
void display(vector<T> &v){
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

template <class T>
void display_with_iterator(vector<T> &v){
    // Iterators play rols like index
    for (vector<int>::iterator it = v.begin() ; it != v.end(); ++it)
        cout << *it << ' ';
    cout << endl;
}

template <class T>
void display_auto(vector<T> &v){
    // auto automatically define start & end
    for (auto i: v)
        cout << i << ' ';
    cout << endl;
}

int main(){
    // ways to create vector
    vector<int> vec1;        // zero length integer vector          : 
    vector<int> vec2(4);     // 4-element integer vector            :  0, 0, 0, 0
    vector<int> vec3(vec2);  // 4-element integer vector from vec2  :  0, 0, 0, 0
    vector<int> vec4(5, 3);  // 5 element vector of 3's             :  3, 3, 3, 3, 3
    vector<int> vec5 (vec4.begin(), vec4.end()); // // iterating through vec4  : 3, 3, 3, 3, 3

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    vector<int> vec6 (myints, myints + sizeof(myints) / sizeof(int)); // 16, 2, 77, 29

    display(vec1);
    display(vec2);
    display(vec3);
    display(vec4);
    display(vec5);
    display(vec6);

    // Iterators : it point's to an element of the container
    display_with_iterator(vec4);
    vector<int>::iterator it1 = vec6.begin(); // Return iterator to beginning
    vector<int>::iterator it2 = vec4.end();   // Return iterator to end
    // Reverse Iterators : It begins from the last and increasing it, wil go towards beginning
    vector<int>::reverse_iterator r_it1 = vec3.rbegin();   // Return reverse iterator to reverse beginning
    vector<int>::reverse_iterator r_it2 = vec2.rbegin();   // Return reverse iterator to reverse end
    cout << "3rd element of vec6 : " << *(it1+2) << endl;
    cout << "First element of vec4 : " << *vec4.begin() << endl;

    // Capacity :
    int size = vec6.size();       // Return size
    int m_size = vec6.max_size(); // Return maximum size
    vec6.resize(5);               // Return size of allocated storage capacity
    vec6.capacity();              // Change size
    if (vec6.empty())             // Test whether vector is empty
        cout << " Vec6 is empty" << endl;
    vec6.reserve(5);              // Request a change in capacity
    vec6.shrink_to_fit();         // Shrink to fit. Reduce capacity to size

    // Element access:
    cout << vec6[2] << endl;    // Access index 2 element
    cout << vec6.at(2) << endl; // Access index 2 element
    int first = vec6.front();   // Access the first element
    int last = vec6.back();     // Access the last element
    int* p = vec6.data();       // Returns a direct pointer to the memory array used internally by the vector to store its owned elements 
    
    // Modifiers:
    vec1.push_back(57);                             // Add element at the end
    vec1.pop_back();                                // Delete last element
    vec5.insert(vec5.begin()+2, 5);                 // Insert '5' at 3rd position
    int myarray [] = {501, 502, 503};
    vec5.insert(vec5.begin(), myarray, myarray+3);  // Insert the array at begin
    vec5.erase(vec5.begin()+2);                     // Erase the 3rd element
    vec3.swap(vec2);                                // Swap content of vec3 and vec2
    vec3.clear();                                   // Clear content (Delete all elements)


    return 0;
}
