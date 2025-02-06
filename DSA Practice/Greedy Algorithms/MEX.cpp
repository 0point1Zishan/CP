#include<bits/stdc++.h>
using namespace std;

int mex_cal(unordered_set<int> &st){

    int mex = 0;
    while(st.find(mex) != st.end())     mex++;
    return mex;
}

int main(){
    
    int n;  cin >> n;
    unordered_set<int> st;
    while(n--){
        int k;  cin >> k;
        st.insert(k);
    }
    
    cout << mex_cal(st) << endl;
    return 0;
}