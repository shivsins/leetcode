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
        int rh = height(root);
        TreeNode* temp = root;
        while(temp){
            ans.push_back(temp->val);
            temp=temp->right;
        }
        vector<vector<int>> lot;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        while(!q.empty()){
            int qs = q.size();
            vector<int> level;
            while(qs){
            TreeNode* node = q.front();
            q.pop();
            level.push_back(node->val);
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
            qs--; 
            }
            lot.push_back(level);
        }
        for(int i = rh; i<lot.size();i++){
            ans.push_back(lot[i].back());
        }
        return ans;
        
    }

    int height(TreeNode* root){
        if(!root) return 0;
        return height(root->right)+1;
    }
};