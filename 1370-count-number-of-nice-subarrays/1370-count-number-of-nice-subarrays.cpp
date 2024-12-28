class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int start=0;
        int cnt=0;
        int odd=0;
        vector<int>oddarr;
        for(int end=0;end<n;end++){
            if(nums[end]%2==1){
                odd++;
                oddarr.push_back(end);
            }
            while(odd>k){
                if(nums[start]%2==1){
                    odd--;
                    oddarr.erase(oddarr.begin());
                }
                start++;
            }
            if(odd==k){
                //cnt = cnt+ (end-start+1) - (end-begining);
                cnt = cnt+ (oddarr[0]-start+1);
            }
        }
        return cnt;
    }
};