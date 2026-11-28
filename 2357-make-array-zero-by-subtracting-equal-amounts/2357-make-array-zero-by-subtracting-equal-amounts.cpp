class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=0){
                p.push(nums[i]);
            }
        }
        int count=0;
        while(!p.empty()){
            int mini =p.top();
            p.pop();
            count++;
            while(!p.empty()&& p.top()==mini){ 
                p.pop();// if elemts with duplictaes occur 
            }
        }
        return count;

        
    }
};