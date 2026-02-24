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
    void func(TreeNode* root,int currsum,int& count){
        if(root==NULL){
            return;
        }
        currsum= currsum*2+root->val;
        if(!root->left&&!root->right){
            count +=currsum;
            return;
        }

        func(root->left,currsum,count);
        func(root->right,currsum,count);
    }
    int sumRootToLeaf(TreeNode* root) {
        int count = 0;
        if(root ==NULL) return count;
        func(root,0,count);
        return count;
    }
};