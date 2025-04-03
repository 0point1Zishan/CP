class Solution {
    public:
        bool containsDuplicate(vector<int>& nums) {
            unordered_set<int> st;
            for(auto &it: nums){
                if(st.find(it) == st.end()){
                    st.insert(it);
                }
                else return true;
            }
            return false;
        }
    };