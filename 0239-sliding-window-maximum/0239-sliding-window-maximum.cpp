
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        vector<int> ans;
        deque<int> q;
        int n = nums.size();

        for(int i = 0; i < n; i++)
        {
            while(!q.empty() && nums[i] > nums[q.back()])
            {
                q.pop_back();
            }

            q.push_back(i);

            if(q.front() < i - k + 1)
            {
                q.pop_front();
            }

            if(i >= k - 1)
            {
                ans.push_back(nums[q.front()]);
            }
        }

        return ans;
    }
};


