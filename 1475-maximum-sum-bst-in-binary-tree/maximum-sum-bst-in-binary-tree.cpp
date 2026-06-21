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
    vector<int>traverse(TreeNode* root,int& ans){
        if(!root) return{INT_MAX,INT_MIN,0};
        vector<int>leftt(traverse(root->left,ans)),rightt(traverse(root->right,ans));
        if (leftt.empty() || rightt.empty() || root->val <= leftt[1] || root->val >= rightt[0]) return {};
        int curr = leftt[2]+rightt[2]+root->val;
        ans = max(ans,curr);
        return{min(leftt[0],root->val),max(rightt[1],root->val),curr};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        traverse(root,ans);
        return ans;

    }
};