class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        string t = s + s;
        return t.find(goal) != string::npos;
    }
};