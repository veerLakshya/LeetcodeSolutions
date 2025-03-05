/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool dfs(TreeNode* root, TreeNode* tar, vector<TreeNode*>& path){
        if(!root) return false;
        path.push_back(root);
        if(root == tar) return true;
        else if(dfs(root->left, tar, path) || dfs(root->right, tar, path)) return true;
        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp, pathq;
        dfs(root, p, pathp);
        dfs(root, q, pathq);
        for(int i = min(pathp.size(), pathq.size()) - 1; i >= 0; i--){
            if(pathp[i] == pathq[i]) return pathp[i];
        }
        return NULL;
    }
};