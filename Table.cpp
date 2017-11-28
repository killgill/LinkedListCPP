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


Table::Table() {
    hashSize = HASH_SIZE;
    hashTable = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) listInit(hashTable[i]);
    totalEntries = 0;
}


Table::Table(unsigned int hSize) {
    hashSize = hSize;
    hashTable = new ListType[hashSize];
    for (int i = 0; i < hashSize; i++) listInit(hashTable[i]);
    totalEntries = 0;
}


int * Table::lookup(const string &key) {
    ListType foo = hashTable[hashCode(key)];
    return listLookup(key, foo);
}

bool Table::remove(const string &key) {
    ListType &foo = hashTable[hashCode(key)];
    if (listRemove(key, foo)) {
        totalEntries--;
        return true;
    }
    return false;
}

bool Table::insert(const string &key, int value) {
    ListType &foo = hashTable[hashCode(key)]; 
    if (listLookup(key, foo) == NULL) {
        listInsert(key, value, foo);
        totalEntries++;
        return true;
    }
    return false;
}

int Table::numEntries() const {
    return totalEntries;
}


void Table::printAll() const {
    for (int i = 0; i < hashSize; i++) listPrint(hashTable[i]);
}

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