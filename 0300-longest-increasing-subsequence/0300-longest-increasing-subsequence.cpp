///////////////recursion , time limit exceeded , 22/55

// class Solution {
// public:
//     int fun(int i , int prev , vector<int> &nums){
//         if(i==-1){
//             return 0;
//         }
//         if(nums[i]<prev){
//             return max(  1+fun(i-1,nums[i],nums) , fun(i-1,prev , nums));
//         }
//         return fun(i-1,prev , nums);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         return fun(n-1,INT_MAX,nums);
//     }
// };

////top down   //
// class Solution {
// public:
//     int fun(int i , int prev_ind , vector<int> &nums , vector<vector<int>> &dp){
//         int n = nums.size();
//         if(i==n){
//             return 0;
//         }
//         if(dp[i][prev_ind+1]!=-1){
//             return dp[i][prev_ind+1];
//         }
//         int take=0;
//         if(prev_ind==-1 || nums[i]>nums[prev_ind]){
//             take=1+fun(i+1,i,nums,dp);
//         }
//         int nontake = fun(i+1,prev_ind,nums,dp);
//         return dp[i][prev_ind+1] = max(take,nontake);

//     }
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return fun(0,-1,nums,dp);
//     }
// };


///bottom up    TC ->O(N^2) ,  SC->O(N^2)


// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1,vector<int>(n+1,0));
//         for(int i=n-1;i>=0;i--){
//             for(int prev_ind=i-1; prev_ind>=-1;prev_ind--){
//                 int take=0;
//                 if(prev_ind==-1 || nums[i]>nums[prev_ind]){
//                     take = 1+ dp[i+1][i+1];
//                 }
//                 int nontake = dp[i+1][prev_ind+1];
//                 dp[i][prev_ind+1] = max(take,nontake);
//             }
//         }
//         return dp[0][0];
//     }
// };
 
//////space optimized   TC ->O(N^2) ,  SC->O(2N)
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> after(n+1,0);
//         vector<int> curr(n+1,0);
//         for(int i=n-1;i>=0;i--){
//             for(int prev_ind=i-1; prev_ind>=-1;prev_ind--){
//                 int take=0;
//                 if(prev_ind==-1 || nums[i]>nums[prev_ind]){
//                     take = 1+ after[i+1];
//                 }
//                 int nontake = after[prev_ind+1];
//                 curr[prev_ind+1] = max(take,nontake);
//             }
//             after=curr;
//         }
//         return after[0];
//     }
// };

//////////////////////nice  TC ->O(N^2) ,  SC->//O(N) 
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n = nums.size();
//         if (n == 0) return 0;
//         int maxi=1;
//         vector<int> dp(n, 1);
//         for (int i = 1; i < n; ++i) {
//             for (int j = 0; j < i; ++j) {
//                 if (nums[i] > nums[j]) {
//                     dp[i] = max(dp[i], dp[j] + 1);
//                 }
//             }
//             maxi = max(maxi,dp[i]);
//         }
//         return maxi;
//         //return *max_element(dp.begin(), dp.end());
//     }
// };

////////////Binary search 

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};