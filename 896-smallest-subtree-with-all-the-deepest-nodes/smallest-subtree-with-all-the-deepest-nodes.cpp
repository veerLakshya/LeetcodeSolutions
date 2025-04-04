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
    int h[501];
    int maxi = 0;
    void seth(TreeNode* root, int d){
        if(!root) return;
        h[root->val] = d;
        maxi = max(maxi, d);
        seth(root->left, d+1);
        seth(root->right, d+1);
    }
    TreeNode* helper(TreeNode* root, int d){
        if(!root) return NULL;
        if(d == maxi) return root;
        auto left = helper(root->left, d+1);
        auto right = helper(root->right, d+1);
        if(left && right) return root;
        else if(!left) return right;
        else if(!right) return left;
        return NULL;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        memset(h, 0, sizeof(h));
        seth(root, 0);
        return helper(root, 0);
    }
};