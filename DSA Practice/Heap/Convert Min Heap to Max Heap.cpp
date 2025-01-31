//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void heapify(vector<int>& v, int i){
        int idx = i;
        int left = 2 * i + 1, right = 2 * i + 2;
        
        if(left < v.size() && v[idx] < v[left])   idx = left;
        if(right < v.size() && v[idx] < v[right]) idx = right;
        
        if(idx != i){
            swap(v[idx], v[i]);
            heapify(v, idx);
        }
    }
public:
    void convertMinToMaxHeap(vector<int> &arr, int N){
        for(int i = N/2 - i; i >= 0; i--){
            heapify(arr, i);
        }
    }
    
};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        obj.convertMinToMaxHeap(vec,n);
        for(int i = 0;i<n;i++) cout << vec[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends