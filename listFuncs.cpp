// Name: Karan Singh Gill
// USC NetID: karansig
// CSCI 455 PA5
// Fall 2017


#include <iostream>

#include <cassert>

#include "listFuncs.h"

using namespace std;

Node::Node(const string &theKey, int theValue) {
  key = theKey;
  value = theValue;
  next = NULL;
}

Node::Node(const string &theKey, int theValue, Node *n) {
  key = theKey;
  value = theValue;
  next = n;
}

//*************************************************************************
// put the function definitions for your list functions below

//sets the head of the list to null since list is initially empty
void listInit(ListType &list) {
    list = NULL;
}

//inserts a node in the list that is passed by reference to the function
void listInsert(string insertKey, int insertValue, ListType &list) {
    Node *newNode = new Node(insertKey, insertValue, list);
    list = newNode;
}

//removes a node from the list that is passed by reference to the function if the node exists
bool listRemove(string removeTarget, ListType &list) {
    Node *curr = list;
    if (curr == NULL)//returns false if the list is empty
      return false;
    //if the first element in the list needs to be removed, it points the list to the second element
    //it then deletes the first element 
    if (curr->key == removeTarget) {
        list = list->next;
        delete curr;
        return true;
    }
    //this loop only examines the node ahead of the current node, and the node ahead of that. The 
    //reason for this is that when I attempted to make the loop examine the current node and the node
    //ahead of the current node, it would cause a segmentation fault if the last item on the list was removed
    //thus, in order to prevent the segmentation fault, this loop looks ahead rather than at the current element
    //this enables the pointer to be correctly set if the last item is deleted
    //as mentioned in the README, a friend from college helped me with this, my original, non-working code that
    //caused seg faults is commented below
    for (Node *curr = list; curr->next != NULL; curr = curr->next) {
        if (curr->next->key == removeTarget) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
    }
    return false;//if nothing works, it returns false
}
//version of function that causes segmentation faults if the tail is deleted and the pointer from the new tail is accessed
//bool listRemove(string removeTarget, ListType &list) {
//    for (Node *curr = list; curr != NULL; curr = curr->next) {
//        if (curr->key == removeTarget) {
//            Node *temp = curr;
//            curr = curr->next;
//            delete temp;
//            return true;
//        }
//    }
//    return false;
//}

//prints every node in the list going from the head to the tail
void listPrint(ListType &list) {
	Node *curr = list;
	while (curr != NULL) {
		cout << curr->key << " " << curr->value << endl;
		curr = curr->next;
	}
}

//returns a pointer to the value of a given key if that key exists in the list otherwise returns null
int* listLookup(string target, ListType &list) {
	for (Node *curr = list; curr != NULL; curr = curr->next)
		if (curr->key == target)
			return &(curr->value);
	return NULL;
}

//computes the size of the list
int listSize(ListType list) {
	int sum = 0;
	for (Node *curr = list; curr != NULL; curr = curr->next) sum++;
	return sum;
}
