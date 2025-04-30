class Solution {
    public:
        long long calculateScore(vector<string>& instructions, vector<int>& values) {
            int n = values.size();
            vector<bool> visited(n, false);
            int i = 0;
            long long ans = 0;
            while(i < n){
                if(instructions[i] == "jump"){
                    visited[i] = true;
                    i += values[i];
                    if(i < 0 || i >= n || visited[i]) return ans;
                }
                else{
                    ans += values[i];
                    visited[i] = true;
                    i++;
                    if(i < 0 || i >= n || visited[i]) return ans;
                }
            }
            return ans;
        }
    };