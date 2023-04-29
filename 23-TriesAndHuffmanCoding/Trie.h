#include "TrieNode.h"
#include<iostream>

using namespace std;
class Trie{
    TrieNode* root;
    public:

    Trie(){
        root= new TrieNode('\0');
    }

    private:
    void insertWord(TrieNode* root,string word){
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return ;
        }
        // small calculation 

        int index = word[0]-'a';
        TrieNode * child;

        if(root->children[index]!=nullptr){
            child = root->children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // recursive call
        insertWord(child,word.substr(1));
    }

    public:
    void insertWord(string word){
        insertWord(root,word);
    }

    private:
    bool search(TrieNode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode * child;
        if(root->children[index]!=nullptr){
           child = root->children[index];
        }else{
            return false;
        }

        
        return search(child,word.substr(1));
       
    }

    public:
    bool search(string word){
        return search(root,word);
    }

    private:
    void removeWord(TrieNode* root,string word){
        if(word.length()==0){
            root->isTerminal = false;
            return ;
        }
        TrieNode* child;
        int index = word[0]-'a';
        if(root->children[index]!=nullptr){
            child=root->children[index];
        }else{
            return ;
        }
        removeWord(child,word.substr(1));

        // remove child node if it is useless
        if(child->isTerminal==false){
            for(int i=0;i<26;i++){
                if(child->children[i]!=nullptr){
                    return ;
                }
            }
        }
        delete child;
        root->children[index]=nullptr;
    }

    public:
    void removeWord(string word){
        removeWord(root,word);
    }
};