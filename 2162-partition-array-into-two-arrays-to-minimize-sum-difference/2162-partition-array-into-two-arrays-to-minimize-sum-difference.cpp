
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        // Generate all subsets sums for both halves
        auto getSubsetSums = [](vector<int>& arr) {
            int len = arr.size();
            vector<vector<int>> subsetSums(len + 1);
            for (int mask = 0; mask < (1 << len); ++mask) {
                int count = 0, sum = 0;
                for (int i = 0; i < len; ++i) {
                    if (mask & (1 << i)) {
                        ++count;
                        sum += arr[i];
                    }
                }
                subsetSums[count].push_back(sum);
            }
            for (auto& sums : subsetSums) {
                sort(sums.begin(), sums.end());
            }
            return subsetSums;
        };

        vector<vector<int>> leftSums = getSubsetSums(left);
        vector<vector<int>> rightSums = getSubsetSums(right);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum / 2;
        int minDiff = INT_MAX;

        // Minimize the absolute difference
        for (int i = 0; i <= n; ++i) {
            for (int sumL : leftSums[i]) {
                int needed = target - sumL;
                auto& rightSet = rightSums[n - i];
                auto it = lower_bound(rightSet.begin(), rightSet.end(), needed);
                
                // Check closest sums in the right subset
                if (it != rightSet.end()) {
                    int sumR = *it;
                    int diff = abs(totalSum - 2 * (sumL + sumR));
                    minDiff = min(minDiff, diff);
                }
                if (it != rightSet.begin()) {
                    int sumR = *(--it);
                    int diff = abs(totalSum - 2 * (sumL + sumR));
                    minDiff = min(minDiff, diff);
                }
            }
        }

        return minDiff;
    }
};
