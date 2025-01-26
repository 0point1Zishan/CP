class StockSpanner {
public:
    stack<pair<int, int>> st;
    int ind = -1;
    StockSpanner() {

    }

    int next(int price) {
        ind++;
        while(!st.empty() &&  st.top().second <= price) st.pop();
        int res = (!st.empty()) ? ind - st.top().first   :    ind+1;
        st.push({ind, price});
        return res;
    }
};