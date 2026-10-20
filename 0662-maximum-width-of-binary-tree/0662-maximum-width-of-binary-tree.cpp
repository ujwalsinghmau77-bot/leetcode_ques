class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>> que;
        que.push({root,0});
        long long maxi=1;

        while(!que.empty()){
            int n=que.size();
            long long lm=-1;
            long long rm=-1;
            while(n--){
                TreeNode* node=que.front().first;
                int p=que.front().second; que.pop();
                
                if(lm==-1){
                    lm=p;
                    rm=p;
                }
                else {rm=p;}

                if(node->left) que.push({node->left,2LL*p+1});
                if(node->right) que.push({node->right,2LL*p+2});

            }
            maxi=max(maxi,rm-lm+1);
        }

        return maxi;
    }
};