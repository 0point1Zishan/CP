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

    void insert(int n){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit =  ((n >> i) & 1);
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getMax(int n){
        Node* node = root;
        int mx = 0;
        for(int i = 31; i >= 0; i--){
            int bit =  ((n >> i) & 1);
            if(node->containsKey(!bit)){
                mx = mx | (1 << i);
                node = node->get(!bit);
            }
            else{
                node = node->get(bit);
            }
        }
        return mx;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    // Write your code here.  
    Trie trie;
    for(auto &it: arr1){
        trie.insert(it);
    }
    int mx = 0;
    for(auto &it: arr2){
        mx = max(mx, trie.getMax(it));
    }
    return mx;
}