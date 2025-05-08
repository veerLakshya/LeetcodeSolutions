class node{
    public:
    int key, val, cnt; //cnt stores how many times this is used
    node *next, *prev;
    node(int a, int b){
        key = a;
        val = b;
        cnt = 1;
    }
};
class List {
    public:
    int size; // size of this list
    node* head;
    node* tail;
    List(){
        head = new node(0,0);
        tail = new node(0,0);
        size = 0;
        head->next = tail;
        tail->prev = head;
    }
    void addFront(node *temp){
        temp->next = head->next;
        head->next->prev = temp;
        head->next = temp;
        temp->prev = head;
        size++;
    }
    void remove(node *temp){
        node* prevnode = temp->prev;
        node* nextnode = temp->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        size--;
    }
};
class LFUCache {
public:
    unordered_map<int,node*> keysStored; // stores the keys currently stored in cache
    unordered_map<int,List*> freqLists;  // stores the list of keys for each freq
    int cur, cap, minFreq; // minFreq stores the cur minFreq used key, cur = cursize of cache
    
    LFUCache(int capacity) {
        cap = capacity;
        cur = 0;
        minFreq = 0;
    }
    
    int get(int key) {
        // if key is stored in cache then update its freq by 1 and update freqList of cur and cur + 1 freq
        if(keysStored.find(key) != keysStored.end()){
            node* temp = keysStored[key];
            int r = temp->val;
            updateFreqList(temp);
            return r;
        }
        return -1;
    }

    void updateFreqList(node* temp){
        int oldFreq = temp->cnt;
        freqLists[oldFreq]->remove(temp);
        if(oldFreq == minFreq && freqLists[oldFreq]->size == 0) minFreq++;

        //increase freq of cur node and move it to list of the updated freq
        temp->cnt += 1;

        List* newlist = new List();
        if(freqLists.find(oldFreq + 1) != freqLists.end()){
            newlist = freqLists[oldFreq + 1];
        }

        newlist->addFront(temp);
        freqLists[oldFreq + 1] = newlist;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        // if key is already present -> update its freq and update freqlistmap
        if(keysStored.find(key) != keysStored.end()){
            node* temp = keysStored[key];
            temp->val = value;
            updateFreqList(temp);
        }
        else{
            // if cap full then remove the lfu and insert at freqList 1 and in keys
            if(cur == cap){
                List* list = freqLists[minFreq];
                keysStored.erase(list->tail->prev->key);
                freqLists[minFreq]->remove(list->tail->prev);
                cur--;
            }
            minFreq = 1;
            cur++;
            node* temp = new node(key, value);
            List* newlist = new List();

            if(freqLists.find(1) != freqLists.end()) newlist = freqLists[1];
            newlist->addFront(temp);

            freqLists[1] = newlist;
            keysStored[key] = temp;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */