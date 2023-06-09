#include<bits/stdc++.h>
using namespace std;
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;
    public:
        
        DynamicArray(){
            data = new int[5];
            nextIndex=0;
            capacity=5;
        }

        DynamicArray(DynamicArray const &d){
            // this->data=d.data;//shallow copy
            this->data=new int[d.capacity];//deep copy 
            for(int i=0;i<nextIndex;i++){
                this->data[i]=d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity=d.capacity;
        } 

        void operator=(DynamicArray const &d){
            // this->data=d.data;//shallow copy
            this->data=new int[d.capacity];//deep copy 
            for(int i=0;i<nextIndex;i++){
                this->data[i]=d.data[i];
            }
            this->nextIndex=d.nextIndex;
            this->capacity=d.capacity;
        } 
        
        void add(int element){
            if(nextIndex==capacity){
                int *newdata =new int[2*capacity];
                for(int i=0;i<capacity;i++){
                    newdata[i]=data[i];
                }
                delete [] data;
                data=newdata;
                capacity*=2;
            }
            data[nextIndex]=element;
            nextIndex++;
        }

        int get(int i){
            if(i<nextIndex){
                return data[i];
            }else{
                return -1;
            }
        }

        void add(int i,int element){
            if(i<nextIndex){
                data[i]=element;
            }else if(i==nextIndex){
                add(element);
            }else
            {
                return; 
            }
            
        }
        void print(){
            for(int i=0;i<nextIndex;i++){
                cout<<data[i]<<" ";
            }
            cout<<endl;
        }
         
};