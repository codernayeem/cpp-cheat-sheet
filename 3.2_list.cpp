#include <iostream>
#include <list> // a container of STL
using namespace std;

/*
    * Random Access        : Slow
    * Middle Insertion     : Fast
    * Ins./Del. at the end : Fast
More about list : https://www.cplusplus.com/reference/list/list/
*/

template <class T>
void display(list<T> &l){
    // Iterators play rols like index
    for (typename list<T>::iterator it = l.begin(); it != l.end(); ++it)
        cout << ' ' << *it;
    cout << endl;
}

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return ((first-second)<5.0); }
};

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first)<int(second) ); }

// comparison, not case sensitive.
bool compare_nocase (const std::string& first, const std::string& second)
{
  unsigned int i=0;
  while ( (i<first.length()) && (i<second.length()) )
  {
    if (tolower(first[i])<tolower(second[i])) return true;
    else if (tolower(first[i])>tolower(second[i])) return false;
    ++i;
  }
  return ( first.length() < second.length() );
}

int main(){
    // ways to create list
    list<int> list1;        // zero length integer list          : 
    list<int> list2(4);     // 4-element integer list            :  0, 0, 0, 0
    list<int> list3(list2);  // 4-element integer list from list2  :  0, 0, 0, 0
    list<int> list4(5, 3);  // 5 element list of 3's             :  3, 3, 3, 3, 3
    list<int> list5 (list4.begin(), list4.end()); // // iterating through list4  : 3, 3, 3, 3, 3

    // the iterator constructor can also be used to construct from arrays:
    int myints[] = {16, 2, 77, 29};
    list<int> list6 (myints, myints + sizeof(myints) / sizeof(int)); // 16, 2, 77, 29
    list<pair<int, string>> list7; // list of (int, string)

    display(list1);
    display(list2);
    display(list3);
    display(list4);
    display(list5);
    display(list6);

    // Iterators : it point's to an element of the container
    display(list4);
    list<int>::iterator it1 = list6.begin(); // Return iterator to beginning
    list<int>::iterator it2 = list4.end();   // Return iterator to end
    // Reverse Iterators : It begins from the last and increasing it, wil go towards beginning
    list<int>::reverse_iterator r_it1 = list3.rbegin();   // Return reverse iterator to reverse beginning
    list<int>::reverse_iterator r_it2 = list2.rbegin();   // Return reverse iterator to reverse end
    cout << "First element of list6 : " << *it1 << endl;
    ++it1;
    cout << "2nd element of list6 : " << *it1 << endl;

    // Capacity :
    int size = list6.size();       // Return size
    int m_size = list6.max_size(); // Return maximum size
    if (list6.empty())             // Test whether list is empty
        cout << " list6 is empty" << endl;

    // Element access:
    int first = list6.front();   // Access the first element
    int last = list6.back();     // Access the last element

    // Modifiers:
    list1.assign(7, 100);                     // 7 ints with value 100
    list2.assign(list1.begin(), list1.end()); // a copy of list2
    int myints2[] = {1776, 7, 4};
    list3.assign (myints2, myints2+3);        // assigning from array
    list3.emplace_front(45);                  // add '45' int at the front
    list1.push_front(57);                     // add '57' int at the front
    list1.pop_front();                        // Delete first element
    list3.emplace_back(45);                   // add '45' int at the end
    list1.push_back(57);                      // add '57' int at the end
    list1.pop_back();                         // Delete last element
    list7.emplace(list7.begin(), 100, "Hi" ); // add (100, "Hi") at the front
    list6.insert(list6.end(), 10);            // same to emplace
    int myarray [] = { 501,502,503 };
    list1.insert (list1.begin(), myarray, myarray+3); // Insert the array at begin
    list1.erase(list1.begin());                       // Erase the first element
    list1.swap(list2);                                // Swap content of list1 and list2
    list1.clear();                                    // Clear content (Delete all elements)

    // Operations :
    list3.remove(45);                 // Remove elements with specific value
    list3.remove_if(is_odd());        // Remove elements fulfilling condition
    list3.remove_if(single_digit);    // Remove elements fulfilling 
    // remove_if function removes all the elements for which the condition is true
    list3.unique();                   // Remove duplicate values
    // list3.unique(is_near());       // Remove duplicate values with custom duplicate validator function

    list3.merge(list4);               // Merge sorted lists. list4 is now empty
    // list5.merge(list6, mycomparison); // Merge sorted lists with custom comparison

    list5.sort();                     // Sort elements in container
    // list3.sort(compare_nocase);    // Sort elements in container with custom comparison

    list5.reverse();                  // Reverse the order of elements

    return 0;
}
