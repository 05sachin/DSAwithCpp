#include<iostream>
#include<climits>
using namespace std;
int LCS(string str1,string str2){
    if(str1.length()==0 || str2.length()==0){
        return 0;
    }
    int ans=0;
    if(str1[0]==str2[0]){
        ans+=1;
        ans += LCS(str1.substr(1),str2.substr(1));
    }else{
        ans +=max(LCS(str1,str2.substr(1)),LCS(str1.substr(1),str2));
    }
    return ans;
}
int LCSMemo(string str1,string str2,int i,int j,int** arr){
    if(i==str1.length() || j==str2.length()){
        return arr[i][j]=0;
    }
    if(arr[i][j]!=-1) return arr[i][j];
    int ans=0;
    if(str1[i]==str2[j]){
        ans+=1;
        ans += LCSMemo(str1,str2,i+1,j+1,arr);
    }else{
        ans +=max(LCSMemo(str1,str2,i,j+1,arr),LCSMemo(str1,str2,i+1,j,arr));
    }
    return arr[i][j]=ans;
}
int LCS_1(string str1,string str2){
    int** arr = new int*[str1.size()+1];
    for(int i=0;i<=str1.length();i++){
        arr[i] = new int[str2.length()+1];
        for(int j=0;j<=str2.length();j++){
            arr[i][j]=-1;
        }
    }
    return LCSMemo(str1,str2,0,0,arr);
}
int LCS_2(string str1,string str2){
    if(str1.length()==0 || str2.length()==0){
        return 0;
    }
    int** arr = new int*[str1.size()+1];
    for(int i=0;i<=str1.length();i++){

        arr[i] = new int[str2.length()+1];
        arr[i][str2.length()]=0;
        if(i==str1.length()){
            for(int j=0;j<=str2.length();j++){
                arr[i][j]=0;
            }
        }
    }

    for(int i=str1.length()-1;i>=0;i--){
        for(int j=str2.length()-1;j>=0;j--){
            int ans=0;
            if(str1[i]==str2[j]){
                
                ans += arr[i+1][j+1]+1;
            }else{
                ans +=max(arr[i][j+1],arr[i+1][j]);
            }
            arr[i][j]=ans;
        }
    }
    return arr[0][0];


}
int main(){
    string str1;
    string str2;
    cin>>str1;
    cin>>str2;
    cout<<LCS(str1,str2)<<endl;
    // cout<<LCS_1(str1,str2)<<endl;
    // cout<<LCS_2(str1,str2)<<endl;
}