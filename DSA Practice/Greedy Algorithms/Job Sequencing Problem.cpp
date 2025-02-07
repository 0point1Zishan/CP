class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        vector<pair<int, int>> pr;
        int n = id.size(), mxD = -1;
        
        for(int i = 0; i < n; i++){
            pr.push_back({profit[i], deadline[i]});
            mxD = max(mxD, deadline[i]);
        }  
        
        sort(pr.begin(), pr.end(), greater<>());
        vector<int> day(mxD+1, -1);
        
        int earn = 0, jobs = 0;
        for(int i = 0; i < n; i++){
            
            for(int j = pr[i].second; j >= 1; j--){
                if(day[j] == -1){
                    earn += pr[i].first;
                    jobs++;
                    day[j] = 1;
                    break;
                }
            }
        }
        return {jobs, earn};
    }
};