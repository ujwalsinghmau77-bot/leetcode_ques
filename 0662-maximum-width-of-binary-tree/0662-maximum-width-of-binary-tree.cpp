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
    int widthOfBinaryTree(TreeNode* root) {
        typedef unsigned long long ll;
        queue<pair<TreeNode*,ll>>q;
        q.push({root,0});
        ll maxwidth=0;
        while(!q.empty()){
            ll L =q.front().second;
            ll R=q.back().second;
            maxwidth=max(maxwidth,R-L+1);
            int n =q.size();
            while(n--){
                TreeNode*temp=q.front().first;
                ll p = q.front().second;
                q.pop();
                if(temp->left){
                    q.push({temp->left,2*p+1});
                }
                if(temp->right){
                    q.push({temp->right,2*p+2});
                }
            }
            

        }
        return maxwidth;
        
    }
};