class Solution {
    public:
        vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
            vector<int> v(1e5 + 1, -1);
            for(int i = 0; i < elements.size(); i++){
                if(v[elements[i]] == -1)     v[elements[i]] = i;
            }
            
            vector<int> ans;
            for(int i = 0; i < groups.size(); i++){
                int k = 1000000000;
                for(int j = 1; j * j <= groups[i]; j++){
        
                    if(groups[i] % j == 0){
                        if(v[j] != -1)   k = min(k, v[j]);
                        
                        int next = groups[i] / j;
                        if(next != j && v[next] != -1)    k = min(k, v[next]);
                    }
                }
                ans.push_back(k == 1000000000 ? -1 : k);
            }
            return ans;
        }
    };