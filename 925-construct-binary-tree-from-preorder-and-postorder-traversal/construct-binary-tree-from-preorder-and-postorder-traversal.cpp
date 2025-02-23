class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int i = 0, j = 0;
        return h(i, j, preorder, postorder);
    }

private:
    TreeNode* h(int& i, int& j, vector<int>& pre, vector<int>& post) {
        TreeNode* root = new TreeNode(pre[i]);
        i++;

        if (root->val != post[j]) {
            root->left = h(i, j, pre, post);
        }

        if (root->val != post[j]) {
            root->right = h(i, j, pre, post);
        }
        j++;
        return root;
    }
};