class LFUCache {
public:
    class Node{
    public:
        int k, v, cnt;
        Node* next;
        Node* prev;
        Node(int key, int val){
            k = key;
            v = val;
            cnt = 1;
        }
    };

    class List{
    public:
        int sz;
        Node* head;
        Node* tail;
        List(){
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
            sz = 0;
        }

        void add(Node* n){
            Node* t = head->next;
            n->next = t;
            n->prev = head;
            head->next = n;
            t->prev = n;
            sz++;
        }

        void remove(Node* n){
            Node* p = n->prev;
            Node* nxt = n->next;
            p->next = nxt;
            nxt->prev = p;
            sz--;
        }
    };

    unordered_map<int, Node*> mpk;
    unordered_map<int, List*> mpf;
    int c, mn, sz;

    LFUCache(int capacity) {
        c = capacity;
        mn = 0;
        sz = 0;
    }

    void update(Node* n){
      
        mpk.erase(n->k);
        mpf[n->cnt]->remove(n);
        if (n->cnt == mn && mpf[n->cnt]->sz == 0) mn++;

        n->cnt++;
        List* nxtList = new List();
        if (mpf.find(n->cnt) != mpf.end()) nxtList = mpf[n->cnt];
        nxtList->add(n);
      
        mpf[n->cnt] = nxtList;
        mpk[n->k] = n;
    }

    int get(int key) {
        if(mpk.find(key) != mpk.end()){
            Node* n = mpk[key];
            int val = n->v;
            update(n);
            return val;
        }
        return -1;
    }

    void put(int key, int value) {
        if(c == 0) return;
        if(mpk.find(key) != mpk.end()){
            Node* n = mpk[key];
            n->v = value;
            update(n);
        } 
        else{
            if(sz == c){
                List* lst = mpf[mn];
                mpk.erase(lst->tail->prev->k);
                mpf[mn]->remove(lst->tail->prev);
                sz--;
            }
            sz++;
            mn = 1;
          
            List* lst = new List();
            if(mpf.find(mn) != mpf.end()) lst = mpf[mn];
            Node* n = new Node(key, value);
            lst->add(n);
          
            mpk[key] = n;
            mpf[mn] = lst;
        }
    }
};