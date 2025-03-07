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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        if(n == 0) return NULL;
        TreeNode* root = new TreeNode(postorder[n-1]);
        vector<int> inleft,inright, postleft, postright;
        int i = 0;
        while(postorder[n-1] != inorder[i]){
            inleft.push_back(inorder[i]);
            i++;
        }
        i++;
        while(i < n){
            inright.push_back(inorder[i]);
            i++;
        }
        i = 0;
        while(i < inleft.size()){
            postleft.push_back(postorder[i]);
            i++;
        }
        while(postright.size() < inright.size()){
            postright.push_back(postorder[i]);
            i++;
        }
        root->left = buildTree(inleft, postleft);
        root->right = buildTree(inright, postright);

        return root;
    }
};