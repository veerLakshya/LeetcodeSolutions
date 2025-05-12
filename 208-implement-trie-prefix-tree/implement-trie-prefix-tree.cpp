class Node{
    public:
    char data;
    unordered_map<char,Node*> children;
    bool isTerminal;
    Node(char c){
        data = c;
        isTerminal = false;
    }
};
class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');
    }
    
    void insert(string word) {
        Node* temp = root;
        for(char c: word){
            // if it wasnt there, insert the node
            if(temp->children.count(c) == 0){
                temp->children[c] = new Node(c);
            }
            // always move to next node 
            temp = temp->children[c];
        }
        temp->isTerminal = true;
    }
    
    bool search(string word) {
        Node* temp = root;
        for(char ch: word){
            if(temp->children.find(ch) == temp->children.end()) return false;
            temp = temp->children[ch];
        }
        return temp->isTerminal;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;
        for(char ch: prefix){
            if(temp->children.find(ch) == temp->children.end()) return false;
            temp = temp->children[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */