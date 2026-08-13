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
    unordered_map<TreeNode* ,int>mp;
    int rob(TreeNode* root) {

        if(!root) return 0;
        if(mp.count(root)) return mp[root];
        int dontrob = rob(root->left)+rob(root->right);
        int robb = root->val;
        if(root->left) robb += rob(root->left->right)+rob(root->left->left);
        if(root->right) robb += rob(root->right->right)+rob(root->right->left);
        return mp[root]=max(robb,dontrob);
    }
};