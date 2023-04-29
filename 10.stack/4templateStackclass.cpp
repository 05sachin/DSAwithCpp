#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class StackUsingArray{
    T *data;
    int nextIndex; 
    int capacity;
    public:
        StackUsingArray(){
            data=new T[4];
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
        void push(T element){
            if(nextIndex == capacity){
                T *newdata = new T[2*capacity];
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
        T pop(){
            if( isEmpty()/*nextIndex == 0*/){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            nextIndex--;
            return data[nextIndex];
        }
        T top(){
            if( isEmpty()/*nextIndex == 0*/){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            return data[nextIndex-1];
        }
        
};