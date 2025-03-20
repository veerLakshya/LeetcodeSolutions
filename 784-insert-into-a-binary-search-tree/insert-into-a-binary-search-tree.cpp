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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* cur = root;
        while(true){
            if(cur->val <= val){
                if(cur->right == NULL){
                    cur->right = new TreeNode(val);
                    return root;
                }
                else cur = cur->right;
            }
            else{
                if(cur->left) cur = cur->left;
                else{
                    cur->left = new TreeNode(val);
                    return root;
                }
            }
        }
        return root;
    }
};