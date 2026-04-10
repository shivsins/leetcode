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
    int sumEvenGrandparent(TreeNode* root) {
        int sum=0;
        dfs(root, NULL, NULL, sum);
        return sum;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* gp, int &sum){
        if(root==NULL) return;
        if(gp!=NULL && gp->val%2==0){
            sum+=root->val;
        }
        dfs(root->left, root, p, sum);
        dfs(root->right, root, p, sum);
    }
};