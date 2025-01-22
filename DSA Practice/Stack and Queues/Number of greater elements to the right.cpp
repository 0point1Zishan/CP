class Solution{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
        //write your code here
        vector<int> neg(n, 0);
        stack<int> st;
        
        for(int i = n-1; i >= 0; i--){
            if(st.empty()) st.push(arr[i]);
            
            else{
                stack<int> t;
                int cnt = 0;
                while(!st.empty() && st.top() > arr[i]){
                    t.push(st.top());   st.pop();
                    cnt++;
                }
                neg[i] = cnt;
                st.push(arr[i]);
                
                while(!t.empty()) st.push(t.top()), t.pop();
            }
        }
        
        vector<int>ans(queries, 0);
        for(int i = 0; i < queries; i++) ans[i] = neg[indices[i]];
        
        return ans;
       
    }

};