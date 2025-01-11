class Solution {
public:
    vector<int> majorityElement(vector<int>& v) {
        int n = v.size(), cnt1 = 0, cnt2 = 0, e1 = INT_MIN, e2 = INT_MIN;
        for(int i = 0; i < n; i++){
            if(cnt1 == 0 && v[i] != e2){
                e1 = v[i];
                cnt1 = 1;
            }
            else if(cnt2 == 0 && v[i] != e1){
                e2 = v[i];
                cnt2 = 1;
            }
            else if(v[i] == e1) cnt1++;
            else if(v[i] == e2) cnt2++;
            else  cnt1--, cnt2--;
        }
        cnt1 = 0, cnt2 = 0;
        for(int i = 0; i < n; i++){
            if(e1 == v[i]) cnt1++;
            if(e2 == v[i]) cnt2++;
        }
        vector<int> ans;
        if(cnt1 > n/3) ans.push_back(e1);
        if(cnt2 > n/3) ans.push_back(e2);
         
        return ans;
    }
};