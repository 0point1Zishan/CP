//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution {
  public:
    // Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // Your code here
        auto cmp = [&](int i, int j){
            return (val[i] * 1.0) / (wt[i] * 1.0) > (val[j] * 1.0) / (wt[j] * 1.0);
        };
        
        int n = val.size();
        vector<int> Items(n);
        iota(Items.begin(), Items.end(), 0);
        sort(Items.begin(), Items.end(), cmp);

        double value = 0;
        for(int i = 0; i < n; i++){
            if(capacity == 0) break;
            
            int mn = min(capacity, wt[Items[i]]);
            capacity -= mn;
            
            value += ((val[Items[i]] * 1.0) / (wt[Items[i]] * 1.0)) * (mn * 1.0);
        }
        return value;
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    // taking testcases
    cin >> t;
    cin.ignore(); // to ignore the newline after the number of test cases
    cout << setprecision(6) << fixed;

    while (t--) {
        // Reading the value array
        vector<int> values;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            values.push_back(number);
        }

        // Reading the weight array
        vector<int> weights;
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            weights.push_back(number);
        }

        // Reading the capacity
        int w;
        cin >> w;
        cin.ignore(); // to ignore the newline after capacity

        // function call
        Solution ob;
        cout << ob.fractionalKnapsack(values, weights, w) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends