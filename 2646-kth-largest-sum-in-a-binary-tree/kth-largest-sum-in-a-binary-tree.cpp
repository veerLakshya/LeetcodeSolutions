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
    void dfs(TreeNode* root, int level, vector<long long>& levelSum){
        if(root == NULL)return;
        if(levelSum.size() < level + 1) levelSum.push_back(0);
        levelSum[level] += root->val;
        if(root->left!= NULL) dfs(root->left, level + 1, levelSum);
        if(root->right!= NULL) dfs(root->right , level + 1, levelSum);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        long long ans = 0;
        vector<long long> levelSum;
        dfs(root, 0, levelSum);
        sort(levelSum.rbegin(),levelSum.rend());
        for(auto i: levelSum){
            k--;
            ans = i;
            if(k==0)break;
        }
        if(k!=0) return -1;
        else return ans;
    }
};