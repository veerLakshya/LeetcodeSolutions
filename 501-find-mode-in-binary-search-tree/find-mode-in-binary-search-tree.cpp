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
    map<int,int> mp;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        mp[root->val]++;
        dfs(root->left);
        dfs(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> a;
        dfs(root);
        int ans = -1, freq = 0;
        for(auto i: mp){
            if(i.second > freq) ans = i.first, freq = i.second;
        }
        for(auto i: mp){
            cout<<i.first<<" "<<i.second<<endl;
            if(i.second == freq) a.push_back(i.first);
        }
        return a;
    }
};