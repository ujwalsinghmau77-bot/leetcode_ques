class Solution {
public:
    TreeNode* node1=NULL;
    TreeNode* node2=NULL;
    TreeNode* prev=NULL;


    void solve(TreeNode* root){
        if(root==NULL) return;

        solve(root->left);
        if(prev!=NULL){
            if(prev->val>root->val){
                if(node1==NULL) node1=prev;
                node2=root;
            }
        }
        prev=root;
        solve(root->right);    
    }

    void recoverTree(TreeNode* root) {       
        solve(root);
        swap(node1->val,node2->val);
    }
};