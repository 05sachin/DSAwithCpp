#include<bits/stdc++.h>
using namespace std;
class Polynomial{
    int *degdata;
    int capacity;
    public:
        
        Polynomial(){
            degdata = new int[5];
            for(int i=0;i<5;i++){
                degdata[i]=0;
            }
            capacity=5;
        }
        
        Polynomial(int cap){
            degdata=new int[cap];
            for(int i=0;i<cap;i++){
                degdata[i]=0;
            }
            capacity=cap;
        }


        Polynomial(Polynomial const &p){
            // this->data=d.data;//shallow copy
            this->degdata=new int[p.capacity];//deep copy 
            for(int i=0;i<p.capacity;i++){
                this->degdata[i]=p.degdata[i];
            }
            this->capacity=p.capacity;
        } 

        void operator=(Polynomial const &p){
            // this->data=d.data;//shallow copy
            int *newdeg=new int[p.capacity];
             //deep copy 
            for(int i=0;i<p.capacity;i++){
                newdeg[i]=p.degdata[i];
            }
            delete [] degdata;
            this->degdata= newdeg;
            this->capacity=p.capacity;
        } 
        
        void setcoeff(int deg,int coeff){
            if(deg>=capacity){
                int newcapacity=deg+1;
                int *newdata =new int[newcapacity];
                for(int i=0;i<capacity;i++){
                    newdata[i]=degdata[i];
                }
                for(int i=capacity;i<newcapacity;i++){
                    newdata[i]=0;
                }
                delete [] degdata;
                degdata=newdata;
                capacity=newcapacity;
            }
            degdata[deg]=coeff;
        }

        int get(int i){
            if(i<capacity){
                return degdata[i];
            }else{
                return 0;
            }
        }
        void print(){
            for(int i=0;i<capacity;i++){
                if(degdata[i]!=0){
                    cout<<degdata[i]<<".x^"<<i<<" ";
                }
            }
            cout<<endl;
        }

        Polynomial operator+(Polynomial const &p){
            int m=max(capacity,p.capacity);
            Polynomial p3(m);


            for(int i=0;i<m;i++){
                if(i<capacity && i<p.capacity){
                    p3.degdata[i]= this->degdata[i]+p.degdata[i];
                }else if(i<capacity){
                    p3.degdata[i]=this->degdata[i];
                }else{
                    p3.degdata[i]=p.degdata[i];
                }
            }
            return p3;
        }
        

        Polynomial operator-(Polynomial const &p){
            int m=max(capacity,p.capacity);
            Polynomial p3(m);

            
            for(int i=0;i<m;i++){
                if(i<capacity && i<p.capacity){
                    p3.degdata[i]= this->degdata[i]-p.degdata[i];
                }else if(i<capacity){
                    p3.degdata[i]=this->degdata[i];
                }else{
                    p3.degdata[i]=-p.degdata[i];
                }
            }
            return p3;
        }

        Polynomial operator*(Polynomial const &p){
            int m=capacity+p.capacity;
            Polynomial p3(m);

            
            for(int i=0;i<capacity;i++){
                for(int j=0;j<p.capacity;j++){
                    p3.degdata[i+j]+=degdata[i]*p.degdata[j];
                }
                
            }
            return p3;
        }
        
         
};