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
    int sum(TreeNode* root, bool isleft){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL){
            if(isleft) return root->val;
            else return 0;
        }
        int l = sum(root->left, true);
        int r = sum(root->right, false);
        return l + r;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return sum(root, false);
    }
};