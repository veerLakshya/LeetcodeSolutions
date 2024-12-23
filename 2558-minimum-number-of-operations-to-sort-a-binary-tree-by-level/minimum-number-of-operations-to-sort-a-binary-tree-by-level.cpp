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
    // int h(vector<int>& a){

    // }
    int minimumOperations(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);
        int ans = 0;

        auto swaps = [&](vector<int>& a)->int{
            int n = a.size();
            int x = 0;
            vector<int> t = a;
            sort(t.begin(),t.end());
            map<int,int> mp;    //tracking cur pos
            for(int i = 0; i < n; i++){
                mp[a[i]] = i;
            }
            for(int i = 0; i < n; i++)
                if(t[i]!=a[i]){
                        x++;
                        int cur = mp[t[i]]; //position of element to come at this place
                        mp[a[i]] = cur;
                        swap(a[i],a[cur]);
                    }
            return x;
        };

        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelValues(levelSize);

            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front();
                q.pop();
                levelValues[i] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans += swaps(levelValues);
        }
        return ans;
    }
};