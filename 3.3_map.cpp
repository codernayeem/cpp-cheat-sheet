#include <iostream>
#include <map> // a container of STL
using namespace std;

/*
map is just like dictionary
    * All Operations are Fast except Random Access
More about map : https://www.cplusplus.com/reference/map/map/
*/

template <class T1, class T2>
void display(map<T1, T2> &m){
    for (typename map<T1, T2>::iterator it = m.begin(); it != m.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;
    cout << endl;
}

template <class T1, class T2>
void display_auto(map<T1, T2> &m){
    for (auto& x: m)
        cout << x.first << ": " << x.second << '\n';
    cout << endl;
}

int main(){
    // ways to create map
    map<string, int> map1;
    map1["Robi"] = 80;
    map1["Alif"] = 65;
    map1["Siyam"] = 87;
    map1["Payel"] = 52;

    map<string, int> map2 (map1.begin(), map1.end()); // iterating through map1
    map<string, int> map3(map2);                      // copy of map2
    map<string, int> map4 = { { "alpha", 5 }, { "beta", 6 }, { "gamma", 7 } };

    display(map1);
    display(map2);
    display_auto(map3);
    display_auto(map4);

    // Iterators : it point's to an element of the container
    map<string, int>::iterator it1 = map1.begin(); // Return iterator to beginning
    map<string, int>::iterator it2 = map2.end();   // Return iterator to end
    // Reverse Iterators : It begins from the last and increasing it, wil go towards beginning
    map<string, int>::reverse_iterator r_it1 = map3.rbegin();   // Return reverse iterator to reverse beginning
    map<string, int>::reverse_iterator r_it2 = map2.rbegin();   // Return reverse iterator to reverse end
    cout << "First element of map1 : " << it1->first << " => " << it1->second << endl;
    it1++;
    cout << "2nd element of map1 : " << it1->first << " => " << it1->second << endl;

    // Capacity :
    int size = map1.size();       // Return size
    int m_size = map1.max_size(); // Return maximum size
    if (map1.empty())             // Test whether list is empty
        cout << " map1 is empty" << endl;

    // Element access:
    map4["alpha"] = 10;
    cout << map4["alpha"] << endl;
    map4.at("alpha") = 11;
    cout << map4.at("alpha") << endl; // Access index 2 element

    // Modifires 
    map1.insert(pair<string, int>("You", 60));
    map1.insert(map4.begin(),map4.find("beta"));
    map1.emplace("Shohel", 49);
    it1 = map1.find("Payel");
    map1.erase(it1);
    map4.erase("alpha");
    map1.erase(map1.find("Alif"), map1.end());
    map1.swap(map2);                                // Swap content of map1 and map2
    map1.clear();                                   // Clear content (Delete all elements)

    // Operations :
    it1 = map1.find("Nayeem");
    map<char, short int> map5 = {{'f', 5}, {'d', 3}, {'b', 6}, {'g', 9}};
    for (char c = 'a'; c < 'h'; c++){
        cout << c;
        if (map5.count(c) > 0)      // Count elements with a specific key
            std::cout << " is an element of map5.\n";
        else
            std::cout << " is not an element of map5.\n";
    }
    map<char, short int>::iterator itlow, itup;
    itlow = map5.lower_bound('d');  // itlow points to d
    itup = map5.upper_bound('b');   // itup points to g (not b!)

    pair<map<char, short int>::iterator, map<char, short int>::iterator> ret;
    ret = map5.equal_range('b');    // Get range of equal elements 
    cout << "lower bound points to: ";
    cout << ret.first->first << " => " << ret.first->second << '\n';
    cout << "upper bound points to: ";
    cout << ret.second->first << " => " << ret.second->second << '\n';


    return 0;
}
