#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void replace(char* input)
{
    if (input[0]=='\0'|| input[1]=='\0')
    {
        return ;
    }
    replace(input + 1);
    if (input[0] == 'p' && input[1] == 'i')
    {   

        for (int i = strlen(input); i >= 2; i--)
        {
            input[i + 2] = input [i];
        }
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
    }
    

}
int main()
{
    char *input = new char[5];
    cin >> input;
    replace(input);
    cout<<input<<endl;
}