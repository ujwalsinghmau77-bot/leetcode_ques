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
 void solve(TreeNode*root,TreeNode*target,vector<TreeNode*>& path){
    if(root==NULL)return;
    path.push_back(root);
    if(root==target) return ;
    if(root->val>target->val){
        solve(root->left,target,path);
    }
    if(root->val<target->val){
        solve(root->right,target,path);
    }

 }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>v1;
        vector<TreeNode*>v2;
        solve(root,p,v1);
        solve(root,q,v2);
        TreeNode*ans=NULL;
        int i =0;
        while(i<v1.size()&&i<v2.size()){
            if(v1[i]!=v2[i])
            break;
            ans=v1[i];
            i++;
        }
        return ans;
        
    }
};