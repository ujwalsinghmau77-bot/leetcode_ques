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
void getpath(TreeNode*root,vector<int>&res){
    if(root==NULL)return ;
    if(root->left == NULL && root->right == NULL){
        res.push_back(root->val);
        return ;
    }
    getpath(root->left,res);
    getpath(root->right,res);
}
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1;
        vector<int>v2;
        getpath(root1,v1);
        getpath(root2,v2);
        return v1==v2;
        
    }
};