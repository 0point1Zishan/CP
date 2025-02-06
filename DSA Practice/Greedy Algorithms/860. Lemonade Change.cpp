class Solution {
public:
    int f(int n){
        return n / 10;
    }
    bool lemonadeChange(vector<int>& bills) {
        vector<int> fre(3, 0);
        for(int i = 0; i < bills.size(); i++){
            fre[f(bills[i])]++;
            if(bills[i] - 5 > 5 && fre[1]) fre[1]--, bills[i] -= 10;

            int five = (bills[i] - 5) / 5;
            if(fre[0] >= five) fre[0] -= five;
            else return false;
        }
        return true;
    }
};