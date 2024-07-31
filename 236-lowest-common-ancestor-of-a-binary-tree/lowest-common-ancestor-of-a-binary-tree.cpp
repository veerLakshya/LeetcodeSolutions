/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPath(TreeNode* root, vector<TreeNode*>& arr, int x) {
        if (!root)
            return false;

        arr.push_back(root);
        if (root->val == x)
            return true;

        if (hasPath(root->left, arr, x) || hasPath(root->right, arr, x))
            return true;
        arr.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pathp,pathq;
        hasPath(root, pathp,p->val );
        hasPath(root, pathq,q->val );
        for(auto i: pathp)cout<<i->val<<" ";
        cout<<endl;
        for(auto i: pathq)cout<<i->val<<" ";
        for(int i = 1; i<min(pathp.size(),pathq.size());i++){
            if(pathp[i]!=pathq[i])return pathp[i-1];
        }
        return pathp.size()>pathq.size() ? pathq[pathq.size()-1]:pathp[pathp.size()-1];
    }
};