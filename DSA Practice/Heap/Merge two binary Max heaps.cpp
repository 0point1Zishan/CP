class Solution{
    private:
    void heapify(vector<int>& v, int i){
        int idx = i, l = 2*i + 1, r = 2*i + 2;
        if(l < v.size() && v[idx] < v[l]) idx = l;
        if(r < v.size() && v[idx] < v[r]) idx = r;
        
        if(idx != i){
            swap(v[idx], v[i]);
            heapify(v, idx);
        }
        
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        for(int i = 0; i < m; i++)     a.push_back(b[i]);
        
        for(int i = (n + m) / 2 - 1; i >= 0; i--){
            heapify(a, i);
        }
        return a;
        
    }
};