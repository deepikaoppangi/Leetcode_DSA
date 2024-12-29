class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> windowSums(n - k + 1, 0);
        vector<int> left(n - k + 1, 0), right(n - k + 1, 0);
        vector<int> result(3, 0);

        // Calculate sums of all k-length subarrays
        int currentSum = 0;
        for (int i = 0; i < n; i++) {
            currentSum += nums[i];
            if (i >= k) currentSum -= nums[i - k];
            if (i >= k - 1) windowSums[i - k + 1] = currentSum;
        }

        // Fill left array (max sum subarray on the left side)
        int maxIndex = 0;
        for (int i = 0; i < windowSums.size(); i++) {
            if (windowSums[i] > windowSums[maxIndex]) {
                maxIndex = i;
            }
            left[i] = maxIndex;
        }

        // Fill right array (max sum subarray on the right side)
        maxIndex = windowSums.size() - 1;
        for (int i = windowSums.size() - 1; i >= 0; i--) {
            if (windowSums[i] >= windowSums[maxIndex]) { // Ensure lexicographical order
                maxIndex = i;
            }
            right[i] = maxIndex;
        }

        // Iterate for middle interval
        int maxSum = 0;
        for (int mid = k; mid < windowSums.size() - k; mid++) {
            int leftIndex = left[mid - k];
            int rightIndex = right[mid + k];
            int totalSum = windowSums[leftIndex] + windowSums[mid] + windowSums[rightIndex];
            if (totalSum > maxSum) {
                maxSum = totalSum;
                result = {leftIndex, mid, rightIndex};
            }
        }

        return result;
    }
};
