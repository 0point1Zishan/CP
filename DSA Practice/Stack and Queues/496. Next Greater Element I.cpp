class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        int n = nums2.size();
        vector<int> neg(10001, -1);

        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(!st.empty()) neg[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int> ans;
        for(int i = 0; i < nums1.size(); i++){
            ans.push_back(neg[nums1[i]]);
        }
        return ans;
    }
};