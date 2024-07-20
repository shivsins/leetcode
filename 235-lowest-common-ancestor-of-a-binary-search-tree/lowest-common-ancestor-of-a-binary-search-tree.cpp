//This solution is when the tree is not a binary search tree. If its a binary search tree then it gets very simple.
// in case of BST: check is both p&q are either greater of less than root if yes then recursively find karo
//otherwise if one is less and another is greater then that root itselft will be lowest common ancestor.

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
        bool lp = find(root->left,p);
        bool rp = find(root->right,p);
        bool lq = find(root->left,q);
        bool rq = find(root->right,q);
        if((lp && rq) || (rp && lq)) return root;
        if(lp && lq) return lowestCommonAncestor(root->left,p,q);
        else return lowestCommonAncestor(root->right,p,q);
    }

    bool find(TreeNode* root, TreeNode* child){
        if(root==NULL) return false;
        if(root->val==child->val) return true;
        return find(root->left, child) || find(root->right,child);
    }
};