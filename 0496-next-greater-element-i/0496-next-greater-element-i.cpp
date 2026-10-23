class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int, int> nextGreaterMap;
        stack<int> st;

        // Traverse nums2 from right to left to find the next greater element for each value
        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists to the right
            if (st.empty()) {
                nextGreaterMap[nums2[i]] = -1;
            } else {
                nextGreaterMap[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        // Build the result for nums1 using the precomputed map
        vector<int> result(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            result[i] = nextGreaterMap[nums1[i]];
        }

        return result;
    }
};