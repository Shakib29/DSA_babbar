// #include<iostream>
// #include<array>

// using namespace std;
 //1.arrat=y
// int main(){
//     int arr[4]={1,2,3,4};
//     array<int,4> a={5,6,7,8};
//     int size=a.size();
//     for(int i=0;i<size;i++){
//        cout<< a[i]<<endl;
//     }
//     cout<<"element at index 2 "<<a.at(2)<<endl;
//     cout<<"empty or not => "<<a.empty()<<endl;
//     cout<<"first element "<<a.front()<<endl;
//     cout<<"last element "<<a.back();
// }

//2.vector

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<int> v; // Empty vector

//     vector<int> a(5, 1); // Vector 'a' with 5 elements, each initialized to 1

//     vector<int> last(a); // Vector 'last' as a copy of 'a'

//     cout << "Print last:" << endl;
//     for (int i : last) { // Corrected loop to iterate over elements of 'last'
//         cout << i << " "; // Print each element
//     }
//     cout << endl;

//     cout << "Capacity -> " << v.capacity() << endl;
//     v.push_back(1);
//     cout << "Capacity -> " << v.capacity() << endl;
//     v.push_back(2);
//     cout << "Capacity -> " << v.capacity() << endl;
//     v.push_back(3);
//     cout << "Capacity -> " << v.capacity() << endl;
//     cout << "Size -> " << v.size() << endl;

//     cout << "Element at 2nd Index -> " << v.at(2) << endl; // Access element at index 2

//     cout << "Front -> " << v.front() << endl; // Access the first element
//     cout << "Back -> " << v.back() << endl; // Access the last element

//     cout << "Before pop:" << endl;
//     for (int i : v) {
//         cout << i << " "; // Print each element before pop
//     }
//     cout << endl;

//     v.pop_back(); // Remove the last element

//     cout << "After pop:" << endl;
//     for (int i : v) {
//         cout << i << " "; // Print each element after pop
//     }
//     cout << endl;

//     return 0;
// }


//3.deque
// #include <iostream>
// #include <deque>
// using namespace std;

// int main() {
//     deque<int> d; // Create an empty deque

//     d.push_back(1); // Add 1 to the back of the deque
//     d.push_front(2); // Add 2 to the front of the deque

//     // Commented out the pop_front operation
//     // d.pop_front();

//     cout << "Print First Index Element -> " << d.at(1) << endl; // Print element at index 1

//     cout << "Front -> " << d.front() << endl; // Access the first element
//     cout << "Back -> " << d.back() << endl; // Access the last element

//     cout << "Empty or not -> " << (d.empty() ? "Yes" : "No") << endl; // Check if deque is empty

//     cout << "Before erase -> " << d.size() << endl; // Print size before erase
//     d.erase(d.begin(), d.begin() + 1); // Erase the first element
//     cout << "After erase -> " << d.size() << endl; // Print size after erase

//     for (int i : d) { // Corrected loop to iterate over elements of 'd'
//         cout << i << endl; // Print each element
//     }

//     return 0;
// }

// 4.list

#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l; // Create an empty list

    list<int> n(5, 100); // Create a list 'n' with 5 elements, each initialized to 100
    cout << "Printing n" << endl;
    for (int i : n) { // Corrected loop to iterate over elements of 'n'
        cout << i << " "; // Print each element
    }
    cout << endl;

    l.push_back(1); // Add 1 to the back of the list
    l.push_front(2); // Add 2 to the front of the list

    cout << "Printing l after push operations" << endl;
    for (int i : l) { // Corrected loop to iterate over elements of 'l'
        cout << i << " "; // Print each element
    }
    cout << endl;

    l.erase(l.begin()); // Erase the first element

    cout << "After erase" << endl;
    for (int i : l) { // Corrected loop to iterate over elements of 'l'
        cout << i << " "; // Print each element
    }
    cout << endl;

    cout << "Size of list -> " << l.size() << endl; // Print the size of the list

    return 0;
}

