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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* cur = root;
        while(cur){
            if(cur->val > key){
                if(cur->left && cur->left->val == key){
                    cur->left = helper(cur->left);
                    return root;
                    break;
                }
                else{
                    cur = cur->left;
                }
            }
            else{
                if(cur->right && cur->right->val == key){
                    cur->right = helper(cur->right);
                    return root;
                    break;
                }
                else cur = cur->right;
            }
        }
        return root;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;
        else if(!root->left && !root->right) return NULL;
        TreeNode* rightchild = root->right;
        TreeNode* temp = root->left;
        TreeNode* cur = temp;
        while(cur->right != NULL) cur = cur->right;
        cur->right = rightchild;
        return temp;
    }
};