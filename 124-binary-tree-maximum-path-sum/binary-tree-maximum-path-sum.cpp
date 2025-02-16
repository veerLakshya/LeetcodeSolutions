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
    int ans = INT_MIN;
    int helper(TreeNode* root){
        if(root == NULL) return 0;
        int cur = root->val;
        int left = helper(root->left);
        int right = helper(root->right);
        ans = max({ans,  cur + left + right, cur + left, cur + right});
        return max({left + cur, right + cur, 0});
    };
    int maxPathSum(TreeNode* root) {
        helper(root);
        return ans;
    }
};