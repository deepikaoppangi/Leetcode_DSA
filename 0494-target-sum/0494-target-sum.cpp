class Solution {
public:
    int fun(int i , int sum , vector<int> &nums,int target){
        int n = nums.size();
        if(i==-1){
            if(sum==target){
                return 1;
            }
            return 0;
        }
        int negative = fun(i-1,sum-nums[i],nums,target);
        int positive = fun(i-1,sum+nums[i],nums,target);
        return negative+positive;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size();
        return fun(n-1,0,nums,target);
    }
};  


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n  = nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum=sum+nums[i];
//         }
//         int sum2= (sum-target)/2;
//         vector<vector<int>> dp(n,vector<int>(sum2+1,0));

//         if((sum-target)<0 || (sum-target)%2!=0){
//             return 0;
//         }
//         if(nums[0]==0){
//             dp[0][0]=2;
//         }
//         else if(nums[0]!=0){
//             dp[0][0]=1;
//         }
//         if(nums[0]!=0 && nums[0]<=sum2){
//             dp[0][nums[0]]=1;
//         }
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=sum2;j++){
//                 int nonpick = dp[i-1][j];
//                 int pick = 0;
//                 if(j>=nums[i]){
//                     pick = dp[i-1][j-nums[i]];
//                 }
//                 dp[i][j]=pick+nonpick;
//             }
//         }
//         return dp[n-1][sum2];
//     }
// };  