// Name:
// USC NetID:
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

void listInit(ListType &list) {
	list = NULL;
}

void listInsert(string insertKey, int insertValue, ListType &list) {
	Node *newNode = new Node(insertKey, insertValue, list);
	list = newNode;
}

//fix later
bool listRemove(string removeTarget, ListType &list) {
    if (list == NULL) {
        return false;
    }
    Node *curr = list;
    if (curr->key == removeTarget) {
        list = list->next;
        delete curr;
        return true;
    }
    for (Node *curr = list; curr->next != NULL; curr = curr->next) {
        if (curr->next->key == removeTarget) {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return true;
        }
    }
    return false;
}

void listPrint(ListType &list) {
	Node *curr = list;
	while (curr != NULL) {
		cout << curr->key << " " << curr->value << endl;
		curr = curr->next;
	}
}

int* listLookup(string target, ListType &list) {
	for (Node *curr = list; curr != NULL; curr = curr->next) {
		if (curr->key == target) {
			return &(curr->value);
		}
	}
	return NULL;
}

int listSize(ListType list) {
	int sum = 0;
	for (Node *curr = list; curr != NULL; curr = curr->next) {
		sum++;
	}
	return sum;
}