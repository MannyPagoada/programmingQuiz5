//
// Created by manuelpagoada on 2/18/23.
//
/***************************************************************************************
*    Title: <title of program/source code>
*    Author: <author(s) names>
*    Date: <date>
*    Code version: <code version>
*    Availability: <where it's located>
*
***************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>

#include "sorted.h"

using namespace std;

int main(){

    //open input and output file
    ifstream input("input.txt");
    ofstream out("output.txt");
    string inputName, outName, outputLabel, command;
    
    int number;
    ItemType item;
    SortedType list;
    bool found;
    int numCommands;
    


    //create sorted arrray with nodes
    
    input >> command;
    numCommands = 0;
    while (command != "Quit")
    {
    out << command;
    if (command == "PutItem")
    {
      input >> number; 
      item.Initialize(number);
      list.PutItem(item);
      item.Print(out);
      out << " is inserted" << endl;
    }
    else if (command == "DeleteItem")
    {
      input >> number;
      item.Initialize(number);
      list.DeleteItem(item);
      item.Print(out);
      out << " is deleted" << endl;
    }
    else if (command == "GetItem")
    {
      input >> number;
      item.Initialize(number);
      list.GetItem(item, found);
      if (found)
        out << number << " found in list." << endl;
      else out << number  << " not in list."  << endl;  
    } 
    else if (command == "GetLength")  
      out << " Length is " << list.GetLength() << endl;
    else if (command == "IsFull")
      if (list.IsFull())
        out << "List is full." << endl;
      else out << "List is not full."  << endl;  
    else if (command == "MakeEmpty")
	  list.MakeEmpty();
	else if (command == "PrintList")
	  PrintList(out, list);
	else cout << " Command not recognized." << endl;
    numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    input >> command;   
  };
 
  cout << "Quit"  << endl << "Testing completed."  << endl;
  input.close();
  out.close();
  return 0;
}


