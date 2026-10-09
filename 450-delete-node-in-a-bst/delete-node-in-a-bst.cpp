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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if(root->val==key){
            return helper(root);
        }
        TreeNode* temp=root;
        while(temp){
            if(key<temp->val){
                if(temp->left){
                    if(temp->left->val==key){
                        temp->left=helper(temp->left);
                        return root;
                    }else{
                        temp=temp->left;
                    }
                }else return root;
            }else{
                if(temp->right){
                    if(temp->right->val==key){
                        temp->right=helper(temp->right);
                        return root;
                    }else{
                        temp=temp->right;
                    }
                }else{
                    return root;
                }
            }
        }
        return root;

    }

    TreeNode* helper(TreeNode* root){
        if(root->left==NULL) return root->right;
        if(root->right==NULL) return root->left;
        TreeNode* rightChild=root->right;
        TreeNode* node=findRight(root->left);
        node->right=rightChild;
        return root->left;
    }

    TreeNode* findRight(TreeNode* root){
        while(root->right) root=root->right;
        return root;
    }
};