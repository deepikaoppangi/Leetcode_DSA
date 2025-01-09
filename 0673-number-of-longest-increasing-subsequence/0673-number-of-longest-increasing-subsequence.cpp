////1 3 5 4 7 6 
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1);
        vector<int>count(n,1);
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    count[i] = count[j];
                }
                else if(nums[i]>nums[j] && dp[j]+1==dp[i]){
                    count[i]=count[i]+count[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        int nof = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi){
                nof = nof + count[i];
            }
        }
        return nof;
    }
};