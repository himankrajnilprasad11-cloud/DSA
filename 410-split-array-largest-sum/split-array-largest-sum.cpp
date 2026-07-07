class Solution {
private:
    bool canSplit(const std::vector<int>& nums, int k, int target_max_sum) {
        int subarray_count = 1;
        int current_sum = 0;
        for (int num : nums) {
            if (current_sum + num > target_max_sum) {
                subarray_count++;
                current_sum = num;
            } else {
                current_sum += num;
            }
        }
        return subarray_count <= k;
    }
public:
    int splitArray(std::vector<int>& nums, int k) { 
        int low = *std::max_element(nums.begin(), nums.end());
        int high = std::accumulate(nums.begin(), nums.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            if (canSplit(nums, k, mid)) {
                ans = mid;        
                high = mid - 1;    
            } else {
                low = mid + 1;     
            }
        }
        return ans;
    }
};