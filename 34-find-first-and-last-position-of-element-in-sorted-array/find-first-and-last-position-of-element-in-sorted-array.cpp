#include <vector>

class Solution {
private:
    int findBound(const std::vector<int>& nums, int target, bool findFirst) {
        int low = 0;
        int high = nums.size() - 1;
        int bound = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents potential integer overflow

            if (nums[mid] == target) {
                bound = mid; 
                if (findFirst) {
                    high = mid - 1; // Narrow down to the left half
                } else {
                    low = mid + 1;  // Narrow down to the right half
                }
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return bound;
    }

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int start = findBound(nums, target, true);
        int end = findBound(nums, target, false);
        
        return {start, end};
    }
};