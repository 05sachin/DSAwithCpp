#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int> mp;
    //insert
    pair<string,int> p("abc",1);//1
    mp.insert(p);
    mp["def"]=2; // 2

    // find or access
    cout<<"size"<<mp.size()<<endl;
    cout<<mp["abc"]<<endl;
    cout<<mp.at("abc")<<endl;
    // cout<<mp.at("ghi")<<endl;

   cout<<mp["ghi"]<<endl; // automatic fill 0
   cout<<" size "<<mp.size()<<endl;
   
   // check presence 
   if(mp.count("ghi")>0){ // 0 not present,1 present
    cout<<"ghi is present"<<endl;
   }

   // erase
   mp.erase("ghi");
   if(mp.count("ghi")>0){ // 0 not present,1 present
    cout<<"ghi is present"<<endl;
   }
   cout<<" size "<<mp.size()<<endl;

}