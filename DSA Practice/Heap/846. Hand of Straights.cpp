class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) return false;
        map<int, int> mp;
        for(int i = 0; i < hand.size(); i++) mp[hand[i]]++;

        while(!mp.empty()){
            int curr = mp.begin()->first;
            for(int i = 0; i < groupSize; i++){
                if(!mp[curr + i]) return false;
                mp[curr + i]--;
                if(!mp[curr + i])  mp.erase(curr+i);
            }
        }
        return true;
    }
};