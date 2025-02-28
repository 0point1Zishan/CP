class Solution {
    public:
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> st(wordList.begin(), wordList.end());
            vector<vector<string>> ans;
            if(st.find(endWord) == st.end())   return ans;
                
            unordered_map<string, vector<string>> par;
            unordered_map<string, int> level;
            queue<string> q;
            q.push(beginWord);
            level[beginWord] = 0;
            
            while(!q.empty()){
                string word = q.front();
                q.pop();
                int cur = level[word];
                
                for(int i = 0; i < word.size(); i++){
                    string temp = word;
                    char ori = temp[i];
    
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == ori)  continue;
                        temp[i] = ch;
    
                        if(st.count(temp)){
                            if(!level.count(temp)){
                                level[temp] = cur + 1;
                                q.push(temp);
                                par[temp].push_back(word);
                            } 
                            else if(level[temp] == cur + 1)   par[temp].push_back(word);
                        }
                    }
                }
            }
            
            vector<string> path;
            function<void(string)> dfs = [&](string word){
                path.push_back(word);
                if(word == beginWord){
                    vector<string> sol = path;
                    reverse(sol.begin(), sol.end());
                    ans.push_back(sol);
                } 
                else{
                    for(auto par : par[word])  dfs(par);
                }
                path.pop_back();
            };
            
            if(level.count(endWord))  dfs(endWord);
            return ans;
        
        }
    };