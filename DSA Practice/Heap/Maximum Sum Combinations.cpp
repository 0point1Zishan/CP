vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());
    priority_queue<pair<int, pair<int, int>> > pq;
    set<pair<int, int>> s;
    
    pq.push({A[0]+B[0], {0, 0}});
    s.insert({0, 0});
    
    vector<int> ans;
    while(C--){
        auto top = pq.top();
        pq.pop();
        
        int i = top.second.first, j = top.second.second;
        ans.push_back(top.first);
        if(s.find({i+1, j}) == s.end()){
            pq.push({A[i+1] + B[j], {i+1, j}});
            s.insert({i+1, j});
        }
        if(s.find({i, j+1}) == s.end()){
            pq.push({A[i] + B[j+1], {i, j+1}});
            s.insert({i, j+1});
        }
    }
    return ans;
}
