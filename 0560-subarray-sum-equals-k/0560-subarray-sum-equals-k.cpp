class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[0] = 1; 

        int sum = 0;
        int res = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            

            res += freq[sum - k];
            
            
            freq[sum]++;
        }

        return res;
        
    }
};