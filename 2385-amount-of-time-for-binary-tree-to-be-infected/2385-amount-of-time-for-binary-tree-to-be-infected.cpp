class Solution {
public:
    void makegraph(unordered_map<int,vector<int>>& mp, int parent, TreeNode* curr)
    {
        if(!curr) return;

        if(parent != -1){
            mp[curr->val].push_back(parent);
        }

        if(curr->left){
            mp[curr->val].push_back(curr->left->val);
        }

        if(curr->right){
            mp[curr->val].push_back(curr->right->val);
        }

        makegraph(mp,curr->val,curr->left);
        makegraph(mp,curr->val,curr->right);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>> mp;
        makegraph(mp,-1,root);

        queue<int> q;
        unordered_set<int> visited;

        q.push(start);
        visited.insert(start);

        int minutes = 0;

        while(!q.empty()){
            int n = q.size();
            bool burn = false;

            for(int i = 0; i < n; i++){
                int temp = q.front();
                q.pop();

                for(int x : mp[temp]){
                    if(visited.find(x) == visited.end()){
                        q.push(x);
                        visited.insert(x);
                        burn = true;
                    }
                }
            }

            if(burn) minutes++;
        }

        return minutes;
    }
};