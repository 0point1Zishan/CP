#include <bits/stdc++.h> 
struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
        void insert(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i], new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        bool checkIfPrefixExists(string &word){
            Node* node = root;
            for(int i = 0; i < word.size(); i++){
                node = node->get(word[i]);
                if(!node->isEnd()) return false;
            }
            return true;
        }
};

string completeString(int n, vector<string> &a){
    // Write your code here.
    Trie trie;
    for(auto &it: a){
        trie.insert(it);
    }

    string longestStr = "";
    for(auto &it: a){
        if(trie.checkIfPrefixExists(it)){
            if(it.size() > longestStr.size()){
                longestStr = it;
            }
            else if(it.size() == longestStr.size()){
                longestStr = min(longestStr, it);
            }
        }
    }

    return (longestStr == "") ? "None" : longestStr;
}