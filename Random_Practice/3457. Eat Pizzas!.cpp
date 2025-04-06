class Solution {
    public:
        long long maxWeight(vector<int>& pizzas) {
            int n = pizzas.size();
            sort(pizzas.begin(), pizzas.end(), greater<>());
    
            int even = n / 8;
            int odd = n / 4 - even;
            long long sum = accumulate(pizzas.begin(), pizzas.begin() + odd, 0LL);
    
            int i = odd+1;
            while(even--){
                sum += pizzas[i];
                i += 2;
            }
            return sum;
        }
    };