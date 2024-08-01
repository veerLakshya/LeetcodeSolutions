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
    set<int>st;
    void dfs(TreeNode* root){
        if(root==NULL)return;
        st.insert(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        dfs(root);
        for(auto i: st){
            cnt++;
            if(cnt==k)return i;
        }
        return -1;
    }
};