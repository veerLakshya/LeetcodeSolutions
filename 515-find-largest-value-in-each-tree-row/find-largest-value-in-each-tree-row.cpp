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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        auto dfs = [&] (int i, TreeNode* root, auto self){
            if(!root) return;
            if(ans.size() < i + 1) ans.push_back(INT_MIN);
            ans[i] = max(ans[i], root->val);
            if(root->left)self(i+1, root->left, self);
            if(root->right)self(i+1, root->right, self);
        };
        dfs(0, root, dfs);
        return ans;
    }
};