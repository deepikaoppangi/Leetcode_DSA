// //brute force //accepted O(n^2)
// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//         int n = nums.size();
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             int sum=0;
//             for(int j=i;j<n;j++){
//                 sum=sum+nums[j];
//                 if(sum==goal){
//                     cnt++;
//                 }
//                 else if(sum>goal){
//                     break;
//                 }
//             }
//         }
//         return cnt;
//     }
// };

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        if(goal<0){
            return 0;
        }
        if(goal==0){
            return atMost(nums, goal);
        }
        //no.of subarray with sum<=goal - no.of.suarray with sum<=goal-1
        return atMost(nums, goal)-atMost(nums, goal - 1);
    }
    int atMost(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        int left = 0;
        int sum = 0;
        for (int right=0;right<n;right++) {
            sum = sum+ nums[right]; 
            while(sum>goal) {
                sum = sum- nums[left];
                left++;
            }
            cnt = cnt + (right-left+1);
        }
        return cnt;
    }
};
