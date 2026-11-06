class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) {
                return true;
            }

            // Check if left part is sorted or not
            if (nums[low] < nums[mid]) {
                if (target < nums[low] || target > nums[mid]) {
                    // Target is outside left part
                    low = mid + 1;
                }
                else {
                    // Target lies within left part
                    high = mid - 1;
                }
            }

            else if (nums[low] > nums[mid]) {
                // Right part is sorted
                if (target < nums[mid] || target > nums[high]) {
                    high = mid - 1;
                }
                else {
                    // Target lies within right part
                    low = mid + 1;
                }
            }

            else {
                // Handle duplicates
                low++;
            }
        }

        return false;
    }
};