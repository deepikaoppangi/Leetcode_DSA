// class Solution {
// public:
//     int fun(int i , int sum , vector<int> &nums,int target){
//         int n = nums.size();
//         if(i==-1){
//             if(sum==target){
//                 return 1;
//             }
//             return 0;
//         }
//         int negative = fun(i-1,sum-nums[i],nums,target);
//         int positive = fun(i-1,sum+nums[i],nums,target);
//         return negative+positive;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n  = nums.size();
//         return fun(n-1,0,nums,target);
//     }
// };  


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int n  = nums.size();
//         int sum=0;
//         for(int i=0;i<n;i++){
//             sum=sum+nums[i];
//         }
//         if((sum-target)%2!=0 || (sum<abs(target)) ){
//             return 0;
//         }
//         int sum2= (sum-target)/2;
//         vector<int>prev(sum2+1,0);
//         vector<int>curr(sum2+1,0);
//         prev[0]=1;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<=sum2;j++){
//                 int nonpick = prev[j];
//                 int pick = 0;
//                 if(j>=nums[i]){
//                     pick = prev[j-nums[i]];
//                 }
//                 curr[j]=pick+nonpick;
//             }
//             prev=curr;
//         }
//         return prev[sum2];
//     }
// };  



class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n  = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        if((sum-target)<0 || (sum-target)%2!=0){
            return 0;
        }
        int sum2= (sum-target)/2;
        vector<int>prev(sum2+1,0);
        vector<int>curr(sum2+1,0);
        if(nums[0]==0){
            prev[0]=2;
        }
        else if(nums[0]!=0){
            prev[0]=1;
        }
        if(nums[0]!=0 && nums[0]<=sum2){
            prev[nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum2;j++){
                int nonpick = prev[j];
                int pick = 0;
                if(j>=nums[i]){
                    pick = prev[j-nums[i]];
                }
                curr[j]=pick+nonpick;
            }
            prev=curr;
        }
        return prev[sum2];
    }
}; 