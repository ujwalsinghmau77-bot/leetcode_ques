class Solution {
public:
    int work(TreeNode* &root, int& maxi){
        if(root==NULL) return 0;
        int l=work(root->left,maxi);
        int r=work(root->right,maxi);

        maxi=max(maxi,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        work(root,maxi);
        return maxi;
    }
};