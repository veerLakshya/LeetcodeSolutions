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
    bool isbst(TreeNode* root, long long int l, long long int r){
        if(root == NULL) return true;
        if(root->val < r and root->val > l) return isbst(root->left, l, root->val) && isbst(root->right, root->val, r);
        else return false;
    }
    bool isValidBST(TreeNode* root) {
        long long int min = -1e16, max = 1e16;
        return isbst(root, min, max);
    }
};