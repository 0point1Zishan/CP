#include <bits/stdc++.h> 


class AutocompleteSystem {
private:
    Trie trie;
    unordered_map<string, int> fre;
    string cur;
    
    vector<string> sugg(Node* node){
        vector<string> s;
        if(!node) return s;
    
        
        auto cmp = [&](pair<int, string>&a, pair<int, string>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        };
        priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
        
        for(auto &it: node->sen){
            pq.push({fre[it], it});
            if(pq.size() > 3) pq.pop();
        }
        
        while(!pq.empty()){
            s.push_back(pq.top().second);
            pq.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
    
public:
    AutocompleteSystem(vector<string> &sentences, vector<int> &times) {
        // Write your code here.
        cur = "";
        int n = sentences.size();
        for(int i = 0; i < n; i++){
            trie.insert(sentences[i]);
            fre[sentences[i]] = times[i];
        }
    }

    vector<string> input(char c) {
        // Write your code here.
        vector<string> ans;
        if(c == '#'){
            trie.insert(cur);
            fre[cur]++;
            cur = "";
            return ans;
        }
        cur.push_back(c);
        Node* node = trie.search(cur);
        return sugg(node);
    }
};