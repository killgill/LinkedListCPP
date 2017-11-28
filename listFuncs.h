// Name: Karan Singh Gill
// USC NetID: karansig
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

//Initializes the list
void listInit(ListType &list);
//inserts element
void listInsert(string insertKey, int insertValue, ListType &list);
//removes element
bool listRemove(string removeTarget, ListType &list);
//prints all elements
void listPrint(ListType &list);
//returns pointer to the value for a given key
int* listLookup(string target, ListType &list);
//computes and returns size of the list
int listSize(ListType list);

// keep the following line at the end of the file
#endif
