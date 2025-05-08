class node{
    public:
    int key,val;
    node *prev, *next;
    node(int a, int b, node * n, node * p){
        key = a;
        val = b;
        prev = p;
        next = n;
    }
};
class LRUCache {
public:
    int cap;
    unordered_map<int,node*> mp;
    node *head = new node(0,0,NULL,NULL);
    node *tail = new node(0,0,NULL,NULL);
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) != mp.end()){
            node *temp = mp[key];
            int r = temp->val;
            // remove from old position
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            head->next->prev = temp;
            temp->next = head->next;
            head->next = temp;
            temp->prev = head;

            return r;
        }
        else return -1;
    }
    
    void put(int key, int value) {
        // if key is already present move it to start
        if(mp.find(key) != mp.end()){
            node *temp = mp[key];
            temp->val = value;
            // remove from old position
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;

            // insert at start
            temp->prev = head;
            temp->next = head->next;
            head->next->prev = temp;
            head->next = temp;
            
        }
        else{
            // if cap is full, remove lru from front
            if(cap == mp.size()){
                node* lru = tail->prev;
                lru->prev->next = tail;
                tail->prev = lru->prev;
                mp.erase(lru->key);
                delete(lru);
            }
            node *temp = new node(key, value, head->next, head);
            mp[key] = temp;

            head->next->prev = temp;
            head->next = temp;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */