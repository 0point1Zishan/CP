class Solution {
    public:
        int candy(vector<int>& ratings) {
            int n = ratings.size(), i = 1, total = 1;
    
            while(i < n){
                if(ratings[i] == ratings[i-1]) total += 1, i++;
    
                int peek = 1, down = 1;
                while(i < n && ratings[i] > ratings[i-1]) peek++, total += peek, i++;
    
                while(i < n && ratings[i] < ratings[i-1]) total += down, down++, i++;
    
                if(down > peek) total += down - peek;
            }
            return total;
        }
    };