class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder,
                                   vector<int>& postorder) {
        int n = preorder.size();
        return h(0, n - 1, 0, preorder, postorder);
    }

private:
    TreeNode* h(int i, int j, int postStart, vector<int>& pre,
                vector<int>& post) {
        if (i > j)
            return NULL;

        if (i == j) {
            return new TreeNode(pre[i]);
        }

        int leftRoot = pre[i + 1];

        int leftNodes = 1;
        while (post[postStart + leftNodes - 1] != leftRoot) {
            leftNodes++;
        }

        TreeNode* root = new TreeNode(pre[i]);

        root->left =
            h(i + 1, i + leftNodes, postStart, pre, post);

        root->right = h(i + leftNodes + 1, j,
                        postStart + leftNodes, pre, post);

        return root;
    }
};