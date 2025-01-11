class Solution {
  public:
    double findSmallestMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        int mxDis = 0;
        for(int i = 1; i < n; i++){
            mxDis = max(mxDis, stations[i] - stations[i-1]);
        }  
        
        auto count = [&](double dis){
            double cnt = 0;
            for(int i = 1; i < n; i++){
                int point = (double)(stations[i] - stations[i-1]) / dis;
                if((stations[i]-stations[i-1])/dis == point * dis) point--;
                cnt += point;
            }
            return cnt;
        };
        
        double s = 0, e = mxDis, ans = mxDis;
        while(e - s >= 0.0000001){
            double mid = s + (e - s) / 2.0;
            double cnt = count(mid);
            if(cnt > k) s = mid;
            else e = mid;
        }return e;
    }
};