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
    int h (TreeNode* root){
        if(!root) return 1;
        int l = 0, r = 0;
        if(root->left) l = h(root->left);
        if(root->right) r = h(root->right);
        if(l == -1 || r == -1) return -1;
        else if(abs(l - r) > 1) return -1;
        else return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        return h(root) != -1;
    }
};