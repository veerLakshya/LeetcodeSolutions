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
    int level[1001] = {0};
    int parent[1001] = {-1};
    void dfs(TreeNode* root, int l, int par){
        if(root==NULL)return;
        level[root->val] = l;
        parent[root->val] = par;
        dfs(root->left , l + 1, root->val);
        dfs(root->right , l + 1, root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        dfs(root, 0, -1);
        if(level[x] == level[y] &&(parent[x]!=parent[y]))return true;
        else return false;
    }
};