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
    TreeNode* tree(vector<int>& preorder,int startpre,int endpre,vector<int>& inorder,int startin,int endin,map<int,int>&mp){
        if(startpre>endpre||startin>endin){
            return NULL;
        }
        TreeNode* node = new TreeNode(preorder[startpre]);
        int rootin = mp[preorder[startpre]];
        int leftin = rootin-startin;

        node->left = tree(preorder,startpre+1,startpre+leftin,inorder,startin,rootin-1,mp);
        node->right = tree(preorder,startpre+leftin+1,endpre,inorder,rootin+1,endin,mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
};