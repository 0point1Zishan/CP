class node{
    public:
    int val;
    int row;
    int col;
    node(int val, int row, int col){
        this->val = val;
        this->row = row;
        this->col = col;
    }
};
class cmp{
    public:
    bool operator()(node* a, node* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        priority_queue<node*, vector<node*>, cmp> pq;

        int mx = INT_MIN, mn = INT_MIN;
        for(int i = 0; i < n; i++){
            mx = max(mx, nums[i][0]);
            mn = min(mn, nums[i][0]);
            pq.push(new node(nums[i][0], i, 0));
        }

        long long l = mn, r = mx;
        while(!pq.empty()){
            node* temp = pq.top();
            pq.pop();

            mn = temp->val;
            if(mx - mn - 0LL < r - l - 0LL)  l = mn, r = mx;

            if(temp->col + 1 < nums[temp->row].size()){
                mx = max(mx, nums[temp->row][temp->col + 1]);
                pq.push(new node(nums[temp->row][temp->col + 1], temp->row, temp->col + 1));
            }
            else break;
        }
        
        return {(int)r, (int)l};
    }
};