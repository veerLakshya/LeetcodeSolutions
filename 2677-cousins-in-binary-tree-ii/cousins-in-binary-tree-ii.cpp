/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int lsum[100001] = {0};
    void dfs(TreeNode* root, int level) {
        if (root == nullptr) return;
        lsum[level - 1] += root->val;
        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }
    void dfs2(TreeNode* root, int level) {
        if (root == NULL || (root->left == NULL && root->right == NULL)) return;
        int childVal = lsum[level];
        if (root->left != nullptr)
            childVal -= root->left->val;
        if (root->right != nullptr)
            childVal -= root->right->val;

        if (root->left != nullptr)
            root->left->val = childVal;
        if (root->right != nullptr)
            root->right->val = childVal;
            dfs2(root->left, level + 1);
            dfs2(root->right, level + 1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root->val = 0;
        dfs(root, 1);
        dfs2(root, 1);
        return root;
    }
};