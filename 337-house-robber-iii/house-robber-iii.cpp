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
    pair<int,int> dfs(TreeNode* cur){
        if(cur == NULL) return {0,0};
        pair<int,int> l = dfs(cur->left);
        pair<int,int> r = dfs(cur->right);
        int choose = cur->val + l.second + r.second;
        int notchoose = max(l.first,l.second)+ max(r.first, r.second);
        // cout << choose <<" "<< notchoose <<endl;
        return {choose, notchoose};
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        // cout << ans.first << " "<< ans.second;
        return max(ans.first, ans.second);
    }
};