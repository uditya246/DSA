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
    void solve(TreeNode* node,vector<string>& ans,string path){

        if(node == nullptr) return;
        path += to_string(node->val);
        if(node->right==NULL&&node->left==NULL){
            ans.push_back(path);
            return;
        }
        solve(node->left,ans,path+"->");
        solve(node->right,ans,path+"->");
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s = "";
        solve(root,ans,s);
        return ans;
    }
};