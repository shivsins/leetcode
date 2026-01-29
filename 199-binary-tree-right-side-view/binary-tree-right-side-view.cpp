//good question to understand dfs and bfs.
//first we find the depth(say rh) of just the right side view of the tree.
//then add all the right nodes to the ans
//then we get the level order traversal view of the tree
//then add all the last nodes of the level which are greater then rh

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        // int rh = getRightHeight(root);
        // TreeNode* temp = root;
        // while(temp){
        //     ans.push_back(temp->val);
        //     temp=temp->right;
        // }
        // vector<vector<int>> levelView = getLOTView(root);
        // for(int i = rh; i<levelView.size();i++){
        //     ans.push_back(levelView[i].back());
        // }
        // return ans;
        getRV(root,ans,0);
        return ans;
    }

    void getRV(TreeNode* root, vector<int> &ans, int height){
        if(root==NULL) return;
        if(height==ans.size()) ans.push_back(root->val);
        getRV(root->right, ans, height+1);
        getRV(root->left, ans, height+1);
    }

    // int getRightHeight(TreeNode* root){
    //     if(!root) return 0;
    //     return getRightHeight(root->right)+1;
    // }

    // vector<vector<int>> getLOTView(TreeNode* root){
    //     vector<vector<int>> lot;
    //     queue<TreeNode*> q;
    //     if(!root) return lot;
    //     q.push(root);
    //     while(!q.empty()){
    //         int qs = q.size();
    //         vector<int> level;
    //         while(qs){
    //         TreeNode* node = q.front();
    //         q.pop();
    //         level.push_back(node->val);
    //         if(node->left) q.push(node->left);
    //         if(node->right) q.push(node->right);
    //         qs--; 
    //         }
    //         lot.push_back(level);
    //     }
    //     return lot;
// }
};