#include <iostream>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include "gordonj6h.h"
using namespace std;

void getFilename(const int argc, const char* argv[], Element300); //gets the name of the file
void fillTable(ifstream &inFile, Hash300 &HashTable); //counts the pascal reserved words in the file
/********************************************************************
*** FUNCTION main                                         ***
*********************************************************************
*** DESCRIPTION : Calls all other function to run program       ***
*** INPUT ARGS : const int, const, char* []                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : int                                                 ***
********************************************************************/
int main(const int argc, const char* argv[]){
    Hash300 hasharray;
    Element300 fileName;
    ifstream inFile;

    getFilename(argc, argv, fileName);
    inFile.open(fileName);
    fillTable(inFile, hasharray);
    hasharray.view();
    inFile.close();
    return 0;
}
/********************************************************************
*** FUNCTION getFilename                                        ***
*********************************************************************
*** DESCRIPTION : This function gets the file name of the input file       ***
*** INPUT ARGS : const int, const char* [], Element300                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void getFilename(const int argc, const char* argv[], Element300 fileName){
    if(argc==1){
        cout<<"Enter the name of the file: ";
        cin>>fileName;
    }
    else{
        strcpy(fileName, argv[1]);
    }
}
/********************************************************************
*** FUNCTION fillTable                                         ***
*********************************************************************
*** DESCRIPTION : This function counts the number of pascal words in the file       ***
*** INPUT ARGS : ifstream &, Hash300 &                                       ***
*** OUTPUT ARGS : NONE                                            ***
*** IN/OUT ARGS : NONE                                        ***
*** RETURN : void                                                 ***
********************************************************************/
void fillTable(ifstream &inFile, Hash300 &HashTable){
    if(!inFile){
        cout<< "File was not found."<<endl;
        exit(101);
    }
    int Bindex = 0;
    int Sindex = 0;
    Element300 Big, Small;
    while(!inFile.getline(Big, LINE_SIZE, '\n').eof()){
        cout<<Big<<endl;
        for(int i=0; i<LINE_SIZE; i++){
            if(Big[i] != ' ' && Big[i] != '\0'){
                Small[Sindex] = Big[i];
                Sindex++;
            }

            else{
                Small[Sindex] = '\0';
                HashTable.find(Small);
                Sindex = 0;
            }
            if(Big[i] == '\0'){
                Sindex = 0;
                break;
            }
        }
    }
}
