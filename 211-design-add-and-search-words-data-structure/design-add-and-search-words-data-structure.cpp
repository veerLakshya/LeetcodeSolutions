class Node {
public:
    char data;
    unordered_map<char, Node*> children;
    bool isWord;
    Node(char c) {
        data = c;
        isWord = false;
    }
};

class WordDictionary {
public:
    Node* root;
    WordDictionary() {
        root = new Node('\0');
    }

    void addWord(string word) {
        Node* temp = root;
        for (char c : word) {
            if (temp->children.count(c) == 0) {
                temp->children[c] = new Node(c);
            }
            temp = temp->children[c];
        }
        temp->isWord = true;
    }

    bool search(string word) {
        return helper(word, root);
    }
    bool helper(string word, Node* node) {
        Node* temp = node;
        for (int i = 0; i < word.size(); i++) {
            char x = word[i];
            if (x == '.') {
                for (auto& y : temp->children) {
                    if (helper(word.substr(i + 1), y.second)) {
                        return true;
                    }
                }
                return false;
            }
            if (temp->children.find(x) == temp->children.end()) {
                return false;
            }
            temp = temp->children[x];
        }
        return temp->isWord;
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */