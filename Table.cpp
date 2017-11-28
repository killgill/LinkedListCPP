// Name: Karan Singh Gill
// USC NetID: karansig
// CSCI 455 PA5
// Fall 2017

// Table.cpp  Table class implementation


/*
 * Modified 11/22/11 by CMB
 *   changed name of constructor formal parameter to match .h file
 */

#include "Table.h"

#include <iostream>
#include <string>
#include <cassert>


// listFuncs.h has the definition of Node and its methods.  -- when
// you complete it it will also have the function prototypes for your
// list functions.  With this #include, you can use Node type (and
// Node*, and ListType), and call those list functions from inside
// your Table methods, below.

#include "listFuncs.h"


//*************************************************************************

//Initializes table with the default hash size. I initially tried to do the
//java thing and call Table::Table(HASH_SIZE), but that does't work in C++
//Though it's inefficient to make all the hashtable elements point to NULL
//it had to be done explicitly in linux and I was plagued by segmentation
//faults when I didn't
Table::Table() {
    hashSize = HASH_SIZE;
    hashTable = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) listInit(hashTable[i]);
    //rather than having to manually sum entries in the hashtable when size is required,
    //I simply use totalEntries to add a constant time operation to all insert/remove
    //operations so that the size of the table can be provided in constant time
    totalEntries = 0;
}

//same as above, but with custom size
Table::Table(unsigned int hSize) {
    hashSize = hSize;
    hashTable = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) listInit(hashTable[i]);
    totalEntries = 0;
}

//looks up the value in the linkedlist in the bucket that corresponds to the key
//no error message if key does not exist, this is handled in grades.cpp if this returns a null pointer
int* Table::lookup(const string &key) {
    ListType foo = hashTable[hashCode(key)];
    return listLookup(key, foo);
}

//removes an element from the relevant linkedlist if it exists and returns true, else returns false
bool Table::remove(const string &key) {
    ListType &foo = hashTable[hashCode(key)];
    if (listRemove(key, foo)) {
        totalEntries--;//decrements totalEntries
        return true;
    }
    return false;
}

//inserts an element in the relevant linkedlist if the key does not already exist
bool Table::insert(const string &key, int value) {
    ListType &foo = hashTable[hashCode(key)]; 
    if (listLookup(key, foo) == NULL) {
        listInsert(key, value, foo);
        totalEntries++;//increments totalEntries
        return true;
    }
    return false;
}

//returns the totalEntries integer
int Table::numEntries() const {
    return totalEntries;
}

//calls the linkedlist print function on every list in the hashtable
void Table::printAll() const {
    for (int i = 0; i < hashSize; i++) listPrint(hashTable[i]);
}

//computes the nonEmpty buckets and maxLength chain stats and prints them and other hash stats
void Table::hashStats(ostream &out) const {
    int nonEmpty = 0;
    int maxLength = 0;
    for (int i = 0; i < hashSize; i++) {
        if (listSize(hashTable[i]) != 0)
            nonEmpty++;
        if (listSize(hashTable[i]) > maxLength) 
            maxLength = listSize(hashTable[i]);
    }
    out << "Number of buckets: " << hashSize << endl;
    out << "Number of entries: " << totalEntries << endl;
    out << "Number of non-empty buckets: " << nonEmpty << endl;
    out << "Longest chain: " << maxLength << endl;
}


// add definitions for your private methods here