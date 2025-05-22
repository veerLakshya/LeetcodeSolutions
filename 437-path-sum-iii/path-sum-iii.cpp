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
    long long t;

    void h(TreeNode* root, long long sum, unordered_map<long long, int>& mp){
        if(!root) return;

        sum += root->val;

        if(mp.find(sum - t) != mp.end()) ans += mp[sum - t];

        mp[sum]++;

        h(root->left, sum, mp);
        h(root->right, sum, mp);

        mp[sum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        t = targetSum;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        h(root, 0LL, mp);
        return ans;
    }
};
