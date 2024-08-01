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
    multiset<int> st;
    void dfs(TreeNode* r){
        if(r==NULL)return;
        st.insert(r->val);
        dfs(r->left);
        dfs(r->right);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        dfs(root1),dfs(root2);
        vector<int> ans;
        for(auto i:st)ans.push_back(i);
        return ans;        
    }
};