class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this->key = key;
            this->val = val;
        }
    };
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int c = 0;
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void delete_(Node* a){
        Node* x = a->prev;
        Node* y = a->next;

        x->next = y;
        y->prev = x;
    }
    void add_(Node* a){
        Node* t = head->next;
        a->next = t;
        a->prev = head;
        head->next = a;
        t->prev = a;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            Node* a = mp[key];
            int ans = a->val;
            mp.erase(key);
            delete_(a);
            add_(a);
            mp[key] = head->next;
            return ans;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* a = mp[key];
            mp.erase(key);
            delete_(a);
        }
        if(mp.size() == c){
            mp.erase(tail->prev->key);
            delete_(tail->prev);
        }
        add_(new Node(key, value));
        mp[key] = head->next;
    }
};