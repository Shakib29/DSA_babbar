#include <iostream>
using namespace std;

class animal {
private:
    string name;

public:
          //copy contructor
        animal(animal& temp){
            cout<<"i am a copy constructor"<<endl;
            this->name=temp.name;
        }
    animal() {
        cout << "I am the default constructor" << endl;
    }

    animal(string name) {
        this->name = name;
    }

    string getname() {
        return name;
    }

    void setname(string n) {
        name = n;
    }

    void print() {
        cout << name << endl;
    }

    int num = 10;
    string str = "shakib";
};

int main() {
animal a("tiger");
a.print();
animal b(a);
b.print();










    // animal p("tiger");
    // p.print();
    // cout << p.getname() << endl;
    // p.setname("lion");
    // p.print();
    // cout << sizeof(p) << endl;
    // cout << p.num << endl;
    
    // animal *a = new animal("leopard");
    // a->print();
    // delete a; // Clean up dynamically allocated memory
}
