class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for(int i = 0 ;i<k;i++){
            int x = INT_MAX;
            int index=-1;
            for(int i = 0;i<nums.size();i++){
                if(nums[i]<x && index<i){
                    x = nums[i];
                    index = i;
                }
            }
            nums[index] = nums[index]*multiplier;
        }
        return nums;
    }
};