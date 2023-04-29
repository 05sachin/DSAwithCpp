#include<iostream>
using namespace std;
class Complex{
    private:
        int R;
        int I;
    public:
        Complex(int R,int I){
            this->R=R;
            this->I=I;
        }
        void print(){
            cout<< this->R <<" + "<<"i"<<this->I<<endl;

        }
        void plus(Complex const &c2){
            R=R + c2.R;
            I=I + c2.I;
        }
        void mul(Complex const &c2){
            int x = this->R * c2.R - (this->I * c2.I);
            int y = (this->R * c2.I) + (this->I * c2.R);
            R=x;
            I=y;
        }

};