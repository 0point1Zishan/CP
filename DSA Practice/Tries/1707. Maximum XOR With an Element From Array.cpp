class Node{
	public:
	Node* links[2];
	bool containsKey(int bit){
		return links[bit];
	}
	void put(int bit, Node* node){
		links[bit] = node;
	}
	Node* get(int bit){
		return links[bit];
	}
};

class Trie{
	private:
	Node* root;

	public:
	Trie(){
		root = new Node();
	}
	void insert(int num){
		Node* node = root;
		for(int i = 31; i >= 0; i--){
			int bit = ((num >> i) & 1);
			if(!node->containsKey(bit)){
				node->put(bit, new Node());
			}
			node = node->get(bit);
		}
	}
	int getMax(int num){
		Node* node = root;
		int mx = 0;
		for(int i = 31; i >= 0; i--){
			int bit = ((num >> i) & 1);
			if(node->containsKey(!bit)){
				mx = mx | (1 << i);
				node = node->get(!bit);
			}
			else node = node->get(bit);
		}
		return mx;
	}
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int qSize = queries.size();
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<pair<int, int>> pr;
        for(int i = 0; i < qSize; i++){
            pr.push_back({queries[i][1], i});
        }
        sort(pr.begin(), pr.end());

        vector<int> ans(qSize);
        int j = 0;
        Trie trie;
        for(int i = 0; i < qSize; i++){
            int limit = pr[i].first;
            int idx = pr[i].second;

            while(j < n && nums[j] <= limit){
                trie.insert(nums[j]);
                j++;
            }
            int mx = -1;
            if(j != 0) mx = trie.getMax(queries[idx][0]);
            ans[idx] = mx;
        }
        return ans;
    }
};