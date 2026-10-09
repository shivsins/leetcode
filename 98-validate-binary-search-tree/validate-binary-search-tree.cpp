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
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // return isLeftLess(root->left, root->val) && isRightBig(root->right, root->val) && isValidBST(root->left) && isValidBST(root->right);
        return validate(root,LONG_MIN, LONG_MAX);
    }

    bool isLeftLess(TreeNode* root, int target){
        if(!root) return true;
        if(target<=root->val) return false;
        return isLeftLess(root->left, target) && isLeftLess(root->right, target);
    }

    bool isRightBig(TreeNode* root, int target){
        if(!root) return true;
        if(target>=root->val) return false;
        return isRightBig(root->left, target) && isRightBig(root->right, target);
    }
    bool validate(TreeNode* root, long left, long right){
        if(root==NULL) return true;
        if(root->val<=left || root->val>=right) return false;
        return validate(root->left, left, root->val) &&  validate(root->right, root->val, right);
    }
};