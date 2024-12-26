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