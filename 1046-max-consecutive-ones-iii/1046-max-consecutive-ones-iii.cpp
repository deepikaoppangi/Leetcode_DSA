//i can do the brute force for this problem
//consider this maximum subarray with atmost k zeroes

//time limit exceeded for these , 52/59 test cases. //brute force 

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int n =  nums.size();
//         int maxlen=0;
//         for(int i=0;i<n;i++){
//             int zeros=0;
//             for(int j=i;j<n;j++){
//                 if(nums[j]==0){
//                     zeros++;
//                 }
//                 if(zeros>k){
//                     break;
//                 }
//                 maxlen = max(maxlen,j-i+1);
//             }
//         }
//         return maxlen;
//     }
// };

//sliding window 

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =  nums.size();
        int maxlen=0;
        int start = 0 ;
        int zeros=0;
        for(int end=0;end<n;end++){
            if(nums[end]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[start]==0){
                    zeros--;
                }
                start++;
            }
            maxlen = max(maxlen , end-start+1);
        }
        return maxlen;
    }
};