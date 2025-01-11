class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        int mn = INT_MAX, mx = INT_MIN;
        for(int i = 0; i < n; i++){
            mn = min(mn, v[i]);
            mx = max(mx, v[i]);
        }
        int s = mn, e = mx, day = mx+1;

        auto isPos = [&](int d){
            int cnt = 0, cnt_bouquet = 0;
            for(int i = 0; i < n; i++){
                if(v[i] > d){
                    cnt_bouquet += (cnt / k);
                    cnt = 0;
                }
                else cnt++;
            }
            cnt_bouquet += (cnt / k);
            return cnt_bouquet >= m;
        };
        while(s <= e){
            int mid = s + (e - s) / 2;
            if(isPos(mid)){
                day = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return (day == mx+1 ? -1 : day);
    }
};