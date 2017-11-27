// Name:
// USC NetID:
// CS 455 PA5

// pa5list.cpp
// a program to test the linked list code necessary for a hash table chain

// You are not required to submit this program for pa5.

// We gave you this starter file for it so you don't have to figure
// out the #include stuff.  The code that's being tested will be in
// listFuncs.cpp, which uses the header file listFuncs.h

// The pa5 Makefile includes a rule that compiles these two modules
// into one executable.

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

#include "listFuncs.h"


int main() {

    cout << "starting the tester" << endl;

    Node *list;
    listInit(list);
    listPrint(list);
    listRemove("gaurav");
    listInsert(list, "alex", 0);
    listInsert(list, "brandon", 2);
    listInsert(list, "daniel", 3);
    listPrint(list);

    cout << "alex is pledge #" << *listLookup("alex") << endl;
    cout << "brandon is pledge #" << *listLookup("brandon") << endl;
    cout << "daniel is pledge #" << *listLookup("daniel") << endl;

    cout << "numnodes" << listNodes(list) << endl;
    listPrint(list);

    listRemove("brandon");
    cout << "removed element" << endl;
    listPrint(list);

  return 0;
}
