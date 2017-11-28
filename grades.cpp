// Name: Karan Singh Gill
// USC NetID: karansig
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

//prototypes
void cmd(Table *grades);
void insert(Table *grades);
void change(Table *grades);
void lookup(Table *grades);
void remove(Table *grades);
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
  else    // no command line args given -- use default table size
    grades = new Table();


  grades->hashStats(cout);

  // add more code here
  // Reminder: use -> when calling Table methods, since grades is type Table*

  cmd(grades); //runs the loop that continuosly takes commands from the user

  return 0;
}

//This function takes the grades table as an input and checks the command line for a command.
//Upon receiving a command, it checks to see if the command is valid, and if so,
//it calls the relevant function to execute that command.
void cmd(Table *grades) {
    while (true) {
        cout << "cmd>";//prints cmd>
        string command;
        cin >> command;//writes the first word entered to the string command
        if (command == "insert")
            insert(grades);
        else if (command == "change")
            change(grades);
        else if (command == "lookup")
            lookup(grades);
        else if (command == "remove")
            remove(grades);
        else if (command == "print")
            print(grades);
        else if (command == "size")
            size(grades);
        else if (command == "stats")
            stats(grades);
        else if (command == "help")
            help();
        else if (command == "quit")
            quit();
        else {
            cin.ignore(9000, '\n');//ignores until the end of the line, going back to the beginninf of the loop
            cout << "ERROR: invalid command\n\n" << endl;
            help();
        }
    }
}

//This function inserts a student and a grade if the student is not already present
void insert(Table *grades) {
    string name;
    int score;
    cin >> name >> score;
    if (!grades->insert(name, score))
        cout << "This student is already present in the table" << endl;
}

//This function looks up a student in the table and returns the student's score
void lookup(Table *grades) {
    string name;
    cin >> name;
    int *score = grades->lookup(name);//points at the score
    if (score != NULL)//checks to make sure the key exists
        cout << name << *score << endl;
    else
        cout << "This student is not present in the table" << endl;
}

//This function looks up a student in the table, and if the student is present, removes the entry 
//and adds a new entry with different grades, effectively "changing" the grade
void change(Table *grades) {
    string name;
    int score;
    cin >> name >> score;
    if (grades->remove(name))//only works if name is already present
        grades->insert(name, score);
    else
        cout << "This student is not present in the table" << endl;
}

//This function removes a student and their score from the table if the student is present
void remove(Table *grades) {
    string name;
    cin >> name;
    if (!grades->remove(name))
        cout << "This student is not present in the table" << endl;
}

//This function prints all the students and their grades in no particular order
void print(Table *grades) {
    if (grades->numEntries() > 0)
        grades->printAll();
}

//This function prints number of entries in the table
void size(Table *grades) {
    int entries = grades->numEntries();
    cout << "The total number of entries in the table is: " << entries << endl;
}

//This function prints hashstats
void stats(Table *grades) {
    grades->hashStats(cout);
}

//This function prints out the basic help guide
void help() {
    cout << "insert <name> <score>\n\tInsert this name and score in the grade table. If this name was already present, print a message to that effect, and don't do the insert." << endl;
    cout << "change <name> <newscore> \n\tChange the score for name.Print an appropriate message if this name isn't present." << endl;
    cout << "lookup <name> \n\tLookup the name, and print out his or her score, or a message indicating that student is not in the table." << endl;
    cout << "remove <name> \n\tRemove this student. If this student wasn't in the grade table, print a message to that effect." << endl;
    cout << "print \n\tPrints out all names and scores in the table." << endl;
    cout << "size \n\tPrints out the number of entries in the table." << endl;
    cout << "stats \n\tPrints out statistics about the hash table at this point" << endl;
    cout << "help \n\tPrints out this command summary" << endl;
    cout << "quit \n\tExits the program" << endl;
}

//This function quits the program
void quit() {
    cout << "Exiting the program now" << endl;
    exit(0);
}
