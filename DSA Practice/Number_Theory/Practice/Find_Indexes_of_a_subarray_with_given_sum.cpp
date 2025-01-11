#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySum(vector<int>arr, int n, long long s)
{
    // Your code here
    vector<int> ans;
    int l = 0, r = 0, sum = 0;

    while(r < n){
        sum += arr[r];
        if(sum == s){
            ans.push_back(l + 1);
            ans.push_back(r + 1);
            return ans;
        }
        while(l < r && sum > s){
            sum -= arr[l];
            l++;
            if(sum == s){
                ans.push_back(l + 1);
                ans.push_back(r + 1);
                return ans;
            }
        }
        r++;
    }
    ans.push_back(-1);
    return ans;
}

int main(){
    
    int n,sum;  cin >> n >> sum;
    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    
    vector<int> ans = subarraySum(v, n, sum);
    for(auto it: ans)   cout << it << " ";
    
    return 0;
}