class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int l = n - k, r = 0;
        int sum = accumulate(cardPoints.begin()+l, cardPoints.end(), 0);
        int mx = sum;

        while(r < k){
            sum += cardPoints[r++];
            sum -= cardPoints[l % n];
            l++;
            mx = max(mx, sum);
        }
        return mx;
    }
};