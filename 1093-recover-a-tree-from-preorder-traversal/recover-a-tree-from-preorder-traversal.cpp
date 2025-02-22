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
    int n;
    TreeNode* helper(string& s, int& ind, int d){
        if(ind >= n) return nullptr;
        int i = ind;
        while(i < n && s[i] == '-') i++;
        int level = i - ind;
        if (level != d) return nullptr;
        ind += level;
        int num = 0;
        while(ind < n && s[ind] != '-'){
            num *= 10;
            num += (s[ind] - '0');
            ind++;
        }
        TreeNode* root = new TreeNode(num);
        root -> left = helper(s, ind, d + 1);
        root -> right = helper(s, ind, d + 1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();
        int i = 0;
        return helper(traversal, i, 0);
    }
};