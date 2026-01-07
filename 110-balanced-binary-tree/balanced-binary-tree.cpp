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
    bool res = true;
public:
    bool isBalanced(TreeNode* root) {
        // if(root==NULL) return true;
        // int lh = height(root->left);
        // int rh = height(root->right);
        // if(abs(lh-rh)>1) return false;
        // return isBalanced(root->left) && isBalanced(root->right);
        if(height(root)>=0) return true;
        return false;
    }

    int height(TreeNode* root){
        if(root==NULL) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh==-1 || rh==-1) return -1;
        if(abs(lh-rh)>1) return -1;
        return 1+max(lh,rh);
    }

};