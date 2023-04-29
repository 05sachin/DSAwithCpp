#include<vector>
#include<iostream>
using namespace std;
class MaxPriorityQueue{
    vector<int> pq;
    public:
    MaxPriorityQueue(){

    }

    bool isEmpty(){
        return pq.size()==0;
    }

    int getSize(){
        return pq.size();
    }

    int getMax(){
        if(isEmpty()){
            return 0;
        }
        return pq[0];
    }

    void insert(int element){
        pq.push_back(element);

        int childIndex = pq.size()-1;

        while(childIndex > 0){
            int parentIndex = (childIndex - 1)/2;

            if(pq[childIndex] > pq[parentIndex]){
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }else{
                break;
            }
            childIndex = parentIndex; 
        }
    }

    int removeMax(){
        if(isEmpty()){
            return 0;
        }
        int ans = pq[0];
        int lastIndex = pq.size()-1;
        pq[0] = pq[lastIndex];
        pq.pop_back();
        lastIndex--;

        int parentIndex = 0;
        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex +2;

        while(leftChildIndex <= lastIndex){
            int maxIndex = parentIndex;
            if(pq[maxIndex] < pq[leftChildIndex]){
                maxIndex = leftChildIndex;
            }
            
            if(rightChildIndex <= lastIndex){
                if(pq[maxIndex] < pq[rightChildIndex]){
                    maxIndex = rightChildIndex;
                }
            }
            if(maxIndex==parentIndex){
                return ans;
            }
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex +2;


        }
        return ans;
    }
};