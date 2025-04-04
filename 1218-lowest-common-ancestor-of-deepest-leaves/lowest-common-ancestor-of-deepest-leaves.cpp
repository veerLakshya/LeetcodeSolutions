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
    int h[1001];
    set<int> nodes;
    int maxi = 0;
    void he(TreeNode* root, int d){
        if(!root) return;
        nodes.insert(root->val);
        maxi = max(maxi, d);
        h[root->val] = d;
        he(root->left, d + 1);
        he(root->right, d + 1);
    }
    TreeNode* helper(TreeNode* root, int d){
        if(!root) return NULL;
        if(h[root->val] == maxi) return root;
        // cout << root->val << endl;
        auto left = helper(root->left, d + 1);
        auto right = helper(root->right, d + 1);
        if(left && right) return root;
        else if(!left) return right;
        else if(!right) return left;
        else return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return NULL;
        memset(h, 0, sizeof h);
        he(root, 0);
        // cout << maxi;
        return helper(root, 0);
    }
};