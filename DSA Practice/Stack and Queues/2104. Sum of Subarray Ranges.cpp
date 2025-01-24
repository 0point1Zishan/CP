class Solution {
private:
    vector<int> findNse(vector<int>& nums, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();

            v[i] = (st.empty()  ?  n   :   st.top());
            st.push(i);
        }
        return v;
    }
    vector<int> findPsee(vector<int>& nums, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] > nums[i]) st.pop();

            v[i] = (st.empty()  ?  -1   :   st.top());
            st.push(i);
        }
        return v;
    }
    vector<int> findNge(vector<int>& nums, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]) st.pop();

            v[i] = (st.empty()  ?  n   :   st.top());
            st.push(i);
        }
        return v;
    }
    vector<int> findPgee(vector<int>& nums, int n){
        vector<int> v(n);
        stack<int> st;
        for(int i = 0; i < n; i++){
            while(!st.empty() && nums[st.top()] < nums[i]) st.pop();

            v[i] = (st.empty()  ?  -1   :   st.top());
            st.push(i);
        }
        return v;
    }
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> nse = findNse(nums, n);
        vector<int> psee = findPsee(nums, n);

        vector<int> nge = findNge(nums, n);
        vector<int> pgee = findPgee(nums, n);

        long long mn = 0, mx = 0;
        for(int i = 0; i < n; i++){

            int left = i - psee[i];
            int right = nse[i] - i;
            mn += (1LL * left * right  * nums[i]);

            left = i - pgee[i];
            right = nge[i] - i;
            mx += (1LL * left * right * nums[i]);
        }
        return mx - mn;
    }
};