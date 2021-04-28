#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include "gordonj6h.h"
using namespace std;
/********************************************************************
*** FUNCTION constructor                                        ***
*********************************************************************
*** DESCRIPTION : This function initializes a hash table and fills it       ***
*** INPUT ARGS : NONE                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : N/a                                                ***
********************************************************************/
Hash300::Hash300(){
    this->create();
    this->fill();
}
/********************************************************************
*** FUNCTION destructor                                        ***
*********************************************************************
*** DESCRIPTION : This function clears a hash table       ***
*** INPUT ARGS : NONE                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : N/a                                                 ***
********************************************************************/
Hash300::~Hash300(){
    this->create();
}
/********************************************************************
*** FUNCTION create                                        ***
*********************************************************************
*** DESCRIPTION : This function creates an empty hash table       ***
*** INPUT ARGS : NONE                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void Hash300::create(){
    for (int i=0; i<TABLE_SIZE; i++){
        strcpy(hashTable[i].element, "\0");
        hashTable[i].count = 0;
    }
}
/********************************************************************
*** FUNCTION hashElement                                        ***
*********************************************************************
*** DESCRIPTION : This function finds the address of a reserved word       ***
*** INPUT ARGS : Element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : unsigned                                                 ***
********************************************************************/
unsigned Hash300::hashElement(const Element300 x) const{
    unsigned int len, first, last, address;

    len = strlen(x);
    first = convertChar(x[0]);
    last = convertChar(x[len-1]);
    address = len + first + last;

    return address;
}
/********************************************************************
*** FUNCTION convertChar                                         ***
*********************************************************************
*** DESCRIPTION : This function converts a char to its numerical value       ***
*** INPUT ARGS : const char                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : unsigned                                                 ***
********************************************************************/
unsigned Hash300::convertChar(const char c) const{
    if (c == 'D' || c == 'd' || c == 'E' || c == 'e' ||
        c == 'J' || c == 'j' || c == 'K' || c == 'k' ||
        c == 'O' || c == 'o' || c == 'Q' || c == 'q' ||
        c == 'X' || c == 'x' || c == 'Z' || c == 'z'){
        return 0;
        }
    else if (c == 'A' || c == 'a'){
        return 11;
    }
    else if(c == 'B' || c == 'b' || c == 'F' || c == 'f' ||
            c == 'H' || c == 'h' || c == 'L' || c == 'l' ||
            c == 'M' || c == 'm' || c == 'P' || c == 'p'){
        return 15;
    }
    else if(c == 'I' || c == 'i' || c == 'N' || c == 'n' ||
            c == 'Y' || c == 'y'){
        return 13;
    }
    else if(c == 'R' || c == 'r' || c == 'U' || c == 'u'){
        return 14;
    }
    else if(c == 'S' || c == 's' || c == 'T' || c == 't' ||
            c == 'W' || c == 'w'){
        return 6;
    }
    else if(c == 'C' || c == 'c'){
        return 1;
    }
    else if(c == 'G' || c == 'g'){
        return 3;
    }
    else if(c == 'V' || c == 'v'){
        return 10;
    }
}
/********************************************************************
*** FUNCTION fill                                         ***
*********************************************************************
*** DESCRIPTION : This function fills the hashtable with the pascal reserved words       ***
*** INPUT ARGS : NONE                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void Hash300::fill(){
    Element300 reserve;
    ifstream inFile;
    inFile.open("PRWORDS.DAT");
    if (!inFile){
        cout << "Error: File not found." << endl;
        return;
    }
    else {
        while (inFile >> reserve){
            int hashaddress = hashElement(reserve);
            strcpy(hashTable[hashaddress].element, reserve);
        }
    }
    inFile.close();
    return;
}
/********************************************************************
*** FUNCTION view                                         ***
*********************************************************************
*** DESCRIPTION : This function shows the count and address of hash table elements       ***
*** INPUT ARGS : NONE                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void Hash300::view() const{
    cout<<setw(12)<<left<<"Address"<<setw(20)<<left<<"Reserved Word"<<setw(10)<<right<<"Count"<<endl;
    for(int address=0; address<TABLE_SIZE; address++){
        if((address%20 == 0) && (address!=0)){
            cout<<endl<<"Press enter to show more...";
            cin.get();
            cin.ignore();
            cout<<setw(12)<<left<<"Address"<<setw(20)<<left<<"Reserved Word"<<setw(10)<<right<<"Count"<<endl;
        }

        if(hashTable[address].element[0]){
            cout<<setw(12)<<left<<address<<setw(20)<<left<<hashTable[address].element<<setw(10)<<right<<hashTable[address].count<<endl;

        }
    }
}
/********************************************************************
*** FUNCTION find                                         ***
*********************************************************************
*** DESCRIPTION : This function checks if a c string is in the hash table       ***
*** INPUT ARGS : const Element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void Hash300::find(const Element300 elem){
    bool found = false;
    int i = 0;
    cout<<elem<<endl;
    while(!found){
        if(i==TABLE_SIZE){
            found = true;
        }
        if(strcmp(hashTable[i].element, elem)==0){
            found = true;
            hashTable[i].count++;
        }
        else{
            i++;
        }
    }
}
