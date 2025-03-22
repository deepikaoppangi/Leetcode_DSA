// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& nums) {
//         vector<int>sortednums=nums;
//         int n = nums.size();
//         for(int i=0;i<n;i++){
//             sortednums[i]=sortednums[i]*sortednums[i];
//         }
//         sort(sortednums.begin(),sortednums.end());
//         return sortednums;
//     }
// };

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int left = 0, right = n - 1, i = n - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[i] = nums[left] * nums[left];
                left++;
            } 
            else {
                res[i] = nums[right] * nums[right];
                right--;
            }
            i--;
        }
        return res;
    }
};