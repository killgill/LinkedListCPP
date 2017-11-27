// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017


//*************************************************************************
// Node class definition 
// and declarations for functions on ListType

// Note: we don't need Node in Table.h
// because it's used by the Table class; not by any Table client code.


#ifndef LIST_FUNCS_H
#define LIST_FUNCS_H
  
using namespace std;

struct Node {
  string key;
  int value;

  Node *next;

  Node(const string &theKey, int theValue);

  Node(const string &theKey, int theValue, Node *n);
};


typedef Node * ListType;

//*************************************************************************
//add function headers (aka, function prototypes) for your functions
//that operate on a list here (i.e., each includes a parameter of type
//ListType or ListType&).  No function definitions go in this file.

//Returns the node's address or NULL
void listInit(ListType &list);
void listInsert(string insertKey, int insertValue, ListType &list);
bool listRemove(string removeTarget, ListType &list);
void listPrint(ListType &list);
int* listLookup(string target, ListType &list);
int listNodes(ListType list);












// keep the following line at the end of the file
#endif
