class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSums(n + 1, 0);
        
        // Compute prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSums[i + 1] = prefixSums[i] + nums[i];
        }
        
        vector<int> left(n, 0), right(n, n - k);
        
        // Compute best left indices
        int maxSum = prefixSums[k] - prefixSums[0];
        for (int i = k; i < n; ++i) {
            if (prefixSums[i + 1] - prefixSums[i + 1 - k] > maxSum) {
                left[i] = i + 1 - k;
                maxSum = prefixSums[i + 1] - prefixSums[i + 1 - k];
            } else {
                left[i] = left[i - 1];
            }
        }
        
        // Compute best right indices
        maxSum = prefixSums[n] - prefixSums[n - k];
        for (int i = n - k - 1; i >= 0; --i) {
            if (prefixSums[i + k] - prefixSums[i] >= maxSum) {
                right[i] = i;
                maxSum = prefixSums[i + k] - prefixSums[i];
            } else {
                right[i] = right[i + 1];
            }
        }
        
        // Find the best three subarrays
        vector<int> result(3, -1);
        maxSum = 0;
        for (int i = k; i <= n - 2 * k; ++i) {
            int l = left[i - 1];
            int r = right[i + k];
            int totalSum = (prefixSums[l + k] - prefixSums[l]) + 
                           (prefixSums[i + k] - prefixSums[i]) + 
                           (prefixSums[r + k] - prefixSums[r]);
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {l, i, r};
            }
        }
        
        return result;
    }
};
