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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long ans = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()){
            long long size = q.size();
            long long first = q.front().second , last = q.back().second;
            ans = max(ans, last - first + 1);
            for(int i = 0; i < size; i++){
                auto cur = q.front();
                q.pop();
                long long cur_id = cur.second - first;
                TreeNode* node = cur.first;
                if(node->left) q.push({node->left, cur_id*2 + 1});
                if(node->right) q.push({node->right, cur_id*2 + 2});
            }
        }
        return ans;
    } 
};