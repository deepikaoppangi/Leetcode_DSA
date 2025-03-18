// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target){
//         int n= nums.size();
//         vector<int>result;
//         int low = 0;
//         int high  = n-1;
//         while(low<high){
//             if(nums[low] + nums[high] == target){
//                 result.push_back(low);
//                 result.push_back(high);
//                 return result;
//             }
//             else if(nums[low] + nums[high] > target && nums[high]){
//                 high--;
//             }
//             else if(nums[low] < target) {
//                 low++;
//             }
//         }
//         return result;
//     }
// };



/////////////correct solution with o(n^2)
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         vector<int>result;
//         for (int i = 0 ;i < n ; i++){
//             for(int j =i+1 ;j<n;j++){
//                 if(nums[i]+nums[j] == target){
//                     result.push_back(i);
//                     result.push_back(j);
//                     return result;
//                 }
//             }
//         }
//         return result;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0 ;i < n ; i++){
            for(int j =i+1 ;j<n;j++){
                if(nums[i]+nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

