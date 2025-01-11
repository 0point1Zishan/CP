vector<int> alternateNumbers(vector<int>&a) {
    // Write your code here.
    int pos = 0, neg = 1, n = a.size();
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            ans[pos] = a[i];
            pos += 2;
        }
        else{
            ans[neg] = a[i];
            neg += 2;
        }
    }return ans;
}