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
    TreeNode* tree(vector<int>& postorder,int startpost,int endpost,vector<int>& inorder,int startin,int endin,map<int,int>&mp){
        if(startpost>endpost||startin>endin){
            return NULL;
        }
        TreeNode* node = new TreeNode(postorder[endpost]);
        int rootin = mp[postorder[endpost]];
        int leftin = rootin-startin;

        node->left = tree(postorder,startpost,startpost+leftin-1,inorder,startin,rootin-1,mp);
        node->right = tree(postorder,startpost+leftin,endpost-1,inorder,rootin+1,endin,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = tree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};