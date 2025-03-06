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
    vector<int> ans;
    map<int,vector<int>> adj;
    void dfs1(TreeNode* root){
        if(!root) return;
        if(root->left){
            adj[root->left->val].push_back(root->val);
            adj[root->val].push_back(root->left->val);
        }
        if(root->right){
            adj[root->right->val].push_back(root->val);
            adj[root->val].push_back(root->right->val);
        }
        dfs1(root->left);
        dfs1(root->right);
    }
    void dfs2(int cur, int par, int dis, int tar){
        if(dis == tar){
            ans.push_back(cur);
            return;
        }
        for(auto nbr: adj[cur]){
            if(nbr == par) continue;
            dfs2(nbr, cur, dis + 1, tar);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        dfs1(root);
        dfs2(target->val, -1, 0, k);
        return ans;
    }
};