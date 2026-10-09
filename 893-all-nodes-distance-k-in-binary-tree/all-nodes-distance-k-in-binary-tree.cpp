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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parent;
        vector<int> ans;
        if(!root) return ans;
        parent[root]=NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            while(n){
                TreeNode* curr=q.front();
                q.pop();
                n--;
                if(curr->left){
                    parent[curr->left]=curr;
                    q.push(curr->left);
                }
                if(curr->right){
                    parent[curr->right]=curr;
                    q.push(curr->right);
                }
            }
        }
        map<TreeNode*,bool> vis;
        dfs(target,0,k,ans,vis, parent);
        return ans;
    }
    void dfs(TreeNode* node, int dis, int k, vector<int> &ans, map<TreeNode*,bool> &vis, map<TreeNode*,TreeNode*> &parent){
        if(!node) return;
        if(vis[node]) return;
        if(dis==k) ans.push_back(node->val);
        if(dis>k) return;
        vis[node]=true;
        dfs(node->left,dis+1,k,ans,vis,parent);
        dfs(node->right,dis+1,k,ans,vis,parent);
        dfs(parent[node],dis+1,k,ans,vis,parent);
    }


};