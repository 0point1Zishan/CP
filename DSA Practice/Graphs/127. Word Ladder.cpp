class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(), wordList.end());
            if(st.find(beginWord) != st.end()) st.erase(beginWord);
    
            queue<pair<string, int>> q;
            q.push({beginWord, 1});
    
            while(!q.empty()){
                string w = q.front().first;
                int steps = q.front().second;
                q.pop();
    
                if(w == endWord)  return steps;
                for(int i = 0; i < w.size(); i++){
                    char ori = w[i];
                    for(auto ch = 'a'; ch <= 'z'; ch++){
                        w[i] = ch;
                        if(st.find(w) != st.end()){
                            st.erase(w);
                            q.push({w, steps + 1});
                        }
                    }
                    w[i] = ori;
                }
            }
            return 0;
        }
    };