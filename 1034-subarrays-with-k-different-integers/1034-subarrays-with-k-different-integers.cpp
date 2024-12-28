class Solution {
public:
    int fun(vector<int>& nums,int k){
        int n = nums.size();
        int cnt=0;
        if(k<0){
            return 0;
        }
        map<int,int>mpp;
        int start=0;
        for(int end=0;end<n;end++){
            mpp[nums[end]]++;
            while(mpp.size()>k){
                mpp[nums[start]]--;
                if(mpp[nums[start]]==0){
                    mpp.erase(nums[start]);
                }
                start++;
            }
            cnt=cnt+(end-start+1);
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        //no.of subarray's  with <=k - no.of subarray's <=k-1
        return fun(nums,k)-fun(nums,k-1);
    }
};