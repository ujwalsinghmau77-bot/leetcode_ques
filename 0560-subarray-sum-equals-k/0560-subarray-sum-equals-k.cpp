class Solution {
public:
    int subarraySum(vector<int>& a, int k) {
        
        unordered_map<int, int> freq;
    freq[0] = 1; // Base case: prefix sum of 0 has occurred once

    int sum = 0;
    int res = 0;
    int n = a.size();

    for (int i = 0; i < n; i++) {
        sum += a[i];
        
        // C++ map automatically returns 0 if (sum - k) is not found
        res += freq[sum - k]; 
        
        // Record current prefix sum for future iterations
        freq[sum]++;
    }

    return res;
    }
};