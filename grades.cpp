// Name:
// USC NetID:
// CSCI 455 PA5
// Fall 2017

/*
 * grades.cpp
 * A program to test the Table class.
 * How to run it:
 *      grades [hashSize]
 * 
 * the optional argument hashSize is the size of hash table to use.
 * if it's not given, the program uses default size (Table::HASH_SIZE)
 *
 */

#include "Table.h"

// cstdlib needed for call to atoi
#include <cstdlib>

void cmd(Table * grades);
void insert(Table * grades);
void change(Table * grades);
void lookup(Table * grades);
void remove(Table * grades);
void print(Table *grades);
void size(Table *grades);
void stats(Table *grades);
void help();
void quit();


int main(int argc, char * argv[]) {

  // gets the hash table size from the command line

  int hashSize = Table::HASH_SIZE;

  Table * grades;  // Table is dynamically allocated below, so we can call
                   // different constructors depending on input from the user.

  if (argc > 1) {
    hashSize = atoi(argv[1]);  // atoi converts c-string to int

    if (hashSize < 1) {
      cout << "Command line argument (hashSize) must be a positive number" 
	   << endl;
      return 1;
    }

    grades = new Table(hashSize);

  }
  else {   // no command line args given -- use default table size
    grades = new Table();
  }


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*

  cmd(grades);

  return 0;
}

void cmd(Table *grades) {
    while (true) {
        cout << "cmd>";
        string command;
        cin >> command;
        if (command == "insert") {
            insert(grades);
        }
        else if (command == "change") {
            change(grades);
        }
        else if (command == "lookup") {
            lookup(grades);
        }
        else if (command == "remove") {
            remove(grades);
        }
        else if (command == "print") {    // Prints out all names and scores in the table.
            print(grades);
        }
        else if (command == "size") {     // Prints out the number of entries in the table.
            size(grades);
        }
        else if (command == "stats") {    // Prints out statistics about the hash table at this point.
            stats(grades);
        }
        else if (command == "help") {
            help();
        }
        else if (command == "quit") {     // Exits the program.
            quit();
        }
        else {
            cout << "ERROR: invalid command" << endl;
            help();
        }
    }
}

void insert(Table *grades) {
    string name;
    int score;
    cin >> name >> score;
    if (!grades->insert(name, score)) {
        cout << "This student is already present in the table" << endl;
    }
    grades->insert(name, score);
}

void lookup(Table *grades) {
    string name;
    cin >> name;
    int *score = grades->lookup(name);
    if (score != NULL) {
        cout << name << ": " << score << endl;
    } else {
        cout << "This student is not in the table" << endl;
    }
}

void change(Table *grades) {
    string name;
    int score;
    cin >> name >> score;
    if (grades->remove(name)) {
        grades->insert(name, score);
    } else {
        cout << "This student is not present in the table" << endl;
    }

}

void remove(Table *grades) {
    string name;
    cin >> name;
    if (!grades->remove(name)) {
        cout << "This student is not present in the table" << endl;
    }
}

void print(Table *grades) {
    grades->printAll();
}

void size(Table *grades) {
    int entries = grades->numEntries();
    cout << "The total number of entries in the table is: " << entries << endl;
}

void stats(Table *grades) {
    grades->hashStats(cout);
}

void help() {
    cout << "insert <name> <score>\n\tInsert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
    cout << "change name newscore \n\tChange the score for name.Print an appropriate message if this name isn't present." << endl;
    cout << "lookup <name> \n\tLookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
    cout << "remove <name> \n\tRemove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
    cout << "print \n\tPrints out all names and scores in the table." << endl;
    cout << "size \n\tPrints out the number of entries in the table." << endl;
    cout << "stats \n\tPrints out statistics about the hash table at this point" << endl;
    cout << "help \n\tPrints out this command summary" << endl;
    cout << "quit \n\tExits the program" << endl;
}

void quit() {
    cout << "Exiting the program now" << endl;
    exit(0);
}