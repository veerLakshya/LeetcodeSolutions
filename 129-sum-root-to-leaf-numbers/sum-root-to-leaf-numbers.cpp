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
    int ans = 0;
    void dfs(TreeNode* curr, int sum){
        sum*=10;
        sum+=curr->val;
        if(curr->left==NULL && curr->right==NULL){
            ans+=sum;
            return;
        }
        if(curr->left!=NULL)dfs(curr->left,sum);
        if(curr->right!=NULL)dfs(curr->right,sum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};