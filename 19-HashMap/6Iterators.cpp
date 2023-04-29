#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main(){
    unordered_map<string ,int> mp;
    mp["abc"]=1;
    mp["abc1"]=2;
    mp["abc2"]=3;
    mp["abc3"]=4;
    mp["abc4"]=5;
    mp["abc5"]=6;

    unordered_map<string,int>::iterator it=mp.begin();

    while(it!=mp.end()){
        cout<<"key :"<<it->first<<" value: "<<it->second<<endl;
        it++;
    }
    // find
    unordered_map<string,int>::iterator it2=mp.find("abc");
    mp.erase(it2,(it2+2)); 

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    vector<int>::iterator it1=v.begin();
    while(it1!=v.end()){
        cout<<*it1<<endl;
        it1++;
    }

}