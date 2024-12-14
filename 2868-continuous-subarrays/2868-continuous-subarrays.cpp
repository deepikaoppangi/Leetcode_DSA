class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        deque<int> minDeque, maxDeque; // To store indices for min and max
        long long total = 0;
        int start = 0;
        for (int end = 0; end < n; ++end) {
            // Maintain minDeque in increasing order
            while (!minDeque.empty() && nums[minDeque.back()] > nums[end]) {
                minDeque.pop_back();
            }
            minDeque.push_back(end);
            // Maintain maxDeque in decreasing order
            while (!maxDeque.empty() && nums[maxDeque.back()] < nums[end]) {
                maxDeque.pop_back();
            }
            maxDeque.push_back(end);
            // Shrink the window if the condition is violated
            while (nums[maxDeque.front()] - nums[minDeque.front()] > 2) {
                if (minDeque.front() == start) minDeque.pop_front();
                if (maxDeque.front() == start) maxDeque.pop_front();
                ++start;
            }
            // Add the count of valid subarrays ending at `end`
            total += (end - start + 1);
        }
        return total;
    }
};
