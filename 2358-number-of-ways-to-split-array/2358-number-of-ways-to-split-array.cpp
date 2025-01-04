

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num;
        }
        
        long long leftSum = 0;
        int validSplits = 0;
        
        // Iterate through the array
        for (int i = 0; i < n - 1; ++i) {
            leftSum += nums[i];  // Update left sum
            long long rightSum = totalSum - leftSum;  // Calculate right sum
            
            // Check if the current split is valid
            if (leftSum >= rightSum) {
                ++validSplits;
            }
        }
        
        return validSplits;
    }
};
