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
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        int l = diameterOfBinaryTree(root->left);
        int r = diameterOfBinaryTree(root->right);
        int b = depth(root->left)+depth(root->right);
        return max(l,max(r,b));
    }

    int depth(TreeNode* root){
        if(root==NULL) return 0;
        return max(depth(root->left), depth(root->right))+1;
    }
    
};