class Solution {
private:
    void handleNeg(vector<int>& ans, int a){
        
        while(!ans.empty() && ans.back() > 0  && ans.back() <= a){
            if(ans.back() == a){
                ans.pop_back(); return;
            }
            ans.pop_back();
        }
        if(ans.empty() || ans.back() < 0) ans.push_back(-1*a);
    }
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(ans.empty()) ans.push_back(asteroids[i]);
            else{
                if(asteroids[i] < 0){
                    handleNeg(ans, -1 * asteroids[i]);
                }
                else ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};