// TO DO: Implement the driver main() function to test your code.
#include <iostream>
#include <string>
using namespace std;

#include "LinkedList.hpp"

template <typename T>
void basicTests(const string& name, LinkedList<T>& list, const T& a, const T& b, const T& c, const T& repl) {
    cout << "\n=============================\n";
    cout << "TESTING: " << name << "\n";
    cout << "=============================\n";

    cout << "Initially empty? " << (list.isEmpty() ? "true" : "false") << "\n";
    cout << "Initial length: " << list.getLength() << "\n";
    cout << "Initial print: " << list;

    // Exception tests on empty
    try {
        cout << "Trying getElement(0) on empty...\n";
        cout << list.getElement(0) << "\n";
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    try {
        cout << "Trying replace(0, repl) on empty...\n";
        list.replace(0, repl);
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    // Append tests
    cout << "\nAppending 3 elements...\n";
    list.append(a);
    list.append(b);
    list.append(c);

    cout << "List now: " << list;
    cout << "Length now: " << list.getLength() << "\n";
    cout << "Empty now? " << (list.isEmpty() ? "true" : "false") << "\n";

    // getElement tests
    cout << "getElement(0): " << list.getElement(0) << "\n";
    cout << "getElement(1): " << list.getElement(1) << "\n";
    cout << "getElement(2): " << list.getElement(2) << "\n";

    // replace tests (head, middle, tail)
    cout << "\nReplacing head (pos 0) with repl...\n";
    list.replace(0, repl);
    cout << "After replace(0): " << list;

    cout << "Replacing middle (pos 1) with repl...\n";
    list.replace(1, repl);
    cout << "After replace(1): " << list;

    cout << "Replacing tail (pos 2) with repl...\n";
    list.replace(2, repl);
    cout << "After replace(2): " << list;

    // Out of range tests
    cout << "\nOut-of-range tests...\n";
    try {
        list.getElement(-1);
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    try {
        list.getElement(list.getLength());
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    try {
        list.replace(list.getLength(), repl);
    } catch (string& e) {
        cout << "Caught exception: " << e << "\n";
    }

    // clear tests
    cout << "\nClearing list...\n";
    list.clear();
    cout << "After clear: " << list;
    cout << "Length after clear: " << list.getLength() << "\n";
    cout << "Empty after clear? " << (list.isEmpty() ? "true" : "false") << "\n";
}

int main() {
    LinkedList<int> intList;
    basicTests("LinkedList<int>", intList, 10, 20, 30, 999);

    LinkedList<string> strList;
    basicTests("LinkedList<string>", strList, string("A"), string("B"), string("C"), string("REPLACED"));

    LinkedList<double> dblList;
    basicTests("LinkedList<double>", dblList, 1.1, 2.2, 3.3, 9.99);

    cout << "\nAll tests done.\n";
    return 0;
}
