/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* cur = q.front();
            q.pop();
            if(cur == NULL) s.append("#,");
            else s.append(to_string(cur->val)+',');
            if(cur != NULL){
                q.push(cur->left);
                q.push(cur->right);
            }
        }
        cout << s<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()){
            TreeNode* cur = q.front();
            q.pop();

            getline(s, str, ',');
            cout<<str<<endl;
            if(str == "#") cur->left = NULL;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                cur->left = node;
                q.push(node);
            }

            getline(s, str, ',');
            cout<<str<<endl;
            if(str == "#") cur->right = NULL;
            else{
                TreeNode* node = new TreeNode(stoi(str));
                cur->right = node;
                q.push(node);
            }
        } 
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));