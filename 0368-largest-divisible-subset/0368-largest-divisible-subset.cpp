
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxind=0;
        int maxi=1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                maxind=i;
            }
        }
        vector<int>result;
        result.push_back(nums[maxind]);
        while(hash[maxind]!=maxind){
            maxind=hash[maxind];
            result.push_back(nums[maxind]);
        }
        return result;
    }
};