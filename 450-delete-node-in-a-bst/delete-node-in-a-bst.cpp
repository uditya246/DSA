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
        TreeNode* helper(TreeNode* root){
            if(root->right==NULL){
                return root->left;
            }
            else if(root->left==NULL){
                return root->right;
            }
            TreeNode* rightmost = findright(root->left);
            TreeNode* rightchild  = root->right;
            rightmost->right = rightchild;
            return root->left;
        }
        TreeNode* findright(TreeNode* root){
            if(root->right==NULL){
                return root;
            }
            return findright(root->right);
        }
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* temp = root;
        if(root==NULL) return root;
        if(root->val  == key){
            return helper(root);
        }
        while(root){
            if(root->val>key){
                if(root->left!=NULL&&root->left->val==key){
                    root->left = helper(root->left);
                    break;
                }
                else root = root->left;
            }
            else{
                if(root->right&&root->right->val==key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};