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
    void helper(TreeNode* curr){
        if(curr == nullptr)return;
        // if(curr->right == nullptr && curr->left == nullptr) return;
        TreeNode* l = curr->left;
        TreeNode* r = curr->right;
        // if(l != nullptr)
        helper(l);
        // if(r != nullptr)
        helper(r);
        curr->left = r;
        curr->right = l;
    }
    TreeNode* invertTree(TreeNode* root) {
        helper(root);
        // cout<< root->left<<" "<<root->right;
        // cout<<root->val;
        return root;
    }
};