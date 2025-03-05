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
    int countNodes(TreeNode* root) {
        auto dfs = [&](TreeNode* root, auto self)->int{
            if(!root) return 0;
            int l = self(root->left, self);
            int r = self(root->right, self);
            return l+r+1;
        };
        return dfs(root, dfs);
    }
};