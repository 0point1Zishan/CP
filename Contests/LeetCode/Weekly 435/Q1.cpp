int maxDifference(string s) {
    vector<int> v(26, 0);
    for(int i = 0; i < s.size(); i++)  v[s[i] - 'a']++;

    int mxO = 0, mnE = s.size();
    for(int i = 0; i < 26; i++){
        if(v[i] & 1) mxO = max(mxO, v[i]);
        else if(v[i] > 0) mnE = min(mnE, v[i]);
    }
    return mxO - mnE;
}