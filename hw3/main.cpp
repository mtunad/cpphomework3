#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#include "IntegerSet.h"

IntegerSet::IntegerSet() {
    for (int i = 0; i < 101; i++) {
        set[i] = false;
    }
}

void IntegerSet::inputSet() {
    int number;
    do
    {
        cout << "Enter number (-1 to finish): ";
        cin >> number;

        if (validityCheck(number)) set[number] = true;
        else if (number != -1) cout << "This is not in range! \n";
        
    } while(number != -1);

    cout << "Set is completed \n";
}

void IntegerSet::printSet() const {
    cout << "( ";
    for (int j = 0; j < 101; j++) {
        if (set[j]) {
            cout << j << " " ;
        }
    }

    cout << ")" << endl;
}

void IntegerSet::unionSet(IntegerSet b, IntegerSet &c) {
    
    for (int i = 0; i < 101; i++)
    {
        c.set[i] = (set[i] || b.set[i]);
    }
}

void IntegerSet::intersectionSet(IntegerSet b, IntegerSet &c) {
    
    for (int i = 0; i < 101; i++)
    {
        c.set[i] = (set[i] && b.set[i]);
    }
}

int main() {
    IntegerSet a;
    IntegerSet b;
    IntegerSet c;

    cout << "Enter a number for A" << endl;
    a.inputSet();
    cout << "Set A is: " << endl;
    a.printSet();

    cout << "Enter a number for B" << endl;
    b.inputSet();
    cout << "Set B is: " << endl;
    b.printSet();

    cout << "Union: ";
    a.unionSet(b, c);
    c.printSet();
    
    cout << "Intersection: ";
    a.intersectionSet(b, c);
    c.printSet();
  
    return 0;
}