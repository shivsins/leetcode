//This can be solved efficiently with bottom up approach of post order dfs.
//We have to keep track of the res which is the max sum till now and postorder will return
//the max(lefttree, righttree)+root->val as we cannot have branching
//return the max value stored in the res
//also max(post(root->left), 0) means 0 is better than including negative value
//take a simple tree and you will understand how it works

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
    int maxPathSum(TreeNode* root) {
       int ans=INT_MIN;
       cal(root,ans);
       return ans;
    }

    int cal(TreeNode* root, int &ans){
        if(root==NULL) return 0;
        int ls=max(0,cal(root->left,ans));
        int rs=max(0,cal(root->right,ans));
        ans=max(ans,ls+rs+root->val);
        return root->val+max(ls,rs);
    }

    // int path(TreeNode* root, int &sum){
    //     if(root==NULL) return 0;
    //     int ls = path(root->left, sum);
    //     int rs = path(root->right, sum);
    //     sum = max(sum, ls+rs+root->val);
    //     return max(0,root->val+max(ls,rs));
    // }

    // int path(Treeode* root, int &sum){
    //     if(root==NULL) return 0;
    //     int ls = path(root->left, sum);
    //     int rs = path(root->right, sum);
    //     return max(root->val+ls+rs, max(max(ls, ls+root->val),max(rs,rs+root->val)));
    // }

    
};