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
    // TreeNode* helper(vector<int>& preorder, vector<int>&inorder, int prestart, int preend, int instart, int inend){
    //     if(instart > inend || prestart > preend) return NULL;

    // }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return NULL;
        vector<int> preleft, inleft, preright, inright;
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        while(preorder[0] != inorder[i]){
            inleft.push_back(inorder[i]);
            i++;
        }
        i++;
        while( i < preorder.size()){
            inright.push_back(inorder[i]);
            i++;
        }
        i = 1;
        while(i <= inleft.size()){
            preleft.push_back(preorder[i]);
            i++;
        }
        while(i < preorder.size()){
            preright.push_back(preorder[i]);
            i++;
        }
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;
    }
};