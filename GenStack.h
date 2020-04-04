#include<iostream>
using namespace std;

//Class Initilization
template <class T> class GenStack{
public:
//General Fuctions
  GenStack(){
    myArray = new T[50];
    mSize = 50;
    numElements = 0;
    top = -1;
  } //Default Construtor
  GenStack(int maxSize){
    myArray = new T[maxSize];
    mSize = maxSize;

    top = -1;
  } //Overloaded Construtor
  ~GenStack(){
    delete myArray;

  } //desructor
  //Functions
  void push(T data){
    if(!this->isFull()){
    myArray[++top] = data;
    numElements++;
  }else{
    int hold = mSize;
    T *temp = new T[mSize += (mSize / 2)];
    for(int i = 0; i < hold; ++i){
      temp[i] = myArray[i];
    }
    delete myArray;
    myArray = temp;
    myArray[++top] = data;
   }
  }
  T pop(){
    if(!this->isEmpty()){
        numElements--;
        return myArray[top--];
    }
    return -1;
  }
  //Helper Functions
  bool isFull(){
    return (top == mSize-1);
  }
  bool isEmpty(){
    return (top == -1);
  }
  T peak(){
    return myArray[top];
  };
  int size(){
    return numElements;
  }
//Member variables
  int numElements;
  int mSize; //max size of myStackN
  int top; // variable to keep track of indices representing the top of our stack
  T *myArray;
};
