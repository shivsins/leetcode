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
    int goodNodes(TreeNode* root) {
        int res = 0;
        dfs(root,INT_MIN, res);
        return res;
    }

    void dfs(TreeNode* root, int curMax, int &res){
        if(!root) return;
        if(root->val>=curMax) {
            curMax = root->val;
            res++;
        }
        dfs(root->left,curMax, res);
        dfs(root->right, curMax, res);

    }
};