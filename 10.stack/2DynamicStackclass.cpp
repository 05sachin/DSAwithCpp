#include<iostream>
#include<climits>
using namespace std;
class StackUsingArray{
    int *data;
    int nextIndex; 
    int capacity;
    public:
        StackUsingArray(){
            data=new int[4];
            nextIndex=0;
            capacity=4;
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
                int *newdata = new int[2*capacity];
                for(int i=0;i<capacity; i++){
                    newdata[i] = data[i];
                }
                capacity*=2;
                delete [] data;
                data = newdata; 
                /*cout<<"Stack full"<<endl;
                return ;*/

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