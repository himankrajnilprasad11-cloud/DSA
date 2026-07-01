class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        // Step 1: Sort the array
        std::sort(arr.begin(), arr.end());
        
        // Step 2: Get the initial common difference
        int diff = arr[1] - arr[0];
        
        // Step 3: Verify the difference for the rest of the array
        for (size_t i = 2; i < arr.size(); ++i) {
            if (arr[i] - arr[i-1] != diff) {
                return false;
            }
        }
        
        return true;
    }
};