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
    vector<vector<int>> ans;
    vector<int> path;
    int t;

    void h(TreeNode* root, int cur){
        if(!root->left && !root->right){
            if(cur == t) ans.push_back(path);
            return;
        }
        if(root->left){
            int add = root->left->val;
            cur += add;
            path.push_back(add);
            h(root->left, cur);
            cur -= add;
            path.pop_back();
        }
        if(root->right){
            int add = root->right->val;
            cur += add;
            path.push_back(add);
            h(root->right, cur);
            cur -= add;
            path.pop_back();
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(!root) return ans;
        t = targetSum;
        path.push_back(root->val);
        h(root, root->val);

        return ans;
    }
};