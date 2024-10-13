/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // bool f(TreeNode* p, TreeNode* q){
    //     if(p->val != q->val) return false;

    //     if((p->left == NULL && q->left == NULL) && (p->right == NULL && q->right == NULL)) return true;
    //     return true;
    // }
    void dfs(TreeNode* x, vector<int>& a){
        if(x == nullptr){
            a.push_back(-1e6);
            return;
        }
        a.push_back(x->val);
        dfs(x->left, a);
        dfs(x->right, a);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> a,b;
        dfs(p,a);
        dfs(q,b);
        // for(auto i: a) cout<<i<<" ";
        // cout<<endl;
        // for(auto i: b) cout<<i<<" ";
        return a==b;
        // return f(p, q);
    }
};