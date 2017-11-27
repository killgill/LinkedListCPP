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
    listRemove("gaurav",list);
    listInsert("alex", 0, list);
    listInsert("brandon", 2, list);
    listInsert("daniel", 3, list); 
    listInsert("daniel", 3, list); 
    cout << "about to print list" << endl;
    listPrint(list);

    cout << "alex is pledge #" << *listLookup("alex",list) << endl;
    cout << "brandon is pledge #" << *listLookup("brandon",list) << endl;
    cout << "daniel is pledge #" << *listLookup("daniel",list) << endl;

    cout << "numnodes" << listSize(list) << endl;
    listPrint(list);

    listRemove("brandon",list);
    cout << "removed brandon" << endl;
    listPrint(list);

  return 0;
}
