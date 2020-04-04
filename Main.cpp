#include <iostream>
#include <fstream>
#include "GenStack.h"
#include <stdlib.h>
using namespace std;

int main(){
  //variable declarations
  ifstream input;
  string name;
  string line;
  int lineNumber = 1;
  char answer = 'y';
  GenStack<char> *stack = new GenStack<char>(30);
  do{

  cout << "Welcome to the Delimitar Checker!" << endl;
  cout << "Please enter the name of your file: " << endl;
  cin >> name;
  input.open(name);
//Checking file
  if(!input){
    cout << "unable to open file or file already checked" << endl;
    exit(1);
  }
//Main Loop
  while(!input.eof()){

    getline(input,line);
    for(int i = 0; i < line.length(); ++i){
//Main Check for Delimiters
      if(line[i] == '[' || line[i] == '{' || line[i] == '('){
      stack->push(line.at(i));

    }else{
//Second Check for CLosed dilimiters
      if(line.at(i) == ']' || line.at(i) == '}' || line.at(i) == ')'){
//Wants a buddy but doesn't have one.
        if(stack->isEmpty()){
          cout << "Error on line: " << lineNumber << " \"" << line.at(i) << "\": Does not have a buddy." << endl;
          exit(1);
        }
//Checks that the dilimiter matches
        if((line[i] == ']' && stack->peak() != '[') || (line[i] == '}' && stack->peak() != '{') || (line[i] == ')' && stack->peak() != '(')){
          cout << "Error on line: " << lineNumber << " \"" << line.at(i) << "\": Does not have a buddy." << endl;
          exit(1);
        }
      stack->pop();
      }

    }
    }
    lineNumber ++;
  }
//Ending code
  if(stack->isEmpty()){
    cout << "Your file has no errors" << endl;
  }else{
    cout << stack->size() << " Dalimiters were never matched. Closing Delimitar Expected" << endl;
  }
  cout << "Would you like to go again?(y/n)" << endl;
  cin >> answer;
}while(answer == 'y');
//Close and Delete
  input.close();
  delete stack;
}
