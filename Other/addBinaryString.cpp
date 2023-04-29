#include<iostream>
#include<cstring>
using namespace std;

string addBinary(string a, string b) {
        
        string ans="";
        char c='\0';
        while(a.length()!=0&&b.length()!=0){
            int n=a.length();
            int m=b.length();
            int temp=a[n-1]-'0'+b[m-1]-'0';
            if(c!='\0'){
                temp=temp+c-'0';
            }
            
            c=temp/2+'0';
            a=a.substr(0,n-1);
            b=b.substr(0,m-1);

            ans=char(temp%2+'0')+ans;
            


        }
        while(a.length()!=0 && b.length()==0){
            int n=a.length();
            
            int temp=a[n-1]-'0';
            if(c!='\0'){
                temp=temp+c-'0';
            }
            
            c=temp/2+'0';
            a=a.substr(0,n-1);
            

            ans=char(temp%2+'0')+ans;
            


        }
        while(b.length()!=0){
            
            int m=b.length();
            int temp=b[m-1]-'0';
            if(c!='\0'){
                temp=temp+c-'0';
            }
            
            c=temp/2+'0';
            
            b=b.substr(0,m-1);

            ans=char(temp%2+'0')+ans;
            


        }
        ans=c+ans;
        return ans;
    }

int main(){
    string a="11";
    string b="1";
    cout<<addBinary(a,b)<<endl;
    

}