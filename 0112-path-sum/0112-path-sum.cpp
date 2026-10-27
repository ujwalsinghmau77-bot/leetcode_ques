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
  bool solve(TreeNode*root,int sum,int&targetsum)
  {
    if(root==NULL)return false;
    sum+=root->val;
    if(!root->left&&!root->right){
        if(sum==targetsum)
        return true;
    }
      return solve(root->left,sum,targetsum)||solve(root->right,sum,targetsum);
  }
    bool hasPathSum(TreeNode* root, int targetsum) {
       return solve(root,0,targetsum);
        
        
    }
};