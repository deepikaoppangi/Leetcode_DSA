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
//         for (int i = 0 ;i < n ; i++){
//             for(int j =i+1 ;j<n;j++){
//                 if(nums[i]+nums[j] == target){
//                     return {i,j};
//                 }
//             }
//         }
//         return {};
//     }
// };

/////optimal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mpp;
        for (int i = 0 ;i < n ; i++){
            int temp=target-nums[i];
            if(mpp.find(temp)!=mpp.end()){
                return {mpp[temp],i};
            }
            else{
                mpp[nums[i]]=i;
            }
        }
        return {};
    }
};

