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
    // int sum[10001] = {0};
    void dfs(TreeNode* root, int level, vector<int>& sum){
        if(root == NULL) return;
        if(sum.size()<level)sum.push_back(0);
        sum[level - 1] += root->val;
        dfs(root->left, level + 1, sum);
        dfs(root->right, level + 1, sum);
    }
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        dfs(root , 1, sum);
        int maxi = INT_MIN, ind = -1;
        for(int i = 0; i < sum.size(); i++){
            // cout<< i+1<<": "<< sum[i]<<endl;
            if(maxi < sum[i]){
                maxi = sum[i];
                ind = i+1;
            }
        }
        // cout<<maxi;
        return ind;
    }
};