vector<int> superiorElements(vector<int>&a) {
    // Write your code here.
    vector<int> v;
    v.push_back(a.back());
    int n = a.size();
    for(int i = n-2; i >= 0; i--){
        if(a[i] > v.back()){
            v.push_back(a[i]);
        }
    }
    return v;
}