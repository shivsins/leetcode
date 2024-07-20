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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) root;
        if(root->val==p->val || root->val == q->val) return root;
        // bool lp = find(root->left,p);
        // bool rp = find(root->right,p);
        // bool lq = find()
        if((find(root->left,p) && find(root->right,q)) || (find(root->left,q) && find(root->right,p))) return root;
        if(find(root->left,p) && find(root->left,q)) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }

    bool find(TreeNode* root, TreeNode* child){
        if(root==NULL) return false;
        if(root->val==child->val) return true;
        return find(root->left, child) || find(root->right,child);
    }
};