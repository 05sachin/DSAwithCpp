#include <string>
#include<iostream>
using namespace std;

void keypad(int num, string output){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string input;
    if(num == 0){
        cout<<output<<" ";
        return;
    }
    
        int n = num%10;
        num = num/10;
        switch(n){
            case 2: input = "abc";
                break;
            case 3: input = "def";
                break;
            case 4: input = "ghi";
                break;
            case 5: input = "jkl";
                break;
            case 6: input = "mno";
                break;
            case 7: input = "pqrs";
                break;
            case 8: input = "tuv";
                break;
            case 9: input = "wxyz";
                break;
               
        }
        for(int i=0;i<input.size();i++){
            keypad(num,input[i]+output);

        }
    
}
int main(){
    int n;
    cout<<"enter number"<<endl;
    cin>>n;
    string* op=new string[100];
    keypad( n," ");
    
    
}