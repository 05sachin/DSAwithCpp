#include<iostream>
#include<climits>
using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex; 
    int capacity;
    public:
        StackUsingArray(int totalSize){
            data=new int[totalSize];
            nextIndex=0;
            capacity=totalSize;
        }
         // return the number element present in my stack
        int size(){
            return nextIndex;
        }

        // check empty
        bool isEmpty(){
           /* if(nextIndex==0){
                return true;
            }
            return false;*/
            return nextIndex==0;
        }

        // insert element in stack
        void push(int element){
            if(nextIndex == capacity){
                cout<<"Stack full"<<endl;
                return ;
            }
            data[nextIndex] = element;
            nextIndex++;

        }
        // delete element
        int pop(){
            if( isEmpty()/*nextIndex == 0*/){
                cout<<"Stack is empty"<<endl;
                return INT_MIN;
            }
            nextIndex--;
            return data[nextIndex];
        }
        int top(){
            if( isEmpty()/*nextIndex == 0*/){
                cout<<"Stack is empty"<<endl;
                return INT_MIN;
            }
            return data[nextIndex-1];
        }
        
};