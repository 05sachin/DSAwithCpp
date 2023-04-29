#include<iostream>
using namespace std;
class Fraction{
    private:
        int numerator;
        int denominator;
    public:
        Fraction(int numerator ,int denominator){
            this->numerator=numerator;
            this->denominator=denominator;
        }
        void print(){
            cout <<this->numerator<<"/"<<denominator<<endl;
        }
         
        void simplify(){
            int gcd=1;
            int j=min(this->numerator,this->denominator);
            for(int i=1;i<=j;i++){
                if(this->numerator%i==0 && this->denominator%i==0){
                    gcd=i;
                }
            }
            this->numerator=this->numerator/gcd;
            this->denominator=this->denominator/gcd;
        }
        // pre increment
        Fraction& operator++(){
            numerator=numerator + denominator;
            this->simplify();
            return *this;
        }
        //post increment,nesting is not allowed in post increment op.
        Fraction operator++(int){
            Fraction fnew(numerator,denominator);
            numerator=numerator + denominator;
            simplify();
            fnew.simplify();
            return fnew;
        }

        Fraction& operator+=(Fraction const &f2){
            int lcm=denominator*f2.denominator;
            int x=lcm/denominator;
            int y=lcm/f2.denominator;

            int num=x*numerator + (y*f2.numerator);
            numerator= num;
            denominator=lcm;
            simplify();
            return *this;

        }

};