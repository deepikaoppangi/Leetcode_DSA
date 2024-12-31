// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size();
//         if(n==1){
//             return nums[0];
//         }
//         vector<int>dp1(n-1,-1);
//         vector<int>dp2(n-1,-1);
//         dp1[0]=nums[0];
//         dp2[0]=nums[1];
//         for(int i = 1;i<n-1;i++){
//             int pick;
//             if(i-2>=0){
//                 pick = nums[i]+dp1[i-2];
//             }
//             else if(i-2<0){
//                 pick = nums[i];
//             }
//             int nonpick = dp1[i-1];
//             dp1[i]=max(pick,nonpick);
//         }
//         for(int i = 2;i<n;i++){
//             int pick;
//             if(i-3>=0){
//                 pick = nums[i]+dp2[i-3];
//             }
//             else if(i-3<0){
//                 pick = nums[i];
//             }
//             int nonpick = dp2[i-2];
//             dp2[i-1]=max(pick,nonpick);
//         }
//         return max(dp1[n-2],dp2[n-2]);
//     }
// };


class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = nums[start];
        for (int i = start + 1; i <= end; i++) {
            int curri = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curri;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};